#ifndef MotorControllerMaster_h
#define MotorControllerMaster_h
#include "Arduino.h"
#include "Wire.h"
#include "MotorControllerDefinitions.h"

class MotorControllerMaster{
public:
	void begin();
	void goVelocity(int left, int right);	
	void brake();
	void coast();
	void getEncoder(long* left, long* right);
	byte isStandby();
};

#endif