#include <iostream>
#include <string>
#include <mutex>
using namespace std;
class ChocolateBoiler
{
private:
    bool mEmpty;
    bool mBoiled;
    string mName;
    static mutex mLocker;
    static ChocolateBoiler *mInstance;
    ChocolateBoiler(string name) 
    {
        mName = name;
        mEmpty = true;
        mBoiled = false;
    }
public:
    void fill()
    {
        if (isEmpty())
        {
            mEmpty = false;
            mBoiled = false;
            //fill
        }
    }
    void drain()
    {
        if(!isEmpty() && isBoiled())
        {
            //drain
            mEmpty = true;
        }
    }
    void boil()
    {
        if(!isEmpty() && !isBoiled())
        {
            //boil
            mBoiled = true;
        }
    }
    bool isEmpty()
    {
        return mEmpty;
    }
    bool isBoiled()
    {
        return mBoiled;
    }
    string getName()
    {
        return mName;
    }
    static ChocolateBoiler *getInstance(string name)
    {
        mLocker.lock();
        if(mInstance == nullptr)
        {
            mInstance = new ChocolateBoiler(name);
        }
        mLocker.unlock();
        return mInstance;
    }
};
ChocolateBoiler* ChocolateBoiler :: mInstance = nullptr;
mutex ChocolateBoiler :: mLocker; 
int main()
{
    ChocolateBoiler *chocolate1;
    chocolate1 = ChocolateBoiler::getInstance("chocolate 1");
    cout << chocolate1->getName() << endl;
    chocolate1 = ChocolateBoiler::getInstance("chocolate 2");
    cout << chocolate1->getName() << endl;
}