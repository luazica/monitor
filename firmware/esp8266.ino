// #include <ESP8266WiFi.h>
// #include <ESP8266HTTPClient.h>
// #define PIN_LED_GREEN D1
// #define PIN_LED_RED D2

// const char* ssid = "brisa-4475197";
// const char* psswd = "C9QXsAE3";
// int humidity = 0;
// bool triggered = false;

// void setup()
// {
//   Serial.begin(9600);
//   connection();
//   pinMode(PIN_LED_GREEN, OUTPUT);
//   pinMode(PIN_LED_RED, OUTPUT);
// }

// void loop()
// {
//   humidity = generateRandomHumidity();
//   triggered = defineTriggered(humidity);

//   controllLeds(triggered);

//   sendData(humidity, triggered);

//   delay(10000);
// }

// void controllLeds(bool triggered) 
// { 
//   if(!triggered){ 
//     digitalWrite(PIN_LED_GREEN, HIGH); 
//     digitalWrite(PIN_LED_RED, LOW); } 
//   else { 
//     digitalWrite(PIN_LED_GREEN, LOW); 
//     digitalWrite(PIN_LED_RED, HIGH); 
//   } 
// }

// int generateRandomHumidity()
// {
//   return random(0, 100);
// }

// bool defineTriggered(int humidity)
// {
//   if(humidity > 25 && humidity < 75){
//     return false;
//   } else {
//     return true;
//   }
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

