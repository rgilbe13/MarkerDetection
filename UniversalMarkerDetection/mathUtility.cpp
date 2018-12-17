#include<mathUtility.h>

float getDimensions(float alt, float viewingAngle)
{
	float angleA = 90.0;
	float angleB = viewingAngle / 2.0;
	float angleC = 180 - (angleA + angleB);

	float sideC = alt;
	float sideA = sideC / sin(angleC * (3.14159 / 180));
	float sideB = sin(angleB * (3.14159 / 180)) * sideA;
	return sideB * 2.0f;
}

static double angle(Point pt1, Point pt2, Point pt0)
{
	double dx1 = pt1.x - pt0.x;
	double dy1 = pt1.y - pt0.y;
	double dx2 = pt2.x - pt0.x;
	double dy2 = pt2.y - pt0.y;
	return (dx1*dx2 + dy1*dy2) / sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

bool isDistanceClose(Point p1, Point p2)
{
	return sqrt(pow((p1.y - p2.y), 2) + pow((p1.x - p2.x), 2)) < MARKER_DISTANCE;
}