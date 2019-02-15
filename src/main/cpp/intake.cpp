#include <intake.h>


// run this in TeleopPeriodic
void Intake :: update () {
	intake_wheels->update();
	intake_clamp->update();
	//intake_pivot->update();
}
