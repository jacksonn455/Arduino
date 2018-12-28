/*
  LiquidCrystal Library - Blink

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and makes the
 cursor block blink.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
   * ends to +5V and ground
   * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalBlink

*/



// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
#include <LiquidCrystal.h>
#include <Keypad.h>
#define Luz_Fundo  7
const int rs = A0, en = A1, d4 = A5, d5 = A4, d6 = A3, d7 = A2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte linhas = 4; 
const byte colunas = 3; 

char teclado[linhas][colunas] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte linhasPins[linhas] = {9, 8, 7, 6}; 
byte colunasPins[colunas] = {5, 4, 3}; 

Keypad customKeypad = Keypad(makeKeymap(teclado), linhasPins, colunasPins, linhas, colunas); 



byte heart[8] = { 0b00000, // vetor de bytes correspondentes
0b01010,  // ao desenho do coração
0b11111,
0b11111,
0b01110,
0b00100,
0b00000,
0b00000
};

void setup()
{
 lcd.begin(20, 4);
pinMode(Luz_Fundo,OUTPUT);
digitalWrite(Luz_Fundo,HIGH);
lcd.setCursor(0,0);
lcd.print(" teste! ");

lcd.createChar(1, heart); // envia nosso character p/ o display
}

void loop()
{
lcd.setCursor(3,1);
lcd.write(1); // desenha o coração
delay(500);
lcd.setCursor(3,1);
lcd.print(" "); // Após 0.5s apaga o coração, assim ele
delay(500); // ficará piscando
}
