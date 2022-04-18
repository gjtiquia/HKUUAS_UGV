#ifndef GPS_h
#define GPS_h
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>
#include <Coordinate.h>

class GPS {
    public:
        GPS();
        GPS(int rxPin, int txPin, int baudRate);
        void update();
        String getAntennaStatus();
        Coordinate getCurrentLocation();

    private:
        int _rxPin;
        int _txPin;
        SoftwareSerial _gpsSerial = SoftwareSerial(0, 1);
        TinyGPSPlus _gps;

        // Custom for ATGM332D
        TinyGPSCustom _antennaStatus;
};

#endif