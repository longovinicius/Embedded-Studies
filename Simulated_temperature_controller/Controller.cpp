#include "Controller.h"
#include <thread>
#include <iostream>

Controller::Controller(TempSensor& s, double g) : sensor(s), setPoint(g), isActive(true) {}

void Controller::activate() {
    isActive.store(true);
}

void Controller::deactivate() {
    isActive.store(false);
}

void Controller::run() {
    while(true) {
        sensor.variate_temp();

        if (isActive.load()) {
            if (sensor.get_temp() > setPoint)
                cooler.activate(sensor);
            else
                heater.activate(sensor);
        }

        std::cout << sensor.get_temp() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}
