//------------------------------------------------------------------------------
/*
* Dornbusch - 12/08/2016
* opencv 3.0 testing ...
*
*/
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "Pyramid.hpp"
#include "Grayscale.hpp"
#include "Subtraction.hpp"
//------------------------------------------------------------------------------
int main (int argc, char **argv)
{
    //--------------------------------------------------------------------------
    //process images
    //Grayscale image;  
    //image.load(std::string("../img/original/r1w4_640x480.png"));    
    //cv::Mat gray_image = image.run();
    
    Subtraction sutraction_image;
    sutraction_image.load(std::string("../../img/original/deb8_800x600.jpg"),
                          std::string("../../img/original/deb8_tux_800x600.jpg"));
    
    cv::Mat sub_image = sutraction_image.run();
    
    //--------------------------------------------------------------------------
    // show results
    //cv::namedWindow("Original Image 01", CV_WINDOW_KEEPRATIO);
    cv::namedWindow("Original Image 01", CV_WINDOW_KEEPRATIO);
    cv::imshow("Original Image 01", sutraction_image.get_original_01());
    
    cv::namedWindow("Original Image 02", CV_WINDOW_KEEPRATIO);
    cv::imshow("Original Image 02", sutraction_image.get_original_02());

    cv::namedWindow("Subtraction Image", CV_WINDOW_KEEPRATIO);
    cv::imshow("Subtraction Image", sub_image);
    
    cv::waitKey(0);    
    //--------------------------------------------------------------------------
  
    return 0;
}
//------------------------------------------------------------------------------
