// #include <stdio.h>
// #include <stdlib.h>

/*	pin 12 green mod%3
	pin 13 orange mod%2
	pin 14 red mod%0
	pin 15 blue mod%1
 */

/* mod%0 red************************
		gpiomodregister = 0x100000000u;
		gpiodataregister = 0x4000u;
 */

/* mod%1 blue***********************
 	 	gpiomodregister = 0x40000000u;
		gpiodataregister = 0x8000u;
 */

/* mod%2 orange*********************
		gpiomodregister = 0x4000000u;
		gpiodataregister = 0x2000u;
 */

/* mod%3 green**********************
 	 	gpiomodregister = 0x1000000u;
		gpiodataregister = 0x1000u  ;
 */

/*  DoÄŸukan 68+111+196+159+117+107+97+110+10 = 965%4=1 pin 15 blue
	KÃ¶seoÄŸlu 75+195+182+115+101+111+196+159+108+117+32+10=1359%4=3
 */

#define RCCAHB1EN *((unsigned volatile int *) 0x40023830)
#define gpiomodregister *((unsigned volatile int *) 0x40020c00)
#define gpiodataregister *((unsigned volatile int *) 0x40020c14)
	void delay(){ 	//User Created Function for blink Delay
	int delay0 = 0x000FFFFF;
	while (delay0--){  //Until count down reaches zero will wait here
		}
	}

	void init_leds () {//CLOCK GATE
	 	RCCAHB1EN = 0x8;
	}
	void turn_name_on(){
		int x=965;
		if (x%4 == 0) {
		// printf("\n pin 14 red");
		gpiomodregister = 0x10000000u ;
		gpiodataregister = 0x4000u;
	}
	else if (x%4 == 1) {
		// printf("\n pin 15 blue\n");
		gpiomodregister = 0x40000000u;
		gpiodataregister = 0x8000u;
	}
	else if (x%4 == 2) {
		// printf("\n pin 13 orange");
		gpiomodregister = 0x4000000u;
		gpiodataregister = 0x2000u;
	}
	else if (x%4 == 3) {
		// printf("\n pin 12 green");
		gpiomodregister = 0x1000000u;
		gpiodataregister = 0x1000u  ;
	}

	}
	void turn_surname_on(){
		int y=1359;
		if (y%4 == 0) {
		// printf("\n pin 14 red");
		gpiomodregister = 0x10000000u;
		gpiodataregister = 0x4000u;
	}
	else if (y%4 == 1) {
		// printf("\n pin 15 blue\n");
		gpiomodregister = 0x40000000u;
		gpiodataregister = 0x8000u;
	}
	else if (y%4 == 2) {
		// printf("\n pin 13 orange");
		gpiomodregister = 0x4000000u;
		gpiodataregister = 0x2000u;
	}
	else if (y%4 == 3) {
		// printf("\n pin 12 green");
		gpiomodregister = 0x1000000u;
		gpiodataregister = 0x1000u;
	}

	}
	void turn_name_off(){
		gpiodataregister=0x0000u;
}
	void turn_surname_off(){
		gpiodataregister=0x0000u;
}

	int main(){
	init_leds();
	int i,j;

	for(i=0;i<7;i++){
		turn_name_on();
		delay();
		turn_name_off();
		delay();
	}
	for(j=0;j<8;j++){
		turn_surname_on();
		delay();
		turn_surname_off();
		delay();
	}
return 0;
}
