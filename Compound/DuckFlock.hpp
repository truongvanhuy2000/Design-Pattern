#ifndef DUCK_FLOCK
#define DUCK_FLOCK
#include "DuckClass.hpp"
#include "DuckIterator.hpp"
#include <iostream>
#include <string>
#include <vector>
class Flock : public Quackable
{
    std::vector<Quackable*> mFlock;
    public:
    void add(Quackable* menuComponent)
    {
        mFlock.push_back(menuComponent);
    }
    void quack()
    {
        iIterator* iterator = new FlockIterator(mFlock);
        while(iterator->hasNext())
        {
            Quackable* quacker = iterator->next();
            quacker->quack();
        }
    }
};
#endif