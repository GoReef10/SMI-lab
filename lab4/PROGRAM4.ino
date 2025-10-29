#include <util/delay.h>

const int latchPin1 = 7;
const int clockPin1 = 8;
const int dataPin1 = 9;

const int latchPin2 = 10;
const int clockPin2 = 11;
const int dataPin2 = 12;

volatile int digit1 = 0;
volatile int digit2 = 0;

const int numbers[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111};

void setup()
{
    // activare int0 si int1
    EIMSK |= (1 << INT0);
    EIMSK |= (1 << INT1);
    // activare PCI2 (buton 3 - PCINT20 - PCI2)
    PCICR |= (1 << PCIE2);
    PCMSK2 |= (1 << PCINT20);
    pinMode(latchPin1, OUTPUT);
    pinMode(dataPin1, OUTPUT);
    pinMode(clockPin1, OUTPUT);
    pinMode(latchPin2, OUTPUT);
    pinMode(dataPin2, OUTPUT);
    pinMode(clockPin2, OUTPUT);
}

void loop()
{
    digitalWrite(latchPin1, LOW);
    shiftOut(dataPin1, clockPin1, MSBFIRST, numbers[digit1]);
    digitalWrite(latchPin1, HIGH);
    digitalWrite(latchPin2, LOW);
    shiftOut(dataPin2, clockPin2, MSBFIRST, numbers[digit2]);
    digitalWrite(latchPin2, HIGH);
    delay(1000);
}

ISR(INT0_vect)
{
    if (digit1 == 9)
    {
        if (digit2 == 9)
        {
            digit1 = 0;
            digit2 = 0;
        }
        else
        {
            digit1 = 0;
            digit2++;
        }
    }
    else
        digit1++;
    _delay_ms(400);
}

ISR(INT1_vect)
{
    if (digit1 == 0)
    {
        if (digit2 == 0)
        {
            digit1 = 9;
            digit2 = 9;
        }
        else
        {
            digit1 = 9;
            digit2--;
        }
    }
    else
        digit1--;
    _delay_ms(400);
}

ISR(PCINT2_vect)
{
    digit1 = 0;
    digit2 = 0;
    _delay_ms(400);
}