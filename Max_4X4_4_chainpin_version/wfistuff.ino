
const char* ssid = "ESPRider_Mecanum_MAX";               // different name and password?
const char* password = "********";                    // password length minimum 8 char

AsyncWebServer server(80);

// Create a WebSocket object
AsyncWebSocket ws("/ws");

void setupwifi(){
  initWiFi();
  initWebSocket();
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html",MAIN_page);});
  Serial.println("connected:");
  server.begin();
}

// Initialize WiFi
void initWiFi() {
  Serial.println("wifimode started ");
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  Serial.println("HTTP server started");
}  

void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
  Serial.println("done initwebsock");
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    message = (char*)data;  //     Serial.print("message"); Serial.println(message);
  }
}
