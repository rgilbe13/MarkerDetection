#include<imageProcessing.h>
#include<mathUtility.h>

using namespace cv;
using namespace std;

// image
//color orange = { "Orange", fullHSV(20, 89, 84), fullHSV(28, 98, 98) };
//color yellow = { "Yellow", Scalar(23, 40, 25), Scalar(32, 255, 255) };
//color blue = { "Blue", fullHSV(216, 80, 45), fullHSV(222, 90, 62) };

//video
color orange = { "Orange", fullHSV(50, 35, 90), fullHSV(65, 55, 100) };
color blue = { "Blue", fullHSV(180, 80, 90), fullHSV(190, 100, 100) };
vector<Moments> getMoments(Mat image, color c)
{
	Mat output;
	image.copyTo(output);
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	Moments moment;
	vector<Moments> foundMoments;
	output = convertToHSV(output);
	inRange(output, c.lower, c.upper, output);
	findContours(output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	for (int i = 0; i < contours.size(); i++)
	{
		moment = moments(contours[i], false);
		if (moment.m00 > MARKER_SIZE)
		{
			foundMoments.push_back(moment);
		}
	}
	return foundMoments;
}

Mat getImageFromFile(String file)
{
	Mat img = imread(file);
	return img;
}

Mat getVideoFromCamera()
{
	static VideoCapture cap(0);
	static Mat cameraImg;
	cap >> cameraImg;
	return cameraImg;
}

Mat getVideoFromFile(String file)
{
	static VideoCapture cap(file);
	static Mat videoImg;
	cap >> videoImg;
	return videoImg;
}

Mat convertToHSV(Mat img)
{
	cvtColor(img, img, CV_BGR2HSV);
	return img;
}

Scalar fullHSV(int a, int b, int c)
{
	return Scalar(a / 2, (b / 100.0) * 255, (c / 100.0) * 255);
}

bool findPattern(vector<vector<Point2f> > momentCenters, int hitOn)
{
	int numOfColors = momentCenters.size();
	for (int c = 0; c < numOfColors - 1; c++)
	{
		for (int p = 0; p < momentCenters[c].size(); p++)
		{
			for (int p2 = 0; p2 < momentCenters[c + 1].size(); p2++)
			{
				if (isDistanceClose(momentCenters[c][p], momentCenters[c + 1][p2]))
				{
					return true;
				}
			}
		}
	}
	return false;
}

