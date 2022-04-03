#ifndef SEMINAR_6_TEMA_CAR_H
#define SEMINAR_6_TEMA_CAR_H

#include "Weather.h"

class Car {
protected:
    double fuelCapacity;
    double fuelConsumption;
    Weather weather;
    double timeToFinish;
    double averageSpeed;
public:
    virtual double getFuelCapacity() = 0;
    virtual double getFuelConsumption() = 0;
    virtual void setAverageSpeed() = 0;
    virtual void setWeather(Weather) = 0;
    virtual double getAverageSpeed() = 0;
    virtual void setTimeToFinish(double) = 0;
    virtual double getTimeToFinish() = 0;
    virtual char* getName() = 0;
};

#endif //SEMINAR_6_TEMA_CAR_H
