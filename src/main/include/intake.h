#ifndef INTAKE_H
#define INTAKE_H

#include <constants.h>
#include <intake_wheels.h>
#include <intake_clamp.h>
#include <intake_pivot.h>


class Intake {
public:
	// initialize intake
	Intake (
		// receive parameters
		Intake_wheels *intake_wheels,
		Intake_clamp *intake_clamp
	):
		// initialize member variables
		intake_wheels(intake_wheels),
		intake_clamp(intake_clamp)
	{
		// run on initialization
		std::cout<<"initializing intake_clamp";
	};

	// run this in TeleopPeriodic
	void update();
private:
	Intake_wheels *intake_wheels;
	Intake_clamp *intake_clamp;
};

#endif
