
#ifndef GRAYSCALE_HPP
#define GRAYSCALE_HPP

#include "Vision.hpp"

class Grayscale : public Vision
{
    public:
        
        Grayscale();
        cv::Ptr<cv::Mat> run();
};

#endif
