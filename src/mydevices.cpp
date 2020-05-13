
#include "mydevices.h"

using namespace std;

int lum_environment = 200;

//classe AnalogSensorTemperature
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
I2CActuatorScreen::I2CActuatorScreen ():Device(){
  }

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

}
