/*
 * TM74HC595Display.cpp
 *
 *  Created on: 12 de out de 2017
 *      Author: AngelPortal
 */

/*
  TM74HC595Display.cpp - Library
*/

#include "TM74HC595Display.h"
#include <Arduino.h>

unsigned char _LED_0F[57];

TM74HC595Display::TM74HC595Display(int SCLK, int RCLK, int DIO)
{
  pinMode(SCLK, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(DIO, OUTPUT);

  _SCLK = SCLK;
  _RCLK = RCLK;
  _DIO = DIO;

  _LED_0F[0] = 0xC0; //0
  _LED_0F[1] = 0xF9; //1
  _LED_0F[2] = 0xA4; //2
  _LED_0F[3] = 0xB0; //3
  _LED_0F[4] = 0x99; //4
  _LED_0F[5] = 0x92; //5
  _LED_0F[6] = 0x82; //6
  _LED_0F[7] = 0xF8; //7
  _LED_0F[8] = 0x80; //8
  _LED_0F[9] = 0x90; //9
  _LED_0F[10] = 0x88; //A
  _LED_0F[11] = 0x83; //b
  _LED_0F[12] = 0xC6; //C
  _LED_0F[13] = 0xA1; //d
  _LED_0F[14] = 0x86; //E
  _LED_0F[15] = 0x8E; //F
  _LED_0F[16] = 0xC2; //G
  _LED_0F[17] = 0x89; //H
  _LED_0F[18] = 0xF9; //I
  _LED_0F[19] = 0xF1; //J
  _LED_0F[20] = 0xC3; //L
  _LED_0F[21] = 0xA9; //n
  _LED_0F[22] = 0xC0; //O
  _LED_0F[23] = 0x8C; //P
  _LED_0F[24] = 0x98; //q
  _LED_0F[25] = 0x92; //S
  _LED_0F[26] = 0xC1; //U
  _LED_0F[27] = 0x91; //Y
  _LED_0F[28] = 0xFE; //-
  _LED_0F[30] = 0x40; //0.
  _LED_0F[31] = 0x79; //1.
  _LED_0F[32] = 0x24; //2.
  _LED_0F[33] = 0x30; //3.
  _LED_0F[34] = 0x99; //4.
  _LED_0F[35] = 0x92; //5.
  _LED_0F[36] = 0x82; //6.
  _LED_0F[37] = 0xF8; //7.
  _LED_0F[38] = 0x80; //8.
  _LED_0F[39] = 0x90; //9.
  _LED_0F[40] = 0x88; //A.
  _LED_0F[41] = 0x83; //b.
  _LED_0F[42] = 0xC6; //C.
  _LED_0F[43] = 0xA1; //d.
  _LED_0F[44] = 0x86; //E.
  _LED_0F[45] = 0x8E; //F.
  _LED_0F[46] = 0xC2; //G.
  _LED_0F[47] = 0x89; //H.
  _LED_0F[48] = 0xF9; //I.
  _LED_0F[49] = 0xF1; //J.
  _LED_0F[50] = 0xC3; //L.
  _LED_0F[51] = 0xA9; //n.
  _LED_0F[52] = 0xC0; //O.
  _LED_0F[53] = 0x8C; //P.
  _LED_0F[54] = 0x98; //q.
  _LED_0F[55] = 0x92; //S.
  _LED_0F[56] = 0xC1; //U
  _LED_0F[57] = 0x91; //Y.
}


void TM74HC595Display::send(unsigned char X)
{

  for (int i = 8; i >= 1; i--)
  {
    if (X & 0x80)
    {
      digitalWrite(_DIO, HIGH);
    }
    else
    {
      digitalWrite(_DIO, LOW);
    }
    X <<= 1;
    digitalWrite(_SCLK, LOW);
    digitalWrite(_SCLK, HIGH);
  }
}

void TM74HC595Display::send(unsigned char X, unsigned char port)
{
  send(X);
  send(port);
  digitalWrite(_RCLK, LOW);
  digitalWrite(_RCLK, HIGH);
}

void TM74HC595Display::digit4(int n, int replay, bool showZero)
{
  int n1, n2, n3, n4;
  n1 = (int)  n % 10;
  n2 = (int) ((n % 100)-n1)/10;
  n3 = (int) ((n % 1000) - n2 - n1) / 100;
  n4 = (int) ((n % 10000) - n3 - n2 - n1) / 1000;

 for(int i = 0; i<=replay; i++){
	send(_LED_0F[n1], 0b0001);
    if(showZero | n>9)send(_LED_0F[n2], 0b0010);
    if(showZero | n>99)send(_LED_0F[n3], 0b0100);
    if(showZero | n>999)send(_LED_0F[n4], 0b1000);
 }
}

void TM74HC595Display::digit4(int n, int replay)
{
  digit4(n,replay,false);
}

void TM74HC595Display::digit4(int n)
{
  digit4(n,0,false);
}

void TM74HC595Display::digit4showZero(int n, int replay)
{
	digit4(n, replay, true);
}

void TM74HC595Display::digit4showZero(int n)
{
	digit4(n, 0, true);
}


void TM74HC595Display::digit2(int n, int port, int replay)
{
  int n1, n2;
  n1 = (int)  n % 10;
  n2 = (int) ((n % 100)-n1)/10;

   for(int i = 0; i<=replay; i++){
   send(_LED_0F[n1], port);
   send(_LED_0F[n2], port<<1);
   }
}

void TM74HC595Display::digit2(int n, int port)
{
	digit2(n, port, 0);
}



