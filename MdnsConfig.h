#ifndef MdnsConfig_h
#define MdnsConfig_h

// #include "Arduino.h"

class MdnsConfig {
  public:
    MdnsConfig();
    void setMdns(const char * mdnsName);
    const char * getCurrentMdns();
    void mdnsInit();
    void update();
    void close();
  private:
    std::string _mdnsName;
    bool mdnsRunning = false;
};

#endif
