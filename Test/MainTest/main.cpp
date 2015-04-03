// Follower test program
// Authored by: Clint Fernelius
//              Jeanne Munk
//              Tyler Travis
//

#include "../CamTest/camera.h"
#include "../ControlTest/control.h"

int main()
{
    Camera* cam = new Camera();
    Control* cont = new Control();

    cam->track();
    cont->fbControl(cam->getXCenter());
    
    cout << "PRAY THAT THIS WORKS!!!!!!!\n";
    cout << "Radius: " << cam->getRadius() << endl;
    cout << "X-Center: " << cam->getXCenter() << endl;

    cout << endl;

    cout << "FB Voltage: " << cont->getFBvoltage() << endl;

    return 0;
}
