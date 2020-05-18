#include <unistd.h>
#include <fstream>
#include "core_simulation.h"

// la fonction d'initialisation d'arduino
void Board::setup(){

  // on configure la vitesse de la liaison
  Serial.begin(9600);
// on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);

}

// la boucle de controle arduino
void Board::loop(){
  char buf[100];
  char war[100];
  int val;
  static int counter = 0;

  switch (counter) {
    case 0:

      val = analogRead(1);
      sprintf(buf,"Engine temperature %d",val);
      //Serial.println(buf);
      bus.write(1,buf,100);
      if (val > 120) {

        sprintf(war,"Overheated engine %d",val);
        bus.write(2,war,100);

      }
      break;

    case 2:

      val = analogRead(2);
      sprintf(buf,"Speed %d",val);
      //Serial.println(buf);
      bus.write(1,buf,100);
      break;

    case 4:

      val = analogRead(3);
      sprintf(buf,"RPMs %d",val);
      //Serial.println(buf);
      bus.write(1,buf,100);
      break;

    case 6:

      val = analogRead(4);
      sprintf(buf,"Fuel %d%%",val);
      //Serial.println(buf);
      bus.write(1,buf,100);
      if (val < 15) {

        sprintf(war,"Low fuel %d%%",val);
        bus.write(2,war,100);

      }
      break;

    case 8:

      val = analogRead(5);
      sprintf(buf,"Pressure Wheel 1 %d",val);
      //Serial.println(buf);
      bus.write(1,buf,100);
      if (val < 25) {

        sprintf(war,"Low pressure in wheel 1 %d",val);
        bus.write(2,war,100);

      }
      break;

    case 10:

      val = analogRead(6);
      sprintf(buf,"Pressure Wheel 2 %d",val);
      //Serial.println(buf);
      bus.write(1,buf,100);
      if (val < 25) {

        sprintf(war,"Low pressure in wheel 2 %d",val);
        bus.write(2,war,100);

      }
      break;

    case 12:

      val = analogRead(7);
      sprintf(buf,"Pressure Wheel 3 %d",val);
      //Serial.println(buf);
      bus.write(1,buf,100);
      if (val < 25) {

        sprintf(war,"Low pressure in wheel 3 %d",val);
        bus.write(2,war,100);

      }
      break;

    case 14:

      val = analogRead(8);
      sprintf(buf,"Pressure Wheel 4 %d",val);
      //Serial.println(buf);
      bus.write(1,buf,100);
      if (val < 25) {

        sprintf(war,"Low pressure in wheel 4 %d",val);
        bus.write(2,war,100);

      }
      break;

    case 16:

      val = analogRead(9);
      sprintf(buf,"Temperature Wheel 1 %d",val);
      //Serial.println(buf);
      bus.write(1,buf,100);
      if (val > 180) {

        sprintf(war,"High temperature in wheel 1 %d",val);
        bus.write(2,war,100);

      }
      break;

    case 18:

      val = analogRead(10);
      sprintf(buf,"Temperature Wheel 2 %d",val);
      //Serial.println(buf);
      bus.write(1,buf,100);
      if (val > 180) {

        sprintf(war,"High temperature in wheel 2 %d",val);
        bus.write(2,war,100);

      }
      break;

    case 20:

      val = analogRead(11);
      sprintf(buf,"Temperature Wheel 3 %d",val);
      //Serial.println(buf);
      bus.write(1,buf,100);
      if (val > 180) {

        sprintf(war,"High temperature in wheel 3 %d",val);
        bus.write(2,war,100);

      }
      break;

    case 22:

      val = analogRead(12);
      sprintf(buf,"Temperature Wheel 4 %d",val);
      //Serial.println(buf);
      bus.write(1,buf,100);
      if (val > 180) {

        sprintf(war,"High temperature in wheel 4 %d",val);
        bus.write(2,war,100);

      }
      break;
    
    default:

      break;

  };

  if (counter == 24) counter = 0;
  else counter++;

  sleep(1);
  
};

