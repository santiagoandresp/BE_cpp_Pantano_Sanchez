#include "core_simulation.h"
#include "mydevices.h"

int main(){

  // creation d'une board
  Board esp8266;
  // achat des senseurs et actionneurs
  i2cDevice LCDPits;
  i2cDevice LCDPilot;
  i2cDevice CamTransmission;
  TPMS presSensor1(10,1,1);
  TPMS presSensor2(10,1,2);
  TPMS presSensor3(10,1,3);
  TPMS presSensor4(10,1,4);
  EngineTemperatureSensor tempSensor1(10,1);
  WheelTemperatureSensor tempSensor2(10,1,1);
  WheelTemperatureSensor tempSensor3(10,1,2);
  WheelTemperatureSensor tempSensor4(10,1,3);
  WheelTemperatureSensor tempSensor5(10,1,4);
  Speedometer speedometer(5);
  Tachometer tachometer(5);
  Potentiometer fuelPotentiometer(10,1);
  Camera cameraR(20,'R');
  Camera cameraG(20,'G');
  Camera cameraB(20,'B');
  TempLED tempLED(5);
  FuelLED fuelLED(5);
  
  // branchement des capteurs actionneurs
  esp8266.i2c(1,LCDPits);
  esp8266.i2c(2,LCDPilot);
  esp8266.i2c(3,CamTransmission);
  esp8266.pin(1,tempSensor1);
  esp8266.pin(2,speedometer);
  esp8266.pin(3,tachometer);
  esp8266.pin(4,fuelPotentiometer);
  esp8266.pin(5,presSensor1);
  esp8266.pin(6,presSensor2);
  esp8266.pin(7,presSensor3);
  esp8266.pin(8,presSensor4);
  esp8266.pin(9,tempSensor2);
  esp8266.pin(10,tempSensor3);
  esp8266.pin(11,tempSensor4);
  esp8266.pin(12,tempSensor5);
  esp8266.pin(13,cameraR);
  esp8266.pin(14,cameraG);
  esp8266.pin(15,cameraB);
  esp8266.pin(16,tempLED);
  esp8266.pin(17,fuelLED);
  
  // allumage de la carte
  esp8266.run();
  return 0;

}


