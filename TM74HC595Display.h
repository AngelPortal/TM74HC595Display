/*
 * TM74HC595Display.h
 *
 *  Created on: 12 de out de 2017
 *      Author: AngelPortal
 */

#ifndef TM74HC595DISPLAY_H_
#define TM74HC595DISPLAY_H_

class TM74HC595Display
{
  public:
   unsigned char LED_0F[58] =
       {0xC0,0xF9,0xA4,0xB0,0x99,0x92,
        0x82,0xF8,0x00,0x90,0x88,0x83,
        0xC6,0xA1,0x86,0x8E,0xC2,0x89,
        0xF9,0xF1,0xC7,0xAB,0xC0,0x8C,
        0x98,0x92,0xC1,0x91,0xBF,0x40,
        0x79,0x24,0x30,0x19,0x12,0x02,
        0x78,0x00,0x10,0x08,0x03,0x46,
        0x21,0x06,0x0E,0x42,0x09,0x79,
        0x61,0x47,0x2B,0x40,0x0C,0x18,
        0x12,0x41,0x11,0x7f};

    TM74HC595Display(int SCLK, int RCLK, int DIO);
    void send(unsigned char X);
	  void send(unsigned char X, unsigned char port);
	  void digit4(int n, int replay, bool showZero);
	  void digit4(int n, int replay);
	  void digit4(int n);
	  void digit4showZero(int n, int replay);
	  void digit4showZero(int n);
	  void digit2(int n, int port);
	  void digit2(int n, int port, int replay);

  private:
    int _SCLK;
	int _RCLK;
	int _DIO;
};

#endif /* TM74HC595DISPLAY_H_ */
