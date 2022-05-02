#include <iostream>
#include <string>
using namespace std;
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
            cout << "MallardDuck quack" << endl;
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
            cout << "Goose Honk" << endl;
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
void simulate(Quackable *duck)
{
    duck->quack();
}
int main()
{
    Quackable* duck1 = new MallardDuck();
    Quackable* duck2 = new RedHeadDuck();
    Quackable* duck3 = new DuckCall();
    Quackable* duck4 = new RubberDuck();
    Honkable* goose1 = new Goose();
    Quackable* gooseDuck1 = new GooseAdapter(goose1);
    simulate(duck1);
    simulate(duck2);
    simulate(duck3);
    simulate(duck4);
    simulate(gooseDuck1);
    return 0;
}