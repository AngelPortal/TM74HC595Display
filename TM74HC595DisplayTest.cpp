#include <Arduino.h>
#include "TM74HC595Display.h"

int SCLK = 7;
int RCLK = 6;
int DIO = 5;
TM74HC595Display disp(SCLK, RCLK, DIO);

void setup() {

}

void loop() {
	 // int i = 54;
	 // disp.send(disp.LED_0F[i], 0b0001);      //send digital "0." to 1st indicator
	 // disp.send(disp.LED_0F[i + 1], 0b0010);  //send digital "1." to 1st indicator
	//  disp.send(disp.LED_0F[i + 2], 0b0100);  //send digital "2." to 1st indicator
	//  disp.send(disp.LED_0F[i + 3], 0b1000);  //send digital "3." to 1st indicator

	   disp.send(disp.LED_0F[0], 0b0001);    //send digital "0" to 1st indicator
	   delay(2000);
	   disp.send(disp.LED_0F[3], 0b0110);    //send digital "3" to 2nd and 3rd indicator
	   delay(2000);
	   disp.send(disp.LED_0F[10], 0b1111);    //send simbol "A" to all indicators
	   delay(2000);

	   for(int i = 0; i<=99; i++){
	   disp.digit2(i, 0b0001, 50);               //send counter 0-99 with delay 50 cicles int 1st and 2nd view ports
	   }

	   for(int i = 0; i<=99; i++){
	   disp.digit2(i, 0b0100, 50);               //send counter 0-99 with delay 50 cicles int 3st and 4rd view ports
	   }

	   for(int i = 0; i<=100; i++){
	   disp.digit4showZero(i, 50);               //send counter 0-100 with delay 50 cicles with zero
	   }

	   for(int i = 0; i<=9999; i++){
	   disp.digit4(i, 50);               //send counter 0-9999 with delay 50 cicles and hide zero
	   }
}
