#include "Dacia.h"

Dacia::Dacia() {
    fuelCapacity = 20.0;
    fuelConsumption = 5.0;
    timeToFinish = 0;
}

double Dacia::getFuelCapacity() {
    return fuelCapacity;
}

double Dacia::getFuelConsumption() {
    return fuelConsumption;
}

void Dacia::setAverageSpeed() {
    switch(weather) {
        case Weather::Rain:
            averageSpeed = 40.0;
            break;
        case Weather::Snow:
            averageSpeed = 30.0;
            break;
        case Weather::Sunny:
            averageSpeed = 50.0;
            break;
        default:
            break;
    }
}

double Dacia::getAverageSpeed() {
    return averageSpeed;
}

void Dacia::setTimeToFinish(double x) {
    timeToFinish = x;
}

double Dacia::getTimeToFinish() {
    return timeToFinish;
}

char *Dacia::getName() {
    return "Dacia";
}

void Dacia::setWeather(Weather w) {
    weather = w;
}
