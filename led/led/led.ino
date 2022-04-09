int KirmiziLed=2; //Kırmızı ledin bağlı olduğu pin numarasını KirmiziLed adlı değişkene aktardık.
int SariLed=3; //Sarı ledin bağlı olduğu pin numarasını SariLed adlı değişkene aktardık.
int YesilLed=4; //Yeşil ledin bağlı olduğu pin numarasını YesilLed adlı değişkene aktardık.
 
void setup() {
pinMode(KirmiziLed, OUTPUT); //Kırmızı ledin olduğu (2 numaları) pini çıkış pini olarak belirttik.  
pinMode(SariLed, OUTPUT); //Sarı ledin olduğu (3 numaları) pini çıkış pini olarak belirttik.  
pinMode(YesilLed, OUTPUT); //Yeşil ledin bağlı olduğu (4 numaları) pini çıkış pini olarak belirttik.  
}
 
void loop() {
  digitalWrite(KirmiziLed, HIGH); 
  digitalWrite(SariLed, HIGH); //3 led'e aynı anda güç vererk yakıyoruz.
  digitalWrite(YesilLed, LOW); 
  
  delay(500); // 1saniye bekletiyoruz.
  
  digitalWrite(KirmiziLed, LOW); 
  digitalWrite(SariLed, HIGH); //Ledlerin gücünü keserek söndürüyoruz.
  digitalWrite(YesilLed, LOW); 
 
  delay(500); // 1 saniye bekletiyoruz.  
  digitalWrite(KirmiziLed, LOW); 
  digitalWrite(SariLed, LOW); //Ledlerin gücünü keserek söndürüyoruz.
  digitalWrite(YesilLed, HIGH); 
 delay(500);
}
