#pragma once

#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <WiFi.h>

#define SSID "ssid"
#define PASSWORD "password"
#define WEB_SERVER_PORT 80

class WebServer {
public:
    WebServer() = default;

    void init();

    void onMainPage(AsyncWebServerRequest *request);
    void onSensorPageRequest(AsyncWebServerRequest *request);
    void onSensorDownloadRequest(AsyncWebServerRequest *request);
    void onNotFound(AsyncWebServerRequest *request);

public:
    AsyncWebServer server = AsyncWebServer(WEB_SERVER_PORT);
};
