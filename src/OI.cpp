// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Drive.h"
#include "Commands/GoToPickup.h"
#include "Commands/MoveElevator.h"
#include "Commands/MoveGrabbers.h"
#include "Commands/SetElevatorZeroPoint.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	opStick = new Joystick(2);
	
	driveStick = new Joystick(1);
	
     

        // SmartDashboard Buttons
	SmartDashboard::PutData("SetElevatorZeroPoint", new SetElevatorZeroPoint());

	SmartDashboard::PutData("Drive", new Drive());

	SmartDashboard::PutData("MoveGrabbers", new MoveGrabbers());


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

Joystick* OI::getopStick() {
	return opStick;
}

Joystick* OI::getdriveStick() {
	return driveStick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

float OI::getDriveStickX(){
	return (joystickDeadband(driveStick->GetX()));
}

float OI::getDriveStickY(){
	return (joystickDeadband(driveStick->GetY()));
}

float OI::getDriveStickZ(){
	return (joystickDeadband(driveStick->GetZ()));
}

float OI::getOpStickX(){
	return (joystickDeadband(opStick->GetX()));
}

float OI::getOpStickY(){
	return (joystickDeadband(opStick->GetY()));
}

float OI::joystickDeadband(float joystickReturn){
	if(joystickReturn < 0 && joystickReturn > -0.1){
		return 0.0;
	}else if(joystickReturn > 0 && joystickReturn < 0.1){
		return 0.0;
	}
	return joystickReturn;
}
