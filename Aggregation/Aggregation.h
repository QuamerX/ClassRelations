#pragma once

#include <iostream>
#include <string>

class Engine 
{
public:
    Engine(const std::string& type) : type(type) {}
    void Start() 
    { 
        std::cout << type << " engine started\n"; 
    }
private:
    std::string type;
};

class Car {
public:
    Car(const std::string& name, Engine* engine) : name(name), engine(engine) {}

    void Start() 
    {
        std::cout << name << " starting...\n";
        engine->Start();
    }

private:
    std::string name;
    Engine* engine;
};