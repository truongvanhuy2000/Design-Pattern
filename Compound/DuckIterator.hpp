#ifndef DUCK_ITERATOR
#define DUCK_ITERATOR
#include "DuckClass.hpp"
#include <iostream>
#include <string>
#include <vector>
class iIterator
{
    public:
        virtual bool hasNext() = 0;
        virtual Quackable* next() = 0;
};
class FlockIterator : public iIterator
{
    std::vector<Quackable*> mFlock;
    int mPosition = 0;
    public:
        FlockIterator(std::vector<Quackable*> flock)
        {
            mFlock = flock;
        }
        bool hasNext()
        {
            if(mPosition >= mFlock.capacity())
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        Quackable* next()
        {
            Quackable* duck = mFlock[mPosition];
            mPosition++;
            return duck;
        }
};
#endif