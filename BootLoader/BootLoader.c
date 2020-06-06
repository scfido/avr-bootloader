/*
* BootLoader.c
*
* Created: 2020/6/6 14:08:28
* Author : FCCA
*/

/*
# Processor frequency.
#     This will define a symbol, F_CPU, in all source code files equal to the
#     processor frequency. You can then use this symbol in your source code to
#     calculate timings. Do NOT tack on a 'UL' at the end, this will be done
#     automatically to create a 32-bit value in your source code.
*/
#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>



//#define BootAdd 0x3800

void (*app_start)(void) = 0x0000;

__attribute__((section(".app")))
int app(void)
{
	DDRB=0xff;
	
	while(1)
	{
		PORTB =0;
		_delay_ms(100);
		PORTB=0xff;
		_delay_ms(100);
	}
	
	return 0;
}

//boot loader
int main(void)
{
	DDRC=0xff;
	int delay = 10;
	while(delay--)
	{
		PORTC =0;
		_delay_ms(500);
		PORTC=0xff;
		_delay_ms(500);
	}
	
	//回到程序起点
	app_start();
}




