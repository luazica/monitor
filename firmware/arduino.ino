//define ANALOG_PIN A0
#define PIN_LED_GREEN 7
#define PIN_LED_RED 13

bool triggered;
int humidity;

void setup()
{
  Serial.begin(9600);

  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_RED, OUTPUT);
}

void loop()
{
  humidity = generateRandomHumidity();
  triggered = defineTriggered(humidity);

  controllLeds(triggered);

  sendData();

  delay(10000);
}

void sendData()
{
  Serial.print("{\"humidity\":");
  Serial.print(humidity);
  Serial.print(",\"triggered\":");
  Serial.print(triggered ? "true" : "false");
  Serial.println("}");
}

void controllLeds(bool triggered) 
{ 
  if(!triggered){ 
    digitalWrite(PIN_LED_GREEN, HIGH); 
    digitalWrite(PIN_LED_RED, LOW); } 
  else { 
    digitalWrite(PIN_LED_GREEN, LOW); 
    digitalWrite(PIN_LED_RED, HIGH); 
  } 
}

int generateRandomHumidity()
{
  return random(0, 100);
}

bool defineTriggered(int humidity)
{
  if(humidity > 25 && humidity < 75){
    return false;
  } else {
    return true;
  }
}

// caso tivessemos o sensor fisico
// int readHumidity()
// {
//   return analogRead(ANALOG_PIN);
// }

