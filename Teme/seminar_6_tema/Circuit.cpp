#include <stdio.h>
#include <iostream>
#include "Circuit.h"

Circuit::Circuit() {
    length = 0;
    numCars = 0;
}

void Circuit::SetLength(int l) {
    length = l;
}

void Circuit::AddCar(Car *C) {
    C->setWeather(weather);
    C->setAverageSpeed();
    cars[numCars++] = C;
}

void Circuit::Race() {
    for(int i = 0; i < numCars; i++) {
        // time = dist / speed
        if((cars[i]->getFuelCapacity() - (length * cars[i]->getFuelConsumption()) / 100) <  0) {
            cars[i]->setTimeToFinish(-1);
        } else {
            double temp = length / cars[i]->getAverageSpeed();
            cars[i]->setTimeToFinish(temp);
        }
    }
}

void Circuit::ShowFinalRanks() {
    for(int i = 0; i < numCars - 1; i++)
        for(int j = i + 1; j < numCars; j++)
            if(cars[i]->getTimeToFinish() > cars[j]->getTimeToFinish())
                std::swap(cars[i], cars[j]);
    printf("%s", "Final Results: \n");
    for(int i = 0; i < numCars; i++)
        if(cars[i]->getTimeToFinish() != -1)
            printf("Masina de pe locul %d este: %s\n", i + 1,cars[i]->getName());
}

void Circuit::ShowWhoDidNotFinish() {
    printf("%s", "Nu au terminat: \n");
    for(int i =  0; i < numCars; i++) {
        if(cars[i]->getTimeToFinish() == -1)
            printf("%s\n", cars[i]->getName());
    }
}

void Circuit::SetWeather(Weather tmp) {
    weather = tmp;
}
