#include <iostream>
#include <string>
using namespace std;
class iBackEndA
{
    public:
        virtual void setName(string name) = 0;
        virtual string getName() = 0;
};

class UserA : public iBackEndA
{
    private:
        string sUserName;
    public:
        void setName(string name)
        {
            sUserName = name;
        }
        string getName()
        {
            return sUserName;
        }
};
class iBackEndB
{
    public:
        virtual void setFirstName(string name) = 0;
        virtual void setLastName(string name) = 0;
        virtual string getLastName() = 0;
        virtual string getFirstName() = 0;
};
class UserB : public iBackEndB
{
    private:
        string sFirstName;
        string sLastName;
    public:
        void setFirstName(string name)
        {
            sFirstName = name;
        }
        void setLastName(string name)
        {
            sLastName = name;
        }
        string getLastName()
        {
            return sLastName;
        }
        string getFirstName()
        {
            return sFirstName;
        }
};
class UserAtoBAdapter
{
    private:
        iBackEndA *cUser;
        //UserA user1;
        string sFirstName;
        string sLastName;
    public:
        UserAtoBAdapter(iBackEndA *user)
        {
            cUser = user;
            int splitPos = cUser->getName().find_first_of(" ");
            if (splitPos != string::npos)
            {
                sFirstName = user->getName().substr(0, splitPos + 1);
                sLastName = user->getName().substr(splitPos + 1, user->getName().length() - sFirstName.length());
            }

        }
        void setFirstName(string name)
        {
            sFirstName = name;
        }
        void setLastName(string name)
        {
            sLastName = name;
        }
        string getLastName()
        {
            return sLastName;
        }
        string getFirstName()
        {
            return sFirstName;
        }
};
int main()
{
    UserA cUserA;
    UserB cUserB;
    cUserA.setName("van huy");
    UserAtoBAdapter adapter(&cUserA);
    cUserB.setFirstName(adapter.getFirstName());
    cUserB.setLastName(adapter.getLastName());
    cout << cUserB.getFirstName() << endl;
    cout << cUserB.getLastName() << endl;
    return 0;
}