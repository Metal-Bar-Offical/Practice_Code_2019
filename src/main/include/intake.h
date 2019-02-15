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
		Intake_clamp *intake_clamp,
		Intake_pivot *intake_pivot
	):
		// initialize member variables
		intake_wheels(intake_wheels),
		intake_clamp(intake_clamp),
		intake_pivot(intake_pivot)
	{
		// run on initialization
		std::cout<<"\n\t\tintake";
	};

	// run this in TeleopPeriodic
	void update();
private:
	Intake_wheels *intake_wheels;
	Intake_clamp *intake_clamp;
	Intake_pivot *intake_pivot;
};

#endif
