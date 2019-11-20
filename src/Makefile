all: button video 

button:
	g++ -g -Wall /button/button.cpp -o buttontest

video:	
	g++ -I/usr/local/include/opencv4 -L/usr/local/lib/ -g -o test VideoCapture.cpp VideoCapture.hpp -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_video -lopencv_videoio
