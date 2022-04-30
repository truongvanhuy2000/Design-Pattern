#ifndef DUCK_CLASS
#define DUCK_CLASS
#include <iostream>
class Quackable
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
            std::cout << "quack" << std::endl;
        }
};
class RedHeadDuck : public Quackable
{
    public:
        void quack()
        {
            std::cout << "quack" << std::endl;
        }
};
class DuckCall : public Quackable
{
    public:
        void quack()
        {
            std::cout << "kwak" << std::endl;
        }
};
class RubberDuck : public Quackable
{
    public:
        void quack()
        {
            std::cout << "squeak" << std::endl;
        }
};
class Goose : public Honkable
{
    public:
        void honk()
        {
            std::cout << "Honk" << std::endl;
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