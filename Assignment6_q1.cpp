#include <iostream>
using namespace std;

class Product
{
protected:
    int id;
    string title;
    double price;

public:
    Product() : id(0), title(""), price(0.0) {};
    Product(int id, string title, double price) : id(id), title(title), price(price) {}

    virtual double getDiscountPrice() = 0;
    virtual void displayProduct() = 0;
    virtual void acceptProduct() = 0;
    virtual ~Product() {}
};

class Book : public Product
{
private:
    string author;

public:
    Book() : author("") {};
    Book(int id, string title, string author, double price) : Product(id, title, price), author(author) {}

    double getDiscountPrice()
    {
        return price * 0.90;
    }
    void acceptProduct()
    {
        cout << "id :";
        cin >> id;
        cout << "title :";
        cin >> title;
        cout << "author :";
        cin >> author;
        cout << "price :";
        cin >> price;
    }
    void displayProduct()
    {
        cout << "id : " << id << " Book Title: " << title << " Author: " << author << " Original Price: " << price << " Discounted: " << getDiscountPrice() << endl;
    }
};

class Tape : public Product
{
private:
    string artist;

public:
    Tape() : artist("") {};
    Tape(int id, string title, string artist, double price) : Product(id, title, price), artist(artist) {}

    double getDiscountPrice()
    {
        return price * 0.95;
    }
    void acceptProduct()
    {
        cout << "id :";
        cin >> id;
        cout << "title :";
        cin >> title;
        cout << "author :";
        cin >> artist;
        cout << "price :";
        cin >> price;
    }

    void displayProduct()
    {
       cout << "id : " << id << " Tape Title: " << title << " Artist: " << artist << " Original Price: " << price << " Discounted: " << getDiscountPrice() << endl;
    }
};

int main()
{
    Product *p[3];
    int totalAmount = 0;

    for (int i = 0; i < 3; i++)
    {
        int choice;
        cout << "\nproduct : "<< i + 0;
        cout<< " Added to Cart :  ";
        cout << "\n 1. Book : ";
        cout << "\n 2. Tape : \n";
        cin >> choice;

        if (choice == 1)
        {
            p[i] = new Book();
        }
        else
        {
            p[i] = new Tape();
        }
        p[i]->acceptProduct();
    }
    cout << "\nFinal Bill : " << endl;
    for (int i = 0; i < 3; i++)
    {
        p[i]->displayProduct();
        totalAmount += p[i]->getDiscountPrice();

        delete p[i];
        p[i] = NULL;
    }
    cout << "TOTAL AMOUNT: " << totalAmount << endl;
}
