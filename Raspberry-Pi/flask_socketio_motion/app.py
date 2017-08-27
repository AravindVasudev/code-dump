from flask import Flask, render_template
from flask_socketio import SocketIO
import RPi.GPIO as GPIO
import threading
import time

# RPi GPIO init
MOTION_SENSOR = 18
GPIO.setmode(GPIO.BCM)
GPIO.setup(MOTION_SENSOR, GPIO.IN)

# App Instance
app = Flask(__name__)
app.config['SECRET_KEY'] = 'shamballa'

# SocketIO init
socketio = SocketIO(app)

# Sensor thread
def MotionState():
    while True:
        time.sleep(1)
        socketio.emit('motion', GPIO.input(MOTION_SENSOR))

thread = threading.Thread(target=MotionState)
thread.start()

# Index
@app.route('/')
def index():
    return render_template('index.html') 

# Start server
# if __name__ == '__main__':
#    app.run(host='0.0.0.0')
#    socketio.run(app)
