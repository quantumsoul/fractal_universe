#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
using namespace cv;
Point2i WindowSize(vector<Point2f> points) {
	Point2i max = Point2i(INT_MIN, INT_MIN);
	for (int i = 0; i < points.size(); i++)
	{
		int x = points.at(i).x;
		int y = points.at(i).y;
		max.x = x > max.x ? x : max.x;
		max.y = y > max.y ? y : max.y;
	}
	return max;
}
void fractal(float a, float b, vector<Point2f> points, int iter = 100000) {
	Point2f pos = Point2f(0, 0);
	const int dierolls = points.size();
	Point2i urc = WindowSize(points);  //upper right corner
	Mat img = Mat(urc.x, urc.y, CV_8UC1, Scalar::all(0));
	for (int i = 0; i < iter; i++)
	{
		int rnd = rand() % dierolls;
		Point2f pointto = points.at(rnd);
		Point2f diff = pointto - pos;
		pos.x += a * diff.x;
		pos.y += b * diff.y;
		img.at<uchar>(pos.x, pos.y) = 255;
	}
	imshow("serpinsky triangle", img);
	waitKey();
}
int main()
{
	vector<Point2f> points;
	points.push_back(Point2f(0, 0));
	points.push_back(Point2f(1000, 0));
	points.push_back(Point2f(500, 866));
	fractal(0.5, 0.5, points);
	return 0;
}