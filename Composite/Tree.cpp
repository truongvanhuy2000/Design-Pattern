#include <iostream>
#include <string>
#include <vector>
using namespace std;
class MenuComponent
{
    public:
        virtual void add(MenuComponent* menuComponent){}
        virtual void remove(MenuComponent* menuComponent){}
        virtual MenuComponent* getChild(int i){return 0;}
        virtual string getName(){return 0;}
        virtual string getDescription(){return 0;}
        virtual double getPrice(){return 0;}
        virtual bool isVegetarian(){return 0;}
        virtual void print(){}
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
class MenuIterator : public iIterator
{
    vector<MenuComponent*> mMenu;
    int mPosition = 0;
    public:
        MenuIterator(vector<MenuComponent*> menu)
        {
            mMenu = menu;
        }
        bool hasNext()
        {
            if(mPosition >= mMenu.capacity())
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        MenuComponent* next()
        {
            MenuComponent* menu = mMenu[mPosition];
            mPosition++;
            return menu;
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
            cout << getName() << endl;
            cout << getDescription() << endl;
            cout << "---------------------" << endl;;
            iIterator* iterator = new MenuIterator(mMenuList);
            while(iterator->hasNext())
            {
                MenuComponent* menuComponent = iterator->next();
                menuComponent->print();
            }
        }
};
class Waitress
{
    public:
        Waitress(){}
        void print(MenuComponent* allMenu)
        {
            allMenu->print();
        }
};
int main()
{
    MenuComponent* pancakeHouseMenu = new Menu("PANCAKE HOUSE MENU", "Breakfast");
    MenuComponent* dinerMenu = new Menu("DINER MENU", "Lunch");
    MenuComponent* cafeMenu = new Menu("CAFE MENU", "Dinner");
    MenuComponent* dessertMenu = new Menu("DESSERT MENU", "Dessert of course!");
    MenuComponent* allMenus = new Menu("ALL MENUS", "All menus combined");
    allMenus->add(pancakeHouseMenu);
    allMenus->add(dinerMenu);
    allMenus->add(cafeMenu);
    allMenus->add(dessertMenu);
    dinerMenu->add(new MenuItem("Pasta", "Spaghetti with Marinara Sauce, and a slice of sourdough bread", true, 3.89));
    dessertMenu->add(new MenuItem("Apple Pie", "Apple pie with a flakey crust, topped with vanilla icecream", true, 1.59));
    dessertMenu->add(new MenuItem("123456", "456789", true, 1.59));
    pancakeHouseMenu->add(dessertMenu);
    dinerMenu->add(dessertMenu);
    Waitress waitress;
    cout << "here your full Menu" << endl;
    waitress.print(allMenus);
    cout << "\n \n here your Diner Menu" << endl;
    waitress.print(dinerMenu);
    return 0;
}