// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Joystick* opStick;
	JoystickButton* grabTrashcan;
	JoystickButton* grabNormalTote;
	JoystickButton* grabSlimTote;
	JoystickButton* openGrabbers;
	Joystick* driveStick;
	JoystickButton* controldrivebutton;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	JoystickButton * elevatorPickup;
	JoystickButton * stackFirstTote;
	JoystickButton * elevatorLevel2;
	JoystickButton * elevatorLevel3;
	JoystickButton * elevatorLevel4;
	JoystickButton * elevatorLevel5;
public:
	OI();
 
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	Joystick* getdriveStick();
	Joystick* getopStick();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	float joystickDeadband(float joystickReturn);
	float getDriveStickX();
	float getDriveStickY();
	float getDriveStickZ();
	float getOpStickX();
	float getOpStickY();
};

#endif
