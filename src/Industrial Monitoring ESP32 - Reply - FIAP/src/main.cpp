#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <MPU6050_tockn.h>

// DHT22
#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// PIR
#define PIR_PIN 33

// Analógicos
#define LDR_PIN 34
#define GAS_PIN 35
#define MIC_PIN 32
#define CURRENT_PIN 23
#define PRESSURE_PIN 26

// MPU6050
MPU6050 mpu(Wire);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Wire.begin();
  mpu.begin();
  mpu.calcGyroOffsets(true);

  pinMode(PIR_PIN, INPUT);

  Serial.println("Sistema de monitoramento iniciado.");
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int light = analogRead(LDR_PIN);
  int gasLevel = analogRead(GAS_PIN);
  int microphone = analogRead(MIC_PIN);
  int current = analogRead(CURRENT_PIN);
  int pressure = analogRead(PRESSURE_PIN);

  bool motionDetected = digitalRead(PIR_PIN);
  float vibration = mpu.getAccX(); // you can also use getAccY/Z for more data

  Serial.println("======= SENSOR READINGS =======");
  Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" °C");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
  Serial.print("Light (LDR): "); Serial.println(light);
  Serial.print("Gas Level (MQ2): "); Serial.println(gasLevel);
  Serial.print("Microphone (simulated): "); Serial.println(microphone);
  Serial.print("Current (simulated): "); Serial.println(current);
  Serial.print("Pressure (simulated): "); Serial.println(pressure);
  Serial.print("Motion Detected: "); Serial.println(motionDetected ? "YES" : "NO");
  Serial.print("Vibration (MPU6050): "); Serial.println(vibration);
  Serial.println("================================\n");

  delay(2000);
}
