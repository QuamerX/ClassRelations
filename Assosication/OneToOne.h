#pragma once

#include <iostream>
#include <string>

class Passport 
{
public:
    std::string id;
    Passport(std::string i) : id(i) {}
};

class Person 
{
private:
    std::string name_;
    Passport* passport_ = nullptr;

public:
    Person(std::string n) : name_(n) {}

    void SetPassport(Passport* p) 
	{
        passport_ = p;
    }

    void PrintInfo() const 
	{
        std::cout << "Person: " << name_;
        if (passport_) 
		{
            std::cout << " (Passport ID: " << passport_->id << ")" << std::endl;
        } 
		else 
		{
            std::cout << " (No Passport)" << std::endl;
        }
    }
};