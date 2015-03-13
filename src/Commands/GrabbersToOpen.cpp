// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "GrabbersToOpen.h"
#include "../Subsystems/Grabbers.h"

GrabbersToOpen::GrabbersToOpen() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::grabbers);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void GrabbersToOpen::Initialize() {
	RobotMap::grabbersGrabberCANTalon->SetControlMode(CANSpeedController::kPosition);
		RobotMap::grabbersGrabberCANTalon->EnableControl();
		RobotMap::grabbersGrabberCANTalon->Set(TOOPEN_WIDTH);
}

// Called repeatedly when this Command is scheduled to run
void GrabbersToOpen::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool GrabbersToOpen::IsFinished() {
	//TODO: verify that the joystick commands can override these setpoint commands.
	float currentPos = RobotMap::grabbersGrabberCANTalon->GetPosition();
		float error = TOOPEN_WIDTH - currentPos;
		if(fabs(error) < THRESH_HOLD){
			return true;
		}else{
			return false;
		}
}

// Called once after isFinished returns true
void GrabbersToOpen::End() {
}

// Called when another command which requires one or more of the same
// substems is scheduled to run
void GrabbersToOpen::Interrupted() {

}
