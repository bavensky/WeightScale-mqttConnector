#include <Arduino.h> 

/* BOARD INFO */
String DEVICE_NAME      = "YOU-DEVICE-NAME-001"; // Insert your device name here

/* WIFI INFO */ 
String WIFI_SSID        = "YOUR-WIFI-NAME";
String WIFI_PASSWORD    = "YOUR-WIFI-PASSWORD";

/* MQTT INFO */ 
String MQTT_HOST        = "gb.netpie.io";
String MQTT_USERNAME    = "CfiQvoEctV9XXX"; 
String MQTT_PASSWORD    = "GoAkvIs6mL2xDkEiTbWpV9zDXXX";
String MQTT_CLIENT_ID   = "K8fEx1yBp2JaXXX";
String MQTT_PREFIX      = "/devSuperman/gearname/";
int    MQTT_PORT        = 1883;
int PUBLISH_EVERY       = 10L * 1000;
int MQTT_CONNECT_TIMEOUT= 120;
