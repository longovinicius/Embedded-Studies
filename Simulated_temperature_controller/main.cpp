#include <iostream>
#include <thread>
#include "TempSensor.h"
#include "Actuator.h"
#include "Controller.h"

int main() {
    TempSensor sensor(20.0, 1.0); 
    Controller controller(sensor, 25.0); 

    std::thread controllerThread(&Controller::run, &controller);

    char input;
    while (true) {
        std::cout << "Enter 'a' to activate, 'd' to deactivate, 'q' to quit: ";
        std::cin >> input;

        switch (input) {
            case 'a':
                controller.activate();
                break;
            case 'd':
                controller.deactivate();
                break;
            case 'q':
                controller.deactivate(); 
                controllerThread.join(); 
                return 0; 
            default:
                std::cout << "Unknown command." << std::endl;
        }
    }

    return 0;
}
// g++ main.cpp -o exe -lpthread