#include<iostream>
using namespace std;

class Box{
     private:
     double length;
     double width;
     double height;

     public:
     Box(){
         this->length = 1;
         this->width = 1;
         this->height = 1;
     }
     Box(double value){
        this->length = value;
        this->width = value;
        this->height = value;
     }
     Box(double length , double width , double height){
        this->length = length;
        this->width = width;
        this->height= height;
     }
     double volumeOfBox(){
        return (this->length * this->width * this->height);
     }
     int menulist(){
        int choice;
        cout<<"menulist : "<<endl;
        cout<<"1. calculate volume with default values :"<<endl;
        cout<<"2. calculate volume with length , breadth and height with same values  :"<<endl;
        cout<<"3. calculate volume with different length , breadth and height values :"<<endl;
        cout<<"0. Exit : "<<endl;
        cout<<"enter choice : "<<endl;
        cin>>choice;
        return choice;
     }
};
int main() {
    Box b1;
    int choice;

    do {
        choice = b1.menulist();
        switch (choice) {
            case 1: {
                cout << "volume by default values : " << b1.volumeOfBox() << endl;
                break;
            }
            case 2: {
                double n;
                cout << "enter value : " << endl;
                cin >> n;
                Box b2(n);
                cout << "volume by single value : " << b2.volumeOfBox() << endl;
                break;
            }
            case 3: {
                double a, b, c;
                cout << "enter values : " << endl;
                cin >> a >> b >> c;
                Box b3(a, b, c);
                cout << "volume by different values : " << b3.volumeOfBox() << endl;
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}