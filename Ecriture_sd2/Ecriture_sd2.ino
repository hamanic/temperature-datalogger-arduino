#include <SPI.h>
#include <SD.h>
File fichierSD;
float tab[9];
int i=0;
float TemperatureMoy;


void setup() {
  Serial.begin(9600);
if (!SD.begin(4)) {
    Serial.println("Error");
    return;
  }
  Serial.println("SD Card ready");
}


void loop() {
  for(i=0;i<9;i++){
    float v = analogRead(A0);
    float Vout = (v * 5.0)/1024.0;
    float temperatureC = (Vout - 0.5) * 100 ;
    tab[i]= temperatureC; 
    delay(60000);  
  }

  TemperatureMoy=(tab[0]+tab[1]+tab[2]+tab[3]+tab[4]+tab[5]+tab[6]+tab[7]+tab[8]+tab[9])/10;

  fichierSD = SD.open("test.txt", FILE_WRITE);
  if (fichierSD) {
    Serial.println("Ecriture en cours");
    fichierSD.print(TemperatureMoy);
    fichierSD.println(" degré c");
    fichierSD.close();
    } else { 
      Serial.println("Erreur lors de l'ouverture de test.txt");
    } 
}
