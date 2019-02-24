#ifndef INTAKE_H
#define INTAKE_H

#include <constants.h>
#include<intake_clamp.h>
#include<intake_wheels.h>
#include<intake_pivot.h>

class Intake {
public:
	Intake(

TalonSRX*drive_talon_left_enc,
TalonSRX*claw_pivot_talon_enc,

TalonSRX*elevator_talon_enc

		)
	:
	
	drive_talon_left_enc(drive_talon_left_enc),
	claw_pivot_talon_enc(claw_pivot_talon_enc),
	
	elevator_talon_enc(elevator_talon_enc){};
	

	

private:
TalonSRX*drive_talon_right_enc;
TalonSRX*drive_talon_left_enc;
TalonSRX*claw_pivot_talon_enc;

TalonSRX*elevator_talon_enc;


};




#endif
