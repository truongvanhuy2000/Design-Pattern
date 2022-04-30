#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Tuner
{
    public:
        void on()
        {
            cout << "Tuner on" << endl;
        }
        void off()
        {
            cout << "Tuner off" << endl;
        }
        void setAm()
        {
            cout << "setAm" << endl;
        }
        void setFm()
        {
            cout << "setFm" << endl;
        }
};
class Screen
{
    public:
        void up()
        {
            cout << "screen up" << endl;
        }
        void down()
        {
            cout << "screen down" << endl;
        }
};
class Amplifier
{
    public:
        void on()
        {
            cout << "Ampli on" << endl;
        }
        void off()
        {
            cout << "Ampli on" << endl;
        }
        void setStereoSound()
        {
            cout << "set Stereo Sound" << endl;
        }
        void setSurroundSound()
        {
            cout << "set Surround Sound" << endl;
        }
        void setVolume()
        {
            cout << "set Volume" << endl;
        }
};
class CdPlayer
{
    public:
        void on()
        {
            cout << "CD on" << endl;
        }
        void off()
        {
            cout << "CD off" << endl;
        }
        void eject()
        {
            cout << "CD eject" << endl;
        }
        void pause()
        {
            cout << "CD pause" << endl;
        }
        void play()
        {
            cout << "CD play" << endl;
        }
        void stop()
        {
            cout << "CD stop" << endl;
        }
};
class HomeTheaterFacade
{
    Tuner* mTuner;
    CdPlayer* mCdPlayer;
    Amplifier* mAmpli;
    Screen* mScreen;
    public:
        HomeTheaterFacade(Tuner* tuner, CdPlayer* cdPlayer, Amplifier* ampli, Screen* screen)
        {
            mTuner = tuner;
            mCdPlayer = cdPlayer;
            mAmpli = ampli;
            mScreen = screen;
        }
        void doThing1()
        {
            cout << "doThing1" << endl;
            mTuner->on();
            mCdPlayer->pause();
            mScreen->up();
        }
        void doThing2()
        {
            cout << "doThing2" << endl;
            mTuner->setAm();
            mCdPlayer->eject();
            mScreen->down();
            mAmpli->setStereoSound();
        }
        void doThing3()
        {
            cout << "doThing3" << endl;
            mTuner->setFm();
            mScreen->up();
            mCdPlayer->play();
        }
};
int main()
{
    Tuner tuner1;
    CdPlayer cdPlayer1;
    Amplifier ampli1;
    Screen screen1;
    HomeTheaterFacade homeTheater1(&tuner1, &cdPlayer1, &ampli1, &screen1);
    homeTheater1.doThing1();
    homeTheater1.doThing2();
    homeTheater1.doThing3();
    return 0; 
}
