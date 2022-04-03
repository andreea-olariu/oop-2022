#ifndef SEMINAR_6_TEMA_CIRCUIT_H
#define SEMINAR_6_TEMA_CIRCUIT_H

#include "Car.h"

class Circuit {
    int length;
    Car *cars[100];
    int numCars;
    Weather weather;
public:
    Circuit();
    void SetLength(int);
    void SetWeather(Weather);
    void AddCar(Car*);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};

#endif //SEMINAR_6_TEMA_CIRCUIT_H
