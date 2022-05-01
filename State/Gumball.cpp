#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
class StateInterface
{
    public:
        virtual void insertQuarter() = 0;
        virtual void ejectQuarter() = 0;
        virtual void turnCrank() = 0;
        virtual void dispenseGumball() = 0;
};
class GumballMachineInterface
{
    public:
        virtual void insertQuarter() = 0;
        virtual void ejectQuarter() = 0;
        virtual void turnCrank() = 0;
        virtual void dispenseGumball() = 0;
        virtual StateInterface* getState() = 0;
        virtual void setState(StateInterface* state) = 0;
        virtual StateInterface* getNoQuarterState() = 0;
        virtual StateInterface* getHasQuarterState() = 0;
        virtual StateInterface* getGumballSoldState() = 0;
        virtual StateInterface* getOutOfGumballState() = 0;
        virtual StateInterface* getWinnerState() = 0;
        virtual int getGumballs() = 0;
};
class HasQuarterState : public StateInterface
{
    GumballMachineInterface *mGumballMachine;
    int mRandom;
    public:
        HasQuarterState(GumballMachineInterface *gumballMachine)
        {
            mGumballMachine = gumballMachine;
        }
        void insertQuarter()
        {
            cout << "already has quarter" << endl;
        }
        void ejectQuarter()
        {
            cout << "ok eject quarter" << endl;
            mGumballMachine->setState(mGumballMachine->getNoQuarterState());
        }
        void turnCrank()
        {
            cout << "ok turn crank" << endl;
            mRandom = rand() % 10 + 0;
            if(mRandom == 2 && mGumballMachine->getGumballs() > 0)
            {
                mGumballMachine->setState(mGumballMachine->getWinnerState());
            }
            else
            {
                mGumballMachine->setState(mGumballMachine->getGumballSoldState());
            }
        }
        void dispenseGumball()
        {
            cout << "havent turn crank" << endl;
        }
};
class NoQuarterState : public StateInterface
{
    GumballMachineInterface *mGumballMachine;
    public:
        NoQuarterState(GumballMachineInterface *gumballMachine)
        {
            mGumballMachine = gumballMachine;
        }
        void insertQuarter()
        {
            cout << "ok got ur quarter" << endl;
            mGumballMachine->setState(mGumballMachine->getHasQuarterState());
        }
        void ejectQuarter()
        {
            cout << "no quarter" << endl;
        }
        void turnCrank()
        {
            cout << "no quarter" << endl;
        }
        void dispenseGumball()
        {
            cout << "no quarter" << endl;
        }
};
class GumballSoldState : public StateInterface
{
    GumballMachineInterface *mGumballMachine;
    public:
        GumballSoldState(GumballMachineInterface *gumballMachine)
        {
            mGumballMachine = gumballMachine;
        }
        void insertQuarter()
        {
            cout << "already have one" << endl;
        }
        void ejectQuarter()
        {
            cout << "cant eject now" << endl;
        }
        void turnCrank()
        {
            cout << "already turn" << endl;
        }
        void dispenseGumball()
        {
            mGumballMachine->dispenseGumball();
            cout << "here ur gumball" << endl;
            if(mGumballMachine->getGumballs() > 0)
            {
                mGumballMachine->setState(mGumballMachine->getNoQuarterState());
            }
            else
            {
                mGumballMachine->setState(mGumballMachine->getOutOfGumballState());
            }
        }
};
class OutOfGumballState : public StateInterface
{
    GumballMachineInterface *mGumballMachine;
    public:
        OutOfGumballState(GumballMachineInterface *gumballMachine)
        {
            mGumballMachine = gumballMachine;
        }
        void insertQuarter()
        {
            cout << "Out Of Gumball" << endl;
        }
        void ejectQuarter()
        {
            cout << "Out Of Gumball" << endl;
        }
        void turnCrank()
        {
            cout << "Out Of Gumball" << endl;
        }
        void dispenseGumball()
        {
            cout << "Out Of Gumball" << endl;
        }
};
class WinnerState : public StateInterface
{
    GumballMachineInterface *mGumballMachine;
    public:
        WinnerState(GumballMachineInterface *gumballMachine)
        {
            mGumballMachine = gumballMachine;
        }
        void insertQuarter()
        {
            cout << "Already have one" << endl;
        }
        void ejectQuarter()
        {
            cout << "cant" << endl;
        }
        void turnCrank()
        {
            cout << "can't" << endl;
        }
        void dispenseGumball()
        {
            cout << "holy shit u won" << endl;
            cout << "here ur gumball" << endl;
            mGumballMachine->dispenseGumball();
            if(mGumballMachine->getGumballs() > 0)
            {
                cout << "here ur gumball" << endl;
                mGumballMachine->dispenseGumball();
                if(mGumballMachine->getGumballs() > 0)
                {
                    mGumballMachine->setState(mGumballMachine->getNoQuarterState());
                }
                else
                {
                    mGumballMachine->setState(mGumballMachine->getOutOfGumballState());
                }
            }
            else
            {
                mGumballMachine->setState(mGumballMachine->getOutOfGumballState());
            }

        }   
};
class GumballMachine : public GumballMachineInterface
{
    int mGumballs;
    StateInterface* mCurrentState;
    StateInterface* mHasQuarterState;
    StateInterface* mNoQuarterState;
    StateInterface* mGumballSoldState;
    StateInterface* mOutOfGumballState;
    StateInterface* mWinnerState;
    public:
        GumballMachine(int gumballs)
        {
            mGumballs = gumballs;
            mHasQuarterState = new HasQuarterState(this);
            mNoQuarterState = new NoQuarterState(this);
            mGumballSoldState = new GumballSoldState(this);
            mOutOfGumballState = new OutOfGumballState(this);
            mWinnerState = new WinnerState(this);
            mCurrentState = mNoQuarterState;
        }
        void insertQuarter()
        {
            mCurrentState->insertQuarter();
        }
        void ejectQuarter()
        {
            mCurrentState->ejectQuarter();
        }
        void turnCrank()
        {
            mCurrentState->turnCrank();
            mCurrentState->dispenseGumball();
        }
        void dispenseGumball()
        {
            if(mGumballs > 0)
            {
                mGumballs--;
            }
            
        }
        StateInterface* getCurrentState()
        {
            return mCurrentState;
        }
        StateInterface* getNoQuarterState()
        {
            return mNoQuarterState;
        }
        StateInterface* getHasQuarterState()
        {
            return mHasQuarterState;
        }
        StateInterface* getGumballSoldState()
        {
            return mGumballSoldState;
        }
        StateInterface* getOutOfGumballState()
        {
            return mOutOfGumballState;
        }
        StateInterface* getWinnerState()
        {
            return mWinnerState;
        }
        void setState(StateInterface* state)
        {
            mCurrentState = state;  
        }
        int getGumballs()
        {
            return mGumballs;
        }
        StateInterface* getState()
        {
            return mCurrentState;
        }
};
int main()
{
    int count = 5;
    GumballMachine gumballMachine1(100);
    while(count > 0)
    {
        cout << "time : " << count << endl;
        gumballMachine1.insertQuarter();
        gumballMachine1.turnCrank();
        count--;
    }
    return 0;
}