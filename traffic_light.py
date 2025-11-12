import serial
import time

# Connect to Arduino on COM13
arduino = serial.Serial(port='COM13', baudrate=9600, timeout=1)
time.sleep(2)  # Wait for Arduino to initialize

def send_signal(signal):
    arduino.write(signal.encode())
    print(f"Signal sent: {signal}")

try:
    while True:
        # Red light
        send_signal('R')
        print("🔴 Red ON")
        time.sleep(5)

        # Yellow light
        send_signal('Y')
        print("🟡 Yellow ON")
        time.sleep(2)

        # Green light
        send_signal('G')
        print("🟢 Green ON")
        time.sleep(5)

        # Green blinks 3 times
        for i in range(3):
            send_signal('G')
            print("🟢 Green BLINK ON")
            time.sleep(0.5)
            send_signal('X')
            print("⚫ Green OFF")
            time.sleep(0.5)

except KeyboardInterrupt:
    print("\nProgram stopped.")
    send_signal('X')
    arduino.close()
