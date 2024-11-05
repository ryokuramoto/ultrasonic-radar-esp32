# Ultrasonic Radar with ESP32

This project is an Ultrasonic Radar system using an ESP32 microcontroller, a servo motor, an ultrasonic sensor, and a buzzer. The system measures the distance to an object using the ultrasonic sensor, moves the servo motor, and activates a buzzer if the object is within a certain distance.

## Features

- Measures distance using an ultrasonic sensor.
- Moves a servo motor to scan different angles.
- Activates a buzzer when an object is detected within a specified range.

## Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/ryokuramoto/UltrasonicRadar-ESP32.git
    cd UltrasonicRadar-ESP32
    ```

2. **Install the required libraries:**
    - Ensure you have the ESP32Servo library installed. You can install it via the Arduino Library Manager.

3. **Upload the code:**
    - Open `UltrasonicRadar-ESP32.ino` in the Arduino IDE.
    - Select the correct board and port for your ESP32.
    - Upload the code to your ESP32.

## Usage

1. **Connect the hardware:**
    - Connect the ultrasonic sensor, servo motor, and buzzer to the specified pins on the ESP32 as defined in the code.
    - Ultrasonic Sensor: 
      - Trig Pin -> GPIO 5
      - Echo Pin -> GPIO 18
    - Buzzer:
      - Buzzer Pin -> GPIO 19
    - Servo Motor:
      - Servo Pin -> GPIO 8

2. **Power the ESP32:**
    - Ensure the ESP32 is powered via USB or another appropriate power source.

3. **Run the system:**
    - The system will start measuring distances, moving the servo, and activating the buzzer if an object is detected within 10 cm.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
