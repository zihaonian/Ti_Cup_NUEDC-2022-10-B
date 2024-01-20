# Single Color Grayscale Blob Tracking Example
#
# This example shows off single color grayscale tracking using the OpenMV Cam.

import sensor, image, time, math
import pyb
from pyb import Pin
# Color Tracking Thresholds (Grayscale Min, Grayscale Max)
# The below grayscale threshold is set to only find extremely bright white areas.
thresholds = (0, 74)

sensor.reset()
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False) # must be turned off for color tracking
sensor.set_auto_whitebal(False) # must be turned off for color tracking
sensor.set_vflip(1)
sensor.set_hmirror(1)
clock = time.clock()
PIN1=Pin('P0',Pin.OUT_PP)
PIN1.low()
led = pyb.LED(3)
led1 = pyb.LED(1)
led.off()
count_i=0
count_k=0
count_j=0    
# Only blobs that with more pixels than "pixel_threshold" and more area than "area_threshold" are
# returned by "find_blobs" below. Change "pixels_threshold" and "area_threshold" if you change the
# camera resolution. "merge=True" merges all overlapping blobs in the image.
while(True):
    clock.tick()
    img = sensor.snapshot()
    blobs = img.find_blobs([thresholds], roi= [145, 120, 30, 140],pixels_threshold=100, area_threshold=100, merge=True)
    for blob in blobs:
       count_k=count_k+1
    if count_k<2:
       count_j=1
       count_k=0
    else:
       count_k=0
       count_j=0    
    for blob in blobs:
        # These values depend on the blob not being circular - otherwise they will be shaky.
        if blob.elongation() > 0.5:
            img.draw_edges(blob.min_corners(), color=0)
            img.draw_line(blob.major_axis_line(), color=0)
            img.draw_line(blob.minor_axis_line(), color=0)
        # These values are stable all the time.
        img.draw_rectangle(blob.rect(), color=127)
        img.draw_cross(blob.cx(), blob.cy(), color=127)
        #print(blob.pixels())
        print(count_j)
        if blob.pixels()>1000 and count_j==1:
           count_i=count_i+1
           led.on() 
           if count_i<=2:
             time.sleep_ms(500)
           led.off() 
           if count_i==3:
             count_i=0
             PIN1.high()
             led1.on()
             time.sleep_ms(1000)
             PIN1.low()
             led1.off()
          

        #if blob.pixels()/last_num>2:
            #print(2)
        #print(blob.pixels())
