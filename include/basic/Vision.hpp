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

    void load(std::string path);
    void load(std::string path1, std::string path2);
    
    cv::Mat get_original_01(){ return this->source_01; }
    cv::Mat get_original_02(){ return this->source_02; }
    
    virtual cv::Mat run()=0;

  protected:

    std::string path_01;
    std::string path_02;
    
    cv::Mat source_01;
    cv::Mat source_02;
    
};

#endif
