// Motor header test file
// Authored by: Clint Fernelius
//              Jeanne Munk
//              Tyler Travis
//

#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include <string>
#include "../libs/BlackLib/v2_0/BlackLib.h"

using namespace std;
using namespace BlackLib;

class Motor
{
    private:
        BlackPWM pwm_center(EHRPWM1B);
        BlackPWM pwm_fb(EHRPWM0B);
        BlackPWM pwm_lr(EHRPWM0A);

    public:
        Motor();
        void lrMove(float);
        void fbMove(float);
        int v_duty(float);

};
