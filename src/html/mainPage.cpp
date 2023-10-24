#include "Application.hpp"
#include "WebServer.hpp"
#include <Arduino.h>

const char index_html[] PROGMEM = R"rawliteral(<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <title>Sensor all</title>
</head>

<body>
    <h1>Sensor files</h1>
    <ul>
        %FILES%
    </ul>
</body>

</html>)rawliteral";

static String processFiles(const String &var)
{
    if (var != "FILES")
        return String();

    String files;
    for (int i = 1; i < Application::getInstance()->sensorDataController.sessionsCount + 1; i++)
        files += "<li><a href=\"/sensor?session=" + String(i) + "\">data-" + String(i) + ".csv</a></li>";
    return files;
}

void WebServer::onMainPage(AsyncWebServerRequest *request) { request->send_P(200, "text/html", index_html, processFiles); }
