#include <debug.h>

using namespace cv;
using namespace std;

Mat addDot(Mat img, vector<vector<Point2f> > points, vector<color> colors)
{
	for (int i = 0; i < colors.size(); i++)
	{
		for (int x = 0; x < points[i].size(); x++)
		{
			//putText(img, colors[i].name, points[i][x], FONT_HERSHEY_PLAIN, 5, 5);
			circle(img, points[i][x], 6, Scalar(0, 0, 0), -1, 8, 0);
		}
	}
	return img;
}