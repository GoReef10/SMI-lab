const int latchPin = 4;
const int clockPin = 3;
const int dataPin = 2;
const int caracter1 = 6;
const int caracter2 = 7;

const int numbers[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};
// 91 = 64 + 16 + 8 + 2 + 1
// b 0101 1011
//   PGFE DCBA
// etc fiecare numar

void setup()
{
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(caracter1, OUTPUT);
    pinMode(caracter2, OUTPUT);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0);
    digitalWrite(latchPin, HIGH);
}

void loop()
{
    for (int nr = 0; nr < 99; nr++)
    {
        for (int j = 0; j < 99; j++)
        {
            if (nr > 9)
            {
                digitalWrite(caracter1, HIGH);
                digitalWrite(latchPin, LOW);
                shiftOut(dataPin, clockPin, MSBFIRST, numbers[nr / 10]);
                digitalWrite(latchPin, HIGH);
                delay(10);
                digitalWrite(caracter1, LOW);
            }
            digitalWrite(caracter2, HIGH);
            digitalWrite(latchPin, LOW);
            shiftOut(dataPin, clockPin, MSBFIRST, numbers[nr % 10]);
            digitalWrite(latchPin, HIGH);
            delay(10);
            digitalWrite(caracter2, LOW);
        }
    }
}