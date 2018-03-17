/* 6th December 2013 - By Kyle Fieldus

This example sketch is designed to show the inputs and outputs of the Funduino Joystick Shield V1.A
The shield this sketch was developed with was provded by ICStation http://www.icstation.com/
*/

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(11, 10); // RX | TX

int up_button = 2;
int down_button = 4;
int left_button = 5;
int right_button = 3;
int start_button = 6;
int select_button = 7;
int analog_button = 8;
int x_axis = A2;
int y_axis = A1;
int buttons[] = {up_button, down_button, left_button, right_button, start_button, select_button, analog_button};


void setup() {
  for (int i; i < 7; i++)
  {
   pinMode(buttons[i], INPUT);
   digitalWrite(buttons[i], HIGH);
  }
  BTSerial.begin(9600);  // HC-05 default speed in AT command more
  //Serial.begin(9600);
}

void loop() {
  unsigned int statusX = 0,statusY = 0;

  //Serial.print(analogRead(x_axis));Serial.print(" ");
  //Serial.println(analogRead(y_axis));
  //delay(100);
  
  statusX = map(analogRead(x_axis), 0, 700, 0, 2);
  statusY = map(analogRead(y_axis), 0, 700, 0, 2);

  if(statusX == 0)BTSerial.print('R');
  if(statusX == 2)BTSerial.print('L');

  if(statusY == 0)BTSerial.print('B');
  if(statusY == 2)BTSerial.print('F');

  //Serial.print(statusX);Serial.print(" ");
  //Serial.println(statusY);
  //delay(100);
 }


