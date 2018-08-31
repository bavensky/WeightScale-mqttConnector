#include <MqttConnector.h>
#include "HX711.h"
#define DOUT 12
#define SCK 14
HX711 scale(DOUT, SCK);
// caribation 1 kg
float calibration_factor = 9091.00;
#define zero_factor 8617378
float weight = 0.0;

extern int relayPinState;
extern MqttConnector *mqtt;
extern int relayPin;
extern char myName[];

static void readSensor();

extern String DEVICE_NAME;
extern int PUBLISH_EVERY;

void register_publish_hooks()
{
  strcpy(myName, DEVICE_NAME.c_str());
  mqtt->on_prepare_data_once([&](void) {
    Serial.println("initializing hx711...");
    scale.set_scale(calibration_factor);
    scale.set_offset(zero_factor);
    Serial.print("Scale = ");
    Serial.println(scale.get_units() * 0.453592);
  });

  mqtt->on_before_prepare_data([&](void) {
    readSensor();
  });

  mqtt->on_prepare_data([&](JsonObject *root) {
    JsonObject &data = (*root)["d"];
    JsonObject &info = (*root)["info"];
    data["myName"] = myName;
    data["millis"] = millis();
    data["relayState"] = relayPinState;
    data["updateInterval"] = PUBLISH_EVERY;
    unsigned long l_weight = weight * 1000;
    data["scale"] = l_weight;
  },
                        PUBLISH_EVERY);
  mqtt->on_after_prepare_data([&](JsonObject *root) {
    /**************
      JsonObject& data = (*root)["d"];
      data.remove("version");
      data.remove("subscription");
    **************/
  });
}

static void readSensor()
{
  // perform reading sensor
  weight = scale.get_units() * 0.453592;
  Serial.print("weight scale = ");
  Serial.println(weight);
}
