#include "Mercedes.h"


Mercedes::Mercedes() {
    fuelConsumption = 8.0;
    fuelCapacity = 40.0;
}

double Mercedes::getFuelCapacity() {
    return fuelCapacity;
}

double Mercedes::getFuelConsumption() {
    return fuelConsumption;
}

void Mercedes::setAverageSpeed() {
    switch (weather) {
        case Weather::Rain:
            averageSpeed = 65.0;
            break;
        case Weather::Sunny:
            averageSpeed = 75.0;
            break;
        case Weather::Snow:
            averageSpeed = 55.0;
            break;
        default:
            break;
    }
}

void Mercedes::setWeather(Weather _weather) {
    weather = _weather;
}

double Mercedes::getAverageSpeed() {
    return averageSpeed;
}

void Mercedes::setTimeToFinish(double x) {
    timeToFinish = x;
}

double Mercedes::getTimeToFinish() {
    return timeToFinish;
}

char *Mercedes::getName() {
    return "Mercedes";
}
