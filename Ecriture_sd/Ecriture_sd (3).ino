#include <SPI.h>
#include <SD.h>
File fichierSD;

void setup() {
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
   
  fichierSD = SD.open("mesures.txt", FILE_WRITE);
  if (fichierSD) {
    Serial.print("Ecriture en cours ");
    Serial.println(temperatureC);
    fichierSD.print(temperatureC);
    
  }
  else { 
    Serial.println("Erreur lors de l'ouverture de mesures.txt");
  } 
}

