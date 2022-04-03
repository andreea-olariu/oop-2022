#ifndef SEMINAR_6_TEMA_FORD_H
#define SEMINAR_6_TEMA_FORD_H

#include "../Car.h"

class Ford : public Car {
public:
    Ford();
    double getFuelCapacity();
    double getFuelConsumption();
    void setAverageSpeed();
    void setWeather(Weather);
    double getAverageSpeed();
    void setTimeToFinish(double);
    double getTimeToFinish();
    char* getName();
};

#endif //SEMINAR_6_TEMA_FORD_H
