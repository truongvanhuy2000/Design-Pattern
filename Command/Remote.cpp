#include <iostream>
#include <string>
#include <vector>
using namespace std;
class iCommand
{
    public:
        virtual void execute() = 0;
        virtual void undo() = 0;
        virtual string getName() = 0;
};
class Light
{
    private:
        string mName;
    public:
        Light(string name)
        {
            mName = name;
        }
        void on()
        {
            cout << mName << " light on" << endl;
        }
        void off()
        {
            cout << mName << " light off" << endl;
        }
        string getName()
        {
            return mName;
        }
};
class Stereo
{
    private:
        string mName;
    public:
        Stereo(string name)
        {
            mName = name;
        }
        void on()
        {
            cout << mName << " stereo on" << endl;
        }
        void off()
        {
            cout << mName << " stereo off" << endl;
        }
        string getName()
        {
            return mName;
        }
};
class stereoOnCommand : public iCommand
{
    private:
        Stereo *mStereo;
    public:
        stereoOnCommand(Stereo *stereo) 
        {
            mStereo = stereo;
        }
        void execute()
        {
            mStereo->on();
        }
        void undo()
        {
            mStereo->off();
        }
        string getName()
        {
            return "stereoOnCommand";
        }
};
class stereoOffCommand : public iCommand
{
    private:
        Stereo *mStereo;
    public:
        stereoOffCommand(Stereo *stereo) 
        {
            mStereo = stereo;
        }
        void execute()
        {
            mStereo->off();
        }
        void undo()
        {
            mStereo->on();
        }
        string getName()
        {
            return "stereoOffCommand";
        }
};
class lightOnCommand : public iCommand
{
    private:
        Light *mLight;
    public:
        lightOnCommand(Light *Light) 
        {
            mLight = Light;
        }
        void execute()
        {
            mLight->on();
        }
        void undo()
        {
            mLight->off();
        }
        string getName()
        {
            return "lightOnCommand";
        }
};
class lightOffCommand : public iCommand
{
    private:
        Light *mLight;
    public:
        lightOffCommand(Light *Light) 
        {
            mLight = Light;
        }
        void execute()
        {
            mLight->off();
        }
        void undo()
        {
            mLight->on();
        }
        string getName()
        {
            return "lightOffCommand";
        }
};
class partyMacroCommand : public iCommand
{
    private:
        vector<iCommand *> mCommand;
    public:
        partyMacroCommand(vector<iCommand *> command)
        {
            mCommand = command;
        }
        void execute()
        {
            for (int i = 0; i < mCommand.capacity(); i++)
            {
                mCommand[i]->execute();
            }
        }
        void undo()
        {
            for (int i = mCommand.capacity() - 1; i >= 0; i--)
            {
                mCommand[i]->undo();
            }
        }
        string getName()
        {
            return "macro";
        }
};
class NoCommand : public iCommand
{
    public:
        void execute()
        {
            cout << "nothing" << endl;
        }
        void undo()
        {
            cout << "nothing" << endl;
        }
        string getName()
        {
            return "NoCommand";
        }
};
class RemoteControl
{
private:
    int mMaxCommand;
    vector <iCommand *> mOnCommand;
    vector <iCommand *> mOffCommand;
    iCommand *mUndoCommand;
public:
    RemoteControl(int maxCommand) 
    {
        mMaxCommand = maxCommand;
        iCommand *noCommand = new(NoCommand);
        for (int i = 0; i < mMaxCommand; i++)
        {
            mOnCommand.push_back(noCommand);
            mOffCommand.push_back(noCommand);
        }
        mUndoCommand = noCommand;
    }
    ~RemoteControl() {}
    void setCommand(int slot, iCommand *onCommand, iCommand *offCommand)
    {
        mOnCommand[slot] = onCommand;
        mOffCommand[slot] = offCommand;
    }
    void onButtonPressed(int slot)
    {
        mOnCommand[slot]->execute();
        mUndoCommand = mOnCommand[slot];
    }
    void offButtonPressed(int slot)
    {
        mOffCommand[slot]->execute();
        mUndoCommand = mOffCommand[slot];
    }
    void undoButtonPressed()
    {
        mUndoCommand->undo();
    }
    void getList()
    {
        for (int i = 0; i < mOnCommand.capacity(); i++)
        {
            cout << "slot:" << i << ": " << mOnCommand[i]->getName() << " " << mOffCommand[i]->getName() << endl;
        }
    }
};
int main()
{
    RemoteControl remote1(4);
    Light light1("kitchen");
    Light light2("toilet");
    Stereo stereo1("living");
    Stereo stereo2("bedroom");

    lightOnCommand lightOnCommand1(&light1);
    lightOffCommand lightOffCommand1(&light1);
    lightOnCommand lightOnCommand2(&light2);
    lightOffCommand lightOffCommand2(&light2);
    stereoOnCommand stereoOnCommand1(&stereo1);
    stereoOffCommand stereoOffCommand1(&stereo1);
    stereoOnCommand stereoOnCommand2(&stereo2);
    stereoOffCommand stereoOffCommand2(&stereo2);

    // vector <iCommand *> partyOn;
    // vector <iCommand *> partyOff;
    // partyOn.assign({&lightOnCommand1, &lightOnCommand2, &stereoOnCommand1});
    // partyOff.assign({&lightOffCommand1, &lightOffCommand2, &stereoOffCommand1});
    // partyMacroCommand partyOn1(partyOn);
    // partyMacroCommand partyOn2(partyOff);

    remote1.setCommand(0, &lightOnCommand1, &lightOffCommand1);
    remote1.setCommand(1, &lightOnCommand2, &lightOffCommand2);
    remote1.setCommand(2, &stereoOnCommand1, &stereoOffCommand1);
    remote1.setCommand(3, &stereoOnCommand2, &stereoOffCommand2);
    remote1.getList();
    remote1.onButtonPressed(0);
    remote1.onButtonPressed(1);
    remote1.onButtonPressed(2);
    remote1.onButtonPressed(3);
    remote1.undoButtonPressed();
    remote1.offButtonPressed(0);
    remote1.offButtonPressed(1);
    remote1.offButtonPressed(2);
    remote1.offButtonPressed(3);
    
    // remote1.setCommand(0, &partyOn1, &partyOn2);
    // remote1.getList();
    // remote1.onButtonPressed(0);
    // remote1.undoButtonPressed();
}