#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

class Engine {
    public:
        void start() {
            cout << "Engine is on" << endl;
        }
};

class Car {
    private: 
        Engine engine;

    public:
        void startCar() {
            engine.start();
            cout << "Car is on" << endl;
        }    
};

int main() {
    Car car;

    car.startCar();

    return 0;
}