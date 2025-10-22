volatile int nr_sec = 0;

const int latchPin = 4;
const int clockPin = 3;
const int dataPin = 2;
const int caracter1 = 6;
const int caracter2 = 7;

const int numbers[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};

setup()
{
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(caracter1, OUTPUT);
    pinMode(caracter2, OUTPUT);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 0);
    digitalWrite(latchPin, HIGH);

    TIMSK1 = 0x02;     // activare ceas în modul CTC
    OCR1A = 0xF423     // iniţializare registru de comparare
    TCCR1B = 0x0C; // set clock 1 0 0 /set WGM12 – CTC mode
}

ISR(TIMER1_OVF_vect)
{
    nr_sec++;
    if (nr_sec == 100)
        nr_sec = 0;
}

void loop()
{
    if (nr_sec > 9)
    {
        digitalWrite(caracter1, HIGH);
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, numbers[nr_sec / 10]);
        digitalWrite(latchPin, HIGH);
        delay(10);
        digitalWrite(caracter1, LOW);
    }
    digitalWrite(caracter2, HIGH);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, numbers[nr_sec % 10]);
    digitalWrite(latchPin, HIGH);
    delay(10);
    digitalWrite(caracter2, LOW);
}