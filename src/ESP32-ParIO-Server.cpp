#include "ESP32-ParIO-Server.h"

States state;

ParIOServer::ParIOServer()
{
}

ParIOServer::~ParIOServer()
{
}

static void IRAM_ATTR ISR()
{

    delayMicroseconds(20);

    byte Char;

    Char = digitalRead(D0) +
           (digitalRead(D1) << 1) +
           (digitalRead(D2) << 2) +
           (digitalRead(D3) << 3) +
           (digitalRead(D4) << 4) +
           (digitalRead(D5) << 5) +
           (digitalRead(D6) << 6) +
           (digitalRead(D7) << 7);

    Serial1.print((char)Char);

    digitalWrite(ACK_n, LOW);
    digitalWrite(ACK_n, HIGH);
}

void ParIOServer::setup()
{
    // Configure pins
    pinMode(STROBE_n, INPUT_PULLUP); // Input only
    pinMode(D0, INPUT_PULLUP);
    pinMode(D1, INPUT_PULLUP);
    pinMode(D2, INPUT_PULLUP);
    pinMode(D3, INPUT_PULLUP);
    pinMode(D4, INPUT_PULLUP);
    pinMode(D5, INPUT_PULLUP);
    pinMode(D6, INPUT_PULLUP);
    pinMode(D7, INPUT_PULLUP);
    pinMode(ACK_n, OUTPUT);
    pinMode(POUT, INPUT_PULLUP); // Input only
    pinMode(BUSY, OUTPUT);
    pinMode(SEL, INPUT_PULLUP);

    attachInterrupt(POUT, ISR, FALLING);

    digitalWrite(ACK_n, HIGH);
    digitalWrite(BUSY, LOW);

    // digitalWrite(ACT_LED, LOW);
    // state = READY;
}

void ParIOServer::handle()
{
}
