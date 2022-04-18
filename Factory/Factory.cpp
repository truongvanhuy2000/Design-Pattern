#include <iostream>
#include <string>
using namespace std;
enum eConnectionType
{
    CONNECTION_TYPE_ORAL,
    CONNECTION_TYPE_SQL,
    CONNECTION_TYPE_DEFAULT
};
class iConnection
{
    public:
    virtual void getDbName() = 0;
};
class sqlConnection: public iConnection
{
    void getDbName()
    {
        cout << "sql"<< endl;
    }
};
class oralConnection: public iConnection
{
    void getDbName()
    {
        cout << "oral"<< endl;
    }
};
class defaultConnection: public iConnection
{
    void getDbName()
    {
        cout << "default"<< endl;
    }
};
class dbFactory
{
    public:
    static iConnection* createConnection(eConnectionType connetionType);
};
iConnection* dbFactory:: createConnection(eConnectionType connetionType)
{
    iConnection *connetionPtr;
    switch(connetionType)
    {
        case CONNECTION_TYPE_SQL:
            connetionPtr = new sqlConnection();
            break;
        case CONNECTION_TYPE_ORAL:
            connetionPtr = new oralConnection();
            break;
        case CONNECTION_TYPE_DEFAULT:
            connetionPtr = new defaultConnection();
            break;
    }
    return connetionPtr;
}
int main()
{
    iConnection *connection;
    connection = dbFactory::createConnection(CONNECTION_TYPE_SQL);
    connection->getDbName();
    connection = dbFactory::createConnection(CONNECTION_TYPE_ORAL);
    connection->getDbName();
    return 0;
}