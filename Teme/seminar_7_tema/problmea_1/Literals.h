#ifndef PROBLMEA_1_LITERALS_H
#define PROBLMEA_1_LITERALS_H

float operator""_Fahrenheit(unsigned long long temp) {
    return (float)((temp - 32.0f)*(5.0f/9.0f));
}

float operator""_Kelvin(unsigned long long temp) {
    return (float)(temp - 273.15f);
}

#endif //PROBLMEA_1_LITERALS_H
