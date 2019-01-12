#include <SPI.h>
#include <SD.h>
File fichierSD;
int i=0;
void setup() {
  Serial.begin(9600);
if (!SD.begin(4)) {
    Serial.println("Error");
    return;
  }
  Serial.println("SD Card ready");
}

void loop() {
  
  //Ouverture du fichier
  fichierSD = SD.open("mesures.txt", FILE_READ);
  
 if(i==0){
  if(fichierSD) {
    while (fichierSD.available()) {
      Serial.write(fichierSD.read());
    }
    fichierSD.close();
  }
  }
i++;
}
