#include "u-boot.h"

typedef int (*printf_t)(const char *fmt, ...);

static void * memcpy(void * dest,const void *src,unsigned int count)
{
	char *tmp = (char *) dest, *s = (char *) src;
	while (count--)
		*tmp++ = *s++;
	return dest;

}

int main(void){
	struct jt_funcs ** jt = 0;
	jt = (struct jt_funcs **)(&(gd->jt));

	printf_t  printf;
	printf = (*jt)->printf;

	printf("SUDEBUG : %s,%s,line = %d\n",__FILE__,__func__,__LINE__);
	printf("SUDEBUG : %s,%s,line = %d,reloc_off:0x%x\n",__FILE__,__func__,__LINE__,gd->reloc_off);
}
