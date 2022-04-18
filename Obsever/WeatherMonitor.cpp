#include <iostream>
#include <string>
#include <vector>
using namespace std;
class observerInterface
{
    public:
        virtual void updateData(int temp, int humid) = 0;
};
class weatherDataInterface
{
    public:
        virtual void registerObserver(observerInterface *o) = 0;
        virtual void removeObserver(observerInterface *o) = 0;
        virtual void notifyObserver() = 0;
};
class weatherData : public weatherDataInterface
{
    private:
        int mTemp;
        int mHumid;
        vector <observerInterface *> observerList;
    public:
        void registerObserver(observerInterface *o)
        {
            observerList.push_back(o);
        }
        void removeObserver(observerInterface *o)
        {
            if(observerList.size() != 0)
            {
                for(int i = 0; i < observerList.size(); i++)
                {
                    if(observerList[i] == o)
                    {
                        observerList.erase(observerList.begin()+i);
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
            if(observerList.size() != 0)
            {
                for(int i = 0; i < observerList.size(); i++)
                {
                    observerList[i]->updateData(mTemp, mHumid);
                }
            }
            else
            {
                cout << "no one here" << endl;
            }
        }
        void setData(int temp, int humid)
        {
            mTemp = temp;
            mHumid = humid;
            mesurementChanged();
        }
        void mesurementChanged()
        {
            notifyObserver();
        }
};
class forecastDisplay: public observerInterface
{
    private:
        int mLastTemp;
        int mLastHumid;
        string mTempForecast;
        string mHumidForecast;
    public:
        forecastDisplay()
        {
            mLastTemp = 30;
            mLastHumid = 50;
        }
        void updateData(int temp, int humid)
        {
            if(temp > mLastTemp)
            {
                mTempForecast = "warmer";
            }
            else
            {
                mTempForecast = "colder";
            }
            if(humid > mLastHumid)
            {
                mHumidForecast = "more moist";
            }
            else
            {
                mHumidForecast = "less moist";
            }
            displayForcast(mTempForecast, mHumidForecast);
        }
        void displayForcast(string tempForecast, string humidForecast)
        {
            cout << "Forecast Display Temprature: " << tempForecast << " Humidity: " << humidForecast << endl;
        }
};
class statisticDisplay: public observerInterface
{
    private:
        int mMaxTemp;
        int mMinTemp;
        int mMaxHumid;
        int mMinHumid;
    public:
        statisticDisplay()
        {
            mMaxTemp = 30;
            mMinTemp = 30;
            mMaxHumid = 50;
            mMinHumid = 50;
        }
        void updateData(int temp, int humid)
        {
            findMaxMin(temp, humid);
            displayStatistic();
        }
        void findMaxMin(int &temp, int &humid)
        {
            if(temp > mMaxTemp)
            {
                mMaxTemp = temp;
            }
            if(temp < mMinTemp)
            {
                mMinTemp = temp;
            }
            if(humid > mMaxHumid)
            {
                mMaxHumid = humid;
            }
            if(humid < mMinHumid)
            {
                mMinHumid = humid;
            }
        }
        void displayStatistic()
        {
            cout << "Statistic Display Max/Min Temprature: " << mMaxTemp << "/" << mMinTemp << " Max/Min Humidity: " << mMaxHumid << "/" << mMinHumid << endl;
        }
};
class currentConditionsDisplay: public observerInterface
{
    private:
        int mTemp;
        int mHumid;
    public:
        currentConditionsDisplay()
        {
            mTemp = 0;
            mHumid = 0;
        }
        void updateData(int temp, int humid)
        {
            mTemp = temp;
            mHumid = humid;
            displayData();
        }
        void displayData()
        {
            cout << "Current Conditions Display Temprature: " << mTemp << " Humidity: " << mHumid << endl;
        }
};
int main()
{
    weatherData weatherDataObject;
    currentConditionsDisplay CurrentCondition1;
    statisticDisplay statistic1;
    forecastDisplay forecast2;
    weatherDataObject.registerObserver(&CurrentCondition1);
    weatherDataObject.registerObserver(&statistic1);
    weatherDataObject.registerObserver(&forecast2);
    weatherDataObject.setData(100, 20);
    weatherDataObject.removeObserver(&forecast2);
    weatherDataObject.setData(20, 20);
    return 0;
}