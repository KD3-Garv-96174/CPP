#include <iostream>
using namespace std;

struct Date {
    int day;
    int month;
    int year;

    void initDate() {
    day = 1;
    month = 1;
    year = 2000;
}

void printDateOnConsole() {
    cout << "Date: " << day << "/" << month << "/" << year << endl;
}

void acceptDateFromConsole() {
    cout << "Enter Day: ";
    cin >> day;
    cout << "Enter Month: ";
    cin >> month;
    cout << "Enter Year: ";
    cin >> year;
}

bool isLeapYear() {
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}
};



int menulist() {
    int choice;
    cout << "\nMenu List:\n";
    cout << "1. initDate\n";
    cout << "2. printDateOnConsole\n";
    cout << "3. acceptDateFromConsole\n";
    cout << "4. isLeapYear\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}

int main() {
    struct Date d;
    int choice;
    do {
        choice = menulist();
        switch (choice) {
            case 1: d.initDate(); break;
            case 2: d.printDateOnConsole(); break;
            case 3: d.acceptDateFromConsole(); break;
            case 4: cout << (d.isLeapYear() ? "Leap Year\n" : "Not a Leap Year\n"); break;
        }
    } while (choice != 0);
    return 0;
}