#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#define lcdAddr 0x20 // set the address of the I2C device the LCD is connected to
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880

#define melodyPin 2

#include "Wire.h" //Biblioteca para uso do RTC DS1307

#define DS1307_ADDRESS 0x68

byte zero = 0x00;
int seg = 30, min = 18, hor = 14;

int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};


//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};
int fp = 4;                //set frames per second (fps)
int s;
const byte linhas = 4;
const byte colunas = 3;
int buttonState = 0;
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
const int beep = 2;
char  senha[12];
char  correta[] = "123456";
byte currentLength = 0;

Keypad customKeypad = Keypad(makeKeymap(teclado), linhasPins, colunasPins, linhas, colunas);

byte mario11[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00001,
  B00001,
  B00001,
  B00000,

};
byte mario12[8] = {
  B00001,
  B00001,
  B00001,
  B00001,
  B00000,
  B00000,
  B00000,
  B00000
};
byte mario13[8] = {
  B00000,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,

};
byte mario14[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11110
};

byte mario15[8] = {
  B00000,
  B00000,
  B11000,
  B00000,
  B11000,
  B11100,
  B11000,
  B10000,

};

byte mario16[8] = {
  B00000,
  B10000,
  B10000,
  B10000,
  B00000,
  B00000,
  B10000,
  B00000
};

byte mario21[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte mario22[8] = {
  B00111,
  B00111,
  B00111,
  B00000,
  B00001,
  B00011,
  B00011,
  B00001
};

byte mario23[8] = {
  B00000,
  B01111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B01111,

};

byte mario24[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11001,
  B00000,
  B10000
};
byte mario25[8] = {
  B00000,
  B00000,
  B11100,
  B10000,
  B11100,
  B11110,
  B11100,
  B11000,

};

byte mario26[8] = {
  B11111,
  B11111,
  B10110,
  B11110,
  B11110,
  B11110,
  B00000,
  B00000,
};

byte mario31[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,

};


byte mario32[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00011,
  B00011,
  B00111,
  B00000
};
byte heart[8] = { 0b00000, // vetor de bytes correspondentes
                  0b01010,  // ao desenho do coração
                  0b11111,
                  0b11111,
                  0b01110,
                  0b00100,
                  0b00000,
                  0b00000
                };

byte mario33[8] = {
  B00000,
  B00000,
  B00111,
  B01111,
  B01111,
  B11111,
  B11111,
  B11111,

};

byte mario34[8] = {
  B01111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B00111,
  B00111
};

byte mario35[8] = {
  B00000,
  B00000,
  B10000,
  B11110,
  B11000,
  B11110,
  B11111,
  B11110,

};

byte mario36[8] = {
  B11100,
  B11110,
  B11100,
  B11000,
  B11000,
  B10000,
  B00000,
  B10000,
};

byte mario41[8] = {
  B00000,
  B00011,
  B00111,
  B00111,
  B01111,
  B01111,
  B01111,
  B00011,

};


byte mario42[8] = {
  B01111,
  B01111,
  B01111,
  B01111,
  B00111,
  B00011,
  B00011,
  B00011
};

byte mario43[8] = {
  B00000,
  B11000,
  B11111,
  B11100,
  B11111,
  B11111,
  B11111,
  B11110,
};

byte mario44[8] = {
  B11100,
  B11110,
  B11110,
  B11110,
  B11100,
  B11100,
  B11110,
  B10000
};


byte mario51[8] = {
  B00000,
  B00001,
  B00011,
  B00011,
  B00111,
  B00111,
  B00111,
  B00001,
};

byte mario52[8] = {
  B11111,
  B11111,
  B11011,
  B00111,
  B01111,
  B11111,
  B11100,
  B01110,
};

byte mario53[8] = {
  B00000,
  B11100,
  B11111,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111,
};

byte mario54[8] = {
  B11111,
  B11111,
  B11110,
  B11111,
  B11111,
  B01111,
  B00000,
  B00000,
};



byte mario55[8] = {
  B00000,
  B00000,
  B10000,
  B00000,
  B00000,
  B10000,
  B00000,
  B00000,
};


byte mario56[8] = {
  B11000,
  B11000,
  B10000,
  B10000,
  B10000,
  B10000,
  B00000,
  B00000,
};


byte mario61[8] = {
  B00000,
  B00000,
  B00000,
  B00001,
  B00001,
  B00011,
  B00011,
  B00011,
};

byte mario62[8] = {
  B00001,
  B00011,
  B00111,
  B01111,
  B01111,
  B11111,
  B11000,
  B00000,
};



byte mario63[8] = {
  B00000,
  B00000,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

byte mario64[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11110,
  B11100,
  B11110,
};

byte mario65[8] = {
  B00000,
  B00000,
  B00000,
  B10000,
  B00000,
  B10000,
  B11000,
  B10000,
};


byte mario66[8] = {
  B00000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte clean[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

void  setup() {
  Wire.begin();
  pinMode(beep, OUTPUT);
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.setCursor(4, 0);
  lcd.print("Bem Vindo!!!");
  s = 700 / fp;
  lcd.setCursor(1, 3);
  lcd.print("Horario:");
  horario();
  delay(3000);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Digite sua Senha:");
  delay(3000);
  lcd.clear();
}
void  loop()  {
    char  tecla = customKeypad.getKey();
  if (tecla) {
    lcd.cursor();
    lcd.print("*");
    digitalWrite(beep, HIGH);
    delay(10);
    digitalWrite(beep, LOW);
    if (tecla  !=  NO_KEY) {
      if (tecla  !=  '#' && tecla != '*')  {
        senha[pos]  = tecla;
        pos++;
      }
      if (tecla  ==  '#' || tecla == '*')  {
        lcd.clear();
        if (!strcmp(correta, senha))  {
          lcd.noCursor();
          lcd.print("Senha Correta");
          delay(2000);
          lcd.clear();
          lcd.cursor();
          int num1 = random(2, 11);
          int num2 = random(2, 11);
          int resultado = num1 * num2;
          lcd.print(String(num1) + " x " + String(num2) + " = ");
          // Esperando a resposta do usuário e digitar o resultado
          int resposta = valorLido().toInt(); //recebe um valor no char e converte para o tipo String
          lcd.setCursor(0, 1);
          // Se o valor digitado for igual ao resultado da mutiplicação
          if (resultado == resposta) {
            lcd.noCursor();
            lcd.print("Voce acertou!");
            sing(1);
            mario();


          }
          else {
            // se não for igual ao resultado da multiplicação
            lcd.noCursor();
            lcd.print("Errou... R: " + String(resultado));
            sing(2);
            mario();
          }
          resposta = valorLido().toInt(); //Apenas esperando pressionar qualquer tecla para continuar
          delay(1000);
          lcd.clear();
        } else {
          lcd.clear();
          lcd.noCursor();
          lcd.print("Senha Incorreta");
          delay(2000);
          lcd.clear();
          lcd.print("Digite Sua Senha: ");
          delay(2000);
          lcd.clear();

        }
        {
          delay(500);
          for (int i = 0; i < strlen(senha); i++)  senha[i]  = ' ';
          pos = 0;
          lcd.print("Digite sua senha:");
          delay(2000);
          lcd.clear();
        }
      }
    }
  }
}
String valorLido() {
  String valorDigitado = "";
  char teclaPressionada = customKeypad.getKey();

  while (teclaPressionada != '#' && teclaPressionada != '*') {
    teclaPressionada = customKeypad.getKey();

    if ((teclaPressionada != NO_KEY && teclaPressionada != '#' && teclaPressionada != '*')) {
      valorDigitado.concat(teclaPressionada);// concatena os valores que recebe com os já recebidos anteriormente
      lcd.print(teclaPressionada);
      digitalWrite(beep, HIGH);
      lcd.cursor();
      delay(10);
      digitalWrite(beep, LOW);
    }
  }
  return (valorDigitado); // retorna o valor digitado para a função anterior
}

int song = 0;
void sing(int s) {
  // iterate over the notes of the melody:
  song = s;
  if (song == 2) {
    Serial.println(" 'Underworld Theme'");
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / underworld_tempo[thisNote];

      buzz(melodyPin, underworld_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);

    }

  } else {

    Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];

      buzz(melodyPin, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);

    }
  }
}

void buzz(int targetPin, long frequency, long length) {
  digitalWrite(2, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(2, LOW);
}

void mario() {
  lcd.setCursor(11, 0);
  lcd.write(1);
  lcd.setCursor(11, 1);
  lcd.write(2);
  lcd.setCursor(12, 0);
  lcd.write(3);
  lcd.setCursor(12, 1);
  lcd.write(4);
  lcd.setCursor(14, 0);
  lcd.write(1);
  lcd.setCursor(14, 1);
  lcd.write(2);
  lcd.setCursor(15, 0);
  lcd.write(3);
  lcd.setCursor(15, 1);
  lcd.write(4);
  delay(2000);
  lcd.clear();


  for (int aq = 0; aq < 16; aq++) //for loop to repeat marios animation until the end of the display
  {
    lcd.noCursor();
    int bq = aq + 1;
    int cq = aq + 2;
    int dq = aq + 3;
    int eq = aq + 4;

    lcd.createChar(1, mario11);
    lcd.createChar(2, mario12);
    lcd.createChar(3, mario13);
    lcd.createChar(4, mario14);
    lcd.createChar(5, mario15);
    lcd.createChar(6, mario16);
    lcd.createChar(7, clean);
    lcd.createChar(8, heart);

    lcd.setCursor(aq, 0);
    lcd.write(1);
    lcd.setCursor(aq, 1);
    lcd.write(2);
    lcd.setCursor(bq, 0);
    lcd.write(3);
    lcd.setCursor(bq, 1);
    lcd.write(4);
    lcd.setCursor(cq, 0);
    lcd.write(5);
    lcd.setCursor(cq, 1);
    lcd.write(6);
    lcd.write(8);
    delay(s);

    lcd.createChar(1, mario21);
    lcd.createChar(2, mario22);
    lcd.createChar(3, mario23);
    lcd.createChar(4, mario24);
    lcd.createChar(5, mario25);
    lcd.createChar(6, mario26);
    lcd.createChar(8, heart);

    lcd.setCursor(aq, 0);
    lcd.write(1);
    lcd.setCursor(aq, 1);
    lcd.write(2);
    lcd.setCursor(bq, 0);
    lcd.write(3);
    lcd.setCursor(bq, 1);
    lcd.write(4);
    lcd.setCursor(cq, 0);
    lcd.write(5);
    lcd.setCursor(cq, 1);
    lcd.write(6);
    lcd.write(8);

    delay(s);

    lcd.createChar(1, mario31);
    lcd.createChar(2, mario32);
    lcd.createChar(3, mario33);
    lcd.createChar(4, mario34);
    lcd.createChar(5, mario35);
    lcd.createChar(6, mario36);

    lcd.setCursor(aq, 0);
    lcd.write(1);
    lcd.setCursor(aq, 1);
    lcd.write(2);
    lcd.setCursor(bq, 0);
    lcd.write(3);
    lcd.setCursor(bq, 1);
    lcd.write(4);
    lcd.setCursor(cq, 0);
    lcd.write(5);
    lcd.setCursor(cq, 1);
    lcd.write(6);

    delay(s);

    lcd.createChar(1, mario41);
    lcd.createChar(2, mario42);
    lcd.createChar(3, mario43);
    lcd.createChar(4, mario44);
    lcd.createChar(7, clean);
    lcd.setCursor(aq, 0);
    lcd.write(7);
    lcd.setCursor(aq, 1);
    lcd.write(7);
    lcd.setCursor(bq, 0);
    lcd.write(1);
    lcd.setCursor(bq, 1);
    lcd.write(2);
    lcd.setCursor(cq, 0);
    lcd.write(3);
    lcd.setCursor(cq, 1);
    lcd.write(4);


    delay(s);


    lcd.createChar(1, mario51);
    lcd.createChar(2, mario52);
    lcd.createChar(3, mario53);
    lcd.createChar(4, mario54);
    lcd.createChar(5, mario55);
    lcd.createChar(6, mario56);
    lcd.createChar(7, clean);
    lcd.setCursor(a, 0);
    lcd.write(7);
    lcd.setCursor(aq, 1);
    lcd.write(7);
    lcd.setCursor(bq, 0);
    lcd.write(1);
    lcd.setCursor(bq, 1);
    lcd.write(2);
    lcd.setCursor(cq, 0);
    lcd.write(3);
    lcd.setCursor(cq, 1);
    lcd.write(4);
    lcd.setCursor(dq, 0);
    lcd.write(5);
    lcd.setCursor(dq, 1);
    lcd.write(6);

    delay(s);
    lcd.createChar(1, mario61);
    lcd.createChar(2, mario62);
    lcd.createChar(3, mario63);
    lcd.createChar(4, mario64);
    lcd.createChar(5, mario65);
    lcd.createChar(6, mario66);
    lcd.setCursor(bq, 0);
    lcd.write(1);
    lcd.setCursor(bq, 1);
    lcd.write(2);
    lcd.setCursor(cq, 0);
    lcd.write(3);
    lcd.setCursor(cq, 1);
    lcd.write(4);
    lcd.setCursor(dq, 0);
    lcd.write(5);
    lcd.setCursor(dq, 1);
    lcd.write(6);

    delay(s);
  }
}

void horario() {
  lcd.setCursor(11, 3);
  static unsigned long  ult_tempo = 0;
  int tempo = millis();
  if (tempo  - ult_tempo >=  1000) {
    ult_tempo = tempo;

    seg++;
  }
  if (seg >= 60) {
    seg = 0;
    min++;
  }
  if (min >= 60) {
    min = 0;
    hor++;
  }
  if (hor >= 24) {
    hor = 0;
    min = 0;
  }
  lcd.print(hor);
  lcd.print(":");
  lcd.print(min);
  lcd.print(":");
  lcd.print(seg);
  lcd.setCursor(0, 0);
}
