#include "VideoCapture.hpp"

int main(int, char**)
{
	VideoCapture cap(0, cv::CAP_V4L2);

	cap.set(CAP_PROP_FRAME_WIDTH, 800);
 	cap.set(CAP_PROP_FRAME_HEIGHT, 600);
 	cap.set(CAP_PROP_FPS, 24);
	cap.set(CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
	//cap.set(CAP_PROP_FOURCC, cv::VideoWriter::fourcc('H', '2', '6', '4'));

	if(!cap.isOpened())
	{
	#ifdef DEBUG
		std::cout << "Could not open video or camera\n";
	#endif
		return -1; //end the program, possibly add error flag here later	
	}

	int fcount = 0;
	int width = cap.get(3); //3 is width
	int height = cap.get(4); //4 is height
	int framerate = cap.get(5); //5 is framerate

/*
	std::cout << "This is the width \n" << width;
	std::cout << "\nThis is the height \n" << height;
	std::cout << "\nThis is the framerate \n" << framerate;
	std::cout << "\n";
*/

	VideoWriter video("akoutput.avi",cv::CAP_FFMPEG,cv::VideoWriter::fourcc('H', '2', '6', '4'),cap.get(5),Size(800, 600),true);	

	for(fcount; fcount < 1560; fcount++)
	{
		Mat frame;
		cap >> frame;
		video << frame; //YOU'RE TELLING ME YOU NEED TO WRITE IT TO THE OUTPUT TOO??? --> 
		//The above line represents three days of my life that I will never get back, YAY
		if(frame.empty())
		{
			break;
		}
	}
	cap.release();
	video.release();

	return 0;
} 

