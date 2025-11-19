#include <LiquidCrystal.h>
#include <Wire.h>

LiquidCrystal lcd(12, NULL, 11, 9, 8, 7, 6);

const int tmp102Address = 0x48;
float temperatura;

void setup()
{
    lcd.begin(16, 2);
    lcd.noCursor();
    Wire.begin();
    Serial.begin(9600);
}

void loop()
{
    temperatura = getTemperature();
    lcd.setCursor(0, 1);
    if (temperatura >= 0)
        lcd.print(" ");
    else
    {
        lcd.print("-");
        temperatura = -temperatura;
    }
    if (temperatura < 10)
        lcd.print(" ");
    lcd.print(temperatura);
    Serial.println(temperatura);
    delay(5000);
}

float getTemperature()
{
    byte MSB = 0x00;
    byte LSB = 0x00;
    int TempCitita = 0;
    float TempCelsius = 0.0;
    Wire.beginTransmission(tmp102Address);
    Wire.write(0x00);
    Wire.endTransmission();
    Wire.requestFrom(tmp102Address, 2);
    Wire.endTransmission();
    MSB = Wire.read();
    LSB = Wire.read();
    // temperatura este pe 12 biti cu ultimii 4 biti 0 astfel trebuie
    // shift-ata la stanga cu 4 pozitii
    TempCitita = ((MSB << 8) | LSB) >> 4;
    TempCelsius = TempCitita * 0.0625;
    return TempCelsius;
}
