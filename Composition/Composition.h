#pragma once

#include <iostream>
#include <string>

class Heart 
{
public:
    void Beat() 
    { 
        std::cout << "Heart is beating\n"; 
    }
};

class Human {
public:
    Human(const std::string& name) : name(name), heart() {}

    void Live() 
    {
        std::cout << name << " is alive. ";
        heart.Beat();
    }

private:
    std::string name;
    Heart heart;
};

