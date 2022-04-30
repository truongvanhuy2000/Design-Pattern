#ifndef DUCK_FLOCK
#define DUCK_FLOCK
#include "DuckClass.hpp"
#include "DuckIterator.hpp"
#include <iostream>
#include <string>
#include <vector>
class FlockInterface
{
    public:
        virtual void add(Quackable* duck);
        virtual void remove(Quackable* duck);
};
class Flock
{
    std::vector<Quackable*> mFlock;
    void add(Quackable* menuComponent)
    {
        mFlock
    }
};
#endif