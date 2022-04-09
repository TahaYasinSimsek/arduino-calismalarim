static const int Pin0 = 5; // motor un pinlerini tanimladim
static const int Pin1 = 6;
static const int Pin2 = 7;
static const int Pin3 = 8;


int step = 0; // donusu kontrol etmek icin deger tanimladim
const int x = A0; //joystick den gelen degerlerin kontrolu icin tanimldaim 


int x_eksen;  // donus yonunu belirlemek icin kullandim


void setup() {
  pinMode(Pin0, OUTPUT); // motor pinlerine cikis verdim
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  Serial.begin(9600);
}


void loop() {

   x_eksen = analogRead(A0); // joystick den gelen verileri x_eksen e atadim 
   
  
  switch(step) { // step kontronu switch ile yaptım
    case 0:
      digitalWrite(Pin0, LOW); // motor hareketlerini tanimladim
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      break;
    case 1:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, HIGH);
      break;
    case 2:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      break;
    case 3:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      break;
    case 4:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 5:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 6:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 7:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      break;
  }

  if(x_eksen>550) step++; // saga dondurdukce step 1 artti
  if(x_eksen<50)  step--; // sola dondurdukce step 1 azaldi

  if(step>7) step=0; // 8 durum oldugu icin step 7 yi gecmemesi icin  step i 0 ladim 

  if(step<0) step=7; // step 1 er azaldiginda  - ye dusmeyip harekete devam etmesi icin 7 ye esitldim
  delay(1);

}
