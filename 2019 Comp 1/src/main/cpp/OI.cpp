/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>
#include "Commands/S3_adjustCommand.h"
#include "Commands/S3_pos0Command.h"
#include "Commands/S3_pos1Command.h"

OI::OI() {
  // Process operator interface input here.

    armStick.reset(new frc::Joystick(0));
    
    as_b1_S3_Pos0.reset(new frc::JoystickButton(armStick.get(), 1));
    as_b1_S3_Pos0->WhenPressed(new S3_pos0Command());

    as_b2_S3_Pos1.reset(new frc::JoystickButton(armStick.get(), 2));
    as_b2_S3_Pos1->WhenPressed(new S3_pos1Command());

}

std::shared_ptr<frc::Joystick> OI::getarmStick() {
   return armStick;
}
