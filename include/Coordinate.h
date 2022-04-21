#ifndef Coordinate_h
#define Coordinate_h
#include <Arduino.h>

class Coordinate {
    public:
        Coordinate(float lat, float lon);
        float distanceTo(Coordinate coordinate);
        float getLat();
        float getLon();
        String toString();

    private:
        float _lat;
        float _lon;
};

#endif