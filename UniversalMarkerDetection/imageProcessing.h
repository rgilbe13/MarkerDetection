#pragma once
#include<opencv2\opencv.hpp>

#define MARKER_SIZE 10
#define NUM_MATCH 2

using namespace cv;
using namespace std;

struct color
{
	String name;
	Scalar lower;
	Scalar upper;
};

vector<Moments> getMoments(Mat image, color c);
Mat getImageFromFile(String file);
Mat getVideoFromCamera();
Mat getVideoFromFile(String file);
Mat convertToHSV(Mat img);
Scalar fullHSV(int a, int b, int c);
bool findPattern(vector<vector<Point2f> > momentCenters, int hitOn);

extern color yellow;
extern color blue;
extern color orange;