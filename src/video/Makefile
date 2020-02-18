video.o: VideoCapture.cpp VideoCapture.hpp
	g++ -I/usr/local/include/opencv4 -L/usr/local/lib/ -Wall -c -g VideoCapture.cpp VideoCapture.hpp -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_video -lopencv_videoio

videotest: VideoCapture.cpp VideoCapture.hpp
	g++ -I/usr/local/include/opencv4 -L/usr/local/lib/ -Wall VideoCapture.cpp VideoCapture.hpp -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_video -lopencv_videoio -o videotest
