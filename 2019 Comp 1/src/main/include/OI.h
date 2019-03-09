/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "frc/WPILib.h"

class OI {
 private:

  std::shared_ptr<frc::Joystick> armStick;
  std::shared_ptr<frc::JoystickButton> as_b1_S3_Pos0;
	std::shared_ptr<frc::JoystickButton> as_b2_S3_Pos1;
	std::shared_ptr<frc::JoystickButton> as_b3_S3_Pos2;
 
 public:
  OI();
  std::shared_ptr<frc::Joystick> getarmStick();
	
};


