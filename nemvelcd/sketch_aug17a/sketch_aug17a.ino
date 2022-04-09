#include <LiquidCrystal_I2C.h>
#include <Key.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const byte satir = 4; //satır
const byte sutun = 4; //sutun
String tus;
int basamak=0; //sifreyi kontrol ettirmek için tanımladım 
String sifre="1907"; //sifreyi tanımladım
String girilen=""; // girilen sifreyi tutmak icin bos string tanımladım
char tustakimi[satir][sutun]={{'1','2','3','+'},  // tus haritamin nasıil oldugunu tanimladim
{'4','5','6','-'},
{'7','8','9','*'},
{'0','C','/','=',}};
byte satirPin[satir] = {8, 9, 10, 11}; // satır pinleri
byte sutunPin[sutun] = {4,5,6,7}; //  sutun pinleri

Keypad tuslar = Keypad(makeKeymap(tustakimi) , satirPin , sutunPin , satir , sutun );  // tus haritamin haritalanmasi icin keypad i tuslara tanimladim ve haritami olusturdum

void setup() {
  lcd.begin();  // lcd yi calistirdik
  lcd.backlight();
  lcd.setCursor(0,0); //lcd nin ilk satirina sifre girin yazdim
  lcd.print("sifre girin:    ");
}

void loop() {
 
  tus = tuslar.getKey();  // butona bastiğimizdaki veriyi tus a atadık
  if(tus != NO_KEY)  // tus a deger girildiginde 1 satira girdigimiz degerleri yazdirdim
  {
  lcd.setCursor(basamak,1);  
  lcd.print(tus);
  girilen=girilen+tus;
  basamak++; 
  }
  if(tus == "=" )  // tus a '='  girildiginde sifre kontrolu icin kosul yaptim
    {
    if(girilen.substring(0, basamak-1) == sifre)  // girilen deger sifreye esit olursa sifrenin dogru oldugunu yazdirdim
        {
          lcd.setCursor(0,0);
          lcd.print("dogru bildiniz  ");
          delay(3000);
          for(int i=0;i<=16;i++){  // 3 s sonra 1. satirin 16 basamagina bosluk birakarak temizledik
          lcd.setCursor(i,1);
          lcd.print(" ");
          }
          girilen=""; // girilen ve basamak degerlerini ilk haline getirerek tekrar kontrol saglayabiliriz
          basamak=0;
          lcd.setCursor(0,0);
          lcd.print("sifre girin:    "); // tekrar giris bilgisi almak icin ekrana yazdirdik
        }
    else if(girilen.substring(0, basamak-1) != sifre)  // girilen deger sifreye esit olmazsa sifrenin dogru olmadigini yazdirdim
        {
          lcd.setCursor(0,0);
          lcd.print("hatali sifre    ");
          delay(3000);
          for(int i=0;i<=16;i++){ // 3 s sonra 1. satirin 16 basamagina bosluk birakarak temizledik
          lcd.setCursor(i,1);
          lcd.print(" ");
          }
          girilen="";// girilen ve basamak degerlerini ilk haline getirerek tekrar kontrol saglayabiliriz
          basamak=0;
          lcd.setCursor(0,0);
          lcd.print("sifre girin:    ");// tekrar giris bilgisi almak icin ekrana yazdirdik
        }      
    }
}
