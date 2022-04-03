#ifndef SEMINAR_6_TEMA_DACIA_H
#define SEMINAR_6_TEMA_DACIA_H

#include "../Car.h"

class Dacia : public Car {
public:
    Dacia();

    double getFuelCapacity();
    double getFuelConsumption();
    void setAverageSpeed();
    double getAverageSpeed();
    void setWeather(Weather);
    void setTimeToFinish(double);
    double getTimeToFinish();
    char* getName();
};

#endif //SEMINAR_6_TEMA_DACIA_H
