#ifndef DUCK_FACTORY
#define DUCK_FACTORY
#include <iostream>
#include "DuckClass.hpp"
#include "DuckCounter.hpp"
class AbstractDuckFactory
{
    public:
        virtual Quackable* createMallardDuck()
        {
            return 0;
        }
        virtual Quackable* createRedHeadDuck()
        {
            return 0;
        }
        virtual Quackable* createDuckCall()
        {
            return 0;
        }
        virtual Quackable* createRubberDuck()
        {
            return 0;
        }
        virtual Quackable* createGooseDuck()
        {
            return 0;
        }
};
class DuckFactory : public AbstractDuckFactory
{
    Quackable* mDuck;
    public:
        Quackable* createMallardDuck()
        {
            return new MallardDuck();
        }
        Quackable* createRedHeadDuck()
        {
            return new RedHeadDuck();
        }
        Quackable* createDuckCall()
        {
            return new DuckCall();
        }
        Quackable* createRubberDuck()
        {
            return new RubberDuck();
        }
        Quackable* createGooseDuck()
        {
            return new GooseAdapter(new Goose());
        }
};
class CountingDuckFactory : public AbstractDuckFactory
{
    public:
        Quackable* createMallardDuck()
        {
            return new QuackCounter(new MallardDuck());
        }
        Quackable* createRedHeadDuck()
        {
            return new QuackCounter(new RedHeadDuck());
        }
        Quackable* createDuckCall()
        {
            return new QuackCounter(new DuckCall());
        }
        Quackable* createRubberDuck()
        {
            return new QuackCounter(new RubberDuck());
        }
        Quackable* createGooseDuck()
        {
            return new QuackCounter(new GooseAdapter(new Goose()));
        }
};
#endif