# ESP32 Agricultural Monitoring System with Arduino IoT Cloud


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
