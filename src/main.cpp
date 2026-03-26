/*
 * Simple LED Blink Example for ESP32
 * Blinks an LED on and off every 1 second
 */

#include <Arduino.h>

// Pin definition - change if needed
#define LED_PIN 14  // GPIO 4 (or use 2 for built-in LED on some boards)
#define LED_PIN2 12 // GPIO 5 (or use 2 for built-in LED on some boards)
void setup() {
    // Initialize LED pin as output
    pinMode(LED_PIN, OUTPUT);
    pinMode(LED_PIN2, OUTPUT);
}

void loop() {
    // Turn LED ON
    digitalWrite(LED_PIN, HIGH);
    delay(1000);  // Wait 1 second
    
    // Turn LED OFF
    digitalWrite(LED_PIN, LOW);
    delay(1000);  // Wait 1 second

    digitalWrite(LED_PIN2, HIGH);
    delay(1000);  // Wait 1 second

    // Turn LED OFF
    digitalWrite(LED_PIN2, LOW);
    delay(1000);  // Wait 1 second

}
