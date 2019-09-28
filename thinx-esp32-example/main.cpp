# 1 "/var/folders/z4/xdx0_q792h50_8tv3c4qxjv40000gn/T/tmpmw6cnc22"
#include <Arduino.h>
# 1 "/Users/sychram/Repositories/thinx-firmware-esp32-pio/thinx-esp32-example/thinx-esp32-example.ino"
#include <Arduino.h>
#include <THiNX32Lib.h>

#define ARDUINO_IDE 
#define __DEBUG__ 
# 14 "/Users/sychram/Repositories/thinx-firmware-esp32-pio/thinx-esp32-example/thinx-esp32-example.ino"
const char *apikey = "388496180dab9d1bd7060ffdba4fd37aa4b369710a851d29dc66e575c57f5e1e";
const char *owner_id = "cedc16bb6bb06daaa3ff6d30666d91aacd6e3efbf9abbc151b4dcade59af7c12";
const char *ssid = "Mandragora";
const char *pass = "najednicku";

THiNX thx;
void finalizeCallback ();
void setup();
void loop();
#line 22 "/Users/sychram/Repositories/thinx-firmware-esp32-pio/thinx-esp32-example/thinx-esp32-example.ino"
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