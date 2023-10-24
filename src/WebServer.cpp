#include "WebServer.hpp"
#include <SPIFFS.h>
#include <WiFi.h>

void WebServer::init()
{
    WiFi.mode(WIFI_MODE_AP);
    WiFi.softAP(SSID, PASSWORD);
    Serial.println("WiFi AP started");
    Serial.println(WiFi.softAPIP());

    using namespace std::placeholders;
    server.on("/", HTTP_GET, std::bind(&WebServer::onMainPage, this, _1));
    server.on("/sensor", HTTP_GET, std::bind(&WebServer::onSensorPageRequest, this, _1));
    server.on("/sensor/download", HTTP_GET, std::bind(&WebServer::onSensorDownloadRequest, this, _1));
    server.onNotFound(std::bind(&WebServer::onNotFound, this, _1));

    server.begin();
}

void WebServer::onNotFound(AsyncWebServerRequest *request) { request->send(404, "text/plain", "Not found"); }
