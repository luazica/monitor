import serial
import requests
import json

arduino = serial.Serial('/dev/ttyACM0', 9600)

while True:
    line = arduino.readline().decode().strip()

    if line:
        data = json.loads(line)

        print(data)

        requests.post(
            "http://localhost:8080/api/sensor",
            json=data
        )