#include <iostream>
#include <string>
using namespace std;
enum eGameGenre
{
    GENRE_ACTION,
    GENRE_RPG,
    GENRE_SHOOTER
};
class iGameGenre
{
    public:
        virtual void getGenre() = 0;
};
class genreRPG : public iGameGenre
{
    public:
        void getGenre()
        {
            cout<< "RPG"<<endl;
        }
};
class genreAction : public iGameGenre
{
    public:
        void getGenre()
        {
            cout<< "Action"<<endl;
        }
};
class genreShooter : public iGameGenre
{
    public:
        void getGenre()
        {
            cout<< "Shooter"<<endl;
        }
};
class genreFactory
{
    public:
    static iGameGenre* intGameGenre(eGameGenre genre);
};
iGameGenre* genreFactory::intGameGenre(eGameGenre genre)
{
    iGameGenre *genrePtr;
    switch (genre)
    {
    case GENRE_ACTION:
        genrePtr = new genreAction();
        break;
    case GENRE_RPG:
        genrePtr = new genreRPG();
        break;
    case GENRE_SHOOTER:
        genrePtr = new genreShooter();
        break;
    default:
        break;
    }
    return genrePtr;
}
int main()
{
    iGameGenre *genrePtr;
    genrePtr = genreFactory::intGameGenre(GENRE_SHOOTER);
    genrePtr->getGenre();
    return 0;
}