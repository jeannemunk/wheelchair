// Motor header test file
// Authored by: Clint Fernelius
//              Jeanne Munk
//              Tyler Travis
//

#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include <string>
#include <vector>
#include "../../libs/BlackLib/v2_0/BlackLib.h"

using namespace std;
using namespace BlackLib;

class Motor
{
    private:
        //BlackPWM pwm_center(BlackPWM::EHRPWM1B);
        //BlackPWM pwm_fb(BlackPWM::EHRPWM0B);
        //BlackPWM pwm_lr(BlackPWM::EHRPWM0A);

    public:
        Motor(BlackPWM*, BlackPWM*, BlackPWM*);
        void lrMove(float, BlackPWM*);
        void fbMove(float, BlackPWM*);
        void stop(BlackPWM*, BlackPWM*);
        int v_duty(float);

};

#endif
