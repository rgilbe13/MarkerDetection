#pragma once
#include<opencv2\opencv.hpp>

#define MARKER_SIZE 10

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
void drawLines(Mat img, vector<vector<Point2f> > momentCenters);

extern color yellow;
extern color blue;
extern color orange;