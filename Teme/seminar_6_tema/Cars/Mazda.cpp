#include "Mazda.h"

Mazda::Mazda() {
    fuelConsumption = 8.0;
    fuelCapacity = 40.0;
}

double Mazda::getFuelCapacity() {
    return fuelCapacity;
}

double Mazda::getFuelConsumption() {
    return fuelConsumption;
}

void Mazda::setAverageSpeed() {
    switch (weather) {
        case Weather::Rain:
            averageSpeed = 60.0;
            break;
        case Weather::Sunny:
            averageSpeed = 70.0;
            break;
        case Weather::Snow:
            averageSpeed = 55.0;
            break;
        default:
            break;
    }
}

void Mazda::setWeather(Weather _weather) {
    weather = _weather;
}

double Mazda::getAverageSpeed() {
    return averageSpeed;
}

void Mazda::setTimeToFinish(double x) {
    timeToFinish = x;
}

double Mazda::getTimeToFinish() {
    return timeToFinish;
}

char *Mazda::getName() {
    return "Mazda";
}
