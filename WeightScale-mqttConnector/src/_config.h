#include <Arduino.h> 

/* BOARD INFO */
String DEVICE_NAME      = "SWC-001"; // SWC mean Smart Weight sCale

/* WIFI INFO */ 
String WIFI_SSID        = "ampere";
String WIFI_PASSWORD    = "espertap";

/* MQTT INFO */ 
String MQTT_HOST        = "gb.netpie.io";
String MQTT_USERNAME    = "CfiQvoEctV9uk92";
String MQTT_PASSWORD    = "GoAkvIs6mL2xDkEiTbWpV9zDw7o=";
String MQTT_CLIENT_ID   = "K8fEx1yBp2JaMVZ0";
String MQTT_PREFIX      = "/devSuperman/gearname/";
int    MQTT_PORT        = 1883;
int PUBLISH_EVERY       = 10L * 1000;
int MQTT_CONNECT_TIMEOUT= 120; 


/*
* board
*   mosquitto_sub -t "/devSuperman/gearname/#" -h gb.netpie.io -i K8fEx1yBp2JaMVZ0 -u "CfiQvoEctV9uk92" -P "GoAkvIs6mL2xDkEiTbWpV9zDw7o=" -p 1883 -d
* subscribe
*   
* web
*   
*/