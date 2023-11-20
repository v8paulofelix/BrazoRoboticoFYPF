#include <Servo.h>
Servo pinzas;
Servo servo1;
Servo servo2;
Servo servo3;
Servo base;

int angulo1 = 90;  // Empezamos en el centro base
int angulo2 = 90;  // Empezamos en el centro hombro
int angulo3 = 90;  // Empezamos en el centro codo
int angulo4 = 80;  // Empezamos en 120 grados pinza
int angulo5 = 80;  // Empezamos en 120 grados pinza
int salto = 3;     // Controla el salto por movimiento


void setup() {
  pinzas.attach(11);
  servo1.attach(10);
  servo2.attach(9);
  servo3.attach(6);
  base.attach(5);

  pinzas.write(140);
  servo1.write(73);
  servo2.write(108);
  servo3.write(95);
  base.write(50);
  delay(10);
}
void loop() {

  int pinza_servo = analogRead(A0);
  if (pinza_servo < 200)                 // Si la lectura es menor de 200
    angulo1 = angulo1 - salto;           // disminuimos el angulo
  else if (pinza_servo > 800)            // Si mayor de 800
    angulo1 = angulo1 + salto;           // Aumentamos el angulo
  angulo1 = constrain(angulo1, 0, 180);  //Limita la distancia
  pinzas.write(angulo1);                 // Y este es el que mueve el servo

  int servo_1 = analogRead(A1);
  if (servo_1 < 200)                     // Si la lectura es menor de 200
    angulo2 = angulo2 - salto;           // disminuimos el angulo
  else if (servo_1 > 800)                // Si mayor de 800
    angulo2 = angulo2 + salto;           // Aumentamos el angulo
  angulo2 = constrain(angulo2, 0, 180);  //Limita la distancia
  pinzas.write(angulo2);                 // Y este es el que mueve el servo

  int servo_2 = analogRead(A1);
  if (servo_2 < 200)                     // Si la lectura es menor de 200
    angulo3 = angulo3 - salto;           // disminuimos el angulo
  else if (servo_2 > 800)                // Si mayor de 800
    angulo3 = angulo3 + salto;           // Aumentamos el angulo
  angulo3 = constrain(angulo3, 0, 180);  //Limita la distancia
  pinzas.write(angulo3);                 // Y este es el que mueve el servo

  int base_servo = analogRead(A1);
  if (base_servo < 200)                  // Si la lectura es menor de 200
    angulo4 = angulo4 - salto;           // disminuimos el angulo
  else if (base_servo > 800)             // Si mayor de 800
    angulo4 = angulo4 + salto;           // Aumentamos el angulo
  angulo4 = constrain(angulo4, 0, 180);  //Limita la distancia
  pinzas.write(angulo4);                 // Y este es el que mueve el servo

  int servo_3 = analogRead(A1);
  if (servo_3 < 200)                     // Si la lectura es menor de 200
    angulo5 = angulo5 - salto;           // disminuimos el angulo
  else if (angulo5 > 800)                // Si mayor de 800
    angulo5 = angulo5 + salto;           // Aumentamos el angulo
  angulo5 = constrain(angulo5, 0, 180);  //Limita la distancia
  pinzas.write(angulo5);                 // Y este es el que mueve el servo
}