#include <iostream>
#include <string>
#include <vector>
#include "DuckClass.hpp"
#include "DuckCounter.hpp"
#include "DuckFactory.hpp"
#include "DuckIterator.hpp"
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
    simulate(mallardDuck);
    simulate(redHeadDuck);
    simulate(duckCall);
    simulate(rubberDuck);
    simulate(gooseDuck);
    cout << QuackCounter :: getCount() << endl;
    return 0;
}
