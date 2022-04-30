#include <iostream>
#include <string>
#include <vector>
using namespace std;
class iMenuItem
{
    public:
        virtual string getName() = 0;
        virtual string getDescription() = 0;
        virtual bool isVegetarian() = 0;
        virtual double getPrice() = 0;
};
class iIterator
{
    public:
        virtual bool hasNext() = 0;
        virtual iMenuItem* next() = 0;
};
class iMenu
{
    public:
        virtual iIterator* createIterator() = 0;
};
class MenuItem : public iMenuItem
{
    private:
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
};
class PancakeIterator : public iIterator
{
    vector<iMenuItem*> mMenuItem;
    int mPosition = 0;
    public:
        PancakeIterator(vector<iMenuItem*> menuItem)
        {
            mMenuItem = menuItem;
        }
        bool hasNext()
        {
            if(mPosition >= mMenuItem.capacity())
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        iMenuItem* next()
        {
            iMenuItem* menItem = mMenuItem[mPosition];
            mPosition++;
            return menItem;
        }
};
class PancakeMenu : public iMenu
{
    private:
        vector<iMenuItem*> mMenuItem;
    public:
        PancakeMenu()
        {
            addItem("cake", "abcd", true, 2.99);
            addItem("cake", "bcde", false, 1.99);
            addItem("cake", "456", false, 0.99);
        }
        void addItem(string name, string description,bool vegeterian, double price)
        {
            iMenuItem *menuItem = new MenuItem(name, description, vegeterian, price);
            mMenuItem.push_back(menuItem);
        }
        iIterator* createIterator()
        {
            return new PancakeIterator(mMenuItem);
        }
};
class DinerIterator : public iIterator
{
    iMenuItem* *mMenuItem;
    int mMaxItem;
    int mPosition = 0;
    public:
        DinerIterator(iMenuItem* *menuItem, int maxItem)
        {
            mMenuItem = menuItem;
            mMaxItem = maxItem;
        }
        bool hasNext()
        {
            if(mPosition >= mMaxItem)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        iMenuItem* next()
        {
            iMenuItem* menItem = *(mMenuItem + mPosition);
            mPosition++;
            return menItem;
        }
};
class DinerMenu : public iMenu
{
    private:
        int mMaxItem = 3;
        iMenuItem* mMenuItem[3];
        int mPosition = 0;;
    public:
        DinerMenu()
        {
            addItem("diner", "abcd", true, 2.99);
            addItem("diner", "bcde", false, 1.99);
            addItem("diner", "456", false, 0.99);
        }
        void addItem(string name, string description,bool vegeterian, double price)
        {
            iMenuItem* menuItem = new MenuItem(name, description, vegeterian, price);
            mMenuItem[mPosition] = menuItem;
            mPosition++;
        }
        iIterator* createIterator()
        {
            return new DinerIterator(mMenuItem, mMaxItem);
        }
};
class Waitress
{
    iMenu *mPancakeMenu;
    iMenu *mDinerMenu;
    void printMenu(iIterator *menuIterator)
    {
        while(menuIterator->hasNext())
        {
            iMenuItem* menuItem = menuIterator->next();
            cout << " Name: " << menuItem->getName() <<" Description: " << menuItem->getDescription() << " Price: " << menuItem->getPrice() << endl;
        }
    }
    public:
        Waitress(iMenu *PancakeMenu, iMenu *DinerMenu)
        {
            mPancakeMenu = PancakeMenu;
            mDinerMenu = DinerMenu;
        }
        void printMenu()
        {
            iIterator *pancakeIterator = mPancakeMenu->createIterator();
            iIterator *dinerIterator = mDinerMenu->createIterator();
            cout << "Pancake Menu" << endl;
            printMenu(pancakeIterator);
            cout << "Diner Menu" << endl;
            printMenu(dinerIterator);
        }
};
int main()
{
    PancakeMenu pankeMenu1;
    DinerMenu dinerMenu1;
    Waitress waitress1(&pankeMenu1, &dinerMenu1);
    waitress1.printMenu();
}