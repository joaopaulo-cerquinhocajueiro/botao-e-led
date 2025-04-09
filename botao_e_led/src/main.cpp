/**
 * @file main.cpp
 * @brief Controle de LED via botão com lógica configurável por DIP switch.
 *
 * Projeto: botao_e_led
 * Versão: 0.1 (pré-alfa)
 * Plataforma: Arduino Uno (ATmega328P)
 * Framework: PlatformIO + Arduino
 * Autor: João Paulo Cerquinho Cajueiro
 * Data: 09/04/2025
 * Licença: MIT
 * 
 * Descrição:
 * Este projeto acende um LED conectado ao pino digital 3 quando um botão, 
 * conectado ao pino digital 4 (configurado com PULLUP interno), é pressionado.
 * A lógica que define quando o LED deve acender é determinada por 4 chaves 
 * DIP switch conectadas aos pinos 5, 6, 7 e 8. Essa lógica é definida 
 * no código pelas funções loop0 a loop 15, e a brincadeira é tentar identificar
 * o funcionamento do sistema sem saber que configuração está sendo usada.
 * 
 * Conexões:
 * - LED: pino 3 (saída)
 * - Botão: pino 4 (entrada com PULLUP; botão ligado ao GND)
 * - DIP Switch:
 *     - Chave 1: pino 5
 *     - Chave 2: pino 6
 *     - Chave 3: pino 7
 *     - Chave 4: pino 8
 * 
 * Licença:
 * MIT License
 * Copyright (c) 2025 João Paulo Cerquinho Cajueiro
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

 #include <arduino.h>

#define PINO_BOTAO 4
#define PINO_LED 3

#define PINO_CFG0 5
#define PINO_CFG1 6
#define PINO_CFG2 7
#define PINO_CFG3 8

int workingMode = 0;
const char* modeText[] ={"Chave sem retenção",
                         "Set-Reset",
                         "Integrador 'leaky'",
                         "Somador 'leaky'",
                         "Não definido",
                         "Não definido",
                         "Não definido",
                         "Não definido",
                         "Não definido",
                         "Não definido",
                         "Não definido",
                         "Não definido",
                         "Não definido",
                         "Não definido",
                         "Não definido",
                         "Não definido"
};

int valBotao;
int valBotaoAnt = 1;

void loop0(){ //"Chave sem retenção"
  digitalWrite(PINO_LED,digitalRead(PINO_BOTAO));
  delay(20);
}

void loop1(){ // "Set-Reset"
  static int statusLed = 0;
  valBotao = digitalRead(PINO_BOTAO);
  if((valBotao==0)&&(valBotaoAnt==1)){
      statusLed !=statusLed;
      digitalWrite(PINO_LED,statusLed);
  }
  valBotaoAnt = valBotao;
}

void loop2(){ // "Integrador 'leaky'"
  static int valLed = 0;
  valLed = digitalRead(PINO_BOTAO)?valLed-1:valLed+2;
  valLed = constrain(valLed,0,255);
  analogWrite(PINO_LED,valLed);
  delay(1);
}

void loop3(){ // Somador 'leaky'
  static int valLed = 0;
  valBotao = digitalRead(PINO_BOTAO);
  if((valBotao==0)&&(valBotaoAnt==1)){
      valLed += 20;
  }
  valLed -=1;
  valLed = constrain(valLed,0,400);
  valBotaoAnt = valBotao;
  analogWrite(PINO_LED,constrain(valLed,0,255));
}

void loop4(){ // TON 3s TOFF 5s
  static uint32_t ton,toff;
  valBotao = digitalRead(PINO_BOTAO);
  if(valBotao==0){ // se apertado
    if(valBotaoAnt==1){ // se acabou de apertar
      ton = millis()+3000;
    } else if (millis()>ton){
      digitalWrite(PINO_LED,HIGH);
    }
  } else { // se não apertado (valBotao == 1)
    if(valBotaoAnt==0){ // se acabou de soltar
      toff = millis()+5000;
    } else if (millis()>toff){
      digitalWrite(PINO_LED,LOW);
    }
  }
    
  valBotaoAnt = valBotao;
}

void loop5(){

}

void loop6(){

}

void loop7(){

}

void loop8(){

}

void loop9(){

}

void loop10(){

}

void loop11(){

}

void loop12(){

}

void loop13(){

}

void loop14(){

}

void loop15(){

}

void setup(){
    Serial.begin(115200);
    pinMode(PINO_BOTAO,INPUT_PULLUP);
    pinMode(PINO_LED,OUTPUT);
    digitalWrite(PINO_LED,LOW);
    pinMode(PINO_CFG0,INPUT);
    pinMode(PINO_CFG1,INPUT);
    pinMode(PINO_CFG2,INPUT);
    pinMode(PINO_CFG3,INPUT);
    workingMode = (digitalRead(PINO_CFG3)<<3 |
            digitalRead(PINO_CFG2)<<2 |
            digitalRead(PINO_CFG1)<<1 |
            digitalRead(PINO_CFG0));
    Serial.print("O modo de trabalho é ");
    Serial.println(modeText[constrain(workingMode,0,15)]);
}

void loop(){
    switch (workingMode)
    {
    case 0:
        loop0();
        break;
    case 1:
        loop1();
        break;
    default:
        break;
    }
}

// AMDG