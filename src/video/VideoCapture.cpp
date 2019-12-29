#include "VideoCapture.hpp"

VideoCapture initCapture()
{
	VideoCapture cap(0, cv::CAP_V4L2);
	cap.set(CAP_PROP_FRAME_WIDTH, 800);
 	cap.set(CAP_PROP_FRAME_HEIGHT, 600);
 	cap.set(CAP_PROP_FPS, 24);
	cap.set(CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));

	if(!cap.isOpened())
	{
	#ifdef DEBUG
		std::cout << "Could not open video or camera\n";
	#endif
		return -1; //end the program, possibly add error flag here later	
	}

/*	int width = cap.get(3); //3 is width
	int height = cap.get(4); //4 is height
	int framerate = cap.get(5); //5 is framerate
*/	
	return cap;
}

VideoWriter initWriter(VideoCapture cap)
{
	
	VideoWriter video("akoutput.avi",cv::CAP_FFMPEG,cv::VideoWriter::fourcc('H', '2', '6', '4'),cap.get(5),Size(800, 600),true);

	return video;
}

void closeVideo(VideoCapture cap, VideoWriter video)
{
	cap.release();
	video.release();
}
