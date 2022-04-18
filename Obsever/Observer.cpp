#include <iostream>
#include <string>
#include <vector>
using namespace std;
class iObserver
{
    public:
        virtual void update(string operation, string record) = 0;
};
class iSubject
{
    public:
        virtual void registerObserver(iObserver *o) = 0;
        virtual void removeObserver(iObserver *o) = 0;
        virtual void notifyObserver() = 0;
        virtual void editRecord(string operation, string record) = 0;
};
class database : public iSubject
{
    private:
    vector<iObserver *> vObserver;
    string mOperation;
    string mRecord;
    public:
        void registerObserver(iObserver *observer)
        {
            vObserver.push_back(observer);
        }
        void removeObserver(iObserver *observer)
        {
            if(vObserver.size() != 0)
            {
                for(int i = 0; i < vObserver.size(); i++)
                {
                    if(vObserver[i] == observer)
                    {
                        vObserver.erase(vObserver.begin()+i);
                    }
                }
            }
            else
            {
                cout << "no one here" << endl;
            }
        }
        void notifyObserver()
        {
            if(vObserver.size() != 0)
            {
                for(int i = 0; i < vObserver.size(); i++)
                {
                    vObserver[i]->update(mOperation, mRecord);
                }
            }
            else
            {
                cout << "no one here" << endl;
            }
            
        }
        void editRecord(string operation, string record)
        {
            mOperation = operation;
            mRecord = record;
            notifyObserver();
        }
};
class boss : public iObserver
{
    void update(string operation, string record)
    {
        cout << "boss update, operation: " << operation << " record: " << record << endl;
    }
};
class client : public iObserver
{
    void update(string operation, string record)
    {
        cout << "client update, operation: " << operation << " record: " << record << endl;
    }
};
class dev : public iObserver
{
    void update(string operation, string record)
    {
        cout << "dev update, operation: " << operation << " record: " << record << endl;
    }
};
int main()
{
    boss BossA;
    client ClientA;
    dev DevA;
    database Data;
    Data.registerObserver(&BossA);
    Data.registerObserver(&ClientA);
    Data.registerObserver(&DevA);
    Data.editRecord("shit", "ass");
    Data.removeObserver(&DevA);
    Data.editRecord("fuck", "dicc");
    return 0;
}