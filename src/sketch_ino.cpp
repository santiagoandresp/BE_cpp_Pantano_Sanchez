#include <unistd.h>
#include <fstream>
#include "core_simulation.h"

// la fonction d'initialisation d'arduino
void Board::setup(){

  // on configure la vitesse de la liaison
  Serial.begin(9600);
// on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
  pinMode(1,INPUT);
  pinMode(0,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,INPUT);
  digitalWrite(0,LOW);
  digitalWrite(3,LOW);

}

// la boucle de controle arduino
void Board::loop(){
  char buf[100];
  int val;
  static int cpt=0;
  static int bascule=0;
  int i=0;

  for(i=0;i<10;i++){
    // lecture sur la pin 1 : capteur de temperature
    val = analogRead(1);
    sprintf(buf,"temperature %d",val);
    // Serial.println(buf);

    if (cpt%5 == 0) {

      // tous les 5 fois on affiche sur l ecran la temperature
      sprintf(buf,"%d",val);
      bus.write(1,buf,100);
      sprintf(buf,"%d",val);
      bus.write(1,buf,100);

    }

    val = analogRead(2);
    sprintf(buf,"Luminosity %d",val);
    // Serial.println(buf);

    if ((cpt+1)%5 == 0) {

      // tous les 5 fois on affiche sur l ecran la luminosité
      sprintf(buf,"%d",val);
      bus.write(1,buf,100);
      sprintf(buf,"%d",val);
      bus.write(1,buf,100);

    }

    cpt++;
    sleep(1);

  }

  // on eteint et on allume la LED
  if(bascule) {

    digitalWrite(0,HIGH);

  } else {

    digitalWrite(0,LOW);

  }

  bascule = 1 - bascule;

  val = digitalRead(4);
  if (val == 1) digitalWrite(3,HIGH);
  else digitalWrite(3,LOW);
  
}


