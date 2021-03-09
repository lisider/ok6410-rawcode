#define INDEX_PTR        (*(unsigned short *) 0x18000000)    //因为cmd连接在srom1的ADDR2,所以当地址的第[2]为0:选中index,为1:选中data
#define DATA_PTR        (*(unsigned short *) 0x18000004)    //因为0x18000000这个地址是SRom1的映射地址,但没有使用srom所以...

void delay(int i)
{
	while (i--);
}

//从网卡读取指定寄存器的数据
unsigned short dm_read(unsigned char reg)
{
    delay(400);  //适当延时
    //写命令,相当于CMD为高电平
    INDEX_PTR = ((unsigned short)reg)<<8;    //写入需要访问的寄存器编号,注意字节序
    delay(400);
    //读数据
    return (unsigned short)DATA_PTR;
}
//向网卡指定的寄存器中写入数据
void dm_write(char reg, unsigned char data)
{
    delay(400);
    //写命令,相当于CMD为高电平
    INDEX_PTR = ((unsigned short)reg)<<8;    //写入需要访问的寄存器编号,注意字节序,网络的高八位代表了实际数据的低八位

    delay(400);
    //写数据
    DATA_PTR = ((unsigned short)data)<<8;    //这儿要注意字节序的问题,dm9000的总线是16位的,所以高字节在低八位,低字节在高八位
}
