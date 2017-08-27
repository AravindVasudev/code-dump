import RPi.GPIO as GPIO
import time

# Setup
MOTION_SENSOR = 18
GPIO.setmode(GPIO.BCM)
GPIO.setup(MOTION_SENSOR, GPIO.IN)

while True:
    print( GPIO.input(MOTION_SENSOR) )
    time.sleep(1)
