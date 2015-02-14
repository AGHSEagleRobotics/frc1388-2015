// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
DigitalInput* RobotMap::elevatorElevatorTopLimit = NULL;
DigitalInput* RobotMap::elevatorElevatorBottomLimit = NULL;
SpeedController* RobotMap::driveTrainLeftfronttalon = NULL;
SpeedController* RobotMap::driveTrainRightfronttalon = NULL;
SpeedController* RobotMap::driveTrainLeftbacktalon = NULL;
SpeedController* RobotMap::driveTrainRightbacktalon = NULL;
RobotDrive* RobotMap::driveTrainRobotDrive41 = NULL;
Encoder* RobotMap::driveTrainDriveencoder = NULL;
DigitalInput* RobotMap::grabbersGrabberoutsidelimit = NULL;
DigitalInput* RobotMap::grabbersGrabberinsidelimit = NULL;
DigitalInput* RobotMap::grabbersGrabbertotelimit = NULL;
Encoder* RobotMap::grabbersGrabberencoder = NULL;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

CANTalon * RobotMap::grabbersGrabberCANTalon = NULL;
CANTalon * RobotMap::elevatorElevatorTalon = NULL;
ITG3200  * RobotMap::driveTrainGyro = NULL;

void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();

	elevatorElevatorTopLimit = new DigitalInput(2);
	lw->AddSensor("Elevator", "ElevatorTopLimit", elevatorElevatorTopLimit);
	
	elevatorElevatorBottomLimit = new DigitalInput(3);
	lw->AddSensor("Elevator", "ElevatorBottomLimit", elevatorElevatorBottomLimit);
	
	driveTrainLeftfronttalon = new Talon(3);
	lw->AddActuator("DriveTrain", "Leftfronttalon", (Talon*) driveTrainLeftfronttalon);
	
	driveTrainRightfronttalon = new Talon(2);
	lw->AddActuator("DriveTrain", "Rightfronttalon", (Talon*) driveTrainRightfronttalon);
	
	driveTrainLeftbacktalon = new Talon(1);
	lw->AddActuator("DriveTrain", "Leftbacktalon ", (Talon*) driveTrainLeftbacktalon);
	
	driveTrainRightbacktalon = new Talon(0);
	lw->AddActuator("DriveTrain", "Rightbacktalon ", (Talon*) driveTrainRightbacktalon);
	
	driveTrainRobotDrive41 = new RobotDrive(driveTrainLeftfronttalon, driveTrainLeftbacktalon,
              driveTrainRightfronttalon, driveTrainRightbacktalon);
	
	driveTrainRobotDrive41->SetSafetyEnabled(true);
        driveTrainRobotDrive41->SetExpiration(0.1);
        driveTrainRobotDrive41->SetSensitivity(0.5);
        driveTrainRobotDrive41->SetMaxOutput(1.0);
        driveTrainRobotDrive41->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
        driveTrainRobotDrive41->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	driveTrainDriveencoder = new Encoder(5, 7, false, Encoder::k4X);
	lw->AddSensor("DriveTrain", "Driveencoder ", driveTrainDriveencoder);
	driveTrainDriveencoder->SetDistancePerPulse(1.0);
        driveTrainDriveencoder->SetPIDSourceParameter(Encoder::kRate);
	grabbersGrabberoutsidelimit = new DigitalInput(6);
	lw->AddSensor("Grabbers", "Grabberoutsidelimit", grabbersGrabberoutsidelimit);
	
	grabbersGrabberinsidelimit = new DigitalInput(4);
	lw->AddSensor("Grabbers", "Grabberinsidelimit", grabbersGrabberinsidelimit);
	
	grabbersGrabbertotelimit = new DigitalInput(9);
	lw->AddSensor("Grabbers", "Grabbertotelimit", grabbersGrabbertotelimit);
	
	grabbersGrabberencoder = new Encoder(10, 11, false, Encoder::k4X);
	lw->AddSensor("Grabbers", "Grabberencoder", grabbersGrabberencoder);
	grabbersGrabberencoder->SetDistancePerPulse(1.0);
        grabbersGrabberencoder->SetPIDSourceParameter(Encoder::kRate);


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    grabbersGrabberCANTalon = new CANTalon (5);
    grabbersGrabberCANTalon->SetControlMode(CANSpeedController::kPosition);
    grabbersGrabberCANTalon->SetPID(1,0.001,0);
    grabbersGrabberCANTalon->EnableControl();
    elevatorElevatorTalon = new CANTalon(13);
    driveTrainGyro = new ITG3200();
}
