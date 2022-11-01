#include <Servo.h>
//analog 1
int analog1x =A0;
int analog1y =A1;
//analog 2
int analog2x =A2;
int analog2y =A3;

Servo altServo;
Servo anaKolServo;
Servo kaldiracServo;
Servo kiskacServo;

int val1x,val1y,val2x,val2y;//analog okunan değerlerin atandığı değişkenler.
int x1,x2,y1,y2; //map edilmiş değerlerin atandığı değişkenler.

void setup() {
  //Servo değişkenlerine dijital pinlerin atanması.
  altServo.attach(8);
  anaKolServo.attach(9);
  kaldiracServo.attach(10);
  kiskacServo.attach(11);
}

void loop() {
  //Analog değerlerinin okunup değerlere atanması.
  val1x = analogRead(analog1x);
  val1y = analogRead(analog1y);
  val2x = analogRead(analog2x);
  val2y = analogRead(analog2y);

  //Josystick lerden okunan analog değerinin servoların çalıştığı aralığa dönüştürülmesi.
  x1= map(val1x,0,1023,0,180);
  y1= map(val1y,0,1023,80,160);
  x2= map(val2x,0,1023,75,180);
  y2= map(val2y,0,1023,100,170);
  
  //Servolara komut gönderme.
  altServo.write(x1);
  anaKolServo.write(y1);
  kaldiracServo.write(y2);
  kiskacServo.write(x2);

  delay(10);

}
