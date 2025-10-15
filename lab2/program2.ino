const int latchPin = 4;
const int clockPin = 3;
const int dataPin = 2;

void setup()
{
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    Serial.begin(9600);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0);
    digitalWrite(latchPin, HIGH);
}

void joc1()
{
    while (1)
    {
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, 170);
        digitalWrite(latchPin, HIGH);
        delay(1000);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, 85);
        digitalWrite(latchPin, HIGH);
        delay(1000);
    }
}

void joc2()
{
    int afisare = 0;
    while (1)
    {
        for (int i = 0; i < 9; i++)
        {
            afisare = afisare + (1 << i);
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, afisare);
            digitalWrite(latchPin, HIGH);
            delay(500);
        }
        for (int i = 8; i > -1; i--)
        {
            afisare = afisare - (1 << i);
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, afisare);
            digitalWrite(latchPin, HIGH);
            delay(500);
        }
    }
}

void joc3()
{
    int afisare = 1;
    while (1)
    {
        for (int i = 0; i < 8; i++)
        {
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, afisare << i);
            digitalWrite(latchPin, HIGH);
            delay(500);
        }
    }
}

void joc4()
{
    int configuratie;
    while (1)
    {
        configuratie = random(0, 256);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, configuratie);
        digitalWrite(latchPin, HIGH);
        delay(100);
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