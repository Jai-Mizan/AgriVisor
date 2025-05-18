#include "thingProperties.h" //note that thingproperties.h file is confedential so it will not included here
#include <DHT.h>

#define DHTPIN 2      // DHT sensor pin
#define DHTTYPE DHT11 // or DHT22

#define NPK_PIN A0
#define SOIL_MOISTURE_PIN A1

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  delay(1500); 

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  dht.begin();
}

void loop() {
  ArduinoCloud.update();

  // Read temperature and humidity
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (!isnan(temp)) {
    temperature = temp;
  }

  if (!isnan(hum)) {
    humidity = hum;
  }

  // Read NPK Sensor (calibration placeholder)
  int rawNPK = analogRead(NPK_PIN);
  npkValue = map(rawNPK, 0, 1023, 0, 100);  // Replace with actual calibration

  // Read Soil Moisture Sensor (calibrated)
  int rawMoisture = analogRead(SOIL_MOISTURE_PIN);
  soilMoisture = map(rawMoisture, 1023, 300, 0, 100); // 100 = wet, 0 = dry

  // Print to Serial Monitor
  Serial.print("Temp: "); Serial.print(temperature);
  Serial.print(" °C, Humidity: "); Serial.print(humidity);
  Serial.print(" %, Soil Moisture: "); Serial.print(soilMoisture);
  Serial.print(" %, NPK: "); Serial.println(npkValue);

  delay(5000); // Update every 5 seconds
}
