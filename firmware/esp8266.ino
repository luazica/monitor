// #include <ESP8266WiFi.h>
// #include <ESP8266HTTPClient.h>

// const char* ssid = "";
// const char* psswd = "";
// int humidity = 0;
// bool triggered = false;

// void setup() 
// {
//   Serial.begin(115200);
//   connection();
// }

// void loop() 
// {
//   sendData(65, false); 
//   delay(10000); 
// }

// void sendData(int humidity, bool triggered)
// {
//   HTTPClient http;
//   WiFiClient client;
//   http.begin(client, "http://192.168.0.6:8080/api/sensor");
//   http.addHeader("Content-type", "application/json");

//   String json = "{";
//   json += "\"humidity\":" + String(humidity) + ",";
//   json += "\"triggered\":" + String(triggered ? "true" : "false");
//   json += "}";
//   int httpResponse = http.POST(json);

//   Serial.println(httpResponse);
//   http.end();
// }

// void connection()
// {
//   WiFi.begin(ssid, psswd);

//   while(WiFi.status() != WL_CONNECTED){
//   delay(1000);
//   Serial.println("connecting...");
//   }
// }
