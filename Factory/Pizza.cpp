#include <iostream>
#include <string>
using namespace std;
class iPizza
{
    public:
        virtual void prepare() = 0;
        virtual void bake() = 0;
        virtual void cut() = 0;
        virtual void box() = 0;
};
class PizzaStore
{
    public:
        PizzaStore(){};
        iPizza* oderPizza(string pizzaType)
        {
            iPizza* pizza;
            pizza = createPizza(pizzaType);
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
            return pizza;
        }
        virtual iPizza* createPizza(string pizzaType) = 0;
};
class NYCheesePizza : public iPizza
{
    public:
        void prepare()
        {
            cout << "prepare NYCheesePizza" << endl;
        }
        void bake()
        {
            cout << "bake NYCheesePizza" << endl;
        }
        void cut()
        {
            cout << "cut NYCheesePizza" << endl;
        }
        void box()
        {
            cout << "box NYCheesePizza" << endl;
        }
};
class NYVeggiePizza : public iPizza
{
    public:
        void prepare()
        {
            cout << "prepare NYVeggiePizza" << endl;
        }
        void bake()
        {
            cout << "bake NYVeggiePizza" << endl;
        }
        void cut()
        {
            cout << "cut NYVeggiePizza" << endl;
        }
        void box()
        {
            cout << "box NYVeggiePizza" << endl;
        }
};
class ChicagoClamPizza : public iPizza
{
    public:
        void prepare()
        {
            cout << "prepare ChicagoClamPizza" << endl;
        }
        void bake()
        {
            cout << "bake ChicagoClamPizza" << endl;
        }
        void cut()
        {
            cout << "cut ChicagoClamPizza" << endl;
        }
        void box()
        {
            cout << "box ChicagoClamPizza" << endl;
        }
};
class ChicagoPepperoniPizza : public iPizza
{
    public:
        void prepare()
        {
            cout << "prepare ChicagoPepperoniPizza" << endl;
        }
        void bake()
        {
            cout << "bake ChicagoPepperoniPizza" << endl;
        }
        void cut()
        {
            cout << "cut ChicagoPepperoniPizza" << endl;
        }
        void box()
        {
            cout << "box ChicagoPepperoniPizza" << endl;
        }
};
class ChicagoPizzaStore : public PizzaStore
{
    public:
        iPizza* createPizza(string pizzaType)
        {
            if(pizzaType == "ChicagoPepperoniPizza")
            {
                return new ChicagoPepperoniPizza();
            }
            else if(pizzaType == "ChicagoClamPizza")
            {
                return new ChicagoClamPizza();
            }
            else
            return nullptr;
        }
};
class NYPizzaStore : public PizzaStore
{
    public:
        iPizza* createPizza(string pizzaType)
        {
            if(pizzaType == "NYCheesePizza")
            {
                return new NYCheesePizza();
            }
            else if(pizzaType == "NYVeggiePizza")
            {
                return new NYVeggiePizza();
            }
            else
            return nullptr;
        }
};
int main()
{
    PizzaStore* nyPizzaStore = new NYPizzaStore();
    nyPizzaStore->oderPizza("NYVeggiePizza");
    PizzaStore* chicagoPizzaStore = new ChicagoPizzaStore();
    chicagoPizzaStore->oderPizza("ChicagoPepperoniPizza");
    return 0;
}