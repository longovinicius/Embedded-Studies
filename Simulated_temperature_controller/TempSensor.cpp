#include "TempSensor.h"
#include <iostream>

TempSensor::TempSensor(double t, double a) : temp(t), alpha(a), gen(rd()), dist(0, 10) {}

double TempSensor::get_temp() {
    return temp;
}

void TempSensor::variate_temp() {
    if (dist(gen) > 4)
        temp += alpha;
    else
        temp -= alpha;
}

void TempSensor::increase_temp(double amount) {
    temp += amount;
}

void TempSensor::decrease_temp(double amount) {
    temp -= amount;
}
