test:
	g++ ~/dashcam/src/video/VideoCapture.o ~/dashcam/src/main/main.o ~/dashcam/src/button/button.o -o otest -I/usr/local/include/opencv4 -L/usr/local/lib/ -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_video -lopencv_videoio
subs: 
	+$(MAKE) -C ~/dashcam/src/video
	+$(MAKE) -C ~/dashcam/src/main
	+$(MAKE) -C ~/dashcam/src/button

main:
	+$(MAKE) -C ~dashcam/src/main
	
button: 
	+$(MAKE) -C BUTTON

video:
	+$(MAKE) -C VIDEO

