#ifdef ESP32
#include <ESPmDNS.h>
#elif defined ESP8266
#include <ESP8266mDNS.h>
#endif

// #include "Arduino.h"
#include "MdnsConfig.h"
 

MdnsConfig::MdnsConfig() {
}

void MdnsConfig::setMdns(const char * mdnsName) {
  _mdnsName = std::string(mdnsName);
}

const char * MdnsConfig::getCurrentMdns() {
  return _mdnsName.c_str();
}

void MdnsConfig::mdnsInit() {
#ifdef ESP32
    MDNS.end();
    delay(1000);
#elif defined ESP8266
  if (MDNS.isRunning()) {
    Serial.println("Closing mDNS responder");
    MDNS.end();
    // MDNS.close();
    delay(1000);
  }
#endif
  MDNS.begin(_mdnsName.c_str());
  MDNS.addService("http", "tcp", 80);
  MDNS.addService("ws", "tcp", 81);
  Serial.print("mDNS responder started: http://");
  Serial.print(_mdnsName.c_str());
  Serial.println(".local");
  mdnsRunning = true;
}

void MdnsConfig::update() {
#ifdef ESP8266
  if (mdnsRunning) {
    MDNS.update();
  }
#endif
}

void MdnsConfig::close() {
  if (mdnsRunning) {
    MDNS.end();
  }
  // MDNS.close();
}
