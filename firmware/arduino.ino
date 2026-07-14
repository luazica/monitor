//#define ANALOG_PIN A0
#define PIN_LED_GREEN 7
#define PIN_LED_RED 13

bool triggered = false;

void setup()
{
  Serial.begin(115200);
  setupComponents();
}

void loop()
{
  controllLeds(triggered);

  delay(10000);
}

void setupComponents()
{
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_RED, OUTPUT);
}

void controllLeds(bool& triggered)
{
  if(triggered){
    digitalWrite(PIN_LED_GREEN, HIGH);
    digitalWrite(PIN_LED_RED, LOW);
  } else {
    digitalWrite(PIN_LED_GREEN, LOW);
    digitalWrite(PIN_LED_RED, HIGH);
  }
}

// caso tivessemos o sensor fisico
// int readHumidity()
// {
//   return analogRead(ANALOG_PIN);
// }

