#include <unistd.h>
#include <fstream>
#include "core_simulation.h"

// la fonction d'initialisation d'arduino
void Board::setup(){

  // on configure la vitesse de la liaison
  Serial.begin(9600);
// on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
  pinMode(1,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);

}

// la boucle de controle arduino
void Board::loop(){
  char buf[100];
  int val;
  static int counter = 0;

  switch (counter) {
    case 0:

      val = analogRead(4);
      sprintf(buf,"Pressure Wheel 1 %d",val);
      bus.write(1,buf,100);
      break;

    case 2:

      val = analogRead(5);
      sprintf(buf,"Pressure Wheel 2 %d",val);
      bus.write(1,buf,100);
      break;

    case 4:

      val = analogRead(6);
      sprintf(buf,"Pressure Wheel 3 %d",val);
      bus.write(1,buf,100);
      break;

    case 6:

      val = analogRead(7);
      sprintf(buf,"Pressure Wheel 4 %d",val);
      bus.write(1,buf,100);
      break;

    case 8:

      val = analogRead(1);
      sprintf(buf,"Engine temperature %d",val);
      bus.write(1,buf,100);
    
    default:

      break;

  };

  if (counter == 10) counter = 0;
  else counter++;

  sleep(1);
  
};

