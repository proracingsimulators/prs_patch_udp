import socket
import os
import time

address = 'localhost'
port = 53520

class TelemetryData:
    def __init__(self):
        self.roll = 1.0
        self.pitch = 2.0
        self.heave = 3.0
        self.yaw = 4.0
        self.sway = 5.0
        self.surge = 6.0
        self.tractionLoss = 7.0
        self.gear = 8

def main():
    data = TelemetryData()

    process_name = os.path.basename(__file__)
    print(f"Process name: {process_name}")
    print("Client started. Writing to server:")
    print("Roll | Pitch | Heave | Yaw | Sway | Surge | Loss | Gear |")

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_address = ('localhost', port)

    while True:
        data_str = f"{data.roll}-{data.pitch}-{data.heave}-{data.yaw}-{data.sway}-{data.surge}-{data.tractionLoss}-{data.gear}"
        client_socket.sendto(data_str.encode('utf-8'), server_address)
        print(data_str)
        time.sleep(0.01)

if __name__ == "__main__":
    main()
