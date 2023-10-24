#include "SensorDataController.hpp"
#include "WebServer.hpp"
#include <Arduino.h>
#include <SPIFFS.h>

static void serveSensorData(AsyncWebServerRequest *request, bool download)
{
    int session = 0;
    if (!request->hasParam("session"))
        return request->send(400, "text/plain", "Missing session parameter");
    try {
        session = (request->getParam("session")->value()).toInt();
    } catch (const std::exception &e) {
        return request->send(400, "text/plain", "Invalid session parameter");
    }

    if (!SPIFFS.exists(SensorDataController::getFileNameForSession(session)))
        return request->send(404, "text/plain", "File not found");
    request->send(SPIFFS, SensorDataController::getFileNameForSession(session), "text/csv", download);
}

void WebServer::onSensorPageRequest(AsyncWebServerRequest *request) { serveSensorData(request, false); }
void WebServer::onSensorDownloadRequest(AsyncWebServerRequest *request) { serveSensorData(request, true); }
