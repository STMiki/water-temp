#pragma once

#include <Preferences.h>
#include <SPIFFS.h>

class SensorDataController {
public:
    SensorDataController() = default;

    void init();

    void putData(double data);
    static String getFileNameForSession(int session);

public:
    Preferences preferences;
    int sessionsCount = 0;
    fs::File dataFile;
};