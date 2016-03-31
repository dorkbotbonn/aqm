#include "EEPROM.h"
#include "persistent_data.h"

configData_t cfg;
configData_t test;

const uint cfgStart = 0;

void eraseConfig() {
  // Reset EEPROM bytes to '0' for the length of the data structure
  EEPROM.begin(4095);
  for (int i = cfgStart ; i < sizeof(cfg) ; i++) {
    EEPROM.write(i, 0);
  }
  delay(200);
  EEPROM.commit();
  EEPROM.end();
}

void saveConfig() {
  // Save configuration from RAM into EEPROM
  EEPROM.begin(4095);
  EEPROM.put( cfgStart, cfg );
  delay(200);
  EEPROM.commit();                      // Only needed for ESP8266 to get data written
  EEPROM.end();                         // Free RAM copy of structure
}

void loadConfig() {
  // Loads configuration from EEPROM into RAM
  EEPROM.begin(4095);
  EEPROM.get( cfgStart, test );
  EEPROM.end();
}
void setup() {
//  eraseConfig();
//  strcpy(cfg.ssid,"MY-AP");
//  strcpy(cfg.password, "secret;-)");
//  strcpy(cfg.location, "Bonn");
//  strcpy(cfg.mQTTHost, "1.2.3.4");
//  saveConfig();
  delay(1000);
  loadConfig();
  Serial.begin(115200);
  Serial.println();
  
  // put your setup code here, to run once:erase_config();
}

void loop() {
  Serial.println(test.ssid);
  Serial.println(test.password);
  Serial.println(test.location);
  Serial.println(test.mQTTHost);
  Serial.println();
  
  // put your main code here, to run repeatedly:

}
