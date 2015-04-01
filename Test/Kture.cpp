// Program to test curvature on wheelchair
//

#include "../libs/BlackLib/v2_0/BlackLib.h"
#include<iostream>

using namespace std;
using namespace BlackLib;

int main() 
{
    BlackPWM pwm_center(EHRPWM1B);
    BlackPWM pwm_fb(EHRPWM0B);
    BlackPWM pwm_lr(EHRPWM0A);

    pwm_center.setPeriodTime(2000000);
    pwm_fb.setPeriodTime(2000000);
    pwm_lr.setPeriodTime(2000000);

    pwm_center.setDutyPercent(50);
    pwm_fb.setDutyPercent(50);
    pwm_lr.setDutyPercent(50);

    return 0;
}
