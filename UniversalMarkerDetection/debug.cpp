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

void drawLines(Mat img, vector<vector<Point2f> > momentCenters)
{
	float distance;
	float mx;
	float my;
	int numOfColors = momentCenters.size();
	for (int c = 0; c < numOfColors - 1; c++)
	{
		for (int p = 0; p < momentCenters[c].size(); p++)
		{
			for (int p2 = 0; p2 < momentCenters[c + 1].size(); p2++)
			{
				distance = sqrt(pow((momentCenters[c][p].y - momentCenters[c + 1][p2].y), 2) + pow((momentCenters[c][p].x - momentCenters[c + 1][p2].x), 2));
				mx = (momentCenters[c][p].x + momentCenters[c + 1][p2].x) / 2;
				my = (momentCenters[c][p].y + momentCenters[c + 1][p2].y) / 2;
				char s[20];
				// casting from float to int may cause unexpected results. Just for debugging
				sprintf_s(s, "%i", (int)trunc(distance));
				line(img, momentCenters[c][p], momentCenters[c + 1][p2], Scalar(0, 250, 0));
				putText(img, s, Point2f(mx, my), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0, 250, 0), 1, CV_AA);
			}
		}
	}
}