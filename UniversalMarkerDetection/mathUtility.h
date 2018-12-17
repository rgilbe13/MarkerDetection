#pragma once

#include<opencv2\opencv.hpp>
#include <math.h>
#define MARKER_DISTANCE 96

using namespace cv;

float getDimensions(float alt, float viewingAngle);
static double angle(Point pt1, Point pt2, Point pt0);
bool isDistanceClose(Point p1, Point p2);