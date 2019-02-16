#include <climber.h>

using namespace frc;
void Climber::servo_toggle(){
	bool servo_toggle1 =false;
	bool servo_toggle2=false;
	if (joy0->GetRawButton(servo_toggle_joynum)==1 and !servo_toggle1 and !servo_toggle2){
		//unlocks servo
		lock_servo->Set(1.0);
		servo_toggle1 = true;
	}
	if (joy0->GetRawButton(servo_toggle_joynum)==0 and servo_toggle1 ){
		servo_toggle2 = true;
	}
	if (joy0->GetRawButton(servo_toggle_joynum)==1 and servo_toggle2 and servo_toggle1){
		//lock_servo
		lock_servo->Set(0);
		servo_toggle1 = false;
	}
	if (joy0->GetRawButton(servo_toggle_joynum)==0 and servo_toggle2 and !servo_toggle1){
		servo_toggle1 = false;
		servo_toggle2 = false;
	}

}
void Climber::run_climber (double max_speed){
Climber::servo_toggle();
//sets a button to write to ClimberWheel
climber_talon_wheel->Set(ControlMode::PercentOutput, max_speed*joy0->GetRawButton(climber_wheels_control_joynum));
//lowers and brings up the climberArm
if (joy0->GetRawButton(climber_arm_lowering)==1){
	climber_talon_arm->Set(ControlMode::PercentOutput, max_speed * 1);
}
else if (joy0->GetRawButton(climber_arm_raising)==1){
	climber_talon_arm->Set(ControlMode::PercentOutput, max_speed*-1);
}
//shuts down talon
else {
	climber_talon_arm->Set(ControlMode::PercentOutput, 0);
}
}
