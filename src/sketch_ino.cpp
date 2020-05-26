#include <unistd.h>
#include <fstream>
#include "core_simulation.h"

int wheelPressure[4];
int engineTemp;
int wheelTemp[4];
int speed;
int rpm;
int fuel;

void readSim(){

  ifstream readFile("Sim/Overheat.txt");
  string line;

  static int nline = 0;
  int contador = 0;
  int i = 0;
  string values[12];

  while(getline(readFile,line)) {

    if(nline == contador) {
      
      string delimiter = " ";
      size_t pos = 0;
      string value;

      while ((pos = line.find(delimiter)) != std::string::npos) {

          value = line.substr(0, pos);
          values[i] = value;
          line.erase(0,pos + delimiter.length());
          i++;

      }

      values[i] = line;

    }

    contador++;
  }

  nline++;

  engineTemp = stoi(values[0]);
  speed = stoi(values[1]);
  rpm = stoi(values[2]);
  fuel = stoi(values[3]);
  wheelPressure[0] = stoi(values[4]);
  wheelPressure[1] = stoi(values[5]);
  wheelPressure[2] = stoi(values[6]);
  wheelPressure[3] = stoi(values[7]);
  wheelTemp[0] = stoi(values[8]);
  wheelTemp[1] = stoi(values[9]);
  wheelTemp[2] = stoi(values[10]);
  wheelTemp[3] = stoi(values[11]);

}

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
  pinMode(13,INPUT);
  pinMode(14,INPUT);
  pinMode(15,INPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  digitalWrite(16,LOW);
  digitalWrite(17,LOW);

}

// la boucle de controle arduino
void Board::loop(){
  char buf[100];
  char war[100];
  char tr[100];
  static int val;
  static int R;
  static int G;
  static int B;
  static int counter = 0;

  switch (counter) {

    case 0:

      readSim();
      val = analogRead(1);
      sprintf(buf,"Engine temperature %d",val);
      //Serial.println(buf);
      bus.write(1,buf,100);
      break;

    case 1:

      if (val > 120) {

        digitalWrite(16,HIGH);
        sprintf(war,"Overheated engine %d",val);
        bus.write(2,war,100);

      } else {

        digitalWrite(16,LOW);

      };
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
      break;

    case 7:

      if (val < 15) {

        digitalWrite(17,HIGH);
        sprintf(war,"Low fuel %d%%",val);
        bus.write(2,war,100);

      } else {

        digitalWrite(17,LOW);

      };
      break;

    case 8:

      val = analogRead(5);
      sprintf(buf,"Pressure Wheel 1 %d",val);
      //Serial.println(buf);
      bus.write(1,buf,100);
      break;

    case 9:

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
      break;

    case 11:

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
      break;

    case 13:

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
      break;

    case 15:

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
      break;

    case 17:

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
      break;

    case 19:

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
      break;

    case 21:

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
      break;

    case 23:

      if (val > 180) {

        sprintf(war,"High temperature in wheel 4 %d",val);
        bus.write(2,war,100);

      }
      break;

    case 24:

      R = analogRead(13);
      G = analogRead(14);
      B = analogRead(15);
      sprintf(tr,"Onboard camera %d %d %d",R,G,B);
      bus.write(3,tr,100);
      break;
    
    default:

      break;

  };

  if (counter == 25) counter = 0;
  else counter++;

  sleep(1);
  
};

