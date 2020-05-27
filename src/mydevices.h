#ifndef MYDEVICES_H
#define MYDEVICES_H

#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "core_simulation.h"

extern int wheelPressure[4];
extern int engineTemp;
extern int wheelTemp[4];
extern int speed;
extern int rpm;
extern int fuel;

class Sensor: public Device {

protected:

  int val;
  int alea;

public:

  Sensor();

};

class Actuator: public Device {

protected:

  int state;

public:

  Actuator();

};

// Wheel pressure sensor
class TPMS: public Sensor {

private:

  int wheel;

public:

  TPMS(int d,int a, int w);
  void run();

};

// Screen
class i2cDevice: public Actuator {

private:

  char buf[I2C_BUFFER_SIZE];

public:

  i2cDevice();
  void run();

};

// LEDs
class LED: public Actuator {

public:

  LED(int d);

};

// Temperature LED
class TempLED: public LED {

public:

  TempLED(int d);
  void run();

};

// Fuel LED
class FuelLED: public LED {

public:

  FuelLED(int d);
  void run();

};

class EngineTemperatureSensor: public Sensor {

public:

  EngineTemperatureSensor(int d, int a);
  void run();

};

class Speedometer: public Sensor {

public:

  Speedometer(int d);
  void run();

};

class Tachometer: public Sensor {

public:

  Tachometer(int d);
  void run();

};

class Potentiometer: public Sensor {

public:

  Potentiometer(int d, int a);
  void run();

};

class WheelTemperatureSensor: public Sensor {

private:

  int wheel;

public:

  WheelTemperatureSensor(int d, int a, int w);
  void run();

};

class Image {

  int *RGB;

public:

  Image();
  Image(int *a);
  Image & operator = (const Image & img);
  int getRed();
  int getGreen();
  int getBlue();

};

Image generateImage();

class Camera: public Device {

private:

  Image image;
  char color;

public:

  Camera(int d, char c);
  void run();

};

#endif
