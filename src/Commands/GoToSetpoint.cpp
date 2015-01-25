#include "GoToSetpoint.h"
#define SCALING_FACTOR 0.3
#define MAX_POWER 0.75
#define THRESHOLD 0.1

GoToSetpoint::GoToSetpoint(float setpointHeight){
	setpoint = setpointHeight;
}

void GoToSetpoint::goToSetpoint(){
	float errorTerm = (setpoint - (RobotMap::elevatorElevatorEncoder->GetDistance()));

	while(fabs(errorTerm) > THRESHOLD){
		float currentHeight = RobotMap::elevatorElevatorEncoder->GetDistance();
		errorTerm = setpoint - currentHeight;
		float signedMaxPower = Robot::signOf(errorTerm) * MAX_POWER;
		float power;

		power = errorTerm * SCALING_FACTOR;

		if(fabs(power) > fabs(MAX_POWER)){
			power = signedMaxPower;
		}
		RobotMap::elevatorElevatorTalon->Set(power);
	}

	return;
}
