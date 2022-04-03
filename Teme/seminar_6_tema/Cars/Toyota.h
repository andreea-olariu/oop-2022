#ifndef SEMINAR_6_TEMA_TOYOTA_H
#define SEMINAR_6_TEMA_TOYOTA_H

#include "../Car.h"

class Toyota : public Car {
public:
    Toyota();
    double getFuelCapacity();
    double getFuelConsumption();
    void setAverageSpeed();
    void setWeather(Weather);
    double getAverageSpeed();
    void setTimeToFinish(double);
    double getTimeToFinish();
    char* getName();
};

#endif //SEMINAR_6_TEMA_TOYOTA_H
