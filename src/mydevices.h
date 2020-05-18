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
class LCD: public Actuator {

private:

  char buf[I2C_BUFFER_SIZE];

public:

  LCD();
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

/*// exemple de capteur analogique de temperature, ne pas oublier d'heriter de Device
class AnalogSensorTemperature: public Device {
private:
  // fait osciller la valeur du cpateur de 1
  int alea;
  // valeur de temperature mesuree
  int val;
  // temps entre 2 prises de valeurs
  int temps;
  
public:
  //constructeur ne pas oublier d'initialiser la classe mere
  AnalogSensorTemperature(int d,int  t);
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};

// exemple d'actionneur digital : une led, ne pas oublier d'heriter de Device
class DigitalActuatorLED: public Device {
protected:
  // etat de la LED
  int state;
  // temps entre 2 affichage de l etat de la led
  int temps;
  
public:
  // initialisation du temps de rafraichiisement
  DigitalActuatorLED(int t);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();
};

class IntelligentDigitalActuatorLED: public DigitalActuatorLED {
  
public:

  // initialisation du temps de rafraichiisement
  IntelligentDigitalActuatorLED(int t);
  // thread representant l'actionneur et permettant de fonctionner independamment de la board
  virtual void run();

};

// exemple d'actionneur sur le bus I2C permettant d'echanger des tableaux de caracteres : un ecran, ne pas oublier d'heriter de Device
class I2CActuatorScreen : public Device {
protected:
    // memorise l'affichage de l'ecran
  char buf[I2C_BUFFER_SIZE];
  
public:
  // constructeur
  I2CActuatorScreen ();
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();
};

// Capteur de luminosité

class AnalogSensorLuminosity : public Device {

private:
  // fait osciller la valeur du cpateur de 5
  int alea;
  // valeur de luminosité mesuree
  int val;
  // temps entre 2 prises de valeurs
  int temps;
  
public:
  //constructeur ne pas oublier d'initialiser la classe mere
  AnalogSensorLuminosity(int d,int  l);
  // thread representant le capteur et permettant de fonctionner independamment de la board
  virtual void run();

};

class ExternalDigitalSensorButton : public Device {

private:

  bool state;
  int temps;

public:

  ExternalDigitalSensorButton(int d,bool s);
  virtual void run();

};*/

#endif
