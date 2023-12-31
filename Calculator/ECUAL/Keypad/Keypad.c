

#include "Keypad.h"

int Keypad_Cols[] = {C0 ,C1,C2,C3};
int Keypad_Rows[] = {R0 ,R1,R2,R3};

void Keypad_init(){
	/*
	 * The columns are output && The rows are input
	 */
	Keypad_DDR |= ( (1<<C0) | (1<<C1) |(1<<C2) |(1<<C3) );
	Keypad_DDR &= ~((1<<R0) | (1<<R1) |(1<<R2) |(1<<R3) );
	/*
	 * Initialize the PORT to 1 so the Columns are connected VCC
	 * while the roes are input_pullup
	 */
	Keypad_PORT = 0xFF;
}
u8 Keypad_Get_Key(){

	int i, j;
	for(i =0 ; i< 4 ; i++){
		// Columns loop
		Keypad_PORT |= ((1<<Keypad_Cols[0]) | (1<<Keypad_Cols[1]) | (1<<Keypad_Cols[2]) | (1<<Keypad_Cols[3]));
		Keypad_PORT &= ~(1<<Keypad_Cols[i]);

		for(j =0 ; j< 4 ; j++){
			// Rows loop
			if(!GET_BIT(Keypad_PIN, Keypad_Rows[j]))
			{
				while(!GET_BIT(Keypad_PIN, Keypad_Rows[j])); // single press
					switch(i){
					case 0:
						if(j==0) 		return  '7';
						else if(j==1) 	return  '4';
						else if(j==2) 	return  '1';
						else if(j==3) 	return  'C';
						break;
					case 1:
						if(j==0) 		return  '8';
						else if(j==1) 	return  '5';
						else if(j==2) 	return  '2';
						else if(j==3) 	return  '0';
						break;
					case 2:
						if(j==0) 		return  '9';
						else if(j==1) 	return  '6';
						else if(j==2) 	return  '3';
						else if(j==3) 	return  '=';
						break;
					case 3:
						if(j==0) 		return  '/';
						else if(j==1) 	return  '*';
						else if(j==2) 	return  '-';
						else if(j==3) 	return  '+';
						break;

					}

				}

			}
		}
	return NO_KEY_PRESSED;
}
