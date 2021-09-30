/*============================================================================*/
/* File Description                                                           */
/*============================================================================*/
/**
 * @file        load_display.cpp
 * @author      Lena HOUACINE
 * @brief       OpenCV project to show how to load and display an image
 */
 /*============================================================================*/

 /*============================================================================*/
 /* Includes                                                                   */
 /*============================================================================*/

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/*============================================================================*/
/* Defines                                                                    */
/*============================================================================*/

/*============================================================================*/
/* Local Constants                                                            */
/*============================================================================*/

/*============================================================================*/
/* Local Types                                                                */
/*============================================================================*/

/*============================================================================*/
/* Static Variables                                                           */
/*============================================================================*/

/*============================================================================*/
/* Static Functions Prototype                                                 */
/*============================================================================*/

/******************************************************************************/
/* Public Functions                                                           */
/******************************************************************************/

void callbackEvents(int event, int x, int y, int flags, void* userdata) {

    if (event == EVENT_LBUTTONDOWN)
    {
        cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if (event == EVENT_RBUTTONDOWN)
    {
        cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if (event == EVENT_MBUTTONDOWN)
    {
        cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if (event == EVENT_MOUSEMOVE)
    {
        cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;

    }
}

/*============================================================================*/
/* Function Description                                                       */
/*============================================================================*/
/**
 * @brief         Main
 * @param[in]     argc        : Number of arguments
 * @param[in]     argv        : Arguments list
 * @return        <0 if error, 0 if success, >0 if warning
 */
 /*============================================================================*/

int main(int /*argc*/, char** /*argv*/)
{
    int res(0);
    const char filename[] = "../smarties.jpg";

    cv::Mat img = cv::imread(filename, cv::IMREAD_COLOR/*IMREAD_GRAYSCALE*/);
    if (img.empty())
    {
        std::cout << "Cannot load image!" << std::endl;
        res = -1;
    }
    else
    {
        cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
        cv::imshow("image", img);

        double angle(0.);
        cv::Mat img1;

        while (true) {

            char key = static_cast<char>(cv::waitKey(0));

            if ('l' == key) {
                angle += 90;
                cv::Point2f pt(img.cols / 2., img.rows / 2.);
                cv::Mat r = getRotationMatrix2D(pt, angle, 1.0);
                cv::warpAffine(img, img1, r, cv::Size(img.cols, img.rows));
                cv::imshow("image", img1);
                cv::waitKey(0);
            }

            if ('r' == key) {
                angle -= 90;
                cv::Point2f pt(img.cols / 2., img.rows / 2.);
                cv::Mat r = getRotationMatrix2D(pt, angle, 1.0);
                cv::warpAffine(img, img1, r, cv::Size(img.cols, img.rows));
                cv::imshow("image", img1);
                cv::waitKey(0);
            }

            if ('s' == key) {
                imwrite("result.jpg", img1);
                std::cout << "Save image" << std::endl;
            }
        }
        cv::waitKey(0);
    }
    return res;
}
