#include <iostream>
using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time()
    {
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }
    Time(int h, int m, int s)
    {
        this->hour = h;
        this->minute = m;
        this->second = s;
    }

    int getHour()
    {
        return this->hour;
    }

    int getMinute()
    {
        return this->minute;
    }

    int getSeconds()
    {
        return this->second;
    }

    void setHour(int h)
    {
        this->hour = h;
    }

    void setMinute(int m)
    {
        this->minute = m;
    }

    void setSeconds(int s)
    {
        this->second = s;
    }

    void printTime()
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};

int main()
{
    int n;

    cout << "Enter number of Time objects: ";
    cin >> n;

    Time *t = new Time[n];

    int choice;

    do
    {
        cout << "Menulist : ";
        cout << "1. Add Time\n";
        cout << "2. Display All Time\n";
        cout << "3. Display only Hours\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            for (int i = 0; i < n; i++)
            {
                int h, m, s;

                cout << "Enter hour minute second: ";
                cin >> h >> m >> s;

                t[i].setHour(h);
                t[i].setMinute(m);
                t[i].setSeconds(s);
            }
            break;
        }

        case 2:
        {
            cout << "All times \n: ";
            for (int i = 0; i < n; i++)
            {
                t[i].printTime();
            }
            break;
        }

        case 3:
        {
            cout << "Hours of all objects\n";
            for (int i = 0; i < n; i++)
            {
                cout << t[i].getHour() << endl;
            }
            break;
        }

        case 4:
            cout << "Exit\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    delete[] t;
    t = NULL;

    return 0;
}