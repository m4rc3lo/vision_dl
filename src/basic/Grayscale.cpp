#include "Grayscale.hpp"

cv::Mat Grayscale::run()
{
    
    cv::Mat gray = cv::Mat(this->source_01.rows, this->source_01.cols, CV_8UC1);
    
        
    for (int height = 0 ; height < this->source_01.rows ; height++) 
    {        
        cv::Vec3b* src_ptr = this->source_01.ptr<cv::Vec3b>(height);
        uchar* dst_ptr = gray.ptr<uchar>(height);
        
        for (int width = 0 ; width < this->source_01.cols ; width++ ) 
        {   
            float temp = 0.f;
            
            temp = src_ptr[width][0] * 0.114f;
            temp += src_ptr[width][1] * 0.587f;
            temp += src_ptr[width][2] * 0.299f;
            
            dst_ptr[width] = (uchar)temp;
        }
    }
    
    return gray;
}