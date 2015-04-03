// Motor class test file
// Authored by: Clint Fernelius
//              Jeanne Munk
//              Tyler Travis
//

#include "motor.h"

Motor::Motor(BlackPWM* center, BlackPWM* fb, BlackPWM* lr)
{
    sleep(1);
    
    center->setPeriodTime(2000000);
    fb->setPeriodTime(2000000);
    lr->setPeriodTime(2000000);

    center->setDutyPercent(50);
    fb->setDutyPercent(50);
    lr->setDutyPercent(50);
}

void Motor::fbMove(float volt, BlackPWM* fb)
{
    int percent = v_duty(volt);
    fb->setDutyPercent(percent);
}

void Motor::lrMove(float volt, BlackPWM* lr)
{
    int percent = v_duty(volt);
    lr->setDutyPercent(percent);
}

void Motor::stop(BlackPWM* fb, BlackPWM* lr)
{
    fb->setDutyPercent(50);
    lr->setDutyPercent(50);
}

int Motor::v_duty(float volt)
{
    return 100*volt/5.0;
}

