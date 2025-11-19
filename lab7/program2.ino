#include <LiquidCrystal.h>
#include <Wire.h>

LiquidCrystal lcd(12, NULL, 11, 9, 8, 7, 6);

const int tmp102Address = 0x48;
const float TLOW = 25;
const float THIGH = 26;
byte alarma = 0;

void setup()
{
    lcd.begin(16, 2);
    lcd.noCursor();
    Wire.begin();
    setLimit(TLOW, THIGH);
}

void setLimit(float low, float high)
{
    byte MSB;
    byte LSB;
    int Temp;
    Temp = low / 0.0625;
    Temp = Temp << 4;
    LSB = (byte)(Temp & 0xff);
    MSB = (byte)((Temp >> 8) & 0xff);
    Wire.beginTransmission(tmp102Address);
    Wire.write(0x02);
    Wire.write(MSB);
    Wire.write(LSB);
    Wire.endTransmission();
    Temp = high / 0.0625;
    Temp = Temp << 4;
    LSB = (byte)(Temp & 0xff);
    MSB = (byte)((Temp >> 8) & 0xff);
    Wire.beginTransmission(tmp102Address);
    Wire.write(0x03);
    Wire.write(MSB);
    Wire.write(LSB);
    Wire.endTransmission();
}

void loop()
{
    float temperatura = 0.0;
    temperatura = getTemperature();
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.setCursor(5, 0);
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
    if (temperatura > THIGH)
    {
        lcd.setCursor(0, 1);
        lcd.print("ALARMA");
        alarma = 1;
    }
    else
    {
        if (alarma == 0)
        {
            lcd.setCursor(0, 1);
            lcd.print(" ");
        }
        else
        {
            if (temperatura < TLOW)
                alarma = 0;
        }
    }
    delay(1000);
}