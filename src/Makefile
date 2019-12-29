test:
	g++ ~/dashcam/src/video/VideoCapture.o ~/dashcam/src/main/main.o ~/dashcam/src//button/button.o -o test

subs: 
	+$(MAKE) -C ~/dashcam/src/video
	+$(MAKE) -C ~/dashcam/src/main
	+$(MAKE) -C ~/dashcam/src/button

main:
	$(MAKE) -C MAIN

button: 
	$(MAKE) -C BUTTON

video:
	$(MAKE) -C VIDEO

