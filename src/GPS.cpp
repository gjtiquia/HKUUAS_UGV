#include <GPS.h>

GPS::GPS() {}

GPS::GPS(int rxPin, int txPin, int baudRate) {
    _rxPin = rxPin;
    _txPin = txPin;

    _antennaStatus = TinyGPSCustom(_gps, "GPTXT", 5);

    // Set pin
    _gpsSerial = SoftwareSerial(_rxPin, _txPin);
    Serial.println("Software Serial at Tx" + _txPin); 
    Serial.println(" and Rx" + _rxPin);
    _gpsSerial.begin(baudRate);
    Serial.println("Software Serial begin at baud rate " + baudRate);
}

void GPS::update() {
    while (_gpsSerial.available() > 0) {
        // Serial.write(_gpsSerial.read());
        _gps.encode(_gpsSerial.read());
    }
    // Serial.print("Antenna Status: "); Serial.println(_antennaStatus.value());
}

String GPS::getAntennaStatus() {
    return _antennaStatus.value();
}

Coordinate GPS::getCurrentLocation() {
    // TODO
}