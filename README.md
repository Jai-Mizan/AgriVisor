# 🌾 AgriVisor: AI-Powered Crop Prediction System

<div align="center">
  <img src="./assets/system_overview.png" width="800" alt="System Overview">
</div>

## 📋 Project Status
✅ **Completed**  
- FinalProject (ESP32 firmware & sensor integration)  

🔧 **In Progress**  
- Dashboard Local Server (Panel-based visualization)  

📅 **Upcoming**  
- AI Flow Chart documentation  
- Circuit Diagram finalization  

## 🗂️ File Structure
AI_Model_Crop_Prediction/
├── 📁 FinalProject/ # ESP32 main project
│ ├── firmware/ # Embedded code
│ └── analytics/ # Data processing
│
├── 📁 Dashboard_Local_Server/ # Visualization (WIP)
│ ├── app.py # Panel dashboard
│ └── assets/ # Visual assets
│
├── 📄 AI_Flow_Chart.png # Model architecture (294KB)
├── 📄 Circuit_Diagram.jpg # Hardware schematic (124KB)
└── 📄 documentation/ # Project docs


## 🚀 Getting Started

### 1. Hardware Setup
```bash
# Navigate to FinalProject
cd AI_Model_Crop_Prediction/FinalProject

# Build & flash ESP32
idf.py set-target esp32
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor

2. Launch Dashboard (Development)
bash

# From project root
panel serve Dashboard_Local_Server/app.py \
  --show \
  --autoreload \
  --port 5006
🔍 Key Components
Component	Status	Description
ESP32 Firmware	✅	Sensor data collection
Arduino Cloud	✅	Real-time monitoring
Prediction Model	✅	Random Forest implementation
Dashboard UI	🔧	Panel-based visualization
Documentation	📅	Flow charts & diagrams
📊 Data Flow
mermaid

flowchart LR
    A[Sensors] --> B(ESP32)
    B --> C{{Arduino Cloud}}
    C --> D[Prediction Model]
    D --> E[Dashboard]
    E --> F[User]
🛠️ Development Checklist
Core firmware implementation

Complete dashboard features:

Real-time data streaming

Model inference display

Mobile responsiveness

Finalize documentation:

AI flow chart

Circuit diagram

Setup guide

📜 License
MIT License © 2025 - See LICENSE for details.

<div align="center"> <img src="./assets/AI_Flow_Chart.png" width="400" alt="AI Flow Chart"> <img src="./assets/Circuit_Diagram.jpg" width="400" alt="Circuit Diagram"> </div> ```
