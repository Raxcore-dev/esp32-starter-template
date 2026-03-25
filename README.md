# ESP32 Starter Template

> **A PlatformIO-based ESP32 C++ template with WiFi scanner, LED blinking, system monitoring, and formatted serial output.**

A professional starter project for embedded development with ESP32 microcontrollers using PlatformIO and modern C++.

![ESP32](https://img.shields.io/badge/Board-ESP32-blue?style=for-the-badge)
![PlatformIO](https://img.shields.io/badge/Platform-PlatformIO-success?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![GitHub stars](https://img.shields.io/github/stars/raxcore-dev/esp32-starter-template?style=for-the-badge)
![GitHub forks](https://img.shields.io/github/forks/raxcore-dev/esp32-starter-template?style=for-the-badge)

## Features

This template provides essential embedded development features:

- **Built-in LED Blinking** - GPIO control with onboard LED (GPIO2)
- **WiFi Scanner** - Network discovery with formatted ASCII table output
- **System Monitoring** - Real-time telemetry:
  - Free heap memory
  - CPU temperature
  - System uptime
- **Formatted Serial Output** - Clean console output with ASCII tables
- **PlatformIO Ready** - Pre-configured for immediate development

## Prerequisites

### Hardware
- ESP32 Development Board (ESP32 DevKit, NodeMCU-32S, etc.)
- USB cable (data cable required, not charge-only)
- Computer with USB port

### Software
- [PlatformIO Core](https://platformio.org/install)
- Python 3.7+
- USB-to-Serial drivers (CP210x or CH340, depending on your board)

### Install PlatformIO

```bash
# Install PlatformIO Core globally
pip install platformio

# Or use the VS Code extension
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

# Build and upload in one command
pio run --target upload
```

### 3. Open Serial Monitor

```bash
# Open serial monitor
pio device monitor

# Or with custom baud rate
pio device monitor --baud 115200
```

**Tip:** Press `Ctrl+T` then `Ctrl+Q` to exit the serial monitor.

## Project Structure

```
esp32-starter-template/
├── src/
│   └── main.cpp          # Main C++ application
├── .gitignore            # Git ignore rules
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
monitor_speed = 115200
upload_speed = 921600

; For ESP32-C3
[env:esp32c3]
platform = espressif32
board = esp32-c3-devkitm-1
monitor_speed = 115200
upload_speed = 921600
```

Then upload with:
```bash
pio run -e esp32s3 --target upload
```

## Code Overview

### LED Blinking
- Toggles the built-in LED every 250ms
- GPIO 2 is used (standard for most ESP32 boards)
- Status output to serial monitor

### WiFi Scanner
- Scans for networks every 5 seconds
- Displays results in a formatted ASCII table:
  - Network name (SSID)
  - Signal strength (RSSI)
  - Channel
  - Security type (OPEN, WEP, WPA, WPA2)

### System Telemetry
- CPU temperature (internal sensor)
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
- Verify `monitor_speed = 115200` matches `Serial.begin(115200)` in code
- Press the RESET button on the ESP32
- Check your USB cable (some are charge-only)

### WiFi scan shows no networks
- Ensure WiFi is available in your area
- Move closer to your router
- Check antenna connection (if your board has external antenna)

## Extending the Project

Ideas for customization:

- **GPIO Input** - Add button/switch input handling
- **WiFi Client** - Connect to networks and access the internet
- **Web Server** - Host a web interface on your ESP32
- **MQTT Client** - Integrate with IoT platforms like Home Assistant
- **Deep Sleep** - Implement power-saving modes for battery projects
- **OLED Display** - Add I2C OLED for visual output
- **Sensors** - Integrate temperature, humidity, motion sensors

## License

This project is licensed under the MIT License.

## Contributing

Found a bug or have a feature request? Open an issue or submit a pull request.

## Resources

- [ESP32 Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf)
- [ESP32 Technical Reference](https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_en.pdf)
- [PlatformIO Documentation](https://docs.platformio.org/en/latest/)
- [PlatformIO ESP32 Platform](https://docs.platformio.org/en/latest/platforms/espressif32.html)
- [ESP32 Forum](https://www.esp32.com/)

---

**Built for the ESP32 embedded community**
