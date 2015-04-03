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

    sleep(1);
    pwm_center.setPeriodTime(2000000);
    pwm_fb.setPeriodTime(2000000);
    pwm_lr.setPeriodTime(2000000);
    
    sleep(1);
    pwm_center.setDutyPercent(50);
    pwm_fb.setDutyPercent(50);
    pwm_lr.setDutyPercent(50);

    Camera* cam = new Camera();
    Control* cont = new Control();
    Motor* motor = new Motor(&pwm_center, &pwm_fb, &pwm_lr);

    cout << "Motor values initialized" << endl;
    sleep(10);

    while (true)
    {
        cam->track();
        cont->fbControl(cam->getXCenter());
        motor->fbMove(cont->getFBvoltage(), &pwm_fb);
    }
    
    cout << "PRAY THAT THIS WORKS!!!!!!!\n";
    
    cout << "Camera Module\n";
    cout << "Radius: " << cam->getRadius() << endl;
    cout << "X-Center: " << cam->getXCenter() << endl;

    cout << endl;

    cout << "Control Module\n";
    cout << "FB Voltage: " << cont->getFBvoltage() << endl;
    
    sleep(4);

    motor->stop(&pwm_fb, &pwm_lr);

    return 0;
}
