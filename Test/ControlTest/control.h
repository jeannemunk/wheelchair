// Control Header File
// Authored by: Clint Fernelius
//              Jeanne Munk
//              Tyler Travis
//

#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>

using namespace std;

class Control
{
    private:
        float fbV;
        float lrV;

        int pixelD;     // FB Control
        int radiusD;    // LR Control
        
    public:
        Control();

        float getFBvoltage();
        float getLRvoltage();

        void setFBvoltage(float);
        void setLRvoltage(float);

        void fbControl(int);
        void lrControl(int); 
};

#endif
