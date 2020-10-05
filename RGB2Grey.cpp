#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace cv;
using namespace std;
int main(){
    Mat src= imread("../123.jpeg");
    Mat grey(src.rows, src.cols, CV_8UC1, Scalar(0));
    for (int y = 0; y < src.rows; y++)
    {
        auto *cp = src.ptr<uchar>(y);
        auto *gp = grey.ptr<uchar>(y);
        for(int x = 0; x < src.cols; x++){
            *gp= (15*cp[0] + 75*cp[1] + 38*cp[2]) >> 7;
            cp+= 3;
            gp++;
        }
    }
    imshow("src",src);
    imshow("grey",grey);
    waitKey(0);

    return 0;
}