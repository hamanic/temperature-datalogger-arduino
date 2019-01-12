#include <SPI.h>
#include <SD.h>
#include <DS1302.h>
DS1302 rtc(8, 7, 6);
File fichierSD;
float tab[9];
float moy=0;
int i=0;

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
 //for(i=0;i<=9;i++){
    float v = analogRead(A0);
    float Vout = (v * 5.0)/1024.0;
    float temperatureC = (Vout - 0.5) * 100 ;
    moy= temperatureC; 
    delay(60000);  
  //}

  //moy=(tab[0]+tab[1]+tab[2]+tab[3]+tab[4]+tab[5]+tab[6]+tab[7]+tab[8]+tab[9])/10;
  
  fichierSD = SD.open("mesures.csv", FILE_WRITE);
  if (fichierSD) {
    Serial.println("Ecriture en cours");
    fichierSD.print(rtc.getDateStr());
    fichierSD.print(" ; ");
    fichierSD.print(rtc.getTimeStr());
    fichierSD.print(" ; ");
    fichierSD.println(moy);
    fichierSD.close();
  }
  else { 
    Serial.println("Erreur lors de l'ouverture de mesures.csv");
  } 
}

