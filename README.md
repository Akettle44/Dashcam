# DIY Dashcam with Beaglebone Black and OpenCV

This is a DIY personal dashcam using a Beaglebone and a Logitech C920. The code is brief and consists of OpenCV, V4L2, and FFMPEG currently running on Elementary OS 5.0 Juno and Ubuntu 18.04 LTS Bionic Beaver. I am using this as an introduction to embedded systems and wanted to expand this to eventually use a dnn for image processing.

## Getting Started

If all of the prequisites have been satisfied, the quickest way to use this code is the below command

```
//navigate to desired directory
git clone https://github.com/Akettle44/Dashcam.git
make all
./c920settings.sh
./test
```

### Prerequisites

Basic Hardware:

BeagleBone Black, Ethernet Cable, Mini USB Cable, 8 GB (minimum) SD Card

Basic Software:

Ubuntu / Debian (haven't tested on Debian), OpenCV4.0, FFMPEG4.1.3,V4L2


### Installing

For someone trying to emulate this as one of their first projects as well, I would highly suggest following the installation guide very carefully. In particular, trying to use your laptop / desktop natively before cross-compiling to the BeagleBone. 

Note: 

I am going to assume that the user has setup a functioning installation of Ubuntu or Debian, if not there are many tutorials to achieve that!

Step 1: Install V4L2
```
sudo apt-get install v4l-utils
```


End with an example of getting some data out of the system or using it for a little demo

## Authors

* **Andrew Kettle** *

## License

This project is licensed under the GNU GPLv3 [LICENSE.md](LICENSE.md) file for details
