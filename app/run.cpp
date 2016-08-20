//------------------------------------------------------------------------------
/**!
* Dornbusch - 12/08/2016
* opencv 3.x testing ...
*/
//------------------------------------------------------------------------------

//#include <memory> /** for std::stshare_ptr */
#include <cstdint>
#include <cstdlib>
#include <iostream>
//------------------------------------------------------------------------------
//#include <opencv2/cvstd.hpp>
#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//------------------------------------------------------------------------------
#include "Show.hpp"
#include "Pyramid.hpp"
#include "Grayscale.hpp"
#include "Subtraction.hpp"
//------------------------------------------------------------------------------
/**
 * 
 */
const cv::String keys =
        "{help h usage ? |      | print this message   }"
        "{@path_image1   |<none>| original image       }"
        "{@path_image2   |      | image2 for compare   }"
        "{op operation   |<none>| \"string\"           }"
        "{value          | 1.0  | path to file         }"
        ;

enum class Operation : int8_t {Grayscale = 0, Subtraction = 1};

static void help ();
inline Operation hashit (cv::String const& operation_);
//------------------------------------------------------------------------------

int main (int argc, char **argv)
{
    cv::CommandLineParser parser (argc, argv, keys);
    parser.about("Vision Basic v0.0.1");
    
    if ( parser.has("help") || argc < 2 )
    {
        parser.printMessage();
        exit(EXIT_FAILURE);
    }
    
    switch (hashit(parser.get<cv::String>("operation"))) 
    {
        case Operation::Grayscale: 
        {
            //std::cout << "Ops_1" << std::endl;
            
            cv::Ptr<Grayscale> gray (new Grayscale());
            gray->load(parser.get<cv::String>(1));
            
            cv::Ptr<cv::Mat> image_dst = gray->run();// (new cv::Mat(gray->run()));
            
            dl::Show::show(gray->get_original_01(), image_dst, "Original Image", "Grayscale Image");
            break;
        }
        
        case Operation::Subtraction:
        {
        //    std::stringstream stream_;
        //    stream_ << hashit(parser.get<cv::String>("operation", true));
        //    std::cout <<  "\t " << stream_ << std::endl;
            //cv::Ptr<Grayscale> gray();
            //cv::Mat image_dst;
            //cv::Ptr<cv::Mat> image_dst();  
            
            //std::string("../img/original/r1w4_640x480.png")
            //gray->load(parser.get<cv::String>(1));
            //image_dst = gray->run();
            //.reset(&gray->run());// = cv::Ptr<cv::Mat>.operator ()(cv::Mat(gray->run());//new cv::Ptr<cv::Mat>(cv::Mat(gray->run()));
            
            //cv::namedWindow("Original Image 01", CV_WINDOW_KEEPRATIO);
            //cv::imshow("Original Image 01", gray->get_original_01());
            
            //cv::namedWindow("Grayscale Image", CV_WINDOW_KEEPRATIO);
            //cv::imshow("Grayscale Image", image_dst);
            //cv::imshow("Grayscale Image", (cv::Mat*)image_dst);
            //cv::waitKey(0);
            std::cout << "Ops_2" << std::endl;            
            break;            
            
        }
        default:
        {   
            std::cout << "Ops_3" << std::endl;
        }    
                
    }
    
    std::cout << "Ops_" << std::endl;
    exit(EXIT_SUCCESS) ;
    
}  
    
    //--------------------------------------------------------------------------
    //process images
    
    /*
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

*/
    
void help ()
{
    std::cout 
            << "\tThis program illustrates the use of basic structures in opencv 3.1.0\t"
            << "\tInterate a structure cv::Mat"
            << "Usage: "
            ;
            
}

inline Operation hashit (cv::String const& operation_)
{
    if (operation_.compare("grayscale"))
    {
        std::cout << "grayscale" << std::endl;
        return Operation::Grayscale;
    }
    
    else if (operation_.compare("subtraction"))
    {
         std::cout << "subtraction" << std::endl;
        return Operation::Subtraction;
    }
}
