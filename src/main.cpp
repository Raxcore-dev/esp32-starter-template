/*
 * ESP32 Starter Template
 * PlatformIO C++ application: LED blinking, WiFi scanning, and serial output
 */

#include <Arduino.h>
#include <WiFi.h>

// Declare Serial for ESP32
extern HardwareSerial Serial;

// Pin definitions
#define LED_BUILTIN 2  // Most ESP32 boards have LED on GPIO2

// Timing constants
#define LED_BLINK_INTERVAL 250  // ms
#define WIFI_SCAN_INTERVAL 5000 // ms

// Global variables
unsigned long lastLedToggle = 0;
unsigned long lastWifiScan = 0;
bool ledState = false;

// Forward declaration
String getEncryptionType(int type);

void setup() {
    // Initialize serial communication
    Serial.begin(115200);
    while (!Serial) {
        ; // Wait for serial port to connect
    }

    // Initialize LED pin
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    // Print welcome message
    Serial.println();
    Serial.println("+----------------------------------------+");
    Serial.println("|     ESP32 Starter Template Loaded!     |");
    Serial.println("+----------------------------------------+");
    Serial.println();
    Serial.printf("ESP32 Chip Revision: %d\n", ESP.getChipRevision());
    Serial.printf("CPU Frequency: %d MHz\n", ESP.getCpuFreqMHz());
    Serial.printf("Flash Size: %d KB\n", ESP.getFlashChipSize() / 1024);
    Serial.printf("Free Heap: %d bytes\n", ESP.getFreeHeap());
    Serial.println();
    Serial.println("Starting WiFi scan...");
    Serial.println();

    // Initialize WiFi
    WiFi.mode(WIFI_MODE_STA);
}

void scanWiFiNetworks() {
    Serial.println("Scanning for WiFi networks...");
    Serial.println();

    int n = WiFi.scanNetworks();

    if (n == 0) {
        Serial.println("No networks found!");
    } else {
        Serial.printf("Found %d networks!\n", n);
        Serial.println();
        Serial.println("+----+---------------------+---------+--------+------+");
        Serial.println("| #  | SSID                | RSSI    | Chan   | Sec  |");
        Serial.println("+----+---------------------+---------+--------+------+");

        for (int i = 0; i < n; ++i) {
            Serial.printf("| %-2d | %-19s | %-7d | %-6d | %-4s |\n",
                i + 1,
                WiFi.SSID(i).substring(0, 19).c_str(),
                WiFi.RSSI(i),
                WiFi.channel(i),
                getEncryptionType(WiFi.encryptionType(i)).c_str()
            );
        }
        Serial.println("+----+---------------------+---------+--------+------+");
    }

    Serial.println();
    WiFi.scanDelete();
}

String getEncryptionType(int type) {
    switch (type) {
        case WIFI_AUTH_OPEN: return "OPEN";
        case WIFI_AUTH_WEP: return "WEP";
        case WIFI_AUTH_WPA_PSK: return "WPA";
        case WIFI_AUTH_WPA2_PSK: return "WPA2";
        case WIFI_AUTH_WPA_WPA2_PSK: return "WPA/WPA2";
        case WIFI_AUTH_WPA2_ENTERPRISE: return "WPA2-EAP";
        default: return "UNK";
    }
}

void printProgressBar(int progress, int total, int width) {
    float percentage = (float)progress / total * 100;
    int filledWidth = (progress * width) / total;

    Serial.print("[");
    for (int i = 0; i < width; i++) {
        if (i < filledWidth) {
            Serial.print("#");
        } else {
            Serial.print("-");
        }
    }
    Serial.printf("] %5.1f%%\r", percentage);
}

void loop() {
    unsigned long currentMillis = millis();

    // LED Blinking
    if (currentMillis - lastLedToggle >= LED_BLINK_INTERVAL) {
        lastLedToggle = currentMillis;
        ledState = !ledState;
        digitalWrite(LED_BUILTIN, ledState ? HIGH : LOW);

        // Visual feedback on serial
        Serial.print(ledState ? "LED ON  " : "LED OFF ");
        Serial.print(" | Free Heap: ");
        Serial.print(ESP.getFreeHeap());
        Serial.print(" bytes | Uptime: ");
        Serial.print(millis() / 1000);
        Serial.println("s");
    }

    // WiFi Scanning
    if (currentMillis - lastWifiScan >= WIFI_SCAN_INTERVAL) {
        lastWifiScan = currentMillis;
        scanWiFiNetworks();

        // Show system info
        Serial.println("System Info:");
        Serial.printf("   CPU Temp: %.1fC\n", temperatureRead());
        Serial.printf("   Min Free Heap: %d bytes\n", ESP.getMinFreeHeap());
        Serial.println();
    }

    // Small delay to prevent watchdog trigger
    delay(10);
}
