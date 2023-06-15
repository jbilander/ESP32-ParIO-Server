#ifndef _ESP32_PARIO_SERVER_H_
#define _ESP32_PARIO_SERVER_H_

#include <Arduino.h>

/*
Par   P-name  Devkit  ESP32   Type
1     STROBE* VN      GPIO39  Input only
2     D0      D27     GPIO27  I/O
3     D1      D26     GPIO26  I/O
4     D2      D25     GPIO25  I/O
5     D3      D23     GPIO23  I/O
6     D4      D22     GPIO22  I/O
7     D5      D21     GPIO21  I/O
8     D6      D19     GPIO19  I/O
9     D7      D18     GPIO18  I/O
10    ACK*    D5      GPIO5   I/O
11    BUSY    D33     GPIO33  I/O
12    POUT    D35     GPIO35  Input only
13    SELECT  D32     GPIO32  I/O
14    +5V                                   ;Used for Pull-up resistor arrays on PCB
17-22 GND
*/

#define ACT_LED 2 // Activity LED pin

// Parallel port signals mapping
#define STROBE_n 39 // Input only
#define D0 27
#define D1 26
#define D2 25
#define D3 23
#define D4 22
#define D5 21
#define D6 19
#define D7 18
#define ACK_n 5
#define BUSY 33
#define POUT 35 // Input only
#define SEL 32

enum States
{
    READY,
    ACTIVE,
    ACK
};

class ParIOServer
{
public:
    ParIOServer();
    virtual ~ParIOServer();

    void setup();
    void handle();
};

#endif