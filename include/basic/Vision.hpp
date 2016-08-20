/*
* Dornbusch - 13/08/0216
* Interface for basic algorithms
*/

#ifndef VISION_HPP
#define  VISION_HPP

#include <iostream>
#include <string>

#include <opencv2/core.hpp>

class Vision
{
  public:

    void load(cv::String path);
    void load(cv::String path1, cv::String path2);
    
    cv::Ptr<cv::Mat> get_original_01(){ return this->source_01; }
    cv::Ptr<cv::Mat> get_original_02(){ return this->source_02; }
    
    virtual cv::Ptr<cv::Mat> run()=0;

  protected:

    cv::String path_01;
    cv::String path_02;
    
    cv::Ptr<cv::Mat> source_01;
    cv::Ptr<cv::Mat> source_02;
};

#endif
