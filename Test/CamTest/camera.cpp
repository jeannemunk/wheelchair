#include "camera.h"

// Constructor
Camera::Camera()
{
    this->cap.open(0);

    this->radius = 0;
    this->xCenter = 0;

    this->cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
    this->cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);

    if (!this->cap.isOpened())
    {
        cout << "Cannot open the web cam" << endl;
    }
}

int Camera::getRadius()
{
    return this->radius;
}

int Camera::getXCenter()
{
    return this->xCenter;
}

void Camera::setRadius(int aRadius)
{
    if (aRadius > 0)
    {
        this->radius = aRadius;
    }
    else
    {
        this->radius = 0;
    }
}

void Camera::setXCenter(int aXCenter)
{
    if (aXCenter > 0)
    {
        this->xCenter = aXCenter;
    }
    else
    {
        this->xCenter = 0;
    }
}

void Camera::track()
{
    int c = 0;

    int lowH = 90;
    int highH = 140;
    
    int lowS = 50;
    int highS = 255;

    int lowV = 50;
    int highV = 255;

    vector<Vec3f> circles;
    Mat imgOriginal; 
    Mat imgHSV;
    Mat imgThresholded;
    Mat imgDown;

    while (circles.size() == 0)
    {
        if (c >= 5)
        {
            break;
        }

        this->cap >> imgOriginal; // read a new frame from video

        if (imgOriginal.empty()) // if not success, break loop
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }

        // Convert the captured frame from BGR to HSV
        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); 

        // Threshold the image
        inRange(imgHSV, Scalar(lowH, lowS, lowV), Scalar(highH, highS, highV), imgThresholded); 

        // morphological opening (remove small objects from the foreground)
        erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_RECT, Size(5, 5)));
        dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_RECT, Size(3, 3)));
        
        // Downsample and Upsample to blur the image
        pyrDown(imgThresholded, imgDown);
        pyrUp(imgDown, imgThresholded);
        GaussianBlur(imgThresholded, imgThresholded, Size(9, 9), 2, 2);
                    
        HoughCircles(imgThresholded, circles, CV_HOUGH_GRADIENT, 1, imgThresholded.rows / 10, 100, 35, 0, 0);

        // Draw the circles detected
        /*
        for (int i = 0; i < circles.size(); i++)
        {
            Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
            int cRadius = cvRound(circles[i][2]);
            // circle center
            circle(imgOriginal, center, 3, Scalar(0, 255, 0), -1, 8, 0);
            // circle outline
            circle(imgOriginal, center, cRadius, Scalar(0, 0, 255), 3, 8, 0);

            //cout << "Radius " << c << ": " << cRadius << endl;
        }
        */

        // Assign radius and xCenter for tracking
        if (circles.size() > 0)
        {
            this->setRadius(cvRound(circles[0][2]));
            this->setXCenter(cvRound(circles[0][0]));
        }

        /*
        // write the thresholded image
        imwrite("Thresholded-"+to_string(c)+".jpg", imgThresholded);         
 
        // write the original image
        imwrite("Original-"+to_string(c)+".jpg", imgOriginal);
        */

        ++c;
    }

    return;
}
