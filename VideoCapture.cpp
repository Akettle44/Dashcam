#include "VideoCapture.hpp"

int main(int, char**)
{

//	VideoCapture cap(1, cv::CAP_V4L2); //opening the only camera attached, hence the 0

	VideoCapture cap(1, cv::CAP_V4L2);

	cap.set(CAP_PROP_FRAME_WIDTH, 800);
 	cap.set(CAP_PROP_FRAME_HEIGHT, 600);
 	cap.set(CAP_PROP_FPS, 30);
	//cap.set(CAP_MODE_YUYV);
	//cap.set(CAP_PROP_FOURCC,( 'H', '2', '6', '4')); 
//	SetCaptureProperty(cap,cv::CAP_PROP_FOURCC,cv::CV_FOURCC('H', '2', '6', '4'));
//	cap.set(cv::CAP_PROP_FOURCC, 0x21);

	cap.set(CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));

	if(!cap.isOpened())
	{
//	#ifdef DEBUG
		std::cout << "Could not open video or camera\n";
//	#endif
		return -1; //end the program, possibly add error flag here later	
	}

	//Mat edges; //data structure for storing large entities


	int width = cap.get(3);
	int height = cap.get(4);

	std::cout << "This is the width \n" << width;
	std::cout << "\nThis is the height \n" << height;
	std::cout << "\n";
	
	//VideoWriter video("akoutput.mp4",cv::CAP_FFMPEG, 0x21, 30, Size(width, height));	
	VideoWriter video("akoutput.avi",cv::CAP_FFMPEG, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, Size(width, height), true);	

	for(;;)
	{
		Mat frame;
		cap >> frame;
		if(frame.empty())
		{
			break;
		}
		imshow("Hello there", frame);
		if(waitKey(10) == 27)
		{
			break;
		}
		
	}

	return 0;
} 

