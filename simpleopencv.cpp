#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void camera_in()
{
    VideoCapture cap;
    cap.open(0, CAP_AVFOUNDATION);

    if (!cap.isOpened())
    {
        cerr << "Camera open failed!" << endl;
        return;
    }

    cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;

    Mat frame, inversed;
    while (true)
    {
        cap >> frame;
        if (frame.empty())
            break;

        inversed = ~frame;

        imshow("frame", frame);
        imshow("inversed", inversed);

        if (waitKey(10) == 27)
            break;
    }
    destroyAllWindows();
}

int main()
{
    camera_in();
}
