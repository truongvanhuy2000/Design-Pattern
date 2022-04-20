#include <iostream>
#include <string>
#include <vector>
using namespace std;
class beverageAbstract
{
    public:
        virtual string getDiscription()
        {
            return "no beverage";;
        }
        virtual double cost()
        {
            return 0;
        }
};
class condimentAbstract: public beverageAbstract
{
    public:
        virtual string getDiscription()
        {
            return 0;
        }
};
class houseBlendBeverage: public beverageAbstract
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
class coffeBeverage: public beverageAbstract
{
    public:
        string getDiscription()
        {
            return "Coffe";
        }
        double cost()
        {
            return 3.5;
        }
};
class milk: public condimentAbstract
{
    public:
    beverageAbstract *mBeverage;
        milk(beverageAbstract *beverage)
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
class mocha: public condimentAbstract
{
    public:
    beverageAbstract *mBeverage;
        mocha(beverageAbstract *beverage)
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
class soy: public condimentAbstract
{
    public:
    beverageAbstract *mBeverage;
        soy(beverageAbstract *beverage)
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
    beverageAbstract *beveragePtr;
    beveragePtr = new houseBlendBeverage;
    beveragePtr = new milk(beveragePtr);
    beveragePtr = new soy(beveragePtr);
    cout << beveragePtr->getDiscription() << " " << beveragePtr->cost() << endl;
    cout << "oder new drink " << endl;
    beveragePtr = new coffeBeverage;
    beveragePtr = new milk(beveragePtr);
    cout << beveragePtr->getDiscription() << " " << beveragePtr->cost() << endl;
}