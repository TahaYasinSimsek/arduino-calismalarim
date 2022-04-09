#include <Servo.h>
Servo sm;
int deger,derece;
int x_eksen;
void setup() {
sm.attach(9);
}

void loop() {
  deger = analogRead(A0);
  derece = map(deger , 0 , 1023 , 0 , 180);
  sm.write(derece);
}
