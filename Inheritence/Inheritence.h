#pragma once

#include <iostream>

class Animal
{              
public:
    void Eat() 
    { 
        std::cout << "Eating\n"; 
    }

protected:
    void Breathe()
    {
        std::cout << "Breathing\n";
    }

private:
    void Existing()
    {
        std::cout << "Existing\n";
    }
};

class Dog : public Animal 
{
public:
    void Bark() 
    { 
        std::cout << "Barking\n"; 
    }
};

class GoldenRetriever : protected Dog
{
public:
    void FirstBreatheThenEat()
    {
        Breathe();
        Eat();
    }
};

class GoodBoy : private GoldenRetriever
{
public:
    void TailWiggle()
    {
        std::cout << "TailWiggling\n";
    }

    void FirstEatThenBreathe()
    {
        Eat();
        Breathe();
    }
};

class GoodestBoy : private GoodBoy
{
public:
    void JumpOnLap()
    {
        std::cout << "JumpingOnLap\n";
    }

    void EatAndBreathe()
    {
        std::cout << "Cannot do it\n";
        //Eat();
        //Breathe();
    }
};