#include <SPI.h>
#include <SD.h>
#include <DS1302.h>
DS1302 rtc(8, 7, 6);
File fichierSD;

void setup() {
  rtc.halt(false);
  rtc.writeProtect(false);
  Serial.begin(9600);
if (!SD.begin(4)) {
    Serial.println("Error");
    return;
  }
  Serial.println("SD Card ready");
}

void loop() {

    float v = analogRead(A0);
    float Vout = (v * 5.0)/1024.0;
    float temperatureC = (Vout - 0.5) * 100 ;
    delay(600000);  
  
  fichierSD = SD.open("mesures.csv", FILE_WRITE);
  if (fichierSD) {
    Serial.println("Ecriture en cours");
    fichierSD.print(rtc.getDateStr());
    fichierSD.print(" ; ");
    fichierSD.print(rtc.getTimeStr());
    fichierSD.print(" ; ");
    fichierSD.println(temperatureC);
    fichierSD.close();
  }
  else { 
    Serial.println("Erreur lors de l'ouverture de mesures.csv");
  } 
}

