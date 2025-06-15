#include <WiFi.h>
#include <esp_camera.h>
#include <ESP32QRCodeReader.h>
#include <HTTPClient.h>

// WiFi Credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// Google Apps Script Web App URL
const char* scriptURL = "https://script.google.com/macros/s/YOUR_SCRIPT_ID/exec";

// ESP32-CAM Camera Pins
#define PWDN_GPIO_NUM     -1
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM     0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM       5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

ESP32QRCodeReader reader(CAMERA_MODEL_AI_THINKER);

void setup() {
  Serial.begin(115200);
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  // Initialize camera and QR reader
  reader.setup();
  reader.begin();
}

void loop() {
  // Check for QR code
  if (reader.receiveQRCode()) {
    String qrData = reader.qrCodeData();
    Serial.println("QR Code: " + qrData);
    
    // Assume format is product,rate,quantity
    sendToGoogleSheet(qrData);
    delay(5000); // Delay before next scan
  }
}

void sendToGoogleSheet(String data) {
  if ((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    String url = String(scriptURL) + "?data=" + data;
    
    http.begin(url);
    int httpCode = http.GET();
    
    if (httpCode > 0) {
      String response = http.getString();
      Serial.println("Google Sheet Response: " + response);
    } else {
      Serial.println("Error sending to Google Sheet");
    }
    http.end();
  }
}
