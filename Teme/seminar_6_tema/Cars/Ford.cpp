#include "Ford.h"

Ford::Ford() {
    fuelCapacity = 18.0;
    fuelConsumption = 3.0;
}

double Ford::getFuelCapacity() {
    return fuelCapacity;
}

double Ford::getFuelConsumption() {
    return fuelConsumption;
}

void Ford::setAverageSpeed() {
    switch (weather) {
        case Weather::Rain:
            averageSpeed = 35.0;
            break;
        case Weather::Sunny:
            averageSpeed = 50.0;
            break;
        case Weather::Snow:
            averageSpeed = 35.0;
            break;
        default:
            break;
    }
}

void Ford::setWeather(Weather _weather) {
    weather = _weather;
}

double Ford::getAverageSpeed() {
    return averageSpeed;
}

void Ford::setTimeToFinish(double x) {
    timeToFinish = x;
}

double Ford::getTimeToFinish() {
    return timeToFinish;
}

char *Ford::getName() {
    return "Ford";
}
