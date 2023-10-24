#include "Application.hpp"
#include "SensorController.hpp"
#include "WebServer.hpp"
#include <Arduino.h>

Application *app = Application::getInstance();

void setup()
{
    delay(5000);
    Serial.begin(9600);
    app->init();
}

void loop()
{
    app->sensorController.loop();
    delay(100);
}
