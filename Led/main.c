/*
 * Led.c
 *
 * Created: 2020/6/6 9:04:03
 * Author : FCCA
 */ 

/*
# Processor frequency.
#     This will define a symbol, F_CPU, in all source code files equal to the
#     processor frequency. You can then use this symbol in your source code to
#     calculate timings. Do NOT tack on a 'UL' at the end, this will be done
#     automatically to create a 32-bit value in your source code.
*/
#define F_CPU 16000000

 #include <avr/io.h>
 #include <util/delay.h>

   int main(void)
   {
		DDRC=0xff;
	  
		while(1)
		{
			PORTC =0;
			_delay_ms(500);
			
			PORTC=0xff;
			_delay_ms(500);
		}
   }

