#include <Arduino.h>
#include "TM74HC595Display.h"

int SCLK = 7;
int RCLK = 6;
int DIO = 5;
TM74HC595Display disp(SCLK, RCLK, DIO);

void setup() {

}

void loop() {
	  int i = 54;
	  disp.send(disp.LED_0F[i], 0b0001);      //send digital "0." to 1st indicator
	  disp.send(disp.LED_0F[i + 1], 0b0010);  //send digital "1." to 1st indicator
	  disp.send(disp.LED_0F[i + 2], 0b0100);  //send digital "2." to 1st indicator
	  disp.send(disp.LED_0F[i + 3], 0b1000);  //send digital "3." to 1st indicator
}
