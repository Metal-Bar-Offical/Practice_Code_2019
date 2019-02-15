//NEEDS TO BE PID TUNED
#ifndef INTAKE_PIVOT_H
#define INTAKE_PIVOT_H

#include <constants.h>

class Intake_pivot {
public:
	// initialize intake_pivot
	Intake_pivot (
		// receive parameters
		frc::Joystick* joy1,
		TalonSRX* talon_intake_pivot
	):
		// initialize member variables
		joy1 (joy1),
		talon_intake_pivot(talon_intake_pivot)
	{
		// run on initialization
		std::cout<<"\n\t\tintake_pivot";
	};

	// put this in TeleopPeriodic
	void update();

private:
	frc::Joystick* joy1;
	TalonSRX* talon_intake_pivot;
	int toggle=0, toggle_two=0;
};
#endif
