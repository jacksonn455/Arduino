#include <Keypad.h>

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



void setup(){
  Serial.begin(9600);
}

void loop(){
  char customKey = customKeypad.getKey();
    if (customKey){
    Serial.println(customKey);
  }
  }
