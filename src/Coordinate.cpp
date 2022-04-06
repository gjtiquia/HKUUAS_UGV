#include <Coordinate.h>
#include <math.h>
#include <Arduino.h>

Coordinate::Coordinate(float lat, float lon) {
    _lat = lat;
    _lon = lon;
}

float Coordinate::getLat() {
    return _lat;
}

float Coordinate::getLon() {
    return _lon;
}

float Coordinate::distanceTo(Coordinate coordinate) {
    // Use Haversine Formula to calculate the distance
    // Reference: https://stackoverflow.com/questions/27928/calculate-distance-between-two-latitude-longitude-points-haversine-formula
    float lat2 = coordinate.getLat();
    float lon2 = coordinate.getLon();

    float R = 6371; // Radius of the earth in km
    float dLat = (lat2 - _lat) * (PI / 180); // degree in radians
    float dLon = (lon2 - _lon) * (PI / 180); // degree in radians
    float a =
        sin(dLat/2) * sin(dLat/2) +
        cos(_lat * (PI / 180)) * cos(lat2 * (PI / 180)) *
        sin(dLon / 2) * sin(dLon / 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    float d = R * c; // distance in km

    return 1000 * d; // distance in m
}

String Coordinate::toString() {
    String output = "";
    output += "Latitude: " + String(_lat);
    output += ", Longtitude: " + String(_lon);
    return output;
}