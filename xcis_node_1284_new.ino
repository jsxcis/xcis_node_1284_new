#include <RHRouter.h>
#include <RHMesh.h>
#include <RH_RF95.h>
#include <avr/wdt.h>
#include <TimeLib.h>
#include <Device.h>
#include <XcisMessage.h>
#include <EEPROM.h>
#include "Radio.h"
#include "Sensor.h"

#ifdef ARDUINO_AVR_UNO
String board = "ARDUINO_AVR_UNO";
#elif ARDUINO_AVR_MEGA2560
String board = "ARDUINO_AVR_MEGA2560";
#elif __AVR_ATmega1284P__
String board = "__AVR_ATmega1284P__";
#elif __AVR_ATmega1284__
String board = "__AVR_ATmega1284__";
#else
String board = "XCIS Pro or Pro mini";
#endif


void setup()
{
   Serial.begin(115200);
   //device.initialise(board);
   Device::Instance()->initialise(board);
}
void loop()
{  
  //device.execute(); // Execute device functions
  Device::Instance()->execute();
  //device.onReceive(); // Check for poll and respond if needed
  Device::Instance()->onReceive();
  
}
