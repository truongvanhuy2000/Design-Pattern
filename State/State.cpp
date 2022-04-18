#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class iState
{
    public:
    virtual void getForm() = 0;
    virtual void checkForm() = 0;
    virtual void rentApartment() = 0;
    virtual void giveKey() = 0;
};
class iRentalRobot
{
    public:
    virtual void getForm() = 0;
    virtual void checkForm() = 0;
    virtual void setState(iState *state) = 0;
    virtual iState* getState() = 0;
    virtual iState* getWaitingState() = 0;
    virtual iState* getReceivingFormState() = 0;
    virtual iState* getRentApartState() = 0;
    virtual iState* getFullyRentedState() = 0;
    virtual int getCount() = 0;
    virtual void setCount(int count) = 0;
};
class WaitingState : public iState
{
    private:
    iRentalRobot *mRobot;
    public:
    WaitingState(iRentalRobot *robot)
    {
        mRobot = robot;
    }
    void getForm()
    {
        cout << "ok got form" << endl;
        mRobot->setState(mRobot->getReceivingFormState());
    }
    void checkForm()
    {
        cout << "no form bitches" << endl;
    }
    void rentApartment()
    {
        cout << "no form bitches" << endl;
    }
    void giveKey()
    {
        cout << "no form bitches" << endl;
    }
};
class ReceivingFromState : public iState
{
    private:
    iRentalRobot *mRobot;
    int mRandom;
    public:
    ReceivingFromState(iRentalRobot *robot)
    {
        mRobot = robot;
    }
    void getForm()
    {
        cout << "fuck u already got form" << endl;
    }
    void checkForm()
    {
        mRandom = rand() % 10 + 0;
        if(mRandom < 5 && mRobot->getCount() > 0)
        {
            cout << "got u a room" << endl;
            mRobot->setState(mRobot->getRentApartState());
            mRobot->getState()->rentApartment();
        }
        else
        {
            cout << "fuck u no room" << endl;
            mRobot->setState(mRobot->getFullyRentedState());
        }
    }
    void rentApartment()
    {
        cout << "fuck u let me check" << endl;
    }
    void giveKey()
    {
        cout << "fuck u let me check" << endl;
    }
};
class RentApartmentState : public iState
{
    private:
    iRentalRobot *mRobot;
    public:
    RentApartmentState(iRentalRobot *robot)
    {
        mRobot = robot;
    }
    void getForm()
    {
        cout << "fuck u already got form" << endl;
    }
    void checkForm()
    {
        cout << "fuck u already check form" << endl;
    }
    void rentApartment()
    {
        mRobot->setCount(mRobot->getCount() - 1);
        giveKey();
    }
    void giveKey()
    {
        cout << "here ur fk key" << endl;
    }
};
class FullyRentedState : public iState
{
    private:
    iRentalRobot *mRobot;
    public:
    FullyRentedState(iRentalRobot *robot)
    {
        mRobot = robot;
    }
    void getForm()
    {
        cout << "fuck u already got form" << endl;
    }
    void checkForm()
    {
        cout << "fuck u already check form" << endl;
    }
    void rentApartment()
    {
        cout << "full bitch" << endl;
    }
    void giveKey()
    {
        cout << "full bitch" << endl;
    }
};
class RentalRobot : public iRentalRobot
{
    private:
    iState *mCurrentState;
    iState *mWaitingState;
    iState *mReceivingFromState;
    iState *mRentApartmentState;
    iState *mFullyRentedState;
    int mCount;
    public:
    RentalRobot(int count)
    {
        mCount = count;
        mWaitingState = new WaitingState(this);
        mReceivingFromState = new ReceivingFromState(this);
        mRentApartmentState = new RentApartmentState(this);
        mFullyRentedState = new FullyRentedState(this);
        mCurrentState = mWaitingState;
    }
    void getForm()
    {
        mCurrentState->getForm();
    }
    void checkForm()
    {
        mCurrentState->checkForm();
    }
    void setState(iState *state)
    {
        mCurrentState  = state;
    }
    iState* getState()
    {
        return mCurrentState;
    }
    iState* getWaitingState()
    {
        return mWaitingState;
    }
    iState* getReceivingFormState()
    {
        return mReceivingFromState;
    }
    iState* getRentApartState()
    {
        return mRentApartmentState;
    }
    iState* getFullyRentedState()
    {
        return mFullyRentedState;
    }
    int getCount()
    {
        return mCount;
    }
    void setCount(int count)
    {
        mCount = count;
    }
};
int main()
{
    RentalRobot cRobot(10);
    cRobot.getForm();
    cRobot.checkForm();
    return 0;
}