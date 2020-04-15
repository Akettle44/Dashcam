test:
	g++ ~/dashcam/src/video/VideoCapture.o ~/dashcam/src/main/main.o -lpthread -std=c++11 -o otest -I/usr/local/include/opencv4 -L/usr/local/lib/ -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_video -lopencv_videoio
subs: 
	+$(MAKE) -C ~/dashcam/src/video
	+$(MAKE) -C ~/dashcam/src/main

main:
	+$(MAKE) -C ~dashcam/src/main

video:
	+$(MAKE) -C VIDEO

