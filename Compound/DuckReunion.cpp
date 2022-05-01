#include <iostream>
#include <string>
#include <vector>
#include "DuckClass.hpp"
#include "DuckCounter.hpp"
#include "DuckFactory.hpp"
#include "DuckIterator.hpp"
#include "DuckFlock.hpp"
using namespace std;
void simulate(Quackable *duck)
{
    duck->quack();
}
int main()
{
    AbstractDuckFactory *countingDuckFactory = new CountingDuckFactory(); 
    Quackable *mallardDuck = countingDuckFactory->createMallardDuck();
    Quackable *redHeadDuck = countingDuckFactory->createRedHeadDuck();
    Quackable *duckCall = countingDuckFactory->createDuckCall();
    Quackable *rubberDuck = countingDuckFactory->createRubberDuck();
    Quackable *gooseDuck = countingDuckFactory->createGooseDuck();
    Flock duckFlock;
    Flock mallardFlock;
    duckFlock.add(mallardDuck);
    duckFlock.add(redHeadDuck);
    duckFlock.add(duckCall);
    duckFlock.add(rubberDuck);
    duckFlock.add(gooseDuck);
    Quackable *mallardDuck1 = countingDuckFactory->createMallardDuck();
    Quackable *mallardDuck2 = countingDuckFactory->createMallardDuck();
    Quackable *mallardDuck3 = countingDuckFactory->createMallardDuck();
    mallardFlock.add(mallardDuck1);
    mallardFlock.add(mallardDuck2);
    mallardFlock.add(mallardDuck3);
    duckFlock.add(&mallardFlock);
    simulate(&duckFlock);
    cout << QuackCounter :: getCount() << endl;
    return 0;
}
