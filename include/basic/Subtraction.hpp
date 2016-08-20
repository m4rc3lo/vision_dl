/* 
 * File:   Subtraction.hpp
 * Author: marcelo
 *
 * Created on 14 de Agosto de 2016, 21:38
 */

#ifndef SUBTRACTION_HPP
#define	SUBTRACTION_HPP

#include "Vision.hpp"

class Subtraction : public Vision
{
    
    public:
        
        cv::Ptr<cv::Mat> run();       
        
};

#endif	/* SUBTRACTION_HPP */

