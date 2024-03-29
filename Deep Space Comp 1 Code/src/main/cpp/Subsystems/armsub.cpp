// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Subsystems/armsub.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

armsub::armsub() : frc::Subsystem("armsub") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    s3_Motor.reset(new rev::CANSparkMax(16, rev::CANSparkMax::MotorType::kBrushless));
    //AddChild("S3_Motor", std::static_pointer_cast<rev::CANSparkMax>(s3_Motor));
    
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    rev::CANPIDController PID_S3 = s3_Motor->GetPIDController();

    rev::CANEncoder e_S3 = s3_Motor->GetEncoder();

    double kP = 0, kI = 0, kD = 0, kIz = 0, kFF = 0, kMaxOutput = 1, kMinOutput = -1;
    printf("Arm Sub Declared\n");
}

void armsub::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    double kP = 0.1, kI = 0, kD = 1, kIz = 0, kFF = 0, kMaxOutput = 1, kMinOutput = -1;
    PID_S3->SetP(kP);
    PID_S3->SetI(kI);
    PID_S3->SetD(kD);
    PID_S3->SetIZone(kIz);
    PID_S3->SetFF(kFF);
    PID_S3->SetOutputRange(kMinOutput, kMaxOutput);
    printf("PID Values\n");
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void armsub::Periodic() {
    // Put code here to be run every loop

}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.

void armsub::S3_Pos0(double s3SP) {
    // Put code here to be run every loop
    PID_S3->SetReference(s3SP, rev::ControlType::kPosition);

}

void armsub::S3_Pos1(double s3SP) {
    // Put code here to be run every loop
    PID_S3->SetReference(s3SP, rev::ControlType::kPosition);

}

void armsub::S3_Stop() {
    // Put code here to be run every loop
    s3_Motor->StopMotor();

}

