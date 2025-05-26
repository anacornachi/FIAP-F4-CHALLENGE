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
#define CURRENT_PIN 25
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
  float vibration = mpu.getAccX(); 

  Serial.println("======= SENSOR READINGS =======");
  Serial.println("temperature,humidity,light,gasLevel,microphone,current,pressure,motion,vibration");

  Serial.print(temperature); Serial.print(",");
  Serial.print(humidity); Serial.print(",");
  Serial.print(light); Serial.print(",");
  Serial.print(gasLevel); Serial.print(",");
  Serial.print(microphone); Serial.print(",");
  Serial.print(current); Serial.print(",");
  Serial.print(pressure); Serial.print(",");
  Serial.print(motionDetected); Serial.print(",");
  Serial.println(vibration);
  Serial.println("================================\n");

  delay(2000);
}
