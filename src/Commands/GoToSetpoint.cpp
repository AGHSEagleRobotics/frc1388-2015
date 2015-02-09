#include "GoToSetpoint.h"
#define SCALING_FACTOR 0.3
#define MAX_POWER 0.75
#define THRESHOLD 0.1

GoToSetpoint::GoToSetpoint(float setpointHeight){
	setpoint = setpointHeight;
}

void GoToSetpoint::goToSetpoint(){
	float currentPosition = RobotMap::elevatorElevatorTalon->GetEncPosition();
	float errorTerm = setpoint - currentPosition;

	while(fabs(errorTerm) > THRESHOLD){
		currentPosition = RobotMap::elevatorElevatorTalon->GetEncPosition();
		errorTerm = setpoint - currentPosition;
		float signedMaxPower = Robot::signOf(errorTerm) * MAX_POWER;
		float power = errorTerm * SCALING_FACTOR;

		if(fabs(power) > MAX_POWER){
			power = signedMaxPower;
		}
		RobotMap::elevatorElevatorTalon->Set(power);
	}
}
