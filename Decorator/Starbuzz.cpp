#include <iostream>
#include <string>
#include <vector>
using namespace std;
class beverageInterface
{
    public:
        virtual string getDiscription()
        {
            return "no beverage";
        }
        virtual double cost()
        {
            return 0;
        }
};
class condimentInterface: public beverageInterface
{
    public:
        virtual string getDiscription()
        {
            return 0;
        }
};
class houseBlendBeverage: public beverageInterface
{
    public:
        string getDiscription()
        {
            return "House Blend";
        }
        double cost()
        {
            return 2.5;
        }
};
class milk: public condimentInterface
{
    public:
    beverageInterface *mBeverage;
        milk(beverageInterface *beverage)
        {
            mBeverage = beverage;
        }
        string getDiscription()
        {
            return  mBeverage->getDiscription() + " " + "milk";
        }
        double cost()
        {
            return mBeverage->cost() + 2.5;
        }
};
class mocha: public condimentInterface
{
    public:
    beverageInterface *mBeverage;
        mocha(beverageInterface *beverage)
        {
            mBeverage = beverage;
        }
        string getDiscription()
        {
            return  mBeverage->getDiscription() + " " + "Mocha";
        }
        double cost()
        {
            return mBeverage->cost() + 1.5;
        }
};
class soy: public condimentInterface
{
    public:
    beverageInterface *mBeverage;
        soy(beverageInterface *beverage)
        {
            mBeverage = beverage;
        }
        string getDiscription()
        {
            return  mBeverage->getDiscription() + " " + "Soy";
        }
        double cost()
        {
            return mBeverage->cost() + 5.5;
        }
};
int main()
{
    beverageInterface *beveragePtr;
    beveragePtr = new houseBlendBeverage;
    //cout << beveragePtr->getDiscription() << endl;
    beveragePtr = new milk(beveragePtr);
    //cout << beveragePtr->getDiscription() << endl;
    beveragePtr = new soy(beveragePtr);
    cout << beveragePtr->getDiscription() << " " << beveragePtr->cost() << endl;
}