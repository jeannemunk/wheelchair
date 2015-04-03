// Motor class test file
// Authored by: Clint Fernelius
//              Jeanne Munk
//              Tyler Travis
//

#include "motor.h"

Motor::Motor()
{
    sleep(1);
    this->pwm_center.setPeriodTime(2000000);
    this->pwm_fb.setPeriodTime(2000000);
    this->pwm_lr.setPeriodTime(2000000);

    this->pwm_center.setDutyPercent(50);
    this->pwm_fb.setDutyPercent(50);
    this->pwm_lr.setDutyPercent(50);

}

int main() 
{

    while (1)
    {
        // Move forward and left to measure curvature
        pwm_fb.setDutyPercent(40);
        pwm_lr.setDutyPercent(60);
        sleep(5);
        
        pwm_fb.setDutyPercent(50);
        pwm_lr.setDutyPercent(50);
        break;
    }

    return 0;
}
