#include <Servo.h>
Servo myservo;
int val;    // variable to read the value from the analog pin
bool fire = false ;
int pol = 1;
bool n = false;
void setup() {
  pinMode(A7, INPUT);
  analogWrite(A7, LOW);
  Serial.begin(9600);   // подключаем монитор порта
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(90);
  delay(15);
}

void loop() {
  // считываем данные с датчика и выводим на монитор порта
  int light = analogRead(A7);
  Serial.println(light);
if (light > 600){
  delay(10);
  if (fire == true){
   myservo.write(175);
   //Serial.print("first");
   pol = 1;
    }
 if (fire == false){
   myservo.write(175);
  // Serial.print("second");
   pol = 2;
    }
}
 if (light <= 600){
  delay (10);
  if (pol==2) fire = true;  
  if (pol==1) fire = false;   

  }  
  
}
