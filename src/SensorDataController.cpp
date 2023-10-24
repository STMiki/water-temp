#include "SensorDataController.hpp"
#include <SPIFFS.h>

void SensorDataController::init()
{
    // Init sessions count for file storage name
    preferences.begin("sensor", false);
    sessionsCount = preferences.getInt("sessionsCount", 1);
    preferences.putInt("sessionsCount", sessionsCount + 1);
    preferences.end();

    if (!SPIFFS.exists("/data"))
        SPIFFS.mkdir("/data");

    dataFile = SPIFFS.open(getFileNameForSession(sessionsCount), "w", true);
    if (!dataFile)
        Serial.println("File not opened");
    dataFile.println("time,value");
    dataFile.flush();
}

String SensorDataController::getFileNameForSession(int session) { return "/data/data" + String(session) + ".csv"; }

void SensorDataController::putData(double data)
{
    dataFile.println(String(millis()) + "," + String(data));
    dataFile.flush();
}
