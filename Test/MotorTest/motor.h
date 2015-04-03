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
        vector<BlackPWM> motor;

    public:
        Motor();
        void lrMove(float);
        void fbMove(float);
        void stop();
        int v_duty(float);

};

#endif
