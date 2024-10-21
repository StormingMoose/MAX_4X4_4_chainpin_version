/*
https://github.com/robotscity/meccanoid_arduino_demo/blob/master/demo_meccanoids.ino

https://github.com/MrDreamBot/MeccaChannel/tree/master

thanks to Rui and his crew at RandomNerdsTutorials.com could not be done by me without the examples presented there.

*/

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Arduino_JSON.h>
#include "index.h"  //Web page header file

String message;
boolean movingswitch = false;
uint8_t comdelay = 750000;
const uint8_t Red = 0xE1;
const uint8_t Green = 0xE2;
const uint8_t Yellow = 0E3;
const uint8_t Blue = 0xE4;
const uint8_t Purple = 0xE5;
const uint8_t LightBlue = 0xE6;
const uint8_t White = 0xE7;



void setup() 
{
  Serial.begin(115200);
  Serial.println("\n\n");
  Serial.println("Booting Sketch...");

  setupmotor();
//    setupservo(); 
  setuplights();
  setupwifi();
}

void loop()
{ //All the action is because of the message received in wifistuff, the websocket event handling
//  Here the lights are changed for direction changes, I leave it as an exercise to change the colour of the buttons
//  on the cellphone to match using the appropriate websocket routine.

    while (message.endsWith("GET /A")){  if (movingswitch == false){lights(Yellow);}; GO_NW();movingswitch = true;} // because of the script1.js toggle() function containing   websocket.send(x);
    while (message.endsWith("GET /B")){  if (movingswitch == false){lights(Green);};GO_North(); movingswitch = true;}
    while (message.endsWith("GET /C")){  if (movingswitch == false){lights(Yellow);};GO_NE();;movingswitch = true;}
    while (message.endsWith("GET /D")){  if (movingswitch == false){lights(Purple);};GO_West();;movingswitch = true;}
    while (message.endsWith("GET /E")){  if (movingswitch == false){lights(Purple);};GO_East();;movingswitch = true;}
    while (message.endsWith("GET /F")){  if (movingswitch == false){lights(Yellow);};GO_SW();;movingswitch = true;}
    while (message.endsWith("GET /G")){  if (movingswitch == false){lights(Green);};GO_South();;movingswitch = true;}
    while (message.endsWith("GET /H")){  if (movingswitch == false){lights(Yellow);};GO_SE();;movingswitch = true;}
    while (message.endsWith("GET /I")){  if (movingswitch == false){lights(White);};spin_Left();;movingswitch = true;}
    while (message.endsWith("GET /J")){  if (movingswitch == false){lights(White);};spin_Right();;movingswitch = true;}
    while (message.endsWith("GET /off")){  if(movingswitch == true){  lights(Red); GO_Stop(); movingswitch = false;} }
}

