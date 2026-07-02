//#include <HTTPClient.h>
//#include <Wifi.h>
#define ANALOG_PIN A0
#define PIN_LED 7

int humidity = 0;
bool triggered = false;

const char* ssid = "";
const char* psswd = "";

void setup()
{
  Serial.begin(115200);
  setupComponents();
  //connection();
}

void loop()
{
  humidity = readHumidity();
  triggered = defineTriggered(humidity);

  controllLeds(triggered);
  //sendData(humidity, triggered);

  delay(1000);
}

// void sendData(int humidity, bool triggered)
// {
//   HTTPClient http;

//   http.begin("http://10.110.220.122:8080/api/sensor");
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
//     delay(1000);
//     Serial.println("connecting...");
//   }
// }

void setupComponents()
{
  pinMode(ANALOG_PIN, INPUT);
  pinMode(PIN_LED, OUTPUT);
}

void controllLeds(bool triggered)
{
  if(triggered){
    digitalWrite(PIN_LED, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
  }
}

int readHumidity()
{
  return analogRead(ANALOG_PIN);
}

bool defineTriggered(int humidity)
{
  return humidity > 200;
}
