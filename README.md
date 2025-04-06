# 🌱 ESP32 Agricultural Monitoring System with Arduino IoT Cloud

<div align="center">
  <img src="assets/system_architecture.png" width="800" alt="System Architecture">
</div>

## 📋 Table of Contents
- [Key Features](#-key-features)
- [Hardware Requirements](#-hardware-requirements)
- [Setup Guide](#-setup-guide)
- [Cloud Configuration](#-arduino-iot-cloud-configuration)
- [Data Flow](#-data-flow)
- [Troubleshooting](#-troubleshooting)
- [Contributing](#-contributing)
- [License](#-license)

---

## 🌟 Key Features
| Feature | Description |
|---------|-------------|
| **Multi-Sensor Monitoring** | Soil moisture, NPK values, temperature & humidity |
| **Cloud Integration** | Real-time data to Arduino IoT Cloud via MQTT |
| **Smart Calibration** | Configurable dry/wet values for soil sensor |
| **Stable Connectivity** | Automatic WiFi reconnection |
| **Structured Data** | JSON-formatted payloads |

---

## 📦 Hardware Requirements
### Essential Components
- **ESP32 DevKit** (Recommended: ESP32-WROOM-32)
- **Soil Moisture Sensor** (Capacitive preferred)
- **NPK Sensor** (JXCT-IoT model)
- **DHT22** (Temperature & Humidity)
- **Power Supply** (5V/2A with battery backup)

### Wiring Guide
```plaintext
ESP32 Pin    →  Sensor
-----------------------------
GPIO34 (ADC) → Soil Moisture AO
GPIO15       → DHT22 Data
GPIO16 (RX2) → NPK Sensor TX
GPIO17 (TX2) → NPK Sensor RX
3.3V         → All Sensor VCC
GND          → All Sensor GND
🛠️ Setup Guide
1. Prerequisites
Arduino IoT Cloud account

ESP-IDF v4.4+ (or newer)

Python 3.8+ (for optional dashboard)

2. Firmware Setup
bash
Copy
git clone https://github.com/yourusername/esp32-agri-monitor.git
cd esp32-agri-monitor

# Configure WiFi credentials
sed -i 's/your_wifi/YOUR_WIFI_SSID/' main/main.c
sed -i 's/your_password/YOUR_WIFI_PASS/' main/main.c

# Build and flash
idf.py set-target esp32
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor
3. Sensor Calibration
Edit main/main.c:

c
Copy
// For dry soil (in air)
#define DRY_VALUE 3000  
// For fully wet soil
#define WET_VALUE 500   
☁️ Arduino IoT Cloud Configuration
Create a Thing with these variables:

yaml
Copy
humidity: float (0-100%)
temperature: float (°C)
soilMoisture: int (0-100%)
nitrogen: int (ppm)
phosphorus: int (ppm)
potassium: int (ppm)
Dashboard Setup:

Add gauge widgets for soil/NPK values

Create time-series charts for trends

🔄 Data Flow
mermaid
Copy
sequenceDiagram
    participant ESP32
    participant Cloud
    participant Dashboard
    
    Note over ESP32: Every 10 seconds
    ESP32->>Cloud: MQTT Connect
    ESP32->>Sensors: Read data
    Sensors-->>ESP32: Raw values
    ESP32->>Cloud: Publish JSON
    Cloud->>Dashboard: Visualize
⚠️ Troubleshooting
Symptom	Solution
No WiFi connection	Verify SSID/PW, check router logs
NPK sensor timeout	Confirm baud rate (9600 default)
MQTT disconnects	Check secret key validity
Inconsistent ADC readings	Add 0.1μF capacitor to sensor VCC
🤝 Contributing
We welcome contributions in:

🌿 New sensor integrations

🔋 Power optimization

📈 Enhanced data analytics

Process:

Fork the repository

Create a feature branch (git checkout -b feature/your-feature)

Submit a Pull Request

📜 License
MIT License - See LICENSE for details.

<div align="center"> <img src="assets/dashboard_preview.png" width="400" alt="Dashboard Preview"> <img src="assets/circuit_diagram.png" width="400" alt="Circuit Diagram"> </div> ```
Key Improvements:
Visual Hierarchy:

Added proper header image placeholders

Consistent section icons (🌱, ⚠️, etc.)

Better table formatting for features/troubleshooting

Technical Enhancements:

Added sed commands for quick WiFi config

Specific pinout recommendations

Clear variable types for Arduino Cloud

Usability:

Table of Contents for navigation

Mermaid diagram with full sequence

Contributor workflow details

Professional Touches:

Proper YAML syntax for cloud variables

Dual-image footer for dashboards/diagrams

Clear licensing reference

Maintenance-Friendly:

Markdown linting compatibility

Future-proof structure

Mobile-responsive design

To implement:

Create an assets/ folder for images

Replace placeholder image paths

Update repository URL

Add actual screenshots of your dashboard

This version maintains all your technical content while dramatically improving readability and presentation quality.
