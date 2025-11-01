#pragma once

#include <iostream>
#include <vector>

/* Forward declaration to break circular dependency */
class Developer;

class Project 
{
private:
    std::string title_;
    std::vector<Developer*> team_members_;

public:
    Project(std::string t) : title_(t) {}

    void AssignDeveloper(Developer* dev);

    void PrintInfo() const {
        std::cout << "Project: " << title_ << " involves " << team_members_.size() << " people." << std::endl;
    }
};

class Developer 
{
private:
    std::string name_;
    std::vector<Project*> projects_;

public:
    Developer(std::string n) : name_(n) {}

    void AssignToProject(Project* proj) {

        if (std::find(projects_.begin(), projects_.end(), proj) == projects_.end()) 
        {
            projects_.push_back(proj);
            proj->AssignDeveloper(this);
        }
    }

    void PrintInfo() const 
    {
        std::cout << "Developer: " << name_ << " is on " << projects_.size() << " projects." << std::endl;
    }
};

/* This function written outside of class because of forward declaration */
void Project::AssignDeveloper(Developer* dev) 
{
    team_members_.push_back(dev);
}