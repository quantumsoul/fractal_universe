#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
using namespace cv;
Point2f f1(Point2f p) {
	Point2f r;
	r.x = 0;
	r.y = 0.16 * p.y;
	return r;
}
Point2f f2(Point2f p) {
	Point2f r;
	r.x = 0.2 * p.x - 0.26 * p.y;
	r.y = 0.23 * p.x + 0.22 * p.y + 1.6;
	return r;
}
Point2f f3(Point2f p) {
	Point2f r;
	r.x = -0.15 * p.x + 0.28 * p.y;
	r.y = 0.26 * p.x + 0.24 * p.y + 0.44;
	return r;
}
Point2f f4(Point2f p) {
	Point2f r;
	r.x = 0.85 * p.x + 0.04 * p.y;
	r.y = -0.04 * p.x + 0.85 * p.y + 1.6;
	return r;
}

void draw(int iter = 1000000) {
	Point2f pos = Point2f(0, 0);
	const int dierolls = 100;
	Mat img = Mat(1080, 1920, CV_8UC1, Scalar::all(0));
	for (int i = 0; i < iter; i++)
	{
		int rnd = rand() % dierolls;
		if (rnd <= 1)
			pos = f1(pos);
		else if (rnd <= 8)
			pos = f2(pos);
		else if (rnd <= 15)
			pos = f3(pos);
		else
			pos = f4(pos);
		img.at<uchar>((pos.x + 3) * 100, pos.y * 100) = 255;
	}
	imshow("barnsley_fern", img);
	waitKey();
}
int main()
{
	draw();
	return 0;
}