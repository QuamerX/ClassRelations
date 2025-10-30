#include <iostream>
#include <string>

class Shape 
{
public:
    virtual double getArea() const = 0; 
    virtual ~Shape() = default; 
    void Greetings() const 
    {
        std::cout << "I am a shape!" << std::endl;
    }
};

class Rectangle : public Shape 
{
private:
    double width_;
    double height_;

public:
    Rectangle(double w, double h) : width_(w), height_(h) {}
    double getArea() const override 
    {
        return width_ * height_;
    }
};