#ifndef SEMINAR_6_TEMA_MAZDA_H
#define SEMINAR_6_TEMA_MAZDA_H

#include "../Car.h"

class Mazda : public Car {
public:
    Mazda();
    double getFuelCapacity();
    double getFuelConsumption();
    void setAverageSpeed();
    void setWeather(Weather);
    double getAverageSpeed();
    void setTimeToFinish(double);
    double getTimeToFinish();
    char* getName();
};

#endif //SEMINAR_6_TEMA_MAZDA_H
