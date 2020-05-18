#include "mydevices.h"

using namespace std;

int wheelPressure[4] = {32,32,10,31};
int engineTemp = 125;
int wheelTemp[4] = {110,108,125,121};
int speed = 250;
int rpm = 4500;
int fuel = 90;

Sensor::Sensor(): Device() {};

Actuator::Actuator(): Device() {};

TPMS::TPMS(int d,int a, int w): Sensor() {

  temps = d;
  alea = a;
  wheel = w;
  val = wheelPressure[wheel-1];

};

void TPMS::run() {

  while (1) {

    val = wheelPressure[wheel-1];
    alea = 1 - alea;
    if(ptrmem != NULL) *ptrmem = val + alea;
    sleep(temps);

  };

};

LCD::LCD(): Actuator() {};

void LCD::run() {

    while(1){

      if ( (i2cbus!=NULL)&&!(i2cbus->isEmptyRegister(i2caddr))){

        Device::i2cbus->requestFrom(i2caddr, buf, I2C_BUFFER_SIZE);
        if (i2caddr == 1) cout << "---Pits : "<< buf << endl;
        else if (i2caddr == 2) cout << "---Pilot : "<< buf << endl;

      }

      sleep(1);

    }

}

EngineTemperatureSensor::EngineTemperatureSensor(int d, int a): Sensor() {

  temps = d;
  alea = a;
  val = engineTemp;

};

void EngineTemperatureSensor::run() {

  while (1) {

    val = engineTemp;
    alea = 1 - alea;
    if(ptrmem != NULL) *ptrmem = val + alea;
    sleep(temps);

  }

}

Speedometer::Speedometer(int d): Sensor() {

  temps = d;
  alea = 0;
  val = speed;

};

void Speedometer::run() {

  while (1) {

    val = speed;
    if(ptrmem != NULL) *ptrmem = val;
    sleep(temps);

  }

}

Tachometer::Tachometer(int d): Sensor() {

  temps = d;
  alea = 0;
  val = rpm;

};

void Tachometer::run() {

  while (1) {

    val = rpm;
    if(ptrmem != NULL) *ptrmem = val;
    sleep(temps);

  }

}

Potentiometer::Potentiometer(int d, int a): Sensor() {

  temps = d;
  alea = a;
  val = fuel;

};

void Potentiometer::run() {

  while (1) {

    val = fuel;
    alea = 1 - alea;
    if(ptrmem != NULL) *ptrmem = val + alea;
    sleep(temps);

  }

}

WheelTemperatureSensor::WheelTemperatureSensor(int d, int a, int w): Sensor() {

  temps = d;
  alea = a;
  wheel = w;
  val = wheelTemp[wheel-1];

};

void WheelTemperatureSensor::run() {

  while (1) {

    val = wheelTemp[wheel-1];
    alea = 1 - alea;
    if(ptrmem != NULL) *ptrmem = val + alea;
    sleep(temps);

  }

}

/*//classe AnalogSensorTemperature
AnalogSensorTemperature::AnalogSensorTemperature(int d,int  t):Device(),val(t),temps(d){

  alea = 1;

}

void AnalogSensorTemperature::run(){
  while(1){
    val = TEMP;
    alea=1-alea;
    if(ptrmem != NULL)
      *ptrmem = val + alea;
    sleep(temps);
  }
}

//classe DigitalActuatorLED
DigitalActuatorLED::DigitalActuatorLED(int t): Device(),state(LOW),temps(t){
}

void DigitalActuatorLED::run(){
  while(1){
    if(ptrmem != NULL)
      state = *ptrmem;
    if (state==LOW)
      cout << "LED: OFF\n";
    else
      cout << "LED: ON\n";
    sleep(temps);
    }
}

//classe IntelligentDigitalActuatorLED
IntelligentDigitalActuatorLED::IntelligentDigitalActuatorLED(int t): DigitalActuatorLED(t){
}

void IntelligentDigitalActuatorLED::run(){

  while (1) {

    if(ptrmem != NULL)
      state = *ptrmem;
    
    if (state == LOW) {

      cout << "smartLED: OFF\n";
      lum_environment = 200;

    } else {

      cout << "smartLED: ON\n";
      lum_environment = 250;

    }

    sleep(temps);

    }

}

// classe I2CActuatorScreen
I2CActuatorScreen::I2CActuatorScreen ():Device(){};

void I2CActuatorScreen::run(){
  while(1){
    if ( (i2cbus!=NULL)&&!(i2cbus->isEmptyRegister(i2caddr))){
      Device::i2cbus->requestFrom(i2caddr, buf, I2C_BUFFER_SIZE);
      cout << "---screen :"<< buf << endl;
    }
    sleep(1);
    }
}


AnalogSensorLuminosity::AnalogSensorLuminosity(int d,int  l): Device(),val(l),temps(d){

  alea = 5;

}

void AnalogSensorLuminosity::run() {

  while(1){

    val = lum_environment;
    alea = 5 - alea;
    if(ptrmem != NULL)
      *ptrmem = val + alea;
    sleep(temps);

  }

}

// Classe ExternalDigitalSensorButton

ExternalDigitalSensorButton::ExternalDigitalSensorButton(int d,bool s): Device(), state(s), temps(d) {}

void ExternalDigitalSensorButton::run(){

  if (ifstream("on.txt")) state = true;
  else state = false;

  if(ptrmem != NULL) *ptrmem = int(state);

  sleep(temps);

}*/
