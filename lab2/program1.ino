void setup()
{
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    Serial.begin(9600);
}

void joc1();
void joc2();
void joc3();
void joc4();

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

void joc1()
{
    while (1)
    {
        for (int i = 2; i < 10; i++)
        {
            if ((i % 2) == 0)
                digitalWrite(i, HIGH);
            else
                digitalWrite(i, LOW);
        }
        delay(1000);
        for (int i = 2; i < 10; i++)
        {
            if ((i % 2) == 0)
                digitalWrite(i, LOW);
            else
                digitalWrite(i, HIGH);
        }
        delay(1000);
    }
}

void joc2()
{
    while (1)
    {
        for (int i = 2; i < 10; i++)
        {
            digitalWrite(i, HIGH);
            delay(500);
        }
        for (int i = 9; i > 1; i--)
        {
            digitalWrite(i, LOW);
            delay(500);
        }
    }
}

void joc3()
{
    while (1)
    {
        for (int i = 2; i < 10; i++)
        {
            for (int j = 2; j < 10; j++)
            {
                if (j == i)
                {
                    digitalWrite(i, HIGH);
                }
                else
                {
                    digitalWrite(j, LOW);
                }
                delay(100);
            }
            delay(100);
        }
    }
}

void joc4()
{
    int pozitie;
    int aprins;
    while (1)
    {
        pozitie = random(2, 10);
        aprins = random(0, 2);
        digitalWrite(pozitie, aprins);
        delay(100);
    }
}