#include "Toyota.h"

Toyota::Toyota() {
    fuelCapacity = 25.0;
    fuelConsumption = 4.5;
    timeToFinish = 0;
}

double Toyota::getFuelCapacity() {
    return fuelCapacity;
}

double Toyota::getFuelConsumption() {
    return fuelConsumption;
}

void Toyota::setAverageSpeed() {
    switch(weather) {
        case Weather::Rain:
            averageSpeed = 50.0;
            break;
        case Weather::Snow:
            averageSpeed = 40.0;
            break;
        case Weather::Sunny:
            averageSpeed = 60.0;
            break;
        default:
            break;
    }
}

double Toyota::getAverageSpeed() {
    return averageSpeed;
}

void Toyota::setTimeToFinish(double x) {
    timeToFinish = x;
}

double Toyota::getTimeToFinish() {
    return timeToFinish;
}

char *Toyota::getName() {
    return "Toyota";
}

void Toyota::setWeather(Weather w) {
    weather = w;
}
