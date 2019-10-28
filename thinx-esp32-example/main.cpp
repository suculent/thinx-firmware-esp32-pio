#include <Arduino.h>
#include <Arduino.h>
#include <THiNX32Lib.h>

#define ARDUINO_IDE 
#define __DEBUG__ 
const char *apikey = "388496180dab9d1bd7060ffdba4fd37aa4b369710a851d29dc66e575c57f5e1e";
const char *owner_id = "cedc16bb6bb06daaa3ff6d30666d91aacd6e3efbf9abbc151b4dcade59af7c12";
const char *ssid = "Mandragora";
const char *pass = "najednicku";

THiNX thx;
void finalizeCallback ();
void setup();
void loop();
void finalizeCallback () {
  Serial.println("*INO: Finalize callback called.");
  ESP.deepSleep(3e9);
}

void setup() {

  Serial.begin(230400);

#ifdef __DEBUG__
  while (!Serial);
  WiFi.begin(ssid, pass);
#endif

  THiNX::forceHTTP = true;
  thx = THiNX(apikey, owner_id);

  thx.setFinalizeCallback(finalizeCallback);
}


void loop()
{
  thx.loop();
}
