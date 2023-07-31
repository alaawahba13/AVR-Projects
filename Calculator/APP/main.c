#include "main.h"






int main ()
{
	/* Initializations */
	LCD_init();
	u8 man[] = {0x04, 0x0A, 0x04, 0x1F, 0x14, 0x0E, 0x11, 0x00};

	/* Variables Declarations */


	LCD_createCustomCharacter(man, 0);
	LCD_sendCMD(0x80);
	//LCD_8_bit_GoToPos(1,5);
	//LCD_8_bit_sendChar('B');
	//LCD_8_bit_sendString(" Hello 3rd Year");
	while(1)
	{
		//LCD_8_bit_sendChar('C');

		//LCD_8_bit_sendChar(0);
		LCD_sendChar(0);
		//LCD_8_bit_sendCMD(0x88);
		//_delay_ms(1000);
		//LCD_8_bit_sendChar('E');
		//LCD_8_bit_sendString("Max");
		//PORTB = 'a';
		_delay_ms(100);
	}

	return 0;
}
