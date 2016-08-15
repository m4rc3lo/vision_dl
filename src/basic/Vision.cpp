
#include "Vision.hpp"

#include <cstdlib>
#include <opencv2/highgui.hpp>  



void Vision::load(std::string path) 
{
    this->path_01 = std::string (path);
    
    this->source_01 = cv::imread(this->path_01.c_str());    
    if( !this->source_01.data )
    
    { 
        std::cerr << "No data! -- Exiting the program" << std::endl;
        exit (EXIT_FAILURE);
    }
}

void Vision::load(std::string path_01, std::string path_02) 
{
    this->path_01 = std::string (path_01);
    this->path_02 = std::string (path_02);
    
    this->source_01 = cv::imread(this->path_01.c_str());
    this->source_02 = cv::imread(this->path_02.c_str());
    
    if( !this->source_01.data || !this->source_02.data)
    
    { 
        std::cerr << "No data! -- Exiting the program" << std::endl;
        exit (EXIT_FAILURE);
    }
}



/*std::string Vision::get_path()
{
    return this->path;
}*/