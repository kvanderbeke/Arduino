/*
 * Author: Kristof Vanderbeke
 * Date:2018/9/05
 * IDE V1.6.9
 * Function: Measure liters still in watertank
 */
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int TrigPin = 8;
const int EchoPin = 9;
float cm;
int liter;

void setup()
{
    lcd.begin(16, 2);
    lcd.print("  Welcome to ");
    lcd.setCursor(0, 1);
    lcd.print("     Smraza");
    delay(2000);
    lcd.clear();
    pinMode(TrigPin, OUTPUT);
    pinMode(EchoPin, INPUT);
}
void loop()
{
    digitalWrite(TrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin, LOW);
    cm = pulseIn(EchoPin, HIGH) / 58.0; //The echo time is converted into cm
    cm = (int(cm * 100.0)) / 100.0; //Keep two decimal places Serial.print("Distance\t=\t");
    liter = (int(cm * (15000.0 / 230.0)));
    lcd.clear(); //clear display
    lcd.print("Tankinhoud");
    lcd.setCursor(0, 1);
    String liters = String(liter);
    String Tankinhoud = liters + "/15000";
    lcd.print(Tankinhoud);
    delay(1000);
}
