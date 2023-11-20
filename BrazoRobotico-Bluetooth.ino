#include <Servo.h>
Servo pinzas;
Servo servo1;
Servo servo2;
Servo servo3;
Servo base;
char a;
String readString;
void setup() {
  pinzas.attach(9);
  servo1.attach(8);
  servo2.attach(7);
  servo3.attach(6);
  base.attach(5);
  Serial.begin(9600);
  pinzas.write(140);
  servo1.write(73);
  servo2.write(108);
  servo3.write(95);
  base.write(50);
  delay(10);
}
void loop() {
  if (Serial.available()) {
    a = Serial.read();  //Guardo el dato entrante en la variable a
    if (a == 'A')        //Comparo si el dato entrante es “A”
    {
      motorpinzas();  //Ingreso a la función.
    }
    if (a == 'B') {
      motorservo1();
    }
    if (a == 'C') {
      motorservo2();
    }
    if (a == 'D') {
      motorservo3();
    }
    if (a == 'F') {
      motorbase();
    }
  }
}
void motorpinzas() {
  delay(10);
  while (Serial.available())  //Mientras tengamos datos disponibles
  {
    char b = Serial.read();  //Guardo los datos en b
    readString += b;          //Concateno para formar el angulo
  }
  if (readString.length() > 0)  //Si es mayor a 0 la longitud del string
  {
    Serial.println(readString.toInt());  //Convierto el string en entero
    pinzas.write(readString.toInt());     //Muevo el motor el ángulo seteado
    readString = "";                      // Limpio para nueva recepción
  }
}
void motorservo1() {
  delay(10);
  while (Serial.available()) {
    char b = Serial.read();
    readString += b;
  }
  if (readString.length() > 0) {
    Serial.println(readString.toInt());
    servo1.write(readString.toInt());
    readString = "";  // Clear string
  }
}
void motorservo2() {
  delay(10);
  while (Serial.available()) {
    char b = Serial.read();
    readString += b;
  }
  if (readString.length() > 0) {
    Serial.println(readString.toInt());
    servo2.write(readString.toInt());
    readString = "";  // Clear string
  }
}
void motorservo3() {
  delay(10);
  while (Serial.available()) {
    char b = Serial.read();
    readString += b;
  }
  if (readString.length() > 0) {
    Serial.println(readString.toInt());
    servo3.write(readString.toInt());
    readString = "";  // Clear string
  }
}
void motorbase() {
  delay(10);
  while (Serial.available()) {
    char b = Serial.read();
    readString += b;
  }
  if (readString.length() > 0) {
    Serial.println(readString.toInt());
    base.write(readString.toInt());
    readString = "";  // Clear string
  }
}