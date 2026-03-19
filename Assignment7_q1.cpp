#include <iostream>
using namespace std;
#include <typeinfo>

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
    Manager(double bonus) : bonus(bonus) {};
    Manager(int id, double salary, double bonus) : Employee(id, salary), bonus(bonus) {};

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
    Salesman() : commission(0) {}
    Salesman(double commission) : commission(commission) {};
    Salesman(int id, double salary, double commission) : Employee(id, salary), commission(commission) {};

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
    SalesManager(int id, double salary, double bonus, double commission) : Employee(id, salary), Manager(bonus), Salesman(commission) {};

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
int menuList()
{
    int choice;
    cout << "menulist : ";
    cout << "\n1. Add Manager : ";
    cout << "\n2. Add Salesman : ";
    cout << "\n3. Add Salesmanager : ";
    cout << "\n4. Display count of all employees with respect to designation : ";
    cout << "\n5. Display all Manager : ";
    cout << "\n6. Display all Salesman : ";
    cout << "\n7. Display all SalesManager : ";
    cout << "\nenter choice : ";
    cin >> choice;
    return choice;
}

int main()
{
    int i = 0;
    Employee *arr[i];
    int m = 0, s = 0, sm = 0;

    int choice;
    do
    {
        choice = menuList();

        switch (choice)
        {
        case 1:
            arr[i] = new Manager;
            arr[i]->accept();
            i++;
            break;
        case 2:
            arr[i] = new Salesman;
            arr[i]->accept();
            i++;
            break;
        case 3:
            arr[i] = new SalesManager;
            arr[i]->accept();
            i++;
            break;
        case 4:
            for (int j = 0; j < i; j++)
            {
                if (typeid(*arr[j]) == typeid(Manager))
                {
                    m++;
                }
                else if (typeid(*arr[j]) == typeid(Salesman))
                {
                    s++;
                }
                else if (typeid(*arr[j]) == typeid(SalesManager))
                {
                    sm++;
                }
            }
            cout << "Manager : " << m;
            cout << "\nSalesman : " << s;
            cout << "\nSalesManager : \n"
                 << sm << endl;
            break;
        case 5:
            for (int j = 0; j < i; j++)
            {
                if (typeid(*arr[j]) == typeid(Manager))
                {
                    arr[j]->display();
                }
            }
            break;
        case 6:
            for (int j = 0; j < i; j++)
            {
                if (typeid(*arr[j]) == typeid(Salesman))
                {
                    arr[j]->display();
                }
            }
            break;
        case 7:
            for (int j = 0; j < i; j++)
            {
                if (typeid(*arr[j]) == typeid(SalesManager))
                {
                    arr[j]->display();
                }
            }
            break;
        }
    } while (choice != 0);


    for (int j = 0; j < i; j++)
    {
        cout << sizeof(&arr)<<endl;
        delete arr[j];
        arr[j] = NULL;
    }

}
