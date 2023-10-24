#pragma once

#include <Arduino.h>

class SensorController {
public:
    SensorController() = default;

    void init();

    double readSensor();
    void loop();
};
