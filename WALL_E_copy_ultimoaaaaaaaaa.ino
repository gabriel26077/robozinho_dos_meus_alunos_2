 #include "wall_e.h"
#define BRANCO 0
#define PRETO 1
int velocidade_media = 190;

void setup() {s
  Serial.begin(9600);
  iniciar_robo();
}

void loop() {
  // teste: ////////////////////////////////////
  // segue linha 1 ----------------------------------------------------------------------
  int sensor_esq;
  int sensor_dir;
  int sensor_meio;

  pega_leituras(sensor_esq, sensor_dir, sensor_meio);


  // if (sensor_esq == BRANCO) {
  //   Serial.print("BRANCO");
  // } else {
  //   Serial.print("PRETO");
  // }
  // Serial.print(" ");


  // if (sensor_dir == BRANCO) {
  //   Serial.print("BRANCO");
  // } else {
  //   Serial.print("PRETO");
  // }

  // Serial.print('\n');
  // delay(100);
  // // goto teste; ////////////////////////////

  // if (sensor_esq == BRANCO && sensor_dir == BRANCO) {
  //   Serial.println("frente");

  //   roda_esquerda_frente(255);
  //   roda_direita_frente(255);
  // }


  // if (sensor_esq == PRETO && sensor_dir == BRANCO) {
  //   Serial.println("gira antiorário");

  //   roda_direita_frente(255);
  //   roda_esquerda_tras(255);
  // }

  // if (sensor_dir == PRETO && sensor_esq == BRANCO) {
  //   Serial.println("gira horário");

  //   roda_esquerda_frente(255);
  //   roda_direita_tras(255);
  // }
  // if (sensor_dir == PRETO && sensor_esq == PRETO) {
  //   parar();
  // }
  //int sinal = s1 + 2*s2 + 3*s3;
  //int erro = sinal - desejavel;
  //int ajuste = erro*0.05;

  //roda_direita_frente(velocidade_media + ajuste);
  //roda_esquerda_frente(velocidade_media - ajuste);

  //Serial.print(sinal);
  //Serial.print("  ");
  //Serial.println(erro);*/

  //Serial.print(s1);
  //Serial.print(" ");
  //Serial.print(s2);
  //Serial.print(" ");
  //Serial.println(s3);
  // PID
// float Kp, Ki, Kd;
// posicao = leitura_s0*0*1000 + leitura_s1*1*1000 + leitura_s2*2*1000;
// setpoint = 1000; //meio linha certo
// erroAnterior = erro;
// erro = posicao - setpoint;
// somaErro += erro;
// P = Kp * erro;
// I = Ki * (somaErro);
// D = Kd * (erro - erroAnterior);
// correcao = P;//tecnica PID

  if (sensor_dir < LIMIAR and sensor_esq < LIMIAR) {
    frente(velocidade_media);
    Serial.println("frente");

  }
  if (sensor_dir > LIM_PRETO and sensor_esq > LIM_PRETO){
    frente (velocidade_media);
    Serial.println ("frente linha preta"); 
  }
  if (sensor_dir > LIM_PRETO and sensor_esq < LIM_BRANCO) {
    roda_direita_tras(165);
    Serial.println("roda direita tras");
  }

  if (sensor_dir < LIM_BRANCO and sensor_esq > LIM_PRETO) {
    roda_esquerda_tras(165);
    Serial.println("roda esquerda tras");
  }
    if (sensor_dir < LIM_BRANCO and sensor_esq > LIM_PRETO and sensor_meio > LIM_PRETO) {
    roda_esquerda_tras (140);
    roda_direita_frente (140);
    esperar (5000);
    Serial.println ("curva para direita");
  }

    if (sensor_dir > LIM_PRETO and sensor_esq < LIM_BRANCO and sensor_meio > LIM_PRETO) {
    roda_direita_tras(140);
    roda_esquerda_frente (140);
    esperar (5000);
    Serial.println ("curva para esquerda");
  }


  // configurando_robo( sensor_dir, sensor_esq);


  // if (sensor_dir == 0 && sensor_esq == 0) {
  //   frente(velocidade_media);
  //   Serial.println("frente");

  // } else if (sensor_dir == 1 && sensor_esq == 1) {
  //   parar();
  //   Serial.println("parar");
  // }
  // if (sensor_dir == 1 && sensor_esq == 0) {
  //   esquerda();
  //   Serial.println("esquerda");
  // }
  // if (sensor_dir == 0 && sensor_esq == 1) {
  //   direita();
  //   Serial.println("direita");
  // }
  // esperar(200);
}

