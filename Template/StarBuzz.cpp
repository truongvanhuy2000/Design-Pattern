#include <iostream>
#include <string>
using namespace std;
class CaffeineBeverage
{
    public:
        void prepareRecipe()
        {
            boil();
            brew();
            pour();
            if(customerWantsCondiments())
            {
                add();
            }
        }
        virtual void boil()
        {
            cout << "boiling water" << endl;
        }
        virtual void brew()
        {
            cout << "brewing thing" << endl;
        }
        virtual void pour()
        {
            cout << "pour in cup" << endl;
        }
        virtual void add()
        {
            cout << "add condiments" << endl;
        }
        virtual bool customerWantsCondiments()
        {
            return true;
        }
};
class Coffee : public CaffeineBeverage
{
    public:
        void brew()
        {
            cout << "Brew the coffee grinds" << endl;
        }
        void add()
        {
            cout << "Add sugar and milk" << endl;
        }
        bool customerWantsCondiments()
        {
            char x;
            cout << "want condiments or not? (Y/N)" << endl;
            cin >> x;
            if(x == 'y')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};
class Tea : public CaffeineBeverage
{
    public:
        void brew()
        {
            cout << "Steep the teabag in the water" << endl;
        }
        void add()
        {
            cout << "Add lemon" << endl;
        }
        bool customerWantsCondiments()
        {
            char x;
            cout << "want condiments or not? (Y/N)" << endl;
            cin >> x;
            if(x == 'y')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};
int main()
{
    CaffeineBeverage* tea = new Tea();
    CaffeineBeverage* coffee = new Coffee();
    cout << "Prepare tea" << endl;
    tea->prepareRecipe();
    cout << "Prepare coffee" << endl;
    coffee->prepareRecipe();
    return 0;
}
