# ESP32-Based-2.4-GHz-Signal-Monitor
ESP32-based 2.4GHz Bluetooth &amp; Wi-Fi Jammer with real-time OLED display. Features dual NRF24L01 modules, separate code for BT/Wi-Fi modes, and a compact portable design. For educational and security research purposes only.

# ESP32 Bluetooth & Wi-Fi Jammer with OLED

<div align="center">
  <img src="https://img.shields.io/badge/ESP32-DevKit-blue?style=for-the-badge&logo=espressif" alt="ESP32">
  <img src="https://img.shields.io/badge/NRF24L01-2.4GHz-red?style=for-the-badge" alt="NRF24L01">
  <img src="https://img.shields.io/badge/OLED-SSD1306-lightgrey?style=for-the-badge" alt="OLED">
  <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" alt="License">
</div>

> ⚠️ **EDUCATIONAL PURPOSE ONLY:** This project demonstrates 2.4GHz signal interference (jamming) techniques for security research and learning. Do not use it to disrupt networks or devices you do not own. Unauthorized jamming is illegal in most countries.

---

## 📖 About The Project

This project turns an ESP32 into a portable 2.4GHz jammer using two NRF24L01 modules. It features a real-time OLED display showing the current mode, channel, and status. The code is designed to be **flashed separately** for Bluetooth or Wi-Fi jamming using the same hardware setup.

The project was built to demonstrate the vulnerability of unencrypted 2.4GHz communication protocols and to serve as a learning tool for wireless security research.

---

## ✨ Features

| Feature | Description |
| :--- | :--- |
| **Dual NRF24L01** | Uses two modules for wider frequency coverage. |
| **OLED Display** | Shows current mode, channel, and status in real-time. |
| **Portable** | Runs on ESP32 power (USB). |
| **Dual Mode** | Separate code for Bluetooth (79 channels) and Wi-Fi (14 channels). |
| **Simple Wiring** | Minimal components, easy to build. |

---

## 🛠️ Hardware Required

| Component | Quantity |
| :--- | :--- |
| ESP32 Development Board | 1 |
| NRF24L01+PA+LNA Module (with Adapter Board) | 2 |
| 0.96" OLED Display (I2C, SSD1306) | 1 |
| Jumper Wires | As needed |
| 10µF Capacitor (Optional) | 2 |

---

## 🔌 Wiring Diagram

**Note:** The OLED and NRF modules share the same GPIO pins (22 & 21) in this specific setup, which works because they use different communication protocols (I2C vs SPI). If you encounter issues, consider moving the OLED to different pins (e.g., SCL=14, SDA=27).

| Component | Pin | ESP32 Pin |
| :--- | :--- | :--- |
| **OLED** | VCC | **5V** |
| | GND | GND |
| | SCL | **GPIO 22** |
| | SDA | **GPIO 21** |
| **NRF #1** | VCC | **3.3V** |
| | GND | GND |
| | CE | **GPIO 22** |
| | CSN | **GPIO 21** |
| **NRF (SPI)** | SCK | **GPIO 18** |
| | MOSI | **GPIO 23** |
| | MISO | **GPIO 19** |

> **Important:** Add a 10µF capacitor between VCC and GND on the NRF adapter if you experience instability.

---

## 🚀 How to Use

1.  **Install Libraries:** In Arduino IDE, install:
    *   `RF24` by TMRh20
    *   `Adafruit GFX Library`
    *   `Adafruit SSD1306`

2.  **Select Code:** Open either the Bluetooth or Wi-Fi jammer code in this repository.

3.  **Upload:** Select **ESP32 Dev Module** and upload the code.

4.  **Run:** Power the ESP32. The OLED will show "RUNNING..." and jamming will start automatically.

---

## 📂 Project Structure
