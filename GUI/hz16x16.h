
#ifndef HZ16x16_H
#define HZ16x16_H


// ------------------  汉字字模的数据结构定义 ------------------------ //
struct  typFNT_HZ16                      // 汉字字模数据结构 
{
       unsigned char  Index[3];          // 汉字内码索引		   存放内码  如"硕"  但是一个字要两个字节表示
       unsigned char   Msk[32];          // 点阵码数据 	  存放内码后对应的 点阵序列  每个字需要32个字节的点阵序列
};

/////////////////////////////////////////////////////////////////////////
// 汉字字模表                                                          //
// 汉字库: 宋体16.dot,横向取模左高位,数据排列:从左到右从上到下         //
/////////////////////////////////////////////////////////////////////////
/*这个结构，很简单的：一个是内码，一个点阵序列，
以前的点阵库是按内码顺序放的，不需要内码索引的，
如果只放部分汉字，就需要内码索引了。
一般内码两个字节就行了，多用1个字节是加了个尾0而已，
这样，汉字内码处直接放汉字字符串就可；	  */

 code struct  typFNT_HZ16 codeHZ_16[] =          // 数据表 
{
/*--  文字:  落  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"落",0x04,0x40,0x04,0x40,0xFF,0xFE,0x04,0x40,0x45,0x00,0x21,0xF8,0xA1,0x10,0x4A,0xA0,
0x48,0x40,0x10,0xA0,0x13,0x18,0xEF,0xF6,0x22,0x10,0x22,0x10,0x23,0xF0,0x22,0x10,

/*--  文字:  霞  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"霞",0x1F,0xF0,0x01,0x00,0xFF,0xFE,0x89,0x14,0x25,0x48,0x11,0x20,0x00,0x00,0x7D,0xF8,
0x44,0x08,0x7D,0xF8,0x40,0x00,0x7D,0xF8,0x40,0x90,0x7C,0x60,0x40,0xB0,0x47,0x0E,

/*--  文字:  与  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"与",0x00,0x00,0x08,0x00,0x08,0x04,0x0F,0xFE,0x08,0x00,0x08,0x00,0x0F,0xFC,0x00,0x04,
0x00,0x04,0x00,0x24,0x7F,0xF4,0x00,0x04,0x00,0x04,0x00,0x48,0x00,0x30,0x00,0x00,

/*--  文字:  孤  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"孤",0x00,0x00,0x7E,0x3C,0x05,0xD0,0x09,0x50,0x11,0x50,0x15,0x50,0x19,0x50,0x31,0x50,
0xD1,0x50,0x51,0x48,0x11,0x48,0x11,0x64,0x12,0x56,0x12,0xFA,0x54,0x50,0x20,0x00,

/*--  文字:  鹜  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"鹜",0x7E,0x40,0x14,0x40,0x08,0xFE,0xFE,0x88,0x2B,0x50,0xC8,0x30,0x1A,0xCE,0x04,0x00,
0x1F,0xE0,0x12,0x20,0x11,0x60,0x1F,0xF8,0x00,0x08,0xFF,0x88,0x00,0x28,0x00,0x10,

/*--  文字:  齐  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"齐",0x02,0x00,0x01,0x00,0x7F,0xFE,0x04,0x20,0x02,0x40,0x01,0x80,0x02,0x40,0x0C,0x30,
0x74,0x2E,0x04,0x24,0x04,0x20,0x08,0x20,0x08,0x20,0x10,0x20,0x20,0x20,0x00,0x20,

/*--  文字:  飞  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"飞",0x00,0x00,0xFF,0xC0,0x00,0x40,0x00,0x48,0x00,0x50,0x00,0x60,0x00,0x60,0x00,0x50,
0x00,0x48,0x00,0x40,0x00,0x20,0x00,0x22,0x00,0x12,0x00,0x0A,0x00,0x06,0x00,0x00,



/*--  文字:  秋  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"秋",0x00,0x20,0x0E,0x20,0xF0,0x20,0x10,0x24,0x10,0xA4,0xFE,0xA8,0x30,0xB0,0x39,0x20,
0x54,0x60,0x94,0x50,0x10,0x50,0x10,0x88,0x10,0x88,0x11,0x04,0x12,0x06,0x14,0x04,

/*--  文字:  水  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"水",0x01,0x00,0x01,0x00,0x01,0x08,0x01,0x10,0x7D,0x20,0x05,0xC0,0x05,0x40,0x09,0x20,
0x09,0x20,0x11,0x10,0x11,0x18,0x21,0x0E,0xC1,0x04,0x01,0x00,0x05,0x00,0x02,0x00,

/*--  文字:  共  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"共",0x00,0x00,0x04,0x20,0x04,0x20,0x04,0x20,0x7F,0xFC,0x04,0x20,0x04,0x20,0x04,0x20,
0x04,0x20,0xFF,0xFE,0x04,0x40,0x06,0x20,0x0C,0x10,0x08,0x18,0x10,0x0C,0x20,0x08,

/*--  文字:  长  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"长",0x08,0x00,0x08,0x10,0x08,0x20,0x08,0x40,0x09,0x80,0x0E,0x00,0x08,0x00,0xFF,0xFE,
0x0A,0x00,0x09,0x00,0x08,0x80,0x08,0x40,0x09,0x30,0x0A,0x1C,0x0C,0x08,0x08,0x00,

/*--  文字:  天  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"天",0x00,0x00,0x3F,0xFC,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x7F,0xFE,0x01,0x00,
0x01,0x00,0x02,0x80,0x02,0x40,0x04,0x20,0x08,0x18,0x10,0x0E,0x20,0x04,0x40,0x00,

/*--  文字:  一  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"一",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x7F,0xFE,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

/*--  文字:  色  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"色",0x04,0x00,0x04,0x00,0x07,0xF0,0x08,0x20,0x10,0x40,0x3F,0xF0,0x51,0x10,0x11,0x10,
0x11,0x10,0x1F,0xF0,0x10,0x00,0x10,0x04,0x10,0x04,0x10,0x04,0x0F,0xFC,0x00,0x00,


/*--  文字:  ，  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"，",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x10,0x00,0x20,0x00,0x00,0x00,

/*--  文字:  。  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"。",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x30,0x00,0x48,0x00,0x48,0x00,0x30,0x00,0x00,0x00,0x00,0x00,

/*--  文字:  当  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"当",0x00,0x80,0x10,0x90,0x08,0x98,0x0C,0x90,0x08,0xA0,0x00,0x80,0x3F,0xFC,0x00,0x04,
0x00,0x04,0x1F,0xFC,0x00,0x04,0x00,0x04,0x00,0x04,0x3F,0xFC,0x00,0x04,0x00,0x00,

/*--  文字:  前  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"前",0x08,0x10,0x06,0x18,0x04,0x20,0xFF,0xFE,0x00,0x00,0x3E,0x08,0x22,0x48,0x3E,0x48,
0x22,0x48,0x22,0x48,0x3E,0x48,0x22,0x48,0x22,0x48,0x2A,0x08,0x24,0x28,0x00,0x10,


/*--  文字:  电  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"电",0x01,0x00,0x01,0x00,0x01,0x00,0x3F,0xF8,0x21,0x08,0x21,0x08,0x3F,0xF8,0x21,0x08,
0x21,0x08,0x21,0x08,0x3F,0xF8,0x21,0x08,0x01,0x02,0x01,0x02,0x00,0xFE,0x00,0x00,

/*--  文字:  压  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"压",0x00,0x00,0x3F,0xFE,0x20,0x00,0x20,0x80,0x20,0x80,0x20,0x88,0x2F,0xFC,0x20,0x80,
0x20,0xA0,0x20,0x90,0x20,0x98,0x40,0x90,0x40,0x80,0xBF,0xFE,0x00,0x00,0x00,0x00,

/*--  文字:  值  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"值",0x10,0x40,0x18,0x60,0x17,0xFC,0x10,0x40,0x20,0x80,0x33,0xF8,0x62,0x08,0xA3,0xF8,
0x22,0x08,0x23,0xF8,0x22,0x08,0x23,0xF8,0x22,0x08,0x22,0x08,0x2F,0xFE,0x20,0x00,

/*--  文字:  ：  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"：",0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x00,0x00,
};


#endif
