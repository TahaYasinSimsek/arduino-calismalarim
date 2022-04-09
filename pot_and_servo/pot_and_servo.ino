#include <Servo.h>
Servo motor; // servo utuphanesini motor nesnesine atadim
#define pot A0 // potansiyometreden okunan degeri pot a atadim
int deger;  //  pot dan okunan degerleri deger e atamak icin tanimladim
int derece; // sevo motorun hareket derecesini atamak icin derece degerini tanimladim

void setup() {
  motor.attach(5); // motor baslatildi
}

void loop() {
   deger = analogRead(pot); // potansiyodan okunan deeri atadik
   derece = map(deger, 0, 1023, 0, 180); // okudugumuz 0-1023 arasındaki degeri 0-180 e normallestirip dereceye atadik
   motor.write(derece); // normallestirdigimiz degeri motora yansittik
}
