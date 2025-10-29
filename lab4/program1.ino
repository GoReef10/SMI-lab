const int buton1 = 2;
const int buton2 = 3;
const int buton3 = 4;

int a1 = 0;
int a2 = 0;
int a3 = 0;

void setup()
{
    pinMode(buton1, INPUT);
    pinMode(buton2, INPUT);
    pinMode(buton3, INPUT);
    Serial.begin(9600);
}

void loop()
{
    if (digitalRead(buton1) == LOW)
    {
        a1++;
        Serial.print("Butonul 1 s-a apasat butonul de ");
        Serial.print(a1, DEC);
        Serial.print(" ori.");
        Serial.println();
        // debouncing software
        delay(200);
    }
    if (digitalRead(buton2) == LOW)
    {
        a2++;
        Serial.print("Butonul 2 s-a apasat butonul de ");
        Serial.print(a2, DEC);
        Serial.print(" ori.");
        Serial.println();
        // debouncing software
        delay(200);
    }
    if (digitalRead(buton3) == LOW)
    {
        a3++;
        Serial.print("Butonul 3 s-a apasat butonul de ");
        Serial.print(a3, DEC);
        Serial.print(" ori.");
        Serial.println();
        // debouncing software
        delay(200);
    }
}