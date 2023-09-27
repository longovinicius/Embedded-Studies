#pragma once
#include <atomic>
#include <chrono>
#include "TempSensor.h"
#include "Actuator.h"

class Controller {
private:
    TempSensor& sensor;
    Heater heater;
    Cooler cooler;
    double setPoint;
    std::atomic<bool> isActive;

public:
    Controller(TempSensor& s, double g);
    void activate();
    void deactivate();
    void run();
};
