#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <atomic>

class TempSensor {
private:
    double temp;
    double alpha;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dist;

public:
    TempSensor(double t, double a) : temp(t), alpha(a), gen(rd()), dist(0, 10) {}

    double get_temp() {
        return temp;
    }

    void variate_temp() {
        if (dist(gen) > 4)
            temp += alpha;
        else
            temp -= alpha;
    }

    void increase_temp(double amount) {
        temp += amount;
    }

    void decrease_temp(double amount) {
        temp -= amount;
    }
};

class Actuator {
public:
    virtual void activate(TempSensor& sensor) = 0;
};

class Heater : public Actuator {
public:
    void activate(TempSensor& sensor) override {
        sensor.increase_temp(2.0); 
    }
};

class Cooler : public Actuator {
public:
    void activate(TempSensor& sensor) override {
        sensor.decrease_temp(2.0); 
    }
};

class Controller {
private:
    TempSensor& sensor; 
    Heater heater;
    Cooler cooler;
    double setPoint;
    std::atomic<bool> isActive; 

public:
    Controller(TempSensor& s, double g) : sensor(s), setPoint(g), isActive(true) {} 

    void activate() {
        isActive.store(true);
    }

    void deactivate() {
        isActive.store(false);
    }

    void run() {
        while(true){
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
};

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