// Follower test program
// Authored by: Clint Fernelius
//              Jeanne Munk
//              Tyler Travis
//

#include "../CamTest/camera.h"
#include "../ControlTest/control.h"
#include "../MotorTest/motor.h"

int main()
{
    Camera* cam = new Camera();
    Control* cont = new Control();
    //Motor* motor = new Motor();

    cout << "Motor values initialized" << endl;
    //sleep(20);

    //cam->track();
    //cont->fbControl(cam->getXCenter());
    //motor->fbMove(cont->getFBvoltage());

    //sleep(4);

    //motor->stop();
    
    cout << "PRAY THAT THIS WORKS!!!!!!!\n";
    cout << "Radius: " << cam->getRadius() << endl;
    cout << "X-Center: " << cam->getXCenter() << endl;

    cout << endl;

    cout << "FB Voltage: " << cont->getFBvoltage() << endl;

    return 0;
}
