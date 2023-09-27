#pragma once
#include "TempSensor.h"

class Actuator {
public:
    virtual void activate(TempSensor& sensor) = 0;
};

class Heater : public Actuator {
public:
    void activate(TempSensor& sensor) override;
};

class Cooler : public Actuator {
public:
    void activate(TempSensor& sensor) override;
};
