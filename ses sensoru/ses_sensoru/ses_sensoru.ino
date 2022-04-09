#define sensor 7

#define leds 9

int sayac=0;
int deger=0;
void setup() {
 pinMode(sensor,INPUT);
 pinMode(leds,OUTPUT);
 Serial.begin(9600);

}

void loop() {
  
  
  if(digitalRead(sensor))
  {
  digitalWrite(leds,LOW);
  }
  else
  {
    digitalWrite(leds,HIGH);
  }
}
