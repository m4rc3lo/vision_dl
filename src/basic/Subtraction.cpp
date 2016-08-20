/* 
 * File:   Subtraction.cpp
 * Author: marcelo
 * 
 * Created on 14 de Agosto de 2016, 21:38
 */

#include "Subtraction.hpp"

cv::Ptr<cv::Mat> Subtraction::run()
{
    
    if (! (this->source_01->rows == this->source_02->rows && this->source_01->cols == this->source_02->cols))
    {
        std::cerr << "Incompatible images dimensions -- Exiting the program" << std::endl;
        exit (EXIT_FAILURE);
    }
    
    cv::Ptr<cv::Mat> sub_img (new cv::Mat (this->source_01->rows, this->source_01->cols, this->source_01->type()));

    
    for (int height = 0 ; height < this->source_01->rows ; height++) 
    {
        cv::Vec3b* ptr_src_01 = this->source_01->ptr<cv::Vec3b>(height);
        cv::Vec3b* ptr_src_02 = this->source_02->ptr<cv::Vec3b>(height);
        cv::Vec3b* ptr_dst = sub_img->ptr<cv::Vec3b>(height);

            for (int width = 0 ; width < this->source_01->cols ; width++ ) 
            {
                
                uchar sub_b = abs(ptr_src_01[width][0] - ptr_src_02[width][0]);
                uchar sub_g = abs(ptr_src_01[width][1] - ptr_src_02[width][1]);
                uchar sub_r = abs(ptr_src_01[width][2] - ptr_src_02[width][2]);
                
                //std::cout << "sub_b: " << sub_b << std::endl;
                //std::cout << "sub_g: " << sub_g << std::endl;
                //std::cout << "sub_r: " << sub_r << std::endl;
                
                if ((sub_b < 50) && (sub_g < 50) && (sub_r < 50)) 
                {
                    ptr_dst[width][0] = 255;
                    ptr_dst[width][1] = 255;
                    ptr_dst[width][2] = 255;
                }
                else 
                {
                    ptr_dst[width][0] = ptr_src_02[width][0];
                    ptr_dst[width][1] = ptr_src_02[width][1];                 
                    ptr_dst[width][2] = ptr_src_02[width][2];
                }
            }
        }
    return sub_img;
}