// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ElevatorLevel4.h"
#include "GoToSetpoint.h"

GoToSetpoint Level4(56.1);

ElevatorLevel4::ElevatorLevel4() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::elevator);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void ElevatorLevel4::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ElevatorLevel4::Execute() {
	Level4.goToSetpoint();
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorLevel4::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ElevatorLevel4::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorLevel4::Interrupted() {

}