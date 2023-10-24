#pragma once

#include "SensorController.hpp"
#include "SensorDataController.hpp"
#include "WebServer.hpp"
#include <Arduino.h>

class Application {
private:
    Application() = default;

public:
    static Application *getInstance()
    {
        static Application instance;
        return &instance;
    }

    void init()
    {
        SPIFFS.begin(true);
        server.init();
        sensorController.init();
        sensorDataController.init();
    }

public:
    WebServer server;
    SensorController sensorController;
    SensorDataController sensorDataController;
};
