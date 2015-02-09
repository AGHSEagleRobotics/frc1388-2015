// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "MoveElevator.h"
#include "GoToSetpoint.h"

MoveElevator::MoveElevator() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::elevator);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void MoveElevator::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void MoveElevator::Execute() {
	//This first part is basically an event listener for the POV (D-Pad) of the controller

	signed int pov = Robot::oi->getopStick()->GetPOV();
	float currentPosition = RobotMap::elevatorElevatorTalon->GetEncPosition();
	GoToSetpoint StepLift((currentPosition + 4.1987)); //That magic number is the difference in height between the platform and step
	GoToSetpoint SetDown((currentPosition - 2.2)); //2.2 is the amount above the already stacked tote that the elevator will be

	switch(pov){
	case 0:

		StepLift.goToSetpoint();
		break;
	case 4:
		SetDown.goToSetpoint();
		break;
	}

	//This part is for actually moving the elevator manually with a joystick

	float joystickY = Robot::oi->getOpStickY();

	if(RobotMap::elevatorElevatorTalon->IsFwdLimitSwitchClosed() && joystickY > 0){
		RobotMap::elevatorElevatorTalon->Set(0.0);
	}else if(RobotMap::elevatorElevatorTalon->IsRevLimitSwitchClosed() && joystickY < 0){
		RobotMap::elevatorElevatorTalon->Set(0.0);
	}else{
		RobotMap::elevatorElevatorTalon->Set(joystickY);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool MoveElevator::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveElevator::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveElevator::Interrupted() {

}
