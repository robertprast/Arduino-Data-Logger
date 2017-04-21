#include <SPI.h>;
#include <SD.h>;

#define trigPin 10
#define echoPin 9
#define buzzer 8

const int CS_SD = 4;


void setup() {
  Serial.begin(9600);   //init
  if (!SD.begin((CS_SD))) {
    return;
  }
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);

}
void loop() {


  boolean check1;
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  //digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance > 20) {
    tone(buzzer, 1000);
    delay(1000);
    noTone(buzzer);
    check1 = true;
  }
  else {
    check1 = false;
  }


  File dataFile = SD.open("log.csv", FILE_WRITE);
  if (check1) {
    if (dataFile) {
      Serial.println(1);
      dataFile.println("Alarm");

    }
    
  }
  else{
      Serial.println(0);
    }
  dataFile.flush();
  delay(5000);
}



