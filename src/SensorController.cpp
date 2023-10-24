#include "SensorController.hpp"
#include "Application.hpp"
#include <Arduino.h>
#include <SPIFFS.h>

void SensorController::init()
{
    // TODO: implement
}

double SensorController::readSensor()
{
    // TODO: implement
    return 0;
}

void SensorController::loop()
{
    auto sensorValue = readSensor();
    Application::getInstance()->sensorDataController.putData(sensorValue);
}
