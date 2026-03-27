/*
 * DHT11 Sensor Test for ESP32
 * Reads temperature and humidity from DHT11 sensor
 * Displays readings on Serial Monitor
 */

#include <Arduino.h>
#include <DHT.h>

// DHT11 Sensor Configuration
#define DHT_PIN 14       // GPIO pin connected to DHT11 data pin
#define DHT_TYPE DHT11  // DHT sensor type (DHT11 or DHT22)

// Initialize DHT sensor
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
    // Initialize serial communication
    Serial.begin(115200);
    
    // Wait for serial monitor to connect
    while (!Serial) {
        delay(10);
    }
    
    Serial.println("\n=================================");
    Serial.println("DHT11 Sensor Test");
    Serial.println("=================================");
    
    // Initialize DHT sensor
    dht.begin();
    
    Serial.println("DHT11 sensor initialized...");
    Serial.println("Reading temperature and humidity every 2 seconds...");
    Serial.println("=================================\n");
}

void loop() {
    // Wait 2 seconds between measurements (DHT11 is slow)
    delay(2000);
    
    // Read humidity
    float humidity = dht.readHumidity();
    
    // Read temperature as Celsius
    float temperature = dht.readTemperature();
    
    // Read temperature as Fahrenheit
    float temperatureF = dht.readTemperature(true);
    
    // Check if any reads failed
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT11 sensor!");
        Serial.println("Check wiring and connections.");
        return;
    }
    
    // Calculate heat index (how hot it feels)
    float heatIndex = dht.computeHeatIndex(temperatureF, humidity);
    
    // Display readings
    Serial.println("--- DHT11 Reading ---");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
    
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
    
    Serial.print("Temperature: ");
    Serial.print(temperatureF);
    Serial.println(" °F");
    
    Serial.print("Heat Index: ");
    Serial.print(heatIndex);
    Serial.println(" °F");
    
    Serial.println("=====================\n");
}
