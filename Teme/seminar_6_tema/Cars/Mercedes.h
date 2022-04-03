#ifndef SEMINAR_6_TEMA_MERCEDES_H
#define SEMINAR_6_TEMA_MERCEDES_H

#include "../Car.h"

class Mercedes : public Car {
public:
    Mercedes();
    double getFuelCapacity();
    double getFuelConsumption();
    void setAverageSpeed();
    void setWeather(Weather);
    double getAverageSpeed();
    void setTimeToFinish(double);
    double getTimeToFinish();
    char* getName();
};

#endif //SEMINAR_6_TEMA_MERCEDES_H
