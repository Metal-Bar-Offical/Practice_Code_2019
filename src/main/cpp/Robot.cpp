#include "frc/WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <constants.h>//TESTED
#include <drivebase.h> //TESTED
#include <intake_wheels.h>
#include <intake_clamp.h>//TESTED
#include <intake_pivot.h>
#include <intake.h>
#include <elevator.h>
#include <climber.h>//TESTED
#include <diagnostic.h>
#include <PID.h>//TESTED

using namespace frc;

class Robot: public IterativeRobot{
public:

Robot(){}

Joystick *joy0;
Joystick *joy1;
TalonSRX *talon_left_enc;
TalonSRX *talon_left_noenc;
TalonSRX *talon_right_enc; 
TalonSRX *talon_right_noenc;
TalonSRX *climber_talon_wheel;
TalonSRX *climber_talon_arm;
TalonSRX *claw_pivot_talon_enc;
Servo *lock_servo;
DigitalInput * mag_switch_climber;

TalonSRX *talon_clamp;
TalonSRX *talon_elevator_enc;

Drivebase *drivebase;
Climber *climber;
Intake_clamp *intake_clamp;
Intake_pivot *intake_pivot;
PID *pid;

    void RobotInit(){
       joy0 = new Joystick(0);
       joy1 = new Joystick(1);
       talon_left_enc = new TalonSRX(2);
       talon_left_noenc = new TalonSRX(1);
       talon_right_enc = new TalonSRX(4);
       talon_right_noenc = new TalonSRX(3);
       climber_talon_wheel = new TalonSRX(7);
       climber_talon_arm = new TalonSRX(6);
       talon_clamp = new TalonSRX(10);
       claw_pivot_talon_enc = new TalonSRX(5);
       lock_servo = new Servo(1);
       mag_switch_climber = new DigitalInput(0);
       talon_elevator_enc = new TalonSRX(8);
   
   pid = new PID (talon_right_enc, talon_left_enc, claw_pivot_talon_enc, talon_elevator_enc);
   intake_pivot = new Intake_pivot(claw_pivot_talon_enc, joy1);
    intake_clamp = new Intake_clamp(joy1, talon_clamp);
       drivebase = new Drivebase (joy0, talon_left_enc, talon_left_noenc, talon_right_enc, talon_right_noenc);
       talon_left_noenc->Set(ControlMode::Follower, 2);
       talon_right_noenc->Set(ControlMode::Follower, 4);
       climber = new Climber(joy0, mag_switch_climber, climber_talon_arm,climber_talon_wheel, lock_servo);
        std::cout<<"Full Teleop v22"<<std::endl;
    }

    void TeleopInit(){

    }
    void TeleopPeriodic(){
        drivebase->update();
        climber->run_climber(.75);
        pid->PID_claw_elevator();
    
        intake_clamp->update();
        intake_pivot->run_intake_pivot(0, 180, 720);

        


    }

    void AutonomousInit(){
    }
    void AutonomousPeriodic(){
    }

    void TestInit(){
    }
    void TestPeriodic(){
    }

    void DisabledInit(){

    }
    void DisabledPeriodic(){
        
    }

};
START_ROBOT_CLASS(Robot);

