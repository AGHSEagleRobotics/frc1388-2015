/*
 * GrabBox.h
 *
 *  Created on: Dec 1, 2015
 *      Author: Owner
 */

#ifndef GRABBOX_H
#define GRABBOX_H
#define BOX_PRONG_HEIGHT 8.8
//roughly below the 9" maximum of prong
#define BALL_DIAMETER 12.0
//diameter of ball
#define VIEWING_HEIGHT 12.0
//extra space to raise above ball for user viewing
#define HEIGHT_ABOVE_BOX 25.0
//extra space above box for reset to prepare for next

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../Subsystems/Grabbers.h"
#include "../Subsystems/Elevator.h"

class GrabBox: public Command {
public:
	GrabBox();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif /* SRC_COMMANDS_GRABBOX_H_ */
