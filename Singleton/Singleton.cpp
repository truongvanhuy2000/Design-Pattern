#include <iostream>
#include <string>
using namespace std;
class database
{
    private:
        static database* mInstancePtr;
        int iRecord = 0; 
        string sName;
        database(string name)
        {
            sName = name;
            iRecord = 0;
        }
    public:
        void editRecord(int record)
        {
            iRecord = record;
        }
        string getName()
        {
            return sName;
        }
        static database* startInstance(string name)
        {
            if(mInstancePtr == nullptr)
            {
                mInstancePtr = new database(name);
            }
            return mInstancePtr;
        }
};
database* database::mInstancePtr = nullptr;
int main()
{
    database *c_database;
    c_database = database::startInstance("alo1");
    cout<< c_database->getName()<< endl;
    c_database = database::startInstance("alo2");
    cout<< c_database->getName()<< endl;
    return 0;
}