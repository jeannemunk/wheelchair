// Control cpp test file
// Authored by: Clint Fernelius
//              Jeanne Munk
//              Tyler Travis
//

#include "control.h"

Control::Control()
{
    this->fbV = 2.5;
    this->lrV = 2.5;

    this->pixelD = 160;
    this->radiusD = 80;
}

float Control::getFBvoltage()
{
    return this->fbV;
}

float Control::getLRvoltage()
{
    return this->lrV;
}

void Control::setFBvoltage(float aFBvoltage)
{
    if (aFBvoltage > 4)
    {
        this->fbV = 4;
    }
    else if (aFBvoltage < 1)
    {
        this->fbV = 1;
    }
    else
    {
        this->fbV = aFBvoltage;
    }
}

void Control::setLRvoltage(float aLRvoltage)
{
    if (aLRvoltage > 3.7)
    {
        this->lrV = 3.7;
    }
    else if (aLRvoltage < 1.1)
    {
        this->lrV = 1.1;
    }
    else
    {
        this->lrV = aLRvoltage;
    }
}

void Control::fbControl(int pixelA)
{
    float Kg = 0.0085;
    int error = this->pixelD - pixelA;

    if (error < 10 && error > -10)
    {
        error = 0;
    }

    this->setFBvoltage(2.5 + error*Kg);
}

void Control::lrControl(int radiusA)
{

}


