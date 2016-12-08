//Selamunaleyküm .asm
//Arduino drone projemiz vol.14
//Bu proje arduino nano, bluetooth shield, ve bolca sevgi içerir.
//Android program tabanlı yazılımımızdan ses kontrolü ile dronun motor hareketlerindeki değişim amaçlanmıştır.

String voice;
int motor1 = 5;   //ilk motorumuzu 5 nolu pinimize bağladık, çünkii pwm..
int motor2 = 9;   //iki nolu motorumuzu 9 nolu pinimize bağladık.
int motor3 = 10;  //üç nolu motorumuzu 10 nolu pinimize bağladık.
int motor4 = 11;  //dört nolu motorumuzu 11 nolu pinimize bağladık.

//--------------------------Buradan Fonksiyonları çağıracağız-------------------------------//

//Analog grişlerden 0-255 skalasında bir değer göreceğiz ve bu değer motora gönderilecek değerimizi belirleyecek.
//Dronu sabit tutana kadar değerlerle oynadık; 130 veya 135 değerlerinde bu durumu sağlayabildik.

void middlespeed() {    //ortalama hızda
  analogWrite(motor1, 130);
  analogWrite(motor2, 130);
  analogWrite(motor3, 130);
  analogWrite(motor4, 130);
}
void fastspeed() {     //hızlı iken
  analogWrite(motor1, 255);
  analogWrite(motor2, 255);
  analogWrite(motor3, 255);
  analogWrite(motor4, 255);
}

void lowspeed() {     //yavaşken
  analogWrite(motor1, 100);
  analogWrite(motor2, 100);
  analogWrite(motor3, 100);
  analogWrite(motor4, 100);
}
//-----------------------------------------------------------------------//
void setup() {
  Serial.begin(9600);     //Serial portun 9600lü kanalını kullan.
  analogWrite(motor1, 100); 
  analogWrite(motor2, 100);
  analogWrite(motor3, 100);
  analogWrite(motor4, 100);
      //Tüm motorlara başlangıç değerini ver
      
      //Motorları output yap
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
}
//----------------------Asıl Olaya Başladık----------------------------//
void loop() {
  while (Serial.available()) { //Herhangi ulaşılabilir byte var mı sürekli ara..
    delay(10);                 //Bu olay güzel oluyor, bi nefes alması için.
    char c = Serial.read();    //Okunan değeri c 'ye ata.
    if (c == '#') {
      break;                   //sözcükten sonra # gelirse looptan çık
    }
    voice += c;                //voice 'a ekledik.
  }
  if (voice.length() > 0) {
    Serial.println(voice);
    //----------------------Bu kısım projenin devamı için geliştirelecek şu an için geç-----------------------------------//
    //----------Motor Kontrolü----------//
    if (voice == "*bir") {
      lowspeed(); 
    }
    else if (voice == "*2") {
      middlespeed(); 
    }
    else if (voice == "*3") {
      fastspeed(); 
    }

    //----------Doğrultu, yönlerimiz----------//
    //Yönlerin bölümü başladı
    else if (voice == "*sol")
    {
      analogWrite(motor1, 100);
      analogWrite(motor2, 130);
      analogWrite(motor3, 130);
      analogWrite(motor4, 100); 
                            delay(1000);
    }
    else if (voice == "*sağ")
    {
      analogWrite(motor1, 130);
      analogWrite(motor2, 100);
      analogWrite(motor3, 100);
      analogWrite(motor4, 130);
                             delay(1000);
    }
    else if (voice == "*geri") {
     analogWrite(motor1, 130);
     analogWrite(motor2, 130);
     analogWrite(motor3, 100);
     analogWrite(motor4, 100);
                             delay(1000);
    }
    else if (voice == "*ileri") {
     analogWrite(motor1, 100);
     analogWrite(motor2, 100);
     analogWrite(motor3, 130);
     analogWrite(motor4, 130);
                             delay(1000);
    }
    else if (voice == "*right back") {
     analogWrite(motor1, 110);
     analogWrite(motor2, 90);
     analogWrite(motor3, 110);
     analogWrite(motor4, 90);
                             delay(1000);
    }
    else if (voice == "*left back") {
     analogWrite(motor1, 90);
     analogWrite(motor2, 110);
     analogWrite(motor3, 90);
     analogWrite(motor4, 110);
                             delay(1000);
    }
    else if(voice =="*dur") { 
     analogWrite(motor1, 70);
     analogWrite(motor2, 70);
     analogWrite(motor3, 70);
     analogWrite(motor4, 70);
                             delay(1000);
     analogWrite(motor1, 35);
     analogWrite(motor2, 35);
     analogWrite(motor3, 35);
     analogWrite(motor4, 35);
                             delay(1000);
     analogWrite(motor1, 0);
     analogWrite(motor2, 0);
     analogWrite(motor3, 0);
     analogWrite(motor4, 0);
                             delay(1000);
      
    }

    //-----------------------------------------------------------------------//
    voice = "";
    
  }
  
} //Değerleri resetle ve başa dön..

//Gyro ekle, Jarvisle konuştur, lityum iyonu değiştir.. 

//Son edit --> (02.12.2016)
