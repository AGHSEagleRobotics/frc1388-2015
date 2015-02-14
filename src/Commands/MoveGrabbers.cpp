// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "MoveGrabbers.h"
#include "../OI.h"
#include "math.h"

MoveGrabbers::MoveGrabbers() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::grabbers);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void MoveGrabbers::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void MoveGrabbers::Execute() {
	float ModifiedDriveStickX = (Robot::oi->getDriveStickX() * 5);
	if(Robot::grabbers->grabberinsidelimit->Get() == false &&
			Robot::grabbers->grabberoutsidelimit->Get() == false)
	{
	RobotMap::grabbersGrabberCANTalon->Set(
			RobotMap::grabbersGrabberCANTalon->Get() + ModifiedDriveStickX);
	}
	if(Robot::grabbers->grabberinsidelimit->Get() ==  false &&
			Robot::grabbers->grabberoutsidelimit->Get() == true)
	{
		RobotMap::grabbersGrabberCANTalon->Set(
			abs(RobotMap::grabbersGrabberCANTalon->Get() + ModifiedDriveStickX) * (NEGATIVE_VALUE));
	}
	if(Robot::grabbers->grabberinsidelimit->Get() == true &&
			Robot::grabbers->grabberoutsidelimit->Get() == false)
	{
		RobotMap::grabbersGrabberCANTalon->Set(
				abs(RobotMap::grabbersGrabberCANTalon->Get() + ModifiedDriveStickX));
	}
}

// Make this return true when this Command no longer needs to run execute()
bool MoveGrabbers::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveGrabbers::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveGrabbers::Interrupted() {

}
