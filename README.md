# ESP32 Agricultural Monitoring System with Arduino IoT Cloud


## 📌 Overview
This project enables real-time monitoring of soil conditions (moisture, NPK values) and environmental data (humidity, temperature) using an ESP32 microcontroller, with data visualization on Arduino IoT Cloud.

## 🌟 Features
- 📶 WiFi connectivity with automatic reconnection
- 🌱 Soil moisture measurement (0-100%)
- 🔬 NPK (Nitrogen, Phosphorus, Potassium) sensor integration
- 🌡️ Environmental monitoring (temperature & humidity)
- ☁️ Secure MQTT communication with Arduino IoT Cloud
- 📊 JSON-formatted data payloads
- ⚙️ Configurable sensor reading intervals

## 📦 Hardware Requirements
| Component | Specification |
|-----------|--------------|
| Microcontroller | ESP32 (DevKit recommended) |
| Soil Moisture Sensor | Capacitive or resistive analog sensor |
| NPK Sensor | JXCT or similar (UART/Modbus) |
| DHT Sensor | DHT11/DHT22 (temperature & humidity) |
| Power Supply | 5V/2A or LiPo battery |

## 🛠️ Wiring Diagram
ESP32 Pinout:

GPIO34 (ADC1_CH6) → Soil Moisture Sensor

GPIO15 → DHT Data Pin

GPIO16 (U2RX) → NPK Sensor TX

GPIO17 (U2TX) → NPK Sensor RX

3.3V/5V → Sensor VCC

GND → Sensor GND

Copy

## 🚀 Setup Instructions

### 1. Prerequisites
- Arduino IoT Cloud account
- ESP-IDF v4.4+ development environment
- USB-to-UART converter (for NPK sensor debugging)

## 2. Configuration

### 1. Clone this repository:
```bash
git clone https://github.com/yourusername/esp32-agri-monitor.git
cd esp32-agri-monitor
```

### 2. Update configuration:
Edit `main/main.c` to set:
```c
#define WIFI_SSID "your_wifi"       // Fix: Changed WIFL → WIFI
#define WIFI_PASS "your_password"   // Fix: Changed WIFL → WIFI
#define DEVICE_ID "your_device_id"
#define SECRET_KEY "your_secret_key"
```

Configure sensor calibration:
```c
#define DRY_VALUE 3000  // Calibrate for your soil
#define WET_VALUE 500
```

### 3. Building & Flashing
```bash
idf.py set-target esp32
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor
```

---

## Arduino IoT Cloud Setup
1. Create a new **"Thing"** in Arduino IoT Cloud  
2. Add variables matching the JSON structure:
   - `humidity` (float)
   - `temperature` (float)
   - `soilMoisture` (integer)

📊 Data Flow
mermaid
Copy
sequenceDiagram
    ESP32->>+Arduino Cloud: Connect via MQTT
    loop Every 10 seconds
        ESP32->>Sensors: Read data
        Sensors-->>ESP32: Return values
        ESP32->>Arduino Cloud: Publish JSON
    end
⚠️ Troubleshooting
Issue	Solution
WiFi connection fails	Verify credentials, check signal strength
NPK sensor not responding	Check UART wiring, verify baud rate
MQTT connection drops	Verify certificate, check secret key
ADC readings erratic	Ensure stable power supply
📜 License
MIT License - See LICENSE for details.

🤝 Contribution
Contributions are welcome! Please open an issue or PR for:

Additional sensor support

Power optimization

Enhanced error handling

For detailed development notes, see DEVELOPMENT.md

Copy

### Key Sections Included:

1. **Visual Elements**: Placeholder for project image and diagram
2. **Hardware Specs**: Clear table of required components
3. **Step-by-Step Setup**: From cloning to flashing
4. **Cloud Integration**: Specific Arduino IoT Cloud instructions
5. **Troubleshooting**: Common issues and solutions
6. **Visual Data Flow**: Mermaid diagram for easy understanding
7. **Future-Proofing**: Contribution guidelines and license

### Recommended Additions:
1. Add actual project images/videos
2. Include detailed calibration instructions
3. Add power consumption measurements
4. Include sample dashboard screenshots from Arduino IoT Cloud

This README provides both technical users and stakeholders with all necessary information while maintaining professional presentation.
