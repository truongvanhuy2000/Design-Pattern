#include <iostream>
#include <string>
#include <vector>
using namespace std;
class MenuComponent
{
    public:
        virtual void add(MenuComponent* menuComponent);
        virtual void remove(MenuComponent* menuComponent);
        virtual MenuComponent* getChild(int i);
        virtual string getName();
        virtual string getDescription();
        virtual double getPrice();
        virtual bool isVegetarian();
        virtual void print();
};
class iIterator
{
    public:
        virtual bool hasNext() = 0;
        virtual MenuComponent* next() = 0;
};
class MenuItem : public MenuComponent
{
    string mName;
    string mDescription;
    bool mVegetarian;
    double mPrice;
    public:
        MenuItem(string name, string description,bool vegeterian, double price)
        {
            mName = name;
            mDescription = description;
            mVegetarian = vegeterian;
            mPrice = price;
        }
        string getName()
        {
            return mName;
        }
        string getDescription()
        {
            return mDescription;
        }
        bool isVegetarian()
        {
            return mVegetarian;
        }
        double getPrice()
        {
            return mPrice;
        }
        void print()
        {
            cout << " Name: " << getName() <<" Description: " << getDescription() << " Price: " << getPrice() << endl;
        }
};
class Menu : public MenuComponent
{
    vector<MenuComponent*> mMenuList;
    string mName;
    string mDescription;
    public:
        Menu(string name, string description)
        {
            mName = name;
            mDescription = description;
        }
        void add(MenuComponent* menuComponent)
        {
            mMenuList.push_back(menuComponent);
        }
        void remove(MenuComponent* menuComponent)
        {
            for (int i = 0; i < mMenuList.capacity(); i++)
            {
                if(menuComponent == mMenuList[i])
                {
                    mMenuList.erase(mMenuList.begin() + i);
                    break;
                }
            }
        }
        MenuComponent* getChild(int i)
        {
            return mMenuList[i];
        }
        string getName()
        {
            return mName;
        }
        string getDescription()
        {
            return mDescription;
        }
        void print()
        {
            cout << " Name: " << getName() <<" Description: " << getDescription() << endl;
        }
};
int main()
{
    return 0;
}