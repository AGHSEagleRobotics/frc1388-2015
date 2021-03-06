// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef GRABBERS_H
#define GRABBERS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

#define TICKS_PER_INCH			142
#define THRESH_HOLD				100
#define WIDETOTE_WIDTH 			-3736	//
#define SLIMTOTE_WIDTH 			-1020	//This is the raw encoder value (in ticks)
#define TRASHCAN_WIDTH 			-1680	//This is the raw encoder value (in ticks)
#define TOOPEN_WIDTH 			-4418	//This is the raw encoder value (in ticks)
#define INFINITE_ERROR	        999999999999.0 //This is an absurdly large number to set the error term for the encoder setpoint so no matter how jacked up the encoder gets it will still go to the "outside position" (encoder value 0)
/**
 *
 *
 * @author ExampleAuthor
 */
class Grabbers: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	DigitalInput* grabberoutsidelimit;
	DigitalInput* grabberinsidelimit;
	DigitalInput* grabbertotelimit;
	Encoder* grabberencoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Grabbers();
	void InitDefaultCommand();
	void ResetEncoder();
};

#endif
