/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include <frc/TimedRobot.h>
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>
#include "iostream"
#include "Constants.h"

/**
 * This sample program shows how to control a motor using a joystick. In the
 * operator control part of the program, the joystick is read and the value is
 * written to the motor.
 *
 * Joystick analog values range from -1 to 1 and speed controller inputs as
 * range from -1 to 1 making it easy to work together.
 */
class Robot : public frc::TimedRobot {
 public:
  frc::Joystick m_stick{0};
  TalonSRX m_motor{11};
  std::string _sb;
  int _loops = 0;
  bool _lastButton1 = false;

  double targetPositionRotations;
  void RobotInit() {

    m_motor.GetSelectedSensorPosition(0) & 0xFFF;
		/* lets grab the 360 degree position of the MagEncoder's absolute position */
		int absolutePosition = m_motor.GetSelectedSensorPosition(0) & 0xFFF; /* mask out the bottom12 bits, we don't care about the wrap arounds */
		/* use the low level API to set the quad encoder signal */
		m_motor.SetSelectedSensorPosition(absolutePosition, kPIDLoopIdx,
				kTimeoutMs);

		/* choose the sensor and sensor direction */
		m_motor.ConfigSelectedFeedbackSensor(
				FeedbackDevice::CTRE_MagEncoder_Relative, kPIDLoopIdx,
				kTimeoutMs);
		m_motor.SetSensorPhase(true);

		/* set the peak and nominal outputs, 12V means full */
		m_motor.ConfigNominalOutputForward(0, kTimeoutMs);
		m_motor.ConfigNominalOutputReverse(0, kTimeoutMs);
		m_motor.ConfigPeakOutputForward(1, kTimeoutMs);
		m_motor.ConfigPeakOutputReverse(-1, kTimeoutMs);

		/* set closed loop gains in slot0 */
		m_motor.Config_kF(kPIDLoopIdx, 0.0, kTimeoutMs);
		m_motor.Config_kP(kPIDLoopIdx, 0.1, kTimeoutMs);
		m_motor.Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
		m_motor.Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);
	}
  void TeleopPeriodic() override { 
    
    //m_motor.Set(ControlMode::PercentOutput, m_stick.GetY()); 
  /* get gamepad axis */
		double leftYstick = m_stick.GetY();
		double motorOutput = m_motor.GetMotorOutputPercent();
		bool button1 = m_stick.GetRawButton(1);
		bool button2 = m_stick.GetRawButton(2);
		/* prepare line to print */
		_sb.append("\tout:");
		_sb.append(std::to_string(motorOutput));
		_sb.append("\tpos:");
		_sb.append(std::to_string(m_motor.GetSelectedSensorPosition(kPIDLoopIdx)));
		/* on button1 press enter closed-loop mode on target position */
		if (!_lastButton1 && button1) {
			/* Position mode - button just pressed */
			targetPositionRotations = leftYstick * 10.0 * 4096; /* 10 Rotations in either direction */
			m_motor.Set(ControlMode::Position, targetPositionRotations); /* 10 rotations in either direction */
		}
		/* on button2 just straight drive */
		if (button2) {
			/* Percent voltage mode */
			m_motor.Set(ControlMode::PercentOutput, leftYstick);
		}
		/* if Talon is in position closed-loop, print some more info */
		if (m_motor.GetControlMode() == ControlMode::Position) {
			/* append more signals to print when in speed mode. */
			_sb.append("\terrNative:");
			_sb.append(std::to_string(m_motor.GetClosedLoopError(kPIDLoopIdx)));
			_sb.append("\ttrg:");
			_sb.append(std::to_string(targetPositionRotations));
		}
		/* print every ten loops, printing too much too fast is generally bad for performance */
		if (++_loops >= 10) {
			_loops = 0;
			printf("%s\n", _sb.c_str());
		}
		_sb.clear();
		/* save button state for on press detect */
		_lastButton1 = button1;
	}
 


  
 private:
  
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
