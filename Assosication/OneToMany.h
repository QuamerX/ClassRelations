#pragma once

#include <iostream>
#include <vector>

class Employee 
{
public:
    std::string name;
    Employee(std::string n) : name(n) {}
};

class Department 
{
private:
    std::string name_;
    std::vector<Employee*> employees_;

public:
    Department(std::string n) : name_(n) {}

    // Method to create the association
    void AddEmployee(Employee* emp) 
    {
        employees_.push_back(emp);
    }

    void PrintInfo() const 
    {
        std::cout << "Department: " << name_ << " has employees: ";
        for (const auto& emp : employees_) {
            std::cout << emp->name << ", ";
        }
        std::cout << std::endl;
    }
};