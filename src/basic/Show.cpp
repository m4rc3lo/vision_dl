/** 
 * File:   Show.cpp
 * Author: Dornbusch
 * 
 * Created on 19 de Agosto de 2016, 15:18
 */

#include <opencv2/highgui.hpp>

#include "Show.hpp"

namespace dl
{
    Show::Show(){}
    
    void Show::show(cv::Ptr<cv::Mat> image, cv::String name_)
    {
        cv::namedWindow("Original Image 01", CV_WINDOW_KEEPRATIO);
        cv::imshow("Original Image 01", *image);
        
        cv::waitKey(0);
    }
    
    void Show::show(cv::Ptr<cv::Mat> image_1, cv::Ptr<cv::Mat> image_2, cv::String name_1, cv::String name_2 )
    {
        cv::namedWindow(name_1.c_str(), CV_WINDOW_KEEPRATIO);
        cv::imshow(name_1.c_str(), *image_1);
        
        cv::namedWindow(name_2.c_str(), CV_WINDOW_KEEPRATIO);
        cv::imshow(name_2.c_str(), *image_2);
        
        cv::waitKey(0);
    }
    
}