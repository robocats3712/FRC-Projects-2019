/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <IOStream.h>
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>
#include <frc/smartdashboard/SmartDashboard.h>

using namespace frc;
void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */

 
void Robot::RobotPeriodic() {}

  TalonSRX frontLeft = new TalonSRX(10);
	frc::Joystick Joystick1 = new Joystick(0);
	std::string _sb;
	int _loops = 0;
	bool _lastButton1 = false;
	/** save the target position to servo to */
	double targetPositionRotations;
/* lets grab the 360 degree position of the MagEncoder's absolute position */
		int absolutePosition = frontLeft->GetSelectedSensorPosition(0) & 0xFFF; /* mask out the bottom12 bits, we don't care about the wrap arounds */
		/* use the low level API to set the quad encoder signal */
	 frontLeft->SetSelectedSensorPosition(absolutePosition, kPIDLoopIdx,
				kTimeoutMs);

		/* choose the sensor and sensor direction */
	 frontLeft->ConfigSelectedFeedbackSensor(
				FeedbackDevice::CTRE_MagEncoder_Relative, kPIDLoopIdx,
				kTimeoutMs);
	 frontLeft->SetSensorPhase(true);

		/* set the peak and nominal outputs, 12V means full */
	 frontLeft->ConfigNominalOutputForward(0, kTimeoutMs);
	 frontLeft->ConfigNominalOutputReverse(0, kTimeoutMs);
	 frontLeft->ConfigPeakOutputForward(1, kTimeoutMs);
	 frontLeft->ConfigPeakOutputReverse(-1, kTimeoutMs);

		/* set closed loop gains in slot0 */
	 frontLeft->Config_kF(kPIDLoopIdx, 0.0, kTimeoutMs);
	 frontLeft->Config_kP(kPIDLoopIdx, 0.1, kTimeoutMs);
	 frontLeft->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
	 frontLeft->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);
	}

	/**
	 * This function is called periodically during operator control
	 */
/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
