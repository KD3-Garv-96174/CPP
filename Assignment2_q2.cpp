#include<iostream>
using namespace std;

class Tollbooth{
     private:
     unsigned int noOfCars;
     double totalAmount;
     unsigned int nonPayingCars;
     unsigned int payingCars;

     public:
     Tollbooth(){
        this->noOfCars = 0;
        this->totalAmount = 0;
        this->nonPayingCars = 0;
        this->payingCars = 0;
     }
     void payingCar(){
           ++this->payingCars;
           ++this->noOfCars;
           this->totalAmount += 0.50;
     }
     void noPayCar(){
           ++this->nonPayingCars;
           ++this->noOfCars;
     }
     void printOnConsole(){
           cout<<"total no. of cars : "<<this->noOfCars<<endl;
           cout<<"total amount collected : "<<this->totalAmount<<endl;
           cout<<"total non paying cars : "<<this->nonPayingCars<<endl;
           cout<<"total paying cars : "<<this->payingCars<<endl;
     }
};

int main(){
     Tollbooth t1;
     t1.payingCar();
     t1.payingCar();
     t1.payingCar();
     t1.payingCar();
     t1.payingCar();
     t1.noPayCar();
     t1.noPayCar();
     t1.noPayCar();
     t1.printOnConsole();
}
