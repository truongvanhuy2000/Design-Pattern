#ifndef DUCK_OBSERVER
#define DUCK_OBSERVER
#include "DuckClass.hpp"
#include <iostream>
#include <string>
#include <vector>
class QuackObservable
{
    public:
        virtual void registerObserver(Observer* observer) = 0;
        virtual void notifyObserver() = 0;
};
class Observable
{
    
};
class Observer
{
    public:
        virtual void update() = 0;
};
class Quacklogist: public Observer
{
    public:
        void update()
        {
            std::cout << "duck just quack" << std::endl;
        }
};
#endif