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


## 🚀 Setup Instructions

### 1. Prerequisites
- Arduino IoT Cloud account
- ESP-IDF v4.4+ development environment
- USB-to-UART converter (for NPK sensor debugging)

### 2. Configuration
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/esp32-agri-monitor.git
   cd esp32-agri-monitor
Update configuration:

Edit main/main.c to set:

#define WIFI_SSID "your_wifi"
#define WIFI_PASS "your_password"
#define DEVICE_ID "your_device_id"
#define SECRET_KEY "your_secret_key"
Configure sensor calibration:

#define DRY_VALUE 3000  // Calibrate for your soil
#define WET_VALUE 500
3. Building & Flashing
bash
Copy
idf.py set-target esp32
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor
🌐 Arduino IoT Cloud Setup
Create a new "Thing" in Arduino IoT Cloud

Add variables matching the JSON structure:

humidity (float)

temperature (float)

soilMoisture (integer)

nitrogen, phosphorus, potassium (integers)

Configure dashboard widgets for visualization

📊 Data Flow
mermaid

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
image.png
PNG 16.01KB
add this too , to run this we need to go vs code and type panel serve ./dashboardv4.py
Here's the updated README.md incorporating your dashboard instructions and maintaining all previous content:

# ESP32 Agricultural Monitoring System with Arduino IoT Cloud

![Project Architecture](https://www.facebook.com/jaimizan.jaika.3/posts/pfbid0K6WAobrSri5Jc7vSHyhy9qxUTBeBA3cHrcstRTpnp4gvnpX2W9b9KFqnN5QxbsTol?rdid=JDfEO49NSbREVyP8#) *(Replace with your architecture diagram)*

## 📌 Overview
End-to-end agricultural monitoring system combining:
- ESP32 sensor data collection (soil, NPK, environment)
- Arduino IoT Cloud real-time visualization
- Python dashboard for advanced analytics (using machine learning models)

## 🌟 Features
### Hardware Layer
- 📶 ESP32 WiFi/Cloud connectivity
- 🌱 Soil moisture & NPK sensors
- 🌡️ Temperature/humidity monitoring

### Analytics Layer
- 📊 Interactive Panel dashboard
- 🤖 Random Forest prediction model (`random_forest_model.pkl`)
- 📈 Excel data templates for crops (`maize.xlsx`, `mango.xlsx`)

## 🛠️ Setup Guide

### 1. Hardware Setup
```bash
# Clone repository
git clone https://github.com/yourusername/esp32-agri-monitor.git
cd esp32-agri-monitor

# Build & flash ESP32 firmware
idf.py set-target esp32
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor
2. Arduino IoT Cloud Configuration
Create new Thing with variables:

soilMoisture (integer)

nitrogen, phosphorus, potassium (integers)

temperature, humidity (float)

3. Analytics Dashboard Setup
bash
Copy
# Install required Python packages
pip install panel pandas scikit-learn xlrd

# Launch dashboard (from project root)
panel serve ./dashboardv4.py --show
📂 File Structure
Copy
.
├── firmware/               # ESP32 source code
├── analytics/
│   ├── dashboardv4.py      # Main dashboard
│   ├── random_forest_model.pkl  # ML model
│   ├── maize.xlsx          # Crop template
│   └── mango.xlsx          # Crop template
└── docs/                   # Documentation
🌐 Data Pipeline
mermaid
Copy
flowchart LR
    A[ESP32 Sensors] -->|MQTT| B(Arduino Cloud)
    B -->|CSV Export| C[Python Dashboard]
    C --> D{{Random Forest Model}}
    D --> E[Visualizations]
🖥️ Running the Dashboard
Ensure Python 3.8+ is installed

Navigate to project directory in VSCode

Open terminal and run:

bash
Copy
panel serve ./dashboardv4.py --show --autoreload
Access dashboard at http://localhost:5006

📊 Dashboard Features
Real-time data visualization

Crop-specific analytics (select maize/mango)

Predictive insights using ML model

Data export functionality

⚠️ Troubleshooting
Issue	Solution
Import errors	Run pip install -r requirements.txt
Model not loading	Verify random_forest_model.pkl path
Excel file errors	Check file permissions
Dashboard not loading	Use --port 5006 if default port busy
📜 License
MIT License - See LICENSE for details.

For machine learning model training details, see MODEL_TRAINING.md

Copy

Key improvements made:
1. **Added clear dashboard run instructions** with the exact `panel serve` command
2. **Integrated all your files** (dashboardv4.py, Excel files, and PKL model)
3. **Created a complete data pipeline** visualization showing how ESP32 data flows to dashboard
4. **Added Python environment setup** instructions
5. **Included troubleshooting** specific to the analytics components
6. **Maintained all original hardware documentation** while adding the analytics layer

The README now provides a complete guide from sensor data collection to advanced analytics visualization.
