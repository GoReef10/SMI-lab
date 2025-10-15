#include <util/delay.h>.

int leds[] = {3, 5, 6, 9, 10, 11};

void setup()
{
    pinMode(leds[0], OUTPUT);
    pinMode(leds[1], OUTPUT);
    pinMode(leds[2], OUTPUT);
    pinMode(leds[3], OUTPUT);
    pinMode(leds[4], OUTPUT);
    pinMode(leds[5], OUTPUT);
    Serial.begin(9600);
}

void joc1()
{
    while (1)
    {
        for (int i = 0; i < 6; i += 2)
            for (int j = 0; j < 250; j += 20)
            {
                analogWrite(leds[i], j);
                _delay_ms(50);
            }
        _delay_ms(1000);
        for (int i = 0; i < 6; i += 2)
            for (int j = 240; j > -1; j -= 20)
            {
                analogWrite(leds[i], j);
                _delay_ms(50);
            }
        _delay_ms(1000);
        for (int i = 1; i < 6; i += 2)
            for (int j = 0; j < 250; j += 20)
            {
                analogWrite(leds[i], j);
                _delay_ms(50);
            }
        _delay_ms(1000);
        for (int i = 1; i < 6; i += 2)
            for (int j = 240; j > -1; j -= 20)
            {
                analogWrite(leds[i], j);
                _delay_ms(50);
            }
        _delay_ms(1000);
    }
}
void joc2()
{
    while (1)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 250; j += 20)
            {
                analogWrite(leds[i], j);
                _delay_ms(50);
            }
            _delay_ms(500);
        }
        for (int i = 5; i > -1; i--)
        {
            for (int j = 240; j > -1; j -= 20)
            {
                analogWrite(leds[i], j);
                _delay_ms(50);
            }
            _delay_ms(500);
        }
    }
}
void joc3()
{
    while (1)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 250; j += 20)
            {
                analogWrite(leds[i], j);
                _delay_ms(50);
            };
            for (int j = 240; j > -1; j -= 20)
            {
                analogWrite(leds[i], j);
                _delay_ms(50);
            };
        }
        _delay_ms(100);
    }
}
void joc4()
{
    int pozitie;
    int aprins;
    while (1)
    {
        pozitie = random(0, 6);
        aprins = random(0, 2);
        if (aprins == 0)
        {
            for (int j = 0; j < 250; j += 20)
            {
                analogWrite(leds[pozitie], j);
                _delay_ms(50);
            };
        }
        else
        {
            for (int j = 240; j > -1; j -= 20)
            {
                analogWrite(leds[pozitie], j);
                _delay_ms(50);
            };
        }
        _delay_ms(100);
    }
}

void loop()
{
    int alege = 0;
    Serial.println("Joc de lumini");
    Serial.println("Alegeti varianta de joc (1-4)");
    while (alege < '1' || alege > '4')
    {
        alege = Serial.read();
        delay(1000);
    }
    alege = alege - 48;
    Serial.print("Ati ales jocul: ");
    Serial.print(alege, DEC);
    Serial.println();
    Serial.println("Pentru reinitializare apasati butonul Reset alplacii");
    switch (alege)
    {
    case 1:
        joc1();
    case 2:
        joc2();
    case 3:
        joc3();
    case 4:
        joc4();
    }
}