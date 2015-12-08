/*
 * GrabBox.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: Owner
 */

#include "GrabBox.h"

#include <CANSpeedController.h>
#include <CANTalon.h>

#include "../RobotMap.h"

/*
 * THIS CODE
 * IS UNTESTED
 * SUBSEQUENT ACTION BASED ON RESULT OF TEST
 */

GrabBox::GrabBox() {
	Requires(Robot::grabbers);
	Requires(Robot::elevator);
}

void GrabBox::Initialize() {

	//Check the position of the elevator, if not desired, set to 3" above box
	if(RobotMap::elevatorElevatorTalon->GetPosition() != HEIGHT_ABOVE_BOX){
		RobotMap::elevatorElevatorTalon->SetPosition(HEIGHT_ABOVE_BOX);
		new WaitCommand(5);
	}

	//Set the grabbers to full extension
	RobotMap::grabbersGrabberCANTalon->SetControlMode(
			CANSpeedController::kPosition);
	RobotMap::grabbersGrabberCANTalon->EnableControl();
	RobotMap::grabbersGrabberCANTalon->Set(TOOPEN_WIDTH);

	new WaitCommand(3);

	//Set the elevator to 0.2" below prongs on box
	RobotMap::elevatorElevatorTalon->SetControlMode(
			CANSpeedController::kPosition);
	RobotMap::elevatorElevatorTalon->EnableControl();
	RobotMap::elevatorElevatorTalon->SetPosition(
			BOX_PRONG_HEIGHT * ELEVATOR_PULSES_PER_INCH);

	new WaitCommand(5);

	//Set the grabbers to 3" wider than width of box to account for user error
	RobotMap::grabbersGrabberCANTalon->Set(BOX_WIDTH);

	new WaitCommand(3);

	//Raise elevator and box to height of ball, then another foot to allow for viewing
	double currentPos = RobotMap::elevatorElevatorTalon->GetPosition();
	RobotMap::elevatorElevatorTalon->SetPosition(
			(BALL_DIAMETER + currentPos + VIEWING_HEIGHT)
					* ELEVATOR_PULSES_PER_INCH);

}

void GrabBox::Execute() {
}

bool GrabBox::IsFinished() {
	return true;
}

void GrabBox::End() {
	new WaitCommand(7);
	RobotMap::elevatorElevatorTalon->SetPosition(BOX_PRONG_HEIGHT * ELEVATOR_PULSES_PER_INCH);
	RobotMap::grabbersGrabberCANTalon->Set(TOOPEN_WIDTH);
	RobotMap::elevatorElevatorTalon->SetPosition(HEIGHT_ABOVE_BOX);
}

void GrabBox::Interrupted() {

}

