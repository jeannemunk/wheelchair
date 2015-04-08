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
    BlackPWM pwm_center(EHRPWM1B);
    BlackPWM pwm_fb(EHRPWM0B);
    BlackPWM pwm_lr(EHRPWM0A);

    BlackGPIO sysReadyLED(GPIO_30,output);
    BlackGPIO circleWarnLED(GPIO_60,output);

    Camera* cam = new Camera();
    Control* cont = new Control();
    Motor* motor = new Motor(&pwm_center, &pwm_fb, &pwm_lr);

    cout << "Motor values initialized" << endl;
    sysReadyLED.setValue(high);
    cout << "sysReadyLED value: " << sysReadyLED.getValue() << endl;

    sleep(10);

    while (true)
    {
        cam->track();

        if (!cam->getCircleStatus())
        {
            circleWarnLED.setValue(high);
        }
        else
        {
            circleWarnLED.setValue(low);
        }

        cont->fbControl(cam->getXCenter());
        motor->fbMove(cont->getFBvoltage(), &pwm_fb);
        
        /*
        cout << "Camera Module\n";
        cout << "Radius: " << cam->getRadius() << endl;
        cout << "X-Center: " << cam->getXCenter() << endl;

        cout << endl;

        cout << "Control Module\n";
        cout << "FB Voltage: " << cont->getFBvoltage() << endl;
        */

    }
    
    sleep(4);

    motor->stop(&pwm_fb, &pwm_lr);

    return 0;
}
