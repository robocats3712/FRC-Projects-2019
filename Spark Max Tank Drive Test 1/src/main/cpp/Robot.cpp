/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/WPILib.h>
#include <rev/CANSparkMax.h>

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
 /**
   * SPARK MAX controllers are intialized over CAN by constructing a CANSparkMax object
   * 
   * The CAN ID, which can be configured using the SPARK MAX Client, is passed as the
   * first parameter
   * 
   * The motor type is passed as the second parameter. Motor type can either be:
   *  rev::CANSparkMax::MotorType::kBrushless
   *  rev::CANSparkMax::MotorType::kBrushed
   * 
   * The example below initializes four brushless motors with CAN IDs 11, 12, 13 and 14. Change
   * these parameters to match your setup
   * 
   * Make sure you use the configuration tool to set the proper CAN IDs on the Spark Maxs or this 
   * won't work.
   *
   */

  frc::Joystick m_stick{0};
  rev::CANSparkMax m_leftLeadMotor{11, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightLeadMotor{12,rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_leftFollowMotor{13, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightFollowMotor{14, rev::CANSparkMax::MotorType::kBrushless};
  frc::DifferentialDrive t_drive{m_leftLeadMotor, m_rightLeadMotor};

  void RobotInit() {
    /**
     * In CAN mode, one SPARK MAX can be configured to follow another. This is done by calling
     * the Follow() method on the SPARK MAX you want to configure as a follower, and by passing
     * as a parameter the SPARK MAX you want to configure as a leader.
     * 
     * This is shown in the example below, where one motor on each side of our drive train is
     * configured to follow a lead motor.
     */
    m_leftFollowMotor.SetInverted(true);
    m_leftLeadMotor.SetInverted(true);
  
    m_leftFollowMotor.Follow(m_leftLeadMotor);
    m_rightFollowMotor.Follow(m_rightLeadMotor);
  }



  void TeleopPeriodic() override { 
    /**
     * This function calls the tank drive function
     * Convert the Get* to reflect the proper axis ie. GetX rather than GetThrottle
     * or GetZ rather than GetY
    */
    t_drive.TankDrive(m_stick.GetY(), m_stick.GetThrottle(), false);
  
  
  }

 private:
 
  
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
