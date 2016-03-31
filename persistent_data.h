#ifndef __persistent_data_h
#define __persistent_data_h

#include <WString.h>

//Thanks, http://www.kriwanek.de/homeautomation/esp8266-chip/495-eeprom-parameter.html

typedef struct{
	char ssid[31];
	char password[31];
	char mQTTHost[31];
	char location[31];
	
} configData_t;


#endif
