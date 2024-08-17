#ifndef WALL_E_H
#define WALL_E_H

#define LIMIAR 500
#define LIM_PRETO 600
#define LIM_BRANCO 400

#include <Arduino.h>

#define sensor_esq_pin A2   //esquerda
#define sensor_meio_pin A1  //meio
#define sensor_dir_pin A0   //direita

#define pinMotorD1 5
#define pinMotorD2 6
#define pinMotorE1 10
#define pinMotorE2 9

int velocidade = 150;

void iniciar_robo() {
   pinMode(sensor_dir_pin, INPUT);
   pinMode(sensor_esq_pin, INPUT);
   pinMode (sensor_meio_pin, INPUT);

  pinMode(pinMotorD1, OUTPUT);
  pinMode(pinMotorD2, OUTPUT);
  pinMode(pinMotorE1, OUTPUT);
  pinMode(pinMotorE2, OUTPUT);


  digitalWrite(pinMotorD1, LOW);
  digitalWrite(pinMotorD2, LOW);
  digitalWrite(pinMotorE1, LOW);
  digitalWrite(pinMotorE2, LOW);
}

void pega_leituras(int& leitura_sensor_esq, int& leitura_sensor_dir, int& leitura_sensor_meio) {
  leitura_sensor_dir = analogRead(sensor_dir_pin);
  leitura_sensor_esq = analogRead(sensor_esq_pin);
  leitura_sensor_meio = analogRead(sensor_meio_pin);
}

/*int sensor3(){
 return 1023 - analogRead(sensor_esq);  
}

int sensor2(){
  return 1023 - analogRead(sensor_meio);
}

int sensor1(){
  return 1023 - analogRead(sensor_dir);
}
*/

void esperar(int tempo) {
  delay(tempo);
}

void roda_direita_frente(int v) {
  digitalWrite(pinMotorD2, LOW);
  analogWrite(pinMotorD1, v);
}

void roda_direita_tras(int v) {
  digitalWrite(pinMotorD1, LOW);
  analogWrite(pinMotorD2, v);
}

void roda_esquerda_frente(int v) {
  digitalWrite(pinMotorE1, LOW);
  analogWrite(pinMotorE2, v);
}

void roda_esquerda_tras(int v) {
  digitalWrite(pinMotorE2, LOW);
  analogWrite(pinMotorE1, v);
}

void frente(int v) {
  roda_esquerda_frente(v);
  roda_direita_frente(v);
}


void parar() {
  digitalWrite(pinMotorD1, LOW);
  digitalWrite(pinMotorD2, LOW);
  digitalWrite(pinMotorE1, LOW);
  digitalWrite(pinMotorE2, LOW);
}

void esquerda(int v) {
  //return;
  digitalWrite(pinMotorE2, LOW);
  digitalWrite(pinMotorE1, LOW);
  analogWrite(pinMotorD2, LOW);
  analogWrite(pinMotorD1, v);
}

void direita(int v) {
  //return;
  analogWrite(pinMotorD2, LOW);
  digitalWrite(pinMotorD1, LOW);
  digitalWrite(pinMotorE2, v);
  analogWrite(pinMotorE1, LOW);
}

/*int ler_distancia(int trigger, int echo) {
  long duration;
  int distance;

  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("distancia:");
  Serial.print(distance);
  Serial.println("cm");
  delay(500);
}
 */


#endif