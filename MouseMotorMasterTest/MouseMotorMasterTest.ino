#include "MotorControllerMaster.h"
#include "Wire.h"

MotorControllerMaster mc;

void setup(){
	Wire.begin();
	delay(200);
	mc.goVelocity(500,500);
}

void loop(){

}