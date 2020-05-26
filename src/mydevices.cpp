#include "mydevices.h"

using namespace std;

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

i2cDevice::i2cDevice(): Actuator() {};

void i2cDevice::run() {

    while(1){

      if ( (i2cbus!=NULL)&&!(i2cbus->isEmptyRegister(i2caddr))){

        Device::i2cbus->requestFrom(i2caddr, buf, I2C_BUFFER_SIZE);
        if (i2caddr == 1) cout << "---Pits : "<< buf << endl;
        else if (i2caddr == 2) cout << "---Pilot : "<< buf << endl;
        else if (i2caddr == 3) cout << "---TV Transmission : " << buf << endl;

      };

      sleep(1);

    };

};

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

  };

};

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

  };

};

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

  };

};

Potentiometer::Potentiometer(int d, int a): Sensor() {

  temps = d;
  alea = a;
  val = fuel;

};

void Potentiometer::run() {

  while (1) {

    val = fuel;
    if (val == 100) alea = 0;
    else alea = 1 - alea;
    if(ptrmem != NULL) *ptrmem = val + alea;
    sleep(temps);

  };

};

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

Image::Image() {

  RGB = NULL;

}

Image::Image(int *a) {

  RGB = new int[3];
  for(int i=0;i<3;i++) RGB[i] = a[i];

};

Image & Image::operator = (const Image & img){

  if(this!= & img){

		delete[] RGB;
		RGB = new int[3];
		for(int i=0;i<3;i++) RGB[i] = img.RGB[i];

	};
	return (*this);

};

int Image::getRed() {

  return RGB[0];

};

int Image::getGreen() {

  return RGB[1];

};

int Image::getBlue() {

  return RGB[2];

};

Image generateImage() {

  int R = rand() % 255;
  int G = rand() % 255;
  int B = rand() % 255;
  int photo[3] = {R,G,B};
  Image img(photo);
  return img;

};

Camera::Camera(int d, char C): Device() {

  temps = d;
  color = C;

};

void Camera::run() {

  while (1) {
    
    image = generateImage();

    if(ptrmem != NULL) {

      if (color == 'R') *ptrmem = image.getRed();
      if (color == 'G') *ptrmem = image.getGreen();
      if (color == 'B') *ptrmem = image.getBlue();

    };

    sleep(temps);

  };

};
