#include <iostream>
using namespace std;

class Employee
{
protected:
    int id;
    double salary;

public:
    Employee() : id(0), salary(0.0) {};
    Employee(int id, double salary) : id(id), salary(salary) {};

    void setId(int id)
    {
        this->id = id;
    }

    int getId()
    {
        return id;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    double getSalary()
    {
        return salary;
    }

    virtual void accept()
    {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void display()
    {
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : virtual public Employee
{
protected:
    double bonus;

public:
    Manager() : bonus(0) {};

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus()
    {
        return bonus;
    }

    void accept()
    {
        Employee::accept();
        this->acceptManager();
    }

    void display()
    {
        Employee::display();
        this->displayManager();
    }
    void acceptManager()
    {
        cout << "Enter Bonus: ";
        cin >> bonus;
    }

    void displayManager()
    {
        cout << "Bonus: " << bonus << endl;
    }
};

class Salesman : virtual public Employee
{
protected:
    double commission;

public:
    Salesman() {}

    Salesman(int id, double salary, double commission) : Employee(id, salary)
    {
        this->commission = commission;
    }

    void setCommission(double commission)
    {
        this->commission = commission;
    }

    double getCommission()
    {
        return commission;
    }
    void accept()
    {
        Employee::accept();
        this->acceptSalesman();
    }

    void display()
    {
        Employee::display();
        this->displaySalesman();
    }
    void acceptSalesman()
    {
        cout << "Enter Commission: ";
        cin >> commission;
    }

    void displaySalesman()
    {
        cout << "Commission: " << commission << endl;
    }
};

class SalesManager : public Manager, public Salesman
{
public:
    SalesManager() {}
    void accept()
    {
        Employee::accept();
        Salesman::acceptSalesman();
        Manager::acceptManager();
    }

    void display()
    {
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};

int main()
{
    cout << "\nSales Manager\n";
    Employee *e = new SalesManager();
    e->accept();
    e->display();
    delete e;
    e = NULL;
    return 0;
}