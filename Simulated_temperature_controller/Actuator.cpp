#include "Actuator.h"

void Heater::activate(TempSensor& sensor) {
    sensor.increase_temp(2.0); 
}

void Cooler::activate(TempSensor& sensor) {
    sensor.decrease_temp(2.0); 
}
