test:
	g++ ~/dashcam/src/video/VideoCapture.o ~/dashcam/src/main/main.o ~/dashcam/src/button/button.o -lpthread -std=c++11 -g -o otest -I/usr/local/include/opencv4 -L/usr/local/lib/ -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_video -lopencv_videoio -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 -D__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 
subs: 
	+$(MAKE) -C ~/dashcam/src/video
	+$(MAKE) -C ~/dashcam/src/main
	+$(MAKE) -C ~/dashcam/src/button

main:
	$(MAKE) -C ~/dashcam/src/main
	
button: 
	$(MAKE) -C ~/dashcam/src/button

video:
	$(MAKE) -C ~/dashcam/src/video

