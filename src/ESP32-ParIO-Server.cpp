#include "ESP32-ParIO-Server.h"

States state;

ParIOServer::ParIOServer()
{
}

ParIOServer::~ParIOServer()
{
}

void ParIOServer::setup()
{
    // Configure pins
    pinMode(STROBE_n, INPUT_PULLUP); // Input only, not used
    pinMode(D0, INPUT_PULLUP);
    pinMode(D1, INPUT_PULLUP);
    pinMode(D2, INPUT_PULLUP);
    pinMode(D3, INPUT_PULLUP);
    pinMode(D4, INPUT_PULLUP);
    pinMode(D5, INPUT_PULLUP);
    pinMode(D6, INPUT_PULLUP);
    pinMode(D7, INPUT_PULLUP);
    pinMode(ACK_n, OUTPUT);
    pinMode(SEL, INPUT_PULLUP);
    digitalWrite(ACK_n, HIGH); // Not used

    gpio_config_t io_conf;

    io_conf.intr_type = GPIO_INTR_DISABLE; // Disable GPIO interrupt
    io_conf.mode = GPIO_MODE_OUTPUT;       // Set as output mode
    io_conf.pin_bit_mask = (1ULL << BUSY);
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);

    io_conf.pin_bit_mask = (1ULL << POUT);
    io_conf.intr_type = GPIO_INTR_NEGEDGE;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);

    gpio_set_level(GPIO_NUM_33, 1); // Set BUSY to high level

    int INTR_NUM = 31; // extern level 5, see table in file soc.h for details

    ESP_INTR_DISABLE(INTR_NUM);
    intr_matrix_set(xPortGetCoreID(), ETS_GPIO_INTR_SOURCE, INTR_NUM);
    ESP_INTR_ENABLE(INTR_NUM);

    Serial.print("Level 5 Interrupt set on core ");
    Serial.println(xPortGetCoreID());
}

void ParIOServer::handle()
{
}
