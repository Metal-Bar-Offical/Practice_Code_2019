#include <PID.h>

//Configs drivebase 30% of velocity
void PID::PID_drivebase30 (){

talon_right_enc->Config_kP(3,0,10);
talon_right_enc->Config_kI(0,0,10);
talon_right_enc->Config_kD(0,0,10);
talon_right_enc->Config_kF(1.9,0,10);

talon_left_enc->Config_kP(3,0,10);
talon_left_enc->Config_kI(0,0,10);
talon_left_enc->Config_kD(0,0,10);
talon_left_enc->Config_kF(1.85,0,10);
}
//Configs drivebase 10% of velocity
void PID::PID_drivebase10(){
talon_right_enc->Config_kP(3,0,10);
talon_right_enc->Config_kI(0,0,10);
talon_right_enc->Config_kD(0,0,10);
talon_right_enc->Config_kF(1.9,0,10);

talon_left_enc->Config_kP(3,0,10);
talon_left_enc->Config_kI(0,0,10);
talon_left_enc->Config_kD(0,0,10);
talon_left_enc->Config_kF(1.85,0,10);
}
void PID::PID_claw_elevator(){
claw_pivot_talon_enc->Config_kP(38,0,10);
claw_pivot_talon_enc->Config_kI(0,0,10);
claw_pivot_talon_enc->Config_kD(0,0,10);
claw_pivot_talon_enc->Config_kF(0,0,10);


talon_elevator_enc->Config_kP(2.7,0,10);
talon_elevator_enc->Config_kI(0,0,10);
talon_elevator_enc->Config_kD(0,0,10);
talon_elevator_enc->Config_kF(0,0,10);

}



