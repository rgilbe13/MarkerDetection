#define DEBUG 1;
#define WINDOWS 1;


#include <iostream>
#include <imageProcessing.h>
#include <debug.h>
#include <mathUtility.h>

using namespace std;
using namespace cv;

int main()
{
	Mat originalImage;
	vector<color> colors = { orange, blue };
	int numColors = colors.size();
	int numMatch = NUM_MATCH;
	int matchCount;
	vector<vector<Point2f> > momentCenters;
	int i;
	int x;
	int z;
	Point point;
	#ifdef DEBUG
		namedWindow("image", WINDOW_NORMAL);
	#endif
	
	while (true)
	{
		//originalImage = getImageFromFile("..\\DebugMedia\\drone480high.jpg");
		//originalImage = getVideoFromCamera();

		//originalImage = getVideoFromFile("..\\DebugMedia\\Splice\\drone480high.mp4");
		//originalImage = getVideoFromFile("..\\DebugMedia\\Splice\\drone480med.mp4");
		//originalImage = getVideoFromFile("..\\DebugMedia\\Splice\\drone480low.mp4");

		//originalImage = getVideoFromFile("..\\DebugMedia\\Splice\\drone720high.mp4");
		//originalImage = getVideoFromFile("..\\DebugMedia\\Splice\\drone720med.mp4");
		//originalImage = getVideoFromFile("..\\DebugMedia\\Splice\\drone720low.mp4");

		//originalImage = getVideoFromFile("..\\DebugMedia\\Splice\\drone1080high.mp4");
		//originalImage = getVideoFromFile("..\\DebugMedia\\Splice\\drone1080med.mp4");
		originalImage = getVideoFromFile("..\\DebugMedia\\Splice\\drone1080low.mp4");
		if (originalImage.cols == 0) break;
		matchCount = 0;
		momentCenters.clear();
		for (i = 0; i < numColors; i++)
		{
			vector<Moments> moments = getMoments(originalImage, colors[i]);
			vector<Point2f> mc;
			for (int x = 0; x < moments.size(); x++)
			{
				point = Point2f(moments[x].m10 / moments[x].m00, moments[x].m01 / moments[x].m00);
				mc.push_back(point);
			}
			momentCenters.push_back(mc);
			mc.clear();
		}

		#ifdef DEBUG
		originalImage = addDot(originalImage, momentCenters, colors);
		drawLines(originalImage, momentCenters);
		imshow("image", originalImage);
		#endif	

		if (findPattern(momentCenters, 2))
		{
			cout << "Hit" << endl;
		}

		char c = (char)waitKey(25);
		if (c == 27)
			break;
	}
}