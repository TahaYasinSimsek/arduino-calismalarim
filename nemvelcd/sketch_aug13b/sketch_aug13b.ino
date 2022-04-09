#include <LiquidCrystal.h>

#include <Wire.h>

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

int rs =12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() {
  lcd.begin(16,2);
  lcd.print("Sıcaklık ölçüm");
  delay(5000);
  dht.begin();
}

void loop() {
   float t = dht.readTemperature();
  float nem = dht.readHumidity();

  lcd.setCursor(0,0);
  lcd.print("Sicaklik: ");
  lcd.print(t);

  lcd.setCursor(0,1);
  lcd.print("Nem: %");
  lcd.print(nem);
  delay(3000);
}
