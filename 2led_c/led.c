#define gpmcon *((volatile unsigned long *)0x7F008820)
#define gpmdat *((volatile unsigned long *)0x7F008824)

void delay()
{
	volatile int i = 0x100000;
	while (i--);
}
const unsigned char mask[5] = {0x0,0xe,0xd,0xb,0x7};
unsigned int led_change_times = 0;

int led_change(int led_number)
{
	if ((led_change_times%2) == 0)
		gpmdat = gpmdat & mask[led_number];
	else
		gpmdat = gpmdat | ~mask[led_number];

	delay();
	led_change_times++;

	return 0;
}

int led_c_set_led_flash(int led_number,int count){
	while(count --){
		gpmdat = gpmdat & mask[led_number];
		delay();
		gpmdat = gpmdat | ~mask[led_number];
		delay();
	}
	return 0;

}

int led_c_set_led_on(int led_number){
	gpmdat = gpmdat & mask[led_number];
	delay();
	return 0;

}

void led_c_init(void)
{
	gpmcon = 0x1111;
	gpmdat = 0xf;
}

void led_change_test(void)
{
	int n = 5;
	led_change_times=0;
	while(n--)
		led_change(1);
	n = 5;
	led_change_times=0;
	while(n--)
		led_change(2);
	n = 5;
	led_change_times=0;
	while(n--)
		led_change(3);
	n = 5;
	led_change_times=0;
	while(n--)
		led_change(4);

}

void led_sample(void){
	led_c_init();
	led_c_set_led_on(1);
	led_c_set_led_on(2);
	led_c_set_led_on(3);
	led_c_set_led_on(4);
	led_c_set_led_flash(1,5);
	led_c_set_led_flash(2,5);
	led_c_set_led_flash(3,5);
	led_c_set_led_flash(4,5);
	led_change_test();
	while(1);

}
