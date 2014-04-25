#include <iostream>

using namespace std;

class Engine {
    public: 
        void start() const {}; 
        void rev() const {}; 
        void stop() const {};
}; 

class Wheel {
    public: 
        void inflate(int psi) const {};
};

class Window {
    public:
        void rollup() const {}; 
        void rolldown() const {};
};

class Door { 
    public:
        Window window; 
        void open() const {};
        void close() const {};
};

class Vehicle {
    public:
        Vehicle(int i) { cout << "18 wheeler" << endl; };
        Vehicle() {};
        Engine engine;
        Wheel wheel[18];
        Door driver, passenger, hood, trunk;
        void isDriving() { cout << "true" << endl; };
};

class Car : public Vehicle {
    public:
        Car() { Vehicle v(1); };
        Engine engine;
        Wheel wheel[4];
        Door left, right; 
        // 2-door
};

int main() {
    Car car;
    car.left.window.rollup();
    car.wheel[0].inflate(72);
} 
