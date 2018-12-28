#include <Keypad.h>
#include <LiquidCrystal.h>

const byte linhas = 4; 
const byte colunas = 3; 
const int rs = A0, en = A1, d4 = A5, d5 = A4, d6 = A3, d7 = A2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char teclado[linhas][colunas] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte linhasPins[linhas] = {9, 8, 7, 6}; 
byte colunasPins[colunas] = {5, 4, 3}; 
int  pos = 0;
int led = 13;
char  senha[12];
char  correta[] = "123456";


Keypad customKeypad = Keypad(makeKeymap(teclado), linhasPins, colunasPins, linhas, colunas); 


void setup() {
 pinMode(led,OUTPUT);
 Serial.begin(9600);
 lcd.begin(20,4);

}

void loop() {
  char customKey = customKeypad.getKey();
    if (customKey){
    lcd.print(customKey);
    Serial.print(customKey);
      
  }
}
