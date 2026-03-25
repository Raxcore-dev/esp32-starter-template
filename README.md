# ESP32 Starter Template

> **A feature-rich, beginner-friendly ESP32 Arduino template with WiFi scanner, LED blinking, system monitoring, and formatted serial output.**

Perfect for IoT enthusiasts, embedded systems learners, and rapid prototyping with ESP32 microcontrollers.

![ESP32](https://img.shields.io/badge/Board-ESP32-blue?style=for-the-badge)
![PlatformIO](https://img.shields.io/badge/Platform-PlatformIO-success?style=for-the-badge)
![Framework](https://img.shields.io/badge/Framework-Arduino-orange?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![GitHub stars](https://img.shields.io/github/stars/raxcore-dev/esp32-starter-template?style=for-the-badge)
![GitHub forks](https://img.shields.io/github/forks/raxcore-dev/esp32-starter-template?style=for-the-badge)

## Features

This template comes packed with useful features out of the box:

- **Built-in LED Blinking** - Visual feedback with the onboard LED
- **WiFi Scanner** - Scans and displays nearby WiFi networks in a formatted table
- **System Monitoring** - Real-time display of:
  - Free heap memory
  - CPU temperature
  - Uptime counter
- **Formatted Serial Output** - Clean console output with ASCII tables
- **Fast Upload** - Optimized upload speed for quick development cycles

## Prerequisites

### Hardware
- ESP32 Development Board (ESP32 DevKit, NodeMCU-32S, etc.)
- USB cable (make sure it's a data cable, not charge-only!)
- Computer with USB port

### Software
- [PlatformIO Core](https://platformio.org/install) (or PlatformIO VS Code extension)
- Python 3.7+
- USB-to-Serial drivers (CP210x or CH340, depending on your board)

### Install PlatformIO

```bash
# Install PlatformIO Core globally
pip install platformio

# Or use the VS Code extension (recommended for beginners)
# Extensions -> Search "PlatformIO IDE" -> Install
```

### USB Permissions (Linux)

If you get permission errors when uploading:

```bash
# Add your user to the dialout group
sudo usermod -aG dialout $USER

# Log out and log back in for changes to take effect
```

## Quick Start

### 1. Connect Your ESP32

Plug your ESP32 into your computer via USB. Verify it's detected:

```bash
ls /dev/ttyUSB*
# Should show: /dev/ttyUSB0
```

### 2. Build and Upload

```bash
# Navigate to the project folder
cd esp32-starter-template

# Build the project
pio run

# Upload to the ESP32
pio run --target upload

# Or build and upload in one command
pio run --target upload
```

### 3. Open Serial Monitor

```bash
# Open serial monitor
pio device monitor

# Or with custom baud rate
pio device monitor --baud 115200
```

**Pro tip:** Press `Ctrl+T` then `Ctrl+Q` to exit the serial monitor.

## Project Structure

```
esp32-starter-template/
├── src/
│   └── main.cpp          # Main application code
├── .gitignore            # Git ignore file
├── platformio.ini        # PlatformIO configuration
├── LICENSE               # MIT License
├── README.md             # This file
├── CONTRIBUTING.md       # Contribution guidelines
├── CODE_OF_CONDUCT.md    # Community standards
└── SECURITY.md           # Security policy
```

## Configuration

### Change Upload Port

Edit `platformio.ini` and update the `upload_port`:

```ini
upload_port = /dev/ttyUSB0  # Change to your port (e.g., COM3 on Windows)
```

### Use Different ESP32 Board

Uncomment the appropriate environment in `platformio.ini`:

```ini
; For ESP32-S3
[env:esp32s3]
platform = espressif32
board = esp32-s3-devkitc-1
...

; For ESP32-C3
[env:esp32c3]
platform = espressif32
board = esp32-c3-devkitm-1
...
```

Then upload with:
```bash
pio run -e esp32s3 --target upload
```

## What the Code Does

### LED Blinking
- Toggles the built-in LED every 250ms
- GPIO 2 is used (standard for most ESP32 boards)
- Status shown in serial monitor

### WiFi Scanner
- Scans for networks every 5 seconds
- Displays results in a formatted table:
  - Network name (SSID)
  - Signal strength (RSSI)
  - Channel
  - Security type

### System Info
- CPU temperature (using internal sensor)
- Free heap memory
- Minimum free heap
- Uptime counter

## Troubleshooting

### "Permission denied" when uploading
```bash
sudo usermod -aG dialout $USER
# Then log out and back in
```

### "Failed to connect to ESP32"
1. Hold the **BOOT** button on your ESP32
2. Press **RESET/EN** button
3. Release BOOT button
4. Try uploading again

### No serial output
- Check that `monitor_speed = 115200` matches `Serial.begin(115200)` in code
- Try pressing the RESET button on the ESP32
- Check your USB cable (some are charge-only)

### WiFi scan shows no networks
- Make sure WiFi is enabled in your area
- Try moving closer to your router
- Check antenna connection (if your board has external antenna)

## Customization Ideas

Want to extend this template? Here are some ideas:

- **Add a button input** - Read GPIO pins for user interaction
- **Connect to WiFi** - Add your credentials and connect to the internet
- **Web server** - Host a simple webpage on your ESP32
- **MQTT client** - Connect to IoT platforms like Home Assistant
- **Deep sleep** - Add power-saving modes for battery projects
- **OLED display** - Add an I2C OLED for visual output
- **Sensors** - Add temperature, humidity, motion sensors, etc.

## License

This project is licensed under the MIT License - feel free to use it for your projects!

## Contributing

Found a bug? Have a suggestion? Feel free to open an issue or submit a pull request!

## Resources

- [ESP32 Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf)
- [Arduino ESP32 Documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
- [PlatformIO Documentation](https://docs.platformio.org/en/latest/)
- [ESP32 Forum](https://www.esp32.com/)

---

**Made for the ESP32 community**

Happy coding!
