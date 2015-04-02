// Follower test program
// Authored by: Clint Fernelius
//              Jeanne Munk
//              Tyler Travis
//

#include "../CamTest/camera.h"

int main()
{
    Camera* cam = new Camera();

    cam->track();

    cout << "PRAY THAT THIS WORKS!!!!!!!\n";
    cout << "Radius: " << cam->getRadius() << endl;
    cout << "X-Center: " << cam->getXCenter() << endl;

    return 0;
}
