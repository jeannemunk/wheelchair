#include <iostream>
#include <vector>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	VideoCapture cap(0); //capture the video from web cam
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 800);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 600);

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		return -1;
	}

	namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

	int iLowH = 90;
	int iHighH = 140;

	int iLowS = 50;
	int iHighS = 255;

	int iLowV = 50;
	int iHighV = 255;

	vector<Vec3f> circles;

	// Create trackbars in "Control" window
	cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
	cvCreateTrackbar("HighH", "Control", &iHighH, 179);

	cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
	cvCreateTrackbar("HighS", "Control", &iHighS, 255);

	cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
	cvCreateTrackbar("HighV", "Control", &iHighV, 255);

	while (true)
	//for (int ind = 0; ind < 10; ++ind)
	{
		Mat imgOriginal;

		cap >> imgOriginal; // read a new frame from video

		if (imgOriginal.empty()) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		Mat imgHSV;

		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

		Mat imgThresholded;

		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

		//morphological opening (remove small objects from the foreground)
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_RECT, Size(5, 5)));
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_RECT, Size(3, 3)));

		Mat imgUp;
		pyrUp(imgThresholded, imgUp);
		pyrDown(imgUp, imgThresholded);
		GaussianBlur(imgThresholded, imgThresholded, Size(9, 9), 2, 2);
		
		HoughCircles(imgThresholded, circles, CV_HOUGH_GRADIENT, 1, imgThresholded.rows / 10, 100, 40, 0, 0);

		// Draw the circles detected
		for (size_t i = 0; i < circles.size(); i++)
		{
			Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
			int radius = cvRound(circles[i][2]);
			// circle center
			circle(imgOriginal, center, 3, Scalar(0, 255, 0), -1, 8, 0);
			// circle outline
			circle(imgOriginal, center, radius, Scalar(0, 0, 255), 3, 8, 0);
		}

		imshow("Thresholded Image", imgThresholded); //show the thresholded image
		imshow("Original", imgOriginal); //show the original image

		circles.clear();

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}

		//while (waitKey(30) != 32);
	}
	
	while (true);

	return 0;

}