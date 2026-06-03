# Smart Helmet System

## Project Overview

This project is a Smart Helmet System designed to improve rider safety using embedded systems and IoT technologies. The helmet integrates a GPS module and GSM module with an Arduino-based controller to detect emergency situations and send the rider’s live location through SMS.

The system can be used in:
- Road accident emergency response
- Rider safety monitoring
- Smart transportation systems
- Real-time tracking applications

When an accident or emergency trigger occurs, the helmet automatically:
1. Collects the rider’s real-time GPS coordinates.
2. Generates a Google Maps location link.
3. Sends the location to predefined emergency contacts using GSM/SMS communication.

## Key Features
- 📍 Real-time GPS tracking
- 📡 GSM-based SMS alert system
- 🚨 Emergency notification system
- 🔋 Portable embedded hardware setup
- 🛰 Google Maps live location sharing
- ⚡ Arduino-based low-cost implementation
- 🧠 Expandable for crash detection & IoT cloud integration

## Technologies Used

### Hardware
- Arduino Uno / Nano
- NEO-6M GPS Module
- SIM800L GSM Module
- Li-ion Battery / External Power Supply
- Voltage Divider Circuit
- Connecting Wires & Breadboard

### Software
- Arduino IDE
- Embedded C / Arduino Programming
- TinyGPS++ Library
- SoftwareSerial Library

## System Architecture

### Workflow
1. GPS continuously receives satellite coordinates.
2. Arduino processes latitude and longitude values.
3. GSM module connects to the mobile network.
4. On emergency trigger:
   - Arduino creates a Google Maps URL.
   - GSM module sends SMS to emergency contacts.
   - Receiver opens the Maps link for live location.

### Hardware Connections

**GPS Module → Arduino**
| GPS Pin | Arduino Pin |
|---------|-------------|
| TX      | D4          |
| RX      | D3          |
| VCC     | 5V          |
| GND     | GND         |

**GSM Module → Arduino**
| SIM800L Pin | Arduino Pin |
|-------------|-------------|
| TX          | D8          |
| RX          | D7 (via voltage divider) |
| VCC         | External 4V Supply |
| GND         | GND         |

> **Important Notes:**
> **Power Requirements**
> The SIM800L GSM module requires:
> - 3.7V–4.2V supply
> - Minimum 2A current capability
> 
> *The module should not be powered directly from the Arduino 5V pin.*

## Software Workflow
1. **Initialization:**
   - Serial communication starts
   - GSM module initializes using AT commands
   - GPS module starts receiving satellite data
2. **Monitoring:**
   - GPS coordinates are continuously parsed
   - GSM network status is monitored
3. **Emergency Trigger:**
   - When triggered:
     - Current location is fetched
     - SMS is generated
     - Location link is sent to emergency contact

### Sample SMS Output
```
Emergency Alert!

Location:
https://maps.google.com/?q=28.6139,77.2090
```

### AT Commands Used
| Command | Purpose |
|---------|---------|
| `AT` | Check GSM communication |
| `ATE0` | Disable echo |
| `AT+CPIN?` | Verify SIM status |
| `AT+CREG?` | Check network registration |
| `AT+CSQ` | Signal quality |
| `AT+CMGF=1` | SMS text mode |
| `AT+CMGS` | Send SMS |

## Future Improvements
- MPU6050-based accident detection
- Bluetooth helmet authentication
- Cloud data logging
- Mobile application integration
- Voice assistant support
- IoT dashboard monitoring
- SOS button integration
- Fall detection using AI models

## Challenges Faced
- SIM800L power instability
- GSM network registration issues
- GPS satellite acquisition delay
- Baud rate synchronization problems
- SoftwareSerial communication conflicts

## Learning Outcomes
This project helped in understanding:
- Embedded systems design
- Serial communication protocols
- GSM/GPS integration
- IoT system architecture
- Real-time tracking systems
- Hardware debugging & power management

## Required Libraries
- [TinyGPS++](https://github.com/mikalhart/TinyGPSPlus)
- `SoftwareSerial` (built-in)

## Installation Steps
1. Install Arduino IDE
2. Install TinyGPS++ library
3. Connect GPS and GSM modules
4. Insert active SIM card
5. Upload Arduino code
6. Open Serial Monitor
7. Verify GSM and GPS responses
8. Test SMS functionality

## Conclusion
The Smart Helmet System demonstrates how embedded systems and communication technologies can be combined to create a practical and cost-effective safety solution for riders. The project provides a strong foundation for future IoT-based transportation safety systems and real-time emergency response applications.

## Author
**Badri Vishal Pandey**  
B.Tech ECE — Galgotias College of Engineering & Technology  
*Interested in IoT, Embedded Systems, AI & Smart Product Development*
