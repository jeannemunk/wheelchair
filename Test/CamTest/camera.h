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

using namespace std;
using namespace cv;

class Camera
{
    private:
        VideoCapture cap;

        int radius;
        int xCenter;
        
    public:
        Camera();
        void setRadius(int);
        void setXCenter(int);
        int getRadius();
        int getXCenter();
        void track();
};

#endif
