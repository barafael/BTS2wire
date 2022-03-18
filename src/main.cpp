#include <Arduino.h>

#include <BluetoothSerial.h>
#include <HardwareSerial.h>

BluetoothSerial SerialBT;

void setup() {
    Serial.begin(115200);
    Serial2.begin(115200);
    String id = "BTS2wire Bluetooth Serial to UART converter";
    SerialBT.begin(id);
}

void loop() {
    if (SerialBT.available()) {
        Serial2.write(SerialBT.read());
    }
    if (Serial2.available()) {
        SerialBT.write(Serial2.read());
    }
}
