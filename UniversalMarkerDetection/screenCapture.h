#pragma once
#include<opencv2\opencv.hpp>
#include<opencv2\core.hpp>
#include<opencv\cv.h>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>
#include <Windows.h>

using namespace cv;

Mat hwnd2mat(HWND hwnd);
Mat getScreen();