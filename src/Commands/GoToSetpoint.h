#include "../Robot.h"

class GoToSetpoint{
private:
	float setpoint;
public:
	GoToSetpoint(float);
	void goToSetpoint();
};
