#ifndef DUCK_CLASS
#define DUCK_CLASS
#include <iostream>
#include <DuckObserver.hpp>
class Quackable : public QuackObservable
{
    public:
        virtual void quack() = 0;
};
class Honkable
{
    public:
        virtual void honk() = 0;
};
class MallardDuck : public Quackable
{
    public:
        void quack()
        {
            std::cout << "MallardDuck quack" << std::endl;
        }
};
class RedHeadDuck : public Quackable
{
    public:
        void quack()
        {
            std::cout << "RedHeadDuck quack" << std::endl;
        }
};
class DuckCall : public Quackable
{
    public:
        void quack()
        {
            std::cout << "DuckCall kwak" << std::endl;
        }
};
class RubberDuck : public Quackable
{
    public:
        void quack()
        {
            std::cout << "RubberDuck squeak" << std::endl;
        }
};
class Goose : public Honkable
{
    public:
        void honk()
        {
            std::cout << "Goose Honk" << std::endl;
        }
};
class GooseAdapter : public Quackable
{
    Honkable *mGoose;
    public:
        GooseAdapter(Honkable *goose) : mGoose(goose) {}
        void quack()
        {
            mGoose -> honk();
        }
};
#endif