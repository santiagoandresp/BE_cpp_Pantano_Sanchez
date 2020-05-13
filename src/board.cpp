#include "core_simulation.h"
#include "mydevices.h"

int main(){

  // creation d'une board
  Board esp8266;
  // achat des senseurs et actionneurs
  LCD LCDPits;
  TPMS PresSensor1(10,1,1);
  TPMS PresSensor2(10,1,2);
  TPMS PresSensor3(10,1,3);
  TPMS PresSensor4(10,1,4);
  EngineTemperatureSensor TempSensor1(10,1);
  
  
  // branchement des capteurs actionneurs
  esp8266.i2c(1,LCDPits);
  esp8266.pin(1,TempSensor1);
  esp8266.pin(4,PresSensor1);
  esp8266.pin(5,PresSensor2);
  esp8266.pin(6,PresSensor3);
  esp8266.pin(7,PresSensor4);
  
  // allumage de la carte
  esp8266.run();
  return 0;

}


