// Motor class test file
// Authored by: Clint Fernelius
//              Jeanne Munk
//              Tyler Travis
//

#include "motor.h"

Motor::Motor()
{
    BlackPWM pwm_center(EHRPWM1B);
    BlackPWM pwm_fb(EHRPWM0B);
    BlackPWM pwm_lr(EHRPWM0A);

    this->motor.push_back(pwm_center);
    this->motor.push_back(pwm_fb);
    this->motor.push_back(pwm_lr);

    sleep(1);
    this->motor[0].setPeriodTime(2000000);
    this->motor[1].setPeriodTime(2000000);
    this->motor[2].setPeriodTime(2000000);

    this->motor[0].setDutyPercent(50);
    this->motor[1].setDutyPercent(50);
    this->motor[2].setDutyPercent(50);

}

void Motor::fbMove(float volt)
{
    int percent = v_duty(volt);
    this->motor[1].setDutyPercent(percent);
}

void Motor::lrMove(float volt)
{
    int percent = v_duty(volt);
    this->motor[2].setDutyPercent(percent);
}

void Motor::stop()
{
    this->motor[1].setDutyPercent(50);
    this->motor[2].setDutyPercent(50);
}

int Motor::v_duty(float volt)
{
    return volt/5.0;
}

