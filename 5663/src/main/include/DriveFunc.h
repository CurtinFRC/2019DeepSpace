#pragma once

#include <frc/smartdashboard/SmartDashboard.h>
#include "CurtinCtre.h"
#include "Drivetrain.h"
#include "control/PIDController.h"
#include "sensors/NavX.h"

class DriveFunc {
    public:
    DriveFunc(double LSRXID, double RSRXID, double LSPXID, double RSPXID);
    void Forward(double Distance);
    void TurnNinety();
    double TurnAngle(double TargetAngle, double dt, bool firstPress);
    void update();
    void zero();
    void left();
    private:
    curtinfrc::TalonSrx *TalonL, *TalonR;
    curtinfrc::VictorSpx *VictorL, *VictorR;
    curtinfrc::DrivetrainFieldOrientedControlStrategy *DriveControl;
    curtinfrc::control::PIDGains _gains{"Turning gains", 0.03, 0.0, 0.003, 0.0};
    curtinfrc::control::PIDController *_controller;
    curtinfrc::sensors::NavX *Nav;
    curtinfrc::sensors::NavXGyro *NavG;
    const int kToleranceDegrees = 1;
    int encoderTicks;
};