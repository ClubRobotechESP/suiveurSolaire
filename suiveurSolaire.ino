
#include <Servo.h>

int pos =0;
int positionInit = 0;
int positionFinal = 180;
int p = 360;
Servo myservo;
const int sensor1=A0;
const int sensor2=A1;
int n=1;

int periode=20000;// période entre chaque début d'impulsion en microsecondes

int pinServo=9; // variable pour le pin connecté à la commande du servo
int angle =0;

void setup() {
  Serial.begin(9600);
  pinMode(pinServo,OUTPUT);// on prépare le pin en mode OUTPUT

  digitalWrite(pinServo,LOW); // on l'initialise à l'état bas
   Serial.begin(9600);
 
}

void loop() {
  int val1 = analogRead(sensor1);
  int val2 = analogRead(sensor2);
  Serial.print(val1);
  Serial.print(" ");
  Serial.println(val2);
  if(n%2==0)
  avancer10Pas();
  //else reculer10Pas();
  n++;
 // Serial.print(" ");
  //Serial.println(p);
  //avancer10Pas();
  delay(1000);
  
  
}


void avancer10Pas(){
  Serial.println("avancer");
   for(pos = 0; pos <180; pos += 90)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
       myservo.write(pos); 
    Serial.println(myservo.read());// tell servo to go to position in variable 'pos'
    //delay(); 
   // waits 15ms for the servo to reach the position
  } 
  
}

void reculer10Pas(){
  Serial.println("Reculer");
    for(pos = 180; pos >90; pos -= 30)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
       myservo.write(pos); 
    Serial.println(myservo.read());// tell servo to go to position in variable 'pos'
  delay(10); 
   // waits 15ms for the servo to reach the position
  } 
}

