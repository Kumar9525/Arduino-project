#include <LiquidCrystal.h>
int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte dot[8] = {
  0b00000,
  0b00100,
  0b01010,
  0b00100,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
void setup()
{
  lcd.begin(16, 2);
  lcd.createChar(1, dot);
  
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
}

void loop()
{
  baselineTemp = 40;
  
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
   fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");
  
   if (celsius < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Temperature ");
    lcd.setCursor(6, 1);
    lcd.print(celsius);
    
    lcd.setCursor(9, 1);
    lcd.write(byte(1));
    lcd.print("C");
  }
  if (celsius >= baselineTemp && celsius < baselineTemp + 10) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Temperature ");
    lcd.setCursor(6, 1);
    lcd.print(celsius);
    
    lcd.setCursor(9, 1);
    lcd.write(byte(1));
    lcd.print("C");
  }
  if (celsius >= baselineTemp + 10 && celsius < baselineTemp + 20) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Temperature ");
    lcd.setCursor(6, 1);
    lcd.print(celsius);
    
    lcd.setCursor(9, 1);
    lcd.write(byte(1));
    lcd.print("C");
  }
  if (celsius >= baselineTemp + 20 && celsius < baselineTemp + 30) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Temperature ");
    lcd.setCursor(6, 1);
    lcd.print(celsius);
    
    lcd.setCursor(9, 1);
    lcd.write(byte(1));
    lcd.print("C");
  }
  if (celsius >= baselineTemp + 30) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Temperature ");
    lcd.setCursor(6, 1);
    lcd.print(celsius);
    
    lcd.setCursor(9, 1);
    lcd.write(byte(1));
    lcd.print("C");
  }
  delay(1000); 
  
}
