#pragma once
#include <opencv2/core.hpp>
#include <opencv2\cvconfig.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "linked_list.h"
using namespace cv;
using namespace std;



void task1(string path = "C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\Segmented Outputs\\mIMD171.bmp") {

	cv::Mat img = cv::imread(path, 0);
	namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);

	cv::imshow("First OpenCV Application", img);


	int lsz = 500000;
	int* labels = new int [lsz] {0};

	int label = 0, l = 0;

	for (int i = 1; i < img.rows; i++)
	{
		for (int j = 1; j < img.cols; j++)
		{

			Scalar up = img.at<uchar>(i, j);
			Scalar left = img.at<uchar>(i, j);
			Scalar lD = img.at<uchar>(i, j);
			Scalar rD = img.at<uchar>(i, j);

			if (up.val[0] == 255)
			{
				up = img.at<uchar>(i - 1, j);
				left = img.at<uchar>(i, j - 1);
				lD = img.at<uchar>(i - 1, j - 1);
				rD = img.at<uchar>(i - 1, j + 1);
				if (up.val[0] == 0 && left.val[0] == 0 && lD.val[0] == 0 && rD.val[0] == 0)
				{

					img.row(i).col(j) = label;
					label++;
					//cout << label << " ";
				}
				else if (up.val[0] != 0 || left.val[0] != 0 || lD.val[0] != 0 || rD.val[0] != 0)
				{
					int arr[4] = { 0 };
					arr[0] = left.val[0];
					arr[1] = lD.val[0];
					arr[2] = up.val[0];
					arr[3] = rD.val[0];

					int min = 999999;

					for (int m = 0; m < 4; m++)
					{
						if (min > arr[m] && arr[m] != 0)
						{
							min = arr[m];
							/*	if (min != 0)
									cout << min << " ";*/
						}
					}
					labels[l] = min;
					img.row(i).col(j) = min;
					l++;
					//cout << l << " ";
				}




			}





		}


	}

	//cout << label;

	int sz1 = 0, sz2 = 0, s = sz1, val1 = 0, val2 = 0;

	for (int i = 1; i < label; i++)
	{
		for (int j = 0; j < lsz; j++)
		{
			//cout << labels[j];
			if (labels[j] == i) {
				s++;

			}

		}
		if (s > sz1) {

			sz1 = s;
			val1 = i;
		}
		else if (s > sz2) {
			sz2 = s;
			val2 = i;
		}

		s = 0;

	}

	cout << val1 << " ###### " << sz1 << endl;
	cout << val2 << " ###### " << sz2;



	//cv::imshow("First OpenCV Application", img);
	//cv::waitKey(0);



	for (int j = img.cols; j > 0; j--)
	{
		for (int i = img.rows - 8; i > 0; i--)
		{

			Scalar curr = img.at<uchar>(i, j);
			Scalar next = img.at<uchar>(i, j + 1);
			Scalar dn = img.at<uchar>(i + 1, j);
			Scalar left = img.at<uchar>(i, j - 1);
			Scalar lD = img.at<uchar>(i - 1, j - 1);
			Scalar rD = img.at<uchar>(i - 1, j + 1);


			if (curr.val[0] != val1 && curr.val[0] != 0) {
				if (next.val[0] == val1 || left.val[0] == val1 || dn.val[0] == val1 || rD.val[0] == val1 || lD.val[0] == val1) {
					img.row(i).col(j) = val1;
				}
			}





		}

	}





	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{

			Scalar curr = img.at<uchar>(i, j);
			Scalar next = img.at<uchar>(i, j + 4);
			Scalar prev = img.at<uchar>(i, j - 4);
			Scalar up = img.at<uchar>(i - 4, j);
			Scalar dn = img.at<uchar>(i + 4, j);



			if (curr.val[0] == val1) {
				img.row(i).col(j) = 255;
			}
			else
			{
				img.row(i).col(j) = 0;

			}


			/*if (curr.val[0] == 0) {
				if (next.val[0] != 0 && prev.val[0] != 0 && up.val[0] != 0 && dn.val[0] != 0) {
					img.row(i).col(j) = 255;

				}
			}*/

		}

	}
	imwrite("C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\result\\a.bmp", img);
	cv::imshow("not First OpenCV Application", img);
	cv::waitKey(0);
	cv::destroyAllWindows();


}


void task2AndTask3(string path = "C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\Original Images\\IMD002.bmp") {


	//NOTE: Keep the FIle name for Original Images and Ground Trusths Same for correct Value of DICE COEFFICIENT // 

	string gndPath = "C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\Ground Truths\\IMD002_lesion.bmp";


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////328//144////////////////////////////////////////////////////////////////////////////////////////////////
	// TASK2 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cv::Mat img = cv::imread(path);
	namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
	cv::imshow("First OpenCV Application", img);

	srand(time(0));

	int k1 = rand() % 255, k2 = rand() % 255, c1 = 0, c2 = 0, cul1 = 0, cul2 = 0;

	int** image = new int* [img.rows] {0};
	for (int i = 0; i < img.rows; i++)
	{
		image[i] = new int[img.cols] {0};
	}
	//
	for (; k1 != cul1 || k2 != cul2; )
	{
		c1 = 0; c2 = 0; cul1 = 0; cul2 = 0;
		for (int i = 0; i < img.rows; i++)
		{
			for (int j = 0; j < img.cols; j++)
			{
				image[i][j] = (img.at<Vec3b>(i, j).val[0] + img.at<Vec3b>(i, j).val[1] + img.at<Vec3b>(i, j).val[2]) / 3;
				if (image[i][j] <= k1) {

					cul1 += image[i][j];
					c1++;
				}
				else if (image[i][j] >= k2)
				{

					cul2 += image[i][j];
					c2++;

				}
				else
				{
					if (k2 > k1)
					{
						if (k2 - image[i][j] < image[i][j] - k1) {
							cul2 += image[i][j];
							c2++;

						}
						else
						{
							cul1 += image[i][j];
							c1++;
						}

					}
					else if (!(k2 > k1))
					{
						if (k1 - image[i][j] < image[i][j] - k2) {
							cul1 += image[i][j];
							c1++;

						}
						else
						{
							cul2 += image[i][j];
							c2++;
						}
					}
					else
					{
						cul1 += image[i][j];
						c1++;
					}
				}
				//cout << image[i][j]<<" ";
			}
			//cout << endl<<endl;
		}

		cul1 /= c1;
		cul2 /= c2;
		int temp1 = k1, temp2 = k2;
		k1 = cul1;
		k2 = cul2;
		cul1 = temp1;
		cul2 = temp2;
		/*cout << "\nK1: " << k1;
		cout << "\nK2: " << k2;*/

	}


	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			image[i][j] = (img.at<Vec3b>(i, j).val[0] + img.at<Vec3b>(i, j).val[1] + img.at<Vec3b>(i, j).val[2]) / 3;
			if (image[i][j] > (k2 + k1) / 2)
			{
				img.at<Vec3b>(i, j).val[0] = 0;
				img.at<Vec3b>(i, j).val[1] = 0;
				img.at<Vec3b>(i, j).val[2] = 0;
			}
			else if (image[i][j] < (k2 + k1) / 2)
			{
				img.at<Vec3b>(i, j).val[0] = 255;
				img.at<Vec3b>(i, j).val[1] = 255;
				img.at<Vec3b>(i, j).val[2] = 255;
			}





			//cout << image[i][j]<<" ";
		}
		//cout << endl<<endl;
	}

	int jst = 0, jEnd = 0;
	bool isStart = true;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			int curr1 = (img.at<Vec3b>(i, j).val[0] + img.at<Vec3b>(i, j).val[1] + img.at<Vec3b>(i, j).val[2]) / 3;
			int prev1 = (img.at<Vec3b>(i, j - 1).val[0]);
			int next1 = (img.at<Vec3b>(i, j + 1).val[0]);

			if (curr1 == 255 && prev1 == 0)
			{

				jEnd = j;

			}
			else if (curr1 == 255 && next1 == 0 && isStart)
			{

				jst = j;
				isStart = false;

			}




		}

		for (int j = img.cols - 1; j > 0; j--)
		{
			int curr1 = (img.at<Vec3b>(i, j).val[0] + img.at<Vec3b>(i, j).val[1] + img.at<Vec3b>(i, j).val[2]) / 3;
			int prev1 = (img.at<Vec3b>(i, j - 1).val[0]);
			int next1 = (img.at<Vec3b>(i, j + 1).val[0]);

			if (curr1 == 0 && next1 == 0)
			{

				jEnd = j;
				break;

			}

		}

	}


	for (int i = 0; i < img.rows; i++)
	{

		if (img.at<Vec3b>(i, 0).val[0] == 0 || img.at<Vec3b>(i, img.cols - 1).val[0] == 0)
		{
			continue;
		}
		for (int j = 0; j <= jst; j++)
		{


			img.at<Vec3b>(i, j).val[0] = 0;
			img.at<Vec3b>(i, j).val[1] = 0;
			img.at<Vec3b>(i, j).val[2] = 0;


		}

		for (int j = jEnd; j < img.cols; j++)
		{


			img.at<Vec3b>(i, j).val[0] = 0;
			img.at<Vec3b>(i, j).val[1] = 0;
			img.at<Vec3b>(i, j).val[2] = 0;


		}

	}





	string writePath = "C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\result\\a.bmp";
	cv::imwrite(writePath, img);

	int tp = 0, fp = 0, fn = 0;

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//TASK3// DICE COEFFICIENT ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cv::Mat gnd = imread(gndPath);

	for (int i = 0; i < gnd.rows; i++)
	{

		for (int j = 0; j < gnd.cols; j++)
		{
			int imgVal = img.at<Vec3b>(i, j).val[0], gndVal = gnd.at<Vec3b>(i, j).val[0];

			if (imgVal == gndVal && imgVal == 255)
			{
				tp++;
			}
			if (imgVal == 255 && gndVal == 0)
			{
				fp++;


			}
			if (imgVal == 0 && gndVal == 255)
			{
				fn++;
			}

		}

	}

	float num = (2 * tp);
	float den = (fn + (2 * tp) + fp);

	float diceCoff = (num / den);

	cout << "\n\n Dice COffencient: " << diceCoff;
	//<< "   " << tp << "   " << fp << "   " << fn;



	img = cv::imread(writePath);

	cv::imshow("not First OpenCV Application", img);
	cv::waitKey(0);
	cv::destroyAllWindows();

}

void task4(string path = "C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignment 1\\Assignment 1\\Segmented Outputs\\mIMD024.bmp") {

	cv::Mat img = cv::imread(path);

	SLinkedList<int> rlc;
	int curr = 0, prev = 0, next = 0;

	rlc.insert(img.rows);
	rlc.insert(img.cols);
	rlc.insert(-1);

	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			curr = (img.at<Vec3b>(i, j).val[0] + img.at<Vec3b>(i, j).val[1] + img.at<Vec3b>(i, j).val[2]) / 3;
			prev = (img.at<Vec3b>(i, j - 1).val[0] + img.at<Vec3b>(i, j - 1).val[1] + img.at<Vec3b>(i, j - 1).val[2]) / 3;
			next = (img.at<Vec3b>(i, j + 1).val[0] + img.at<Vec3b>(i, j + 1).val[1] + img.at<Vec3b>(i, j + 1).val[2]) / 3;

			if (curr == 255 && prev == 0 ) {

				rlc.insert(j);

				
			}
			if ( curr == 0 && prev == 255) {
				rlc.insert(j-1);

			}




		}

		rlc.insert(-1);

	}

	rlc.print();



}

