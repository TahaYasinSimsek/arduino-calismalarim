#define echo 10
#define trig 9
#define buzzer 8

long sure,uzaklik;
int derece=0;

void setup() {
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(buzzer,OUTPUT);

}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);

  sure=pulseIn(echo,HIGH);
  uzaklik= sure/29.1/2;
  Serial.print("uzaklik   ");
  Serial.print(uzaklik);
  Serial.println("  cm");
  delay(500);
  int ses=0;
  if(uzaklik <= 90)
  {
  derece = uzaklik*2;
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(buzzer,LOW);
  }
  else{
  digitalWrite(buzzer,LOW);
    }

}
