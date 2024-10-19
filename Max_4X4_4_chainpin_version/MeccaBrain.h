
/*
       LEGAL NOTICE:
      Meccano™, MeccaBrain™, MeccanoTech™ and Meccanoid™ are trademarks of Meccano.  All rights reserved.     
      The information contained in this document is Proprietary to Spin Master Ltd.   
      This information should not be used in the creation and sale of any commercial product.”
*/
#ifndef MeccaBrain_h
#define MeccaBrain_h

#include "Arduino.h"

class MeccaBrain{
	public:
		MeccaBrain(int pin);
		
		uint8_t outputByteInfo(int num);
		uint8_t inputByteInfo();
		uint8_t inputBytesInfo(int servoNum);
		uint8_t checkSumByteInfo();
		uint8_t servoPositionsInfo(int servoNum);
		char moduleTypeInfo(int num);
		uint8_t moduleNumInfo();
		uint8_t getLEDorder();
		uint8_t getLEDbyte1();
		uint8_t getLEDbyte2();	

		void setLEDColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t fadetime);
		void setServoColor(int servoNum, uint8_t color);
		void setServoPosition(int servoNum, uint8_t pos);
		void setServotoLIM(int servoNum);
		uint8_t getServoPosition(int servoNum);
    void wheel(int wheelNum, uint8_t direction);            //Storming Moose 2024
		
		void communicate();		
		void sendByte(uint8_t servoData);
		uint8_t receiveByte();
		uint8_t calculateCheckSum(uint8_t Data1, uint8_t Data2, uint8_t Data3, uint8_t Data4);
		
	private:
		int _pmwPin;
		int servoNumber;
		int inputCounter = 0;
		int moduleNum = 0;
		int printModNum = 0;
		int ledOrder = 0;
		int bitDelay = 417;
		int receiveArray[8];
		int servo1Positions[25];                // Storming moose 2024 added 25's to make it work
		int servo2Positions[25];
		int servo3Positions[25];
		int servo4Positions[25];
	
		
		uint8_t inputByte;
		uint8_t checkSum;
		uint8_t servoPos;
		uint8_t LEDoutputByte1 = 0x00;
		uint8_t LEDoutputByte2 = 0x47;
		uint8_t header = 0xFF;
		uint8_t outputByte[4];
		uint8_t printOutputByte[4];
		
		char moduleType[4];
		uint8_t inputBytes[];                        // Storming Moose 2024 moved to bottom so it would compile
		
};

#endif