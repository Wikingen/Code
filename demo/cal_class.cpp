#include <iostream>
using namespace std;

#define MAX_HOLIDAYS 30


struct Date
{
    int day;
    int month;
    int year;
};


class Calendar
{
public:
    Calendar(int d, int m, int y)
    {
        setDay(d);
        setMonth(m);
        setYear(y);
    }

    void nextDay()
    {
        currentDay.day++;
        if (currentDay.day > 31)
        {
            currentDay.month++;
            currentDay.day = 1;
            if (currentDay.month > 12)
            {
                currentDay.year++;
                currentDay.month = 1;
            }
        }
    }


    void printDay()
    {
        cout << "Today is " << currentDay.day << "/" << currentDay.month << "/" << currentDay.year << endl;
    }

    bool isHoliday()
    {

        for (int i = 0; i < MAX_HOLIDAYS; i++)
        {
            if (currentDay.day == holidays[i].day &&
                currentDay.month == holidays[i].month &&
                currentDay.year == holidays[i].year)
                {
                    return true;
                }
        }
        return false;
    }




private:

    Date currentDay = {3,23,2013};
    Date holidays[MAX_HOLIDAYS];

    void setDay(int d)
    {
        if (d < 1 || d > 31)
        {
            currentDay.day = 1;
        }
        else
        {
            currentDay.day = d;
        }
    }
    void setMonth(int m)
    {
        if (m < 1 || m > 12)
        {
            currentDay.month = 1;
        }
        else
        {
            currentDay.month = m;
        }
    }
    void setYear(int y)
    {
        if (y < 1 || y > 2024)
        {
            currentDay.year = 1;
        }
        else
        {
            currentDay.year = y;
        }
    }
};

int main()
{
    Calendar myCal(31,12,2013);

    myCal.printDay();

    cout << "A day later... " << endl;
    myCal.nextDay();

    myCal.printDay();


}