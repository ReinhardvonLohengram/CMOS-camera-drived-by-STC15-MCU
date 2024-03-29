


#include "stc15f2k60s2.h"
#include "sram.h"
#include "tft.h"
#include "def.h"
#include "gui.h"
#include "key.h"
#include "delay.h"
#include "xpt2046.h"


//内存管理函数
//分为两部分  一部分是内存池   一部分是内存管理表
//内存池：指定地址的的数组   所有申请的内存 最后都将指向这里
//内存管理表： 每32个字节表示一块  其大小=内存池/32 个块
//申请内存时  是在内存管理器中 由最后一块开始找到要申请的连续内存块数 并将采集的地址以指针形式返回供调用

	    

//内存片选使能
//内存用到P2 P0 口 而TFT也同样用这两个口
//在使用外部内存时 调用此函数 防止和屏显示发生冲突
//m  0 关闭外部内存片选 开TFT片选  1关闭TFT片选 开内存片选
void sram(u8 m)
{
  if(m==1){ LCD_CS=1; SRAM=0;}
  if(m==0){ SRAM=1; LCD_CS=0;}
}


u8 sram_init=0;			   //内存初始化标志
																	//外部内存空间一共用了 26*1024+1664=28288
																	
u8  srambase[SRAM_BASE_SIZE]_at_(0X0f00);		            	    //外部SRAM内存池 0x0f00 为内存池起始地址
																    //地址为0x0f00 是因为 使用内部扩展和外部扩展内存公用
																	//外部SRAM芯片用的32k  内部扩展内存为1.75k  但手册是3.75k后开始为外部扩展
																	//那么外部扩展为32-3.75=28.25k  也就是外部扩展从3.75k开始即0x0f00
																	


																    //内存管理表 在内存池的后面定义一个空间的一个空间
																	//所以在建立内存池的时候一定要考虑到这一点
u16  srammapbase[SRAM_MAP_SIZE]_at_(0X0f00+SRAM_BASE_SIZE);	        //外部SRAM内存池管理表MAP	地址为内存最末端
																	//如果是26K的内存 
																	//那么内存管理表要用到=((1024*26)/32)*2=1664个字节



//设置内存
//*s:内存首地址
//c :要设置的值
//count:需要设置的内存大小(字节为单位)
void mymemset(void  *s,u8 c,u16 count)  
{  
    u8 *xs = s;  
    while(count--)*xs++=c;  
}	   


//内存管理初始化  
void mem_init()  
{  
    sram(1);	   //打开内存片选
    mymemset(srammapbase, 0,SRAM_MAP_SIZE*2);//内存状态表数据清零  	内存管理表是16位2字节数组 所以后面要*2
	mymemset(srambase, 0,SRAM_BASE_SIZE);	 //内存池所有数据清零  								 
    sram_init=1;  //初始化完成标志符
	sram(0);	   //关闭内存片选

}  




//获取内存使用率  即内存管理表 用到的内存块数/内存管理表的所有块数
//返回值:使用率(0~100)
u8 mem_perused()  
{  
    u32 used=0;  
    u32 i;
	sram(1);  
    for(i=0;i<SRAM_MAP_SIZE;i++)  		  //读出使用的内存块数
    {  
        if(srammapbase[i])used++; 
    } 
	sram(0);
    return (used*100)/(SRAM_MAP_SIZE); 
}  




//内存分配(内部调用)
//size:要分配的内存大小(字节)
//返回值:0XFFFF,代表错误;其他,内存偏移地址 	即字节数
u16 mem_malloc(u16 size)  
{  
    u16 offset=0;  
    u16 nmemb;	//需要的内存块数  
	u16 cmemb=0;//连续空内存块数
    u16 i; 

    if(sram_init==0)mem_init();//未初始化,先执行初始化 

    if(size==0)return 0XFFFF;//不需要分配

									
    nmemb=size/SRAM_BLOCK_SIZE;  	      //获取需要分配的连续内存块数   每块内存32个字节  size/32=需要的内存块数
    if(size%SRAM_BLOCK_SIZE)nmemb++;  	  //如果块数还有小数   块数+1


    for(offset=SRAM_MAP_SIZE-1;offset>=0;offset--)//搜索整个内存控制区  即内存管理表=总内存字节数/32 	由高到低
    {     
													//从最末端开始  
		if(!srammapbase[offset])cmemb++;            //连续空内存块数增加
		else cmemb=0;								//非连续内存块清零

		if(cmemb==nmemb)							//找到了连续nmemb个空内存块
		{
            for(i=0;i<nmemb;i++)  					//标注内存块非空 
            {  
                srammapbase[offset+i]=nmemb;  	    //将申请的每一个内存块的值 赋值用到的内存块数值	  以便后期查找使用的内存块
            }  
			
            return (offset*SRAM_BLOCK_SIZE);        //返回偏移地址  	申请的最后内存块x32  就是在内存池里的偏移字节
		}
    }  
    return 0XFFFF;//未找到符合分配条件的内存块  
}  




//释放内存(内部调用) 		释放内存 只是将内存管理表清零 并没有清零内存池数据
//offset:内存地址偏移		
//返回值:0,释放成功;1,释放失败;  
u8 mem_free(u16 offset)  
{  
    int i;

   if(sram_init==0)//未初始化,先执行初始化
	{
		mem_init();    
        return 1;//未初始化  
    }  

    if(offset<SRAM_BASE_SIZE)//偏移在内存池内. 
    {  
        int index=offset/SRAM_BLOCK_SIZE;	//偏移所在内存申请的第最后一块位置 
        int nmemb=srammapbase[index];	    //带入内存管理表 得出申请时所申请的连续内存块数
        for(i=0;i<nmemb;i++)  				//将申请的内存块清零  即从最后一块开始往前连续nmemb块 进行清内存管理表
        {  
            srammapbase[index+i]=0;  
        }
		for(i=0;i<(nmemb*SRAM_BLOCK_SIZE);i++)	//清空对应内存池数据 以防下次调用存在干扰问题
		srambase[offset+i]=0;
		 
        return 0;  
    }else return 2;//偏移超区了.  
}  



//释放内存(外部调用) 
//ptr:内存首地址 
void myfree(void *ptr)  
{  
	u16 offset;
	sram(1); 
    if(ptr==NULL){sram(0); return;}//地址为0. 
 	offset=(u16)ptr-(u16)srambase;  		//用内存首地址-内存池起始地址=offset在内存池里的偏移量
    mem_free(offset);//释放内存 
	sram(0);    
}  



//分配内存(外部调用)
//size:内存大小(字节)
//返回值:分配到的内存首地址.
void *mymalloc(u16 size)  
{  
    u16 offset; 

	sram(1);	   //打开内存片选								      
	offset=mem_malloc(size);  	   	//将 申请内存的 在内存池里的偏移字节offset提取			   
    if(offset==0XFFFF){sram(0); return NULL;}  //判断是否超出内存最大空间
    else { 
		 sram(0); return (void*)((u16)srambase+offset);	
	} 
}  













 