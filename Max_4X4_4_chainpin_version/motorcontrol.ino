#include "MeccaBrain.h"

uint8_t wheelpin1 = 4;
uint8_t wheelpin2 = 16;
uint8_t wheelpin3 = 17;
uint8_t wheelpin4 = 5;

MeccaBrain chain1(wheelpin1);
MeccaBrain chain2(wheelpin2);
MeccaBrain chain3(wheelpin3);
MeccaBrain chain4(wheelpin4);

const uint8_t forward = 0x2F;
const uint8_t back = 0x3F;
const uint8_t stop = 0x30;

uint8_t LF_Motor=0; 
const int RF_Motor=0; 
const int RR_Motor=0;
const int LR_Motor=0; 

void setupmotor(){
  lights(Green);
for (int i = 0; i < 10; i++)
  {  chain1.communicate();
     chain2.communicate();
     chain3.communicate();
     chain4.communicate();
  }
}

void GO_North(){
     chain1.wheel(LF_Motor,back);
     chain2.wheel(RF_Motor,forward);
     chain3.wheel(RR_Motor,forward);
     chain4.wheel(LR_Motor,back);
     chain1.communicate();//delayMicroseconds(comdelay);
     chain2.communicate();//delayMicroseconds(comdelay);
     chain3.communicate();//delayMicroseconds(comdelay);
     chain4.communicate();//
     delayMicroseconds(comdelay);
     Serial.println("North");
}    
     
void GO_South(){
     chain1.wheel(LF_Motor,forward);
     chain2.wheel(RF_Motor,back);
     chain3.wheel(RR_Motor,back);
     chain4.wheel(LR_Motor,forward);
for (int i = 0; i < 4; i++)
{
     chain1.communicate();//delayMicroseconds(comdelay);//Serial.println("chain 1");
     chain2.communicate();//delayMicroseconds(comdelay);//Serial.println("chain 2");
     chain3.communicate();//delayMicroseconds(comdelay);//Serial.println("chain 3");
     chain4.communicate();
     delayMicroseconds(comdelay);//Serial.println("chain 4");
     
}
Serial.println("south");
}

void GO_NE(){
     chain1.wheel(LF_Motor,stop);
     chain2.wheel(RF_Motor,forward);
     chain3.wheel(RR_Motor,stop);
     chain4.wheel(LR_Motor,back);
     chain1.communicate();delayMicroseconds(comdelay);
     chain2.communicate();delayMicroseconds(comdelay);
     chain3.communicate();delayMicroseconds(comdelay);
     chain4.communicate();delayMicroseconds(comdelay);
     Serial.println("NE");
}
     
void GO_NW(){
     chain1.wheel(LF_Motor,back);
     chain2.wheel(RF_Motor,stop);
     chain3.wheel(RR_Motor,forward);
     chain4.wheel(LR_Motor,stop);
     chain1.communicate();delayMicroseconds(comdelay);
     chain2.communicate();delayMicroseconds(comdelay);
     chain3.communicate();delayMicroseconds(comdelay);
     chain4.communicate();delayMicroseconds(comdelay);
     Serial.println("Nw");
}

void GO_West(){
     chain1.wheel(LF_Motor,back);
     chain2.wheel(RF_Motor,back);
     chain3.wheel(RR_Motor,forward);
     chain4.wheel(LR_Motor,forward);
     chain1.communicate();delayMicroseconds(comdelay);
     chain2.communicate();delayMicroseconds(comdelay);
     chain3.communicate();delayMicroseconds(comdelay);
     chain4.communicate();delayMicroseconds(comdelay);
     Serial.println("West");
}
     
void GO_East(){
     chain1.wheel(LF_Motor,forward);
     chain2.wheel(RF_Motor,forward);
     chain3.wheel(RR_Motor,back);
     chain4.wheel(LR_Motor,back);
     chain1.communicate();delayMicroseconds(comdelay);
     chain2.communicate();delayMicroseconds(comdelay);
     chain3.communicate();delayMicroseconds(comdelay);
     chain4.communicate();delayMicroseconds(comdelay);
     Serial.println("East");
}

void GO_SE(){
     chain1.wheel(LF_Motor,forward);
     chain2.wheel(RF_Motor,stop);
     chain3.wheel(RR_Motor,back);
     chain4.wheel(LR_Motor,stop);
     chain1.communicate();//delayMicroseconds(comdelay);
     chain2.communicate();//delayMicroseconds(comdelay);
     chain3.communicate();//delayMicroseconds(comdelay);
     chain4.communicate();
     delayMicroseconds(comdelay);
     Serial.println("SE");
}
     
void GO_SW(){
     chain1.wheel(LF_Motor,stop);
     chain2.wheel(RF_Motor,back);
     chain3.wheel(RR_Motor,stop);
     chain4.wheel(LR_Motor,forward);
     chain1.communicate();delayMicroseconds(comdelay);
     chain2.communicate();delayMicroseconds(comdelay);
     chain3.communicate();delayMicroseconds(comdelay);
     chain4.communicate();delayMicroseconds(comdelay);
     Serial.println("SW");
}
     
void GO_Stop(){
     chain1.wheel(LF_Motor,stop);
     chain2.wheel(RF_Motor,stop);
     chain3.wheel(RR_Motor,stop);
     chain4.wheel(LR_Motor,stop);
     chain1.communicate();delayMicroseconds(comdelay);
     chain2.communicate();delayMicroseconds(comdelay);
     chain3.communicate();delayMicroseconds(comdelay);
     chain4.communicate();delayMicroseconds(comdelay);
     Serial.println("Stop");
}

void spin_Right(){

     chain1.wheel(LF_Motor,back);
     chain2.wheel(RF_Motor,back);
     chain3.wheel(RR_Motor,back);
     chain4.wheel(LR_Motor,back);
     chain1.communicate();//delayMicroseconds(comdelay);
     chain2.communicate();//delayMicroseconds(comdelay);
     chain3.communicate();//delayMicroseconds(comdelay);
     chain4.communicate();//
     delayMicroseconds(comdelay);
     Serial.println("spin right");
}
     
void spin_Left(){

    chain1.wheel(LF_Motor,forward);
    chain2.wheel(RF_Motor,forward);  // actually back but flipped
    chain3.wheel(RR_Motor,forward);  // actually back but flipped
    chain4.wheel(LR_Motor,forward);
    chain1.communicate();delayMicroseconds(comdelay);
    chain2.communicate();delayMicroseconds(comdelay);
    chain3.communicate();delayMicroseconds(comdelay);
    chain4.communicate();delayMicroseconds(comdelay);
    Serial.println("spin left");
}


void lights(uint8_t Colour) {
     chain1.wheel(LF_Motor,Colour);
     chain2.wheel(RF_Motor,Colour);
     chain3.wheel(RR_Motor,Colour);
     chain4.wheel(LR_Motor,Colour);
     chain1.communicate();//delayMicroseconds(comdelay);
     chain2.communicate();//delayMicroseconds(comdelay);
     chain3.communicate();//delayMicroseconds(comdelay);
     chain4.communicate();
     delayMicroseconds(comdelay);
}

