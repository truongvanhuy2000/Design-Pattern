#include <iostream>
#include <string>
using namespace std;
class cSeasonalAnime
{
    public:
        virtual void getName()
        {
            cout << "seasonal" << endl;
        }
        virtual void isekai()
        {
            cout << "meh" << endl;
        }
        virtual void action()
        {
            cout << "bruh" << endl;
        }
        virtual void romance()
        {
            cout << "meh" << endl;
        }
        virtual void adventure()
        {
            cout << "meh" << endl;
        }
        virtual void scifi()
        {
            cout << "meh" << endl;
        }
        cSeasonalAnime(){};
        virtual void listing()
        {
            getName();
            isekai();
            action();
            romance();
            adventure();
            scifi();
        }
};
class cFallAnime : public cSeasonalAnime
{
    public:
        void getName()
        {
            cout << "Fall" << endl;
        }
        void isekai()
        {
            cout << "dog ass" << endl;
        }
        void scifi()
        {
            cout << "good" << endl;
        }
};
class cWinterAnime : public cSeasonalAnime
{
    public:
        void getName()
        {
            cout << "Winter" << endl;
        }
        void isekai()
        {
            cout << "dog ass" << endl;
        }
        void romance()
        {
            cout << "good" << endl;
        }
        void action()
        {
            cout << "decent" << endl;
        }
};
int main()
{
    cSeasonalAnime *fallAnime = new cFallAnime();
    cSeasonalAnime *winterAnime = new cWinterAnime();
    fallAnime->listing();
    winterAnime->listing();
    return 0;
}