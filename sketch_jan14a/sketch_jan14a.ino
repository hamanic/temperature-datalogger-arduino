
int TMP36 = 0; 
 
void setup()
{
  Serial.begin(9600);  
}
 
void loop()                     
{

 int TensionA0 = analogRead(TMP36);  
 
 float Vout = (TensionA0 * 5.0)/1024.0;
 
 Serial.print(Vout); Serial.println("V");
 
 float temperatureC = (Vout - 0.5) * 100 ; 
 Serial.print(temperatureC); Serial.println("°C");
 
 
 delay(1000);                                     //waiting a second
}
