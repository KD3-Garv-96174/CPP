#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(2000) {};
    Date(int day, int month, int year) : day(day), month(month), year(year) {};

    void acceptDate()
    {
        cout << "day : ";
        cin >> day;
        cout << "month : ";
        cin >> month;
        cout << "year : ";
        cin >> year;
    }
    void displayDate()
    {
        cout << day << "-" << month << "-" << year;
    }
};
class Person
{
private:
    string name;
    string address;
    Date dob;

public:
    Person() : name(""), address("") {};
    Person(string name, string address) : name(name), address(address) {};
    Person(string name, string address, int day, int month, int year) : name(name), address(address), dob(day, month, year) {};

    void acceptPerson()
    {
        cout << "name : ";
        cin >> name;
        cout << "address : ";
        cin >> address;
        cout << "dob : ";
        this->dob.acceptDate();
    }
    void displayPerson()
    {
        cout << "name : " << name << endl;
        cout << "address : " << address << endl;
        cout << "dob ";
        this->dob.displayDate();
    }
};
class Student
{
private:
    int id;
    double marks;
    string course;
    Date joinDate;
    Date endDate;

public:
    Student() : id(0), marks(0.0),course("") {};
    Student(int id,double marks,string course) : id(id),marks(marks),course(course) {};
    Student(int id,double marks,string course,Date joindate , Date endDate) : Student(id,marks,course)  {
        this->joinDate = joinDate;
        this->endDate = endDate;
    };

    void acceptStudent()
    {
        cout << "id : ";
        cin >> id;
        cout << "marks : ";
        cin >> marks;
        cout << "course : ";
        cin >> course;
        cout<<"joinDate : ";
        this->joinDate.acceptDate();
        cout<<"endDate : ";
        this->endDate.acceptDate();
    }
    void displayStudent()
    {
        cout << "id : " << id << endl;
        cout << "marks : " << marks << endl;
        cout << "course : " << course << endl;
        cout << "joinDate : ";
        this->joinDate.displayDate();
        cout << "\nendDate : ";
        this->endDate.displayDate();
    }
};
int main()
{
    Person p;
    Student s;
    int choice;

    do {
        cout << "MENU"<<endl;
        cout << "1. Accept Person\n";
        cout << "2. Display Person\n";
        cout << "3. Accept Student\n";
        cout << "4. Display Student\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: p.acceptPerson(); break;
            case 2: p.displayPerson(); break;
            case 3: s.acceptStudent(); break;
            case 4: s.displayStudent(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);

}