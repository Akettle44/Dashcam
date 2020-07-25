#!/bin/bash
v4l2-ctl -d /dev/video0 --set-fmt-video=width=800,height=600,pixelformat=1
v4l2-ctl -d /dev/video0 --set-ctrl=exposure_auto=1
v4l2-ctl -d /dev/video0 --set-ctrl=focus_auto=0
v4l2-ctl -d /dev/video0 --set-ctrl=exposure_absolute=156
v4l2-ctl -d /dev/video0 --set-ctrl=gain=10

