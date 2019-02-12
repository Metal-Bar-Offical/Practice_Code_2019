#ifndef CLIMBER_H
#define CLIMBER_H

#include <constants.h>

class Climber {
public:
	// initialize climber
	Climber(
		// receive parameters
		frc::Joystick *joy1,
		TalonSRX* climber_talon_vertical_enc,
		TalonSRX* climber_talon_drive_enc
	):
		// initialize member variables
		joy1(joy1),
		climber_talon_vertical_enc(climber_talon_vertical_enc),
		climber_talon_drive_enc(climber_talon_drive_enc)
	{
		// run on initialization
		std::cout<<"initializing climber";
	};

	// run climber given input speed
	void run_climber(double max_speed);
private:
	frc::Joystick* joy1;
	TalonSRX* climber_talon_vertical_enc;
	TalonSRX* climber_talon_drive_enc;

};


#endif
