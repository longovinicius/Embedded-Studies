#pragma once
#include <random>

class TempSensor {
private:
    double temp;
    double alpha;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dist;

public:
    TempSensor(double t, double a);
    double get_temp();
    void variate_temp();
    void increase_temp(double amount);
    void decrease_temp(double amount);
};
