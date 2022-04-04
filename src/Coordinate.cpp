#include <Coordinate.h>

Coordinate::Coordinate(float lat, float lon) {
    _lat = lat;
    _lon = lon;
}

float Coordinate::distanceTo(Coordinate coordinate) {
    // Use Haversine Formula to calculate the distance
}