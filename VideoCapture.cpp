#include "VideoCapture.hpp"

int main(int, char**)
{
	VideoCapture cap(-1); //opening the only camera attached, hence the 0
	if(!cap.isOpened())
	{
//	#ifdef DEBUG
		std::cout << "Coudl not open video or camera\n";
//	#endif
		return -1; //end the program, possibly add error flag here later	
	}

	//Mat edges; //data structure for storing large entities
	
	int width = 1920;
	int height = 1080;
	
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

	//VideoWriter video("akoutput.avi",cv::VideoWriter::fourcc('X', '2', '6', '4'), 30, Size(width, height), true);

	return 0;
} 

