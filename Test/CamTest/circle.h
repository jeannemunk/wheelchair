// Header File for Camera Operations
// Authored by: Clint Fernelius
//              Jeanne Munk
//              Tyler Travis
//

#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

class Camera
{
    private:
        float radius;
        float xCenter;

    public:
        Camera();
        void setRadius(float);
        void setXCenter(float);
        float getRadius();
        float getxCenter();
        void track();
}

#endif
