#include <opencv2/core.hpp>
#include <opencv2\cvconfig.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "Header.h"
using namespace cv;
using namespace std;



//"C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\Original Images\\IMD002.bmp"

// write
//"C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\result\\a.bmp"


int main()
{
	//cv::Mat img = cv::imread("C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\Segmented Outputs\\mIMD171.bmp",0);

	//cv::imshow("First OpenCV Application", img);
	//cv::waitKey(0);

	//namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
	task2AndTask3();
	/*Vec3b curr = img.at<Vec3b>(Point( 255, 255));
	cout << curr.val[0] << curr.val[1] << curr.val[2];*/

	//cv::Mat grey = cv::imread("C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\Segmented Outputs\\mIMD169.bmp", 0);

	//cv::imshow("First OpenCV Application", grey);
	//cv::imshow("not First OpenCV Application", img);

	//imwrite("C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\result\\a.bmp", img);

	//cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}
