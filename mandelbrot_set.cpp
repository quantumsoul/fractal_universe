#include<opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
using namespace cv;

int main()
{
	int iter=1000000;
    float i;
	Point2f pos;
	Mat img = Mat(1080, 1920, CV_8U, Scalar::all(0));
	for (int j = 0; j < img.rows; j++) {
		for (int k = 0; k < img.cols; k++) {
			float cx = (j-300)*0.005;
			float cy = (k-300)*0.005;
			float a = 0.0, b = 0.0;
			for (i = 0; i < 50; ++i) {
				float temp = a;
				a = a*a - b*b + cx;
				b = 2 * temp * b + cy;
				if (fabs(a + b) >= 16)
					break;
			}
			img.at<uchar>(j, k) = (uchar)(i*255.0/50.0);
		}
	}
	imshow("mandelbrot_set", img);
	waitKey();
	return 0;
}
