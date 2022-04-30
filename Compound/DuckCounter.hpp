#ifndef DUCK_COUNTER
#define DUCK_COUNTER
#include <iostream>
#include "DuckClass.hpp"
class QuackCounter : public Quackable
{
    static int mCount;
    Quackable *mDuck;
    public:
        QuackCounter(Quackable *duck)
        {
            mDuck = duck;
        }
        void quack()
        {
            mDuck->quack();
            mCount ++;
        }
        static int getCount()
        {
            return mCount;
        }
};
int QuackCounter :: mCount = 0;
#endif