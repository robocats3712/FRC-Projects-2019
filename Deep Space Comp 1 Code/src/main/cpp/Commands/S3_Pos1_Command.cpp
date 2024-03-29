// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Commands/S3_Pos1_Command.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

S3_Pos1_Command::S3_Pos1_Command(): frc::Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	//Requires(Robot::ArmSub.get());
    pos1 = 25;
    button2pressed = false;
    printf("S3 Pos1\n");
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void S3_Pos1_Command::Initialize() {

    pos1 = 25;
    button2pressed = false;
    printf("S3 Pos1 init\n");

}

// Called repeatedly when this Command is scheduled to run
void S3_Pos1_Command::Execute() {
    pos1 = 25;
    button2pressed = Robot::oi->getarmStick()->GetRawButton(2);
    if (button2pressed){
        Robot::ArmSub->S3_Pos1(pos1);

    }

}

// Make this return true when this Command no longer needs to run execute()
bool S3_Pos1_Command::IsFinished() {
    return false;

}

// Called once after isFinished returns true
void S3_Pos1_Command::End() {
    Robot::ArmSub->S3_Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void S3_Pos1_Command::Interrupted() {

}
