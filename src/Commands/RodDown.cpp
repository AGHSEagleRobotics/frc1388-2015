// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RodDown.h"
#define ROD_SPEED 1
RodDown::RodDown() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::rod);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void RodDown::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void RodDown::Execute() {
	
	RobotMap::rodRodMotor->Set(-ROD_SPEED);

}

// Make this return true when this Command no longer needs to run execute()
bool RodDown::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RodDown::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RodDown::Interrupted() {

}