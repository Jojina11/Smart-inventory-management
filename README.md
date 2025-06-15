## Smart Inventory Management using ESP32-CAM and Google Sheets

This project automates inventory tracking using an **ESP32-CAM** module that scans QR codes containing product details (e.g., name, rate, quantity) and uploads them directly to a **Google Sheet**. It's a cost-effective, real-time stock management solution perfect for small businesses or warehouses.

---

💡 Features

- 📷 QR code scanning with ESP32-CAM
- 🔍 Extracts data like product name, rate, and quantity
- ☁️ Uploads to Google Sheets using Google Apps Script
- 📄 Real-time inventory updates without manual entry
- 💰 Budget-friendly system with open-source tools

---

## 🧰 Tech Stack

| Component         | Technology           |
|------------------ |----------------------|
| Microcontroller   | ESP32-CAM (AI Thinker) |
| QR Decoding       | Arduino + ESP32 libraries |
| Cloud Backend     | Google Apps Script   |
| Data Storage      | Google Sheets        |
| QR Code Generator | Online CSV to QR tools |
| IDEs              | Arduino IDE, Google Script Editor |

---

## 🗂️ Project Structure

```bash
Smart-Inventory-ESP32CAM/
│
├── esp32_qr_inventory.ino      # ESP32-CAM QR scanner code
├── google_sheets_script.gs     # Google Apps Script for data entry
├── example_qr_data.csv         # Sample QR code data: Product, Rate, Quantity
├── README.md                   # This file
