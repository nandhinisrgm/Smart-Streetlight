#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
#define mois  A0
#define volt  A1
#define led  A2
int moisture=0;
float voltage=0;


void setup() 
{

 lcd.begin(16,2);
 lcd.setCursor(0, 0);
 lcd.print("smart street");
 lcd.setCursor(0, 1);
 lcd.print("light  ");
 pinMode(led,OUTPUT);
 delay(2000);
 lcd.clear();
}
void loop() 
{
 moisture=analogRead(mois); 
 voltage=analogRead(volt);
 voltage=voltage/105; 
 moisture=moisture/10;
 Serial.print(moisture);
 lcd.clear();
 
 if(moisture<30)
 {
  analogWrite(led,240);
  lcd.setCursor(0, 0);
  lcd.print("INTENSITY");
  lcd.setCursor(12, 0);
  lcd.print(moisture);

  lcd.setCursor(15, 0);
  lcd.print("%");
  
  lcd.setCursor(0, 1);
  lcd.print("BATT.VOLT");
  lcd.setCursor(11, 1);
  lcd.print(voltage);
 }
 else
 {
  analogWrite(led,0);
  lcd.setCursor(0, 0);
 lcd.print("INTENSITY");
 lcd.setCursor(12, 0);
 lcd.print(moisture);
 
 lcd.setCursor(15, 0);
 lcd.print("%");
  
 lcd.setCursor(0, 1);
 lcd.print("BATT.VOLT");
 lcd.setCursor(11, 1);
 lcd.print(voltage);
 }
 
 delay(2000); 
}
