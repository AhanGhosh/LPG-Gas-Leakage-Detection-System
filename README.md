# 🔥 LPG Gas Leakage Detection System 🚨
<img width="635" height="480" alt="image" src="https://github.com/user-attachments/assets/918b2753-9d73-4d8c-a467-bd3597ad592e" />

A smart IoT-based safety system to detect LPG gas leakage using the MQ6 gas sensor and ESP32 microcontroller. The system automatically activates safety measures like ventilation, audible alerts, gas supply cutoff, and sends real-time email notifications.

---

## 🛠️ Project Overview

This project is designed to enhance safety in environments where Liquefied Petroleum Gas (LPG) is used, such as homes, kitchens, and small industries. It detects gas leaks and performs the following actions automatically:

- Activates an **exhaust fan** for ventilation.
- Triggers a **buzzer** to alert people nearby.
- Rotates a **servo motor** to shut off the **LPG regulator knob**.
- Sends an **email alert** to the user via the internet using **ESP32 Wi-Fi** capabilities.

---

## ⚙️ Features

- 🔍 Real-time gas leak detection using **MQ6 gas sensor**
- 🧠 Smart processing using **ESP32 microcontroller**
- 🌬️ Automatic exhaust fan activation
- 🔊 Buzzer for local alert
- 🔧 Servo motor control to turn off LPG regulator
- 📧 Email notification via **IFTTT** (or SMTP)
- 💻 Fully programmable using **Arduino IDE**

---

## 🧰 Components Used

| Component           | Description                          |
|---------------------|--------------------------------------|
| ESP32               | Wi-Fi-enabled microcontroller        |
| MQ6 Gas Sensor      | Detects LPG, propane, butane gases   |
| Servo Motor         | Closes LPG regulator automatically   |
| Buzzer              | Provides audible alert               |
| Exhaust Fan         | Ventilates the area                  |
| Power Supply        | 5V/9V as per component requirements  |
| Jumper Wires, PCB   | For circuit connection               |

---

## 🔌 Circuit Connections

| MQ6 Sensor Pin | ESP32 Pin  |
|----------------|------------|
| VCC            | 3.3V       |
| GND            | GND        |
| AOUT           | Analog pin (e.g., GPIO34) |

| Servo Motor    | ESP32 Pin  |
|----------------|------------|
| VCC            | VIN/5V     |
| GND            | GND        |
| Signal         | GPIO (e.g., GPIO18) |

**Note:** Buzzer and exhaust fan connected to digital output pins via transistor (if required, depending on current rating).

---

## 📤 Email Notification Setup

You can use [**IFTTT Webhooks**](https://ifttt.com/maker_webhooks) or any SMTP method to send email alerts. The ESP32 triggers the Webhook URL when gas is detected.

### Using IFTTT:
1. Create an applet with Webhooks + Gmail
2. Copy your Webhook URL and paste it into your code
3. Modify the message template as needed

---

## 🧾 How It Works

1. The **MQ6 sensor** continuously monitors the surrounding air.
2. When gas concentration exceeds the **threshold**, ESP32:
   - Turns on **buzzer** and **exhaust fan**
   - Rotates **servo motor** to close the gas regulator
   - Sends an **email alert** using Wi-Fi
3. System remains active and resets once safe levels are restored.

---

## 🖥️ Software Requirements

- Arduino IDE (1.8 or later)
- ESP32 Board Manager installed in Arduino IDE
- Wi-Fi credentials and Webhook setup

---

## 🧪 Testing

- Tested with LPG lighter gas to simulate leak
- Checked response time and reliability of sensor
- Verified servo motor successfully rotated to desired angle
- Email received instantly upon detection

---

## 📸 Images / Video (Optional)

(https://youtu.be/mLNk6Z8TWc8)

---

## 📌 Future Improvements

- Add SMS alert feature using GSM module
- Display gas level data on OLED/ LCD screen
- Integrate mobile app for real-time monitoring

---



---

## 🙌 Acknowledgements

- Inspired by real-world need for kitchen and industrial gas safety.
- Special thanks to Arduino & ESP32 communities for support and documentation.

