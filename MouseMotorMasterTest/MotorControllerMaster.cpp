#include "MotorControllerMaster.h"

void MotorControllerMaster::begin(){
}



void MotorControllerMaster::goVelocity(int forwardVelocity, int ccwVelocity){
	byte send[5];
	send[0] = COMMAND_GOVELOCITY;
	send[1] = forwardVelocity;
	send[2] = forwardVelocity >> 8;
	send[3] = ccwVelocity;
	send[4] = ccwVelocity >> 8;
	Wire.beginTransmission(MOTOR_CONTROLLER_ADDRESS);
	Wire.write(send,5);
	Wire.endTransmission();
}

void MotorControllerMaster::brake(){
	byte send[1];
	send[0] = COMMAND_BRAKE;
	Wire.beginTransmission(MOTOR_CONTROLLER_ADDRESS);
	Wire.write(send,1);
	Wire.endTransmission();	
}

void MotorControllerMaster::coast(){
	byte send[1];
	send[0] = COMMAND_COAST;
	Wire.beginTransmission(MOTOR_CONTROLLER_ADDRESS);
	Wire.write(send,1);
	Wire.endTransmission();	
}

void MotorControllerMaster::getEncoder(long* fwd, long* ccw){
	int32_t remotefwd;
	int32_t remoteccw;
	Wire.beginTransmission(MOTOR_CONTROLLER_ADDRESS);
	Wire.write(COMMAND_REPORTENCODER);
	Wire.endTransmission();	
	Wire.requestFrom(MOTOR_CONTROLLER_ADDRESS, 8);
	remotefwd = Wire.read();
	remotefwd |= Wire.read() << 8;
	remotefwd |= Wire.read() << 16;
	remotefwd |= Wire.read() << 24;
	remoteccw = Wire.read();
	remoteccw |= Wire.read() << 8;
	remoteccw |= Wire.read() << 16;
	remoteccw |= Wire.read() << 24;	
	*fwd = remotefwd;
	*ccw = remoteccw;
}

byte MotorControllerMaster::isStandby(){
	byte isStandby;
	Wire.beginTransmission(MOTOR_CONTROLLER_ADDRESS);
	Wire.write(COMMAND_REPORTSTANDBY);
	Wire.endTransmission();	
	Wire.requestFrom(MOTOR_CONTROLLER_ADDRESS, 1);
	isStandby = Wire.read();
	return isStandby;
}