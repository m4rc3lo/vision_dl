#include <highgui.h>
//#include 
#include <iostream>
//#include <qt5/QtWidgets/QApplication>
#include <QApplication>

//
#include <thread>

//#include "code/texture.hpp"
#include "PointList.h"
#include "Grayscale.hpp"
#include "Show.hpp"

//std::vector<Show> images_; 

void run ();
void CallBack(int event, int x, int y, int flags, PointList* ptr_qtw);

int main(int argc, char **argv)
{
  
    QApplication app (argc, argv);
    
    PointList list;
    list.show();
    
    PointList* ptr_list = &list;
    
    //std::thread run_opencv(run);
    
    
    //run_opencv.join();
    
    cv::Ptr<cv::Mat> img_ = new cv::Mat(cv::imread("../../img/original/deb8_800x600.jpg"));
    
    cv::namedWindow("image", CV_WINDOW_KEEPRATIO);
    
    cv::setMouseCallback("image", CallBack, ptr_list);
    cv::imshow("image", *img_);
    
    return app.exec();
}

void run ()
{
    cv::Ptr<cv::Mat> img_ = new cv::Mat(cv::imread("../../img/original/deb8_800x600.jpg"));
    
    cv::namedWindow("image", CV_WINDOW_KEEPRATIO);
    
    
    cv::imshow("image", *img_);
}

void CallBack(int event, int x, int y, int flags, PointList* ptr_qtw)
{
    
    if  ( event == cv::EVENT_LBUTTONDOWN )
    {
          std::cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
    }
     else if  ( event == cv::EVENT_RBUTTONDOWN )
    {
          std::cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
    }
     else if  ( event == cv::EVENT_MBUTTONDOWN )
    {
          std::cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
    }
     else if ( event == cv::EVENT_MOUSEMOVE )
    {
          std::cout << "Mouse move over the window - position (" << x << ", " << y << ")" << std::endl;

     }
}