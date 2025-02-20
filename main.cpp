#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 2        // Chân kết nối cảm biến DHT11 (GPIO2 - D4)
#define DHTTYPE DHT11   // Loại cảm biến: DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);  // Khởi động Serial Monitor
    Serial.println("Đang khởi động DHT11...");
    dht.begin();
}

void loop() {
    float h = dht.readHumidity();    // Đọc độ ẩm
    float t = dht.readTemperature(); // Đọc nhiệt độ (°C)

    if (isnan(h) || isnan(t)) {
        Serial.println("Lỗi! Không đọc được từ DHT11");
        return;
    }

    Serial.print("Nhiệt độ: ");
    Serial.print(t);
    Serial.print("°C - Độ ẩm: ");
    Serial.print(h);
    Serial.println("%");

    delay(2000); // Chờ 2 giây trước lần đọc tiếp theo
}
