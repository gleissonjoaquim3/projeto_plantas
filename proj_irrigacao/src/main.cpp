/* Programa de irrigação simples que faz a leitura da umidade do solo
e faz a irrigação das plantas levando em consideração :
A temperatura, umidade do solo e a hora adequada. */
#include <Arduino.h>

#define sensor_umidade 33 // Definição de pino sensor
#define bomba 4 // Definição de pino bomba

int valor_analogico = 0; // Variável inicia com valor zerado do sensor
//int estado_rele1 = 0; // Variável controla o estado do rele
//int estado_rele2 = 0; // Variável controla o estado do rele
bool solo_seco;
bool solo_umido;

void aciona_bomba(){

  digitalWrite(bomba, !HIGH);
  delay(500);
  digitalWrite(bomba,!LOW);
  delay(10000);

}


void setup() {// Carregado uma vez pelo esp32
  Serial.begin(9600);
  pinMode(bomba, OUTPUT);   // Inicia o monitor serial
  pinMode(sensor_umidade, INPUT);
}

void loop() {
valor_analogico = analogRead(sensor_umidade); // Armazena na variavel o valor do sensor.
Serial.println(valor_analogico); // Mostra no monitor o valor obtido pelo sensor.
delay(80); // Delay (opcional) de tempo.
if (valor_analogico >= 3300) {
  solo_seco = 1;

  while (solo_seco){
    aciona_bomba();
  }
}

if (valor_analogico >= 2200 && valor_analogico <= 3299) {
   solo_seco = 1;

   while (solo_seco){
     aciona_bomba();
   }
  }
if (valor_analogico >= 1500 && valor_analogico <= 2199) {
   solo_seco = 0;
   solo_umido = 1;

   while (solo_umido){
   aciona_bomba();
 }
if (valor_analogico <= 1499) {
  digitalWrite(bomba, !LOW);
}
}
}
