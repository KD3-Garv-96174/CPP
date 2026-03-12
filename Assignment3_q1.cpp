#include <iostream>
using namespace std;

class Cylinder
{
private:
double radius;
double height;
static double PI;

public:
Cylinder() : radius(0.0),height(0.0) 
{}  
Cylinder(double radius , double height) : radius(radius),height(height)
{}
void calculateVolume(){
    cout<<PI * this->radius*this->radius * this->height;
}
void setRadius(double radius){
    this->radius = radius;
}
double getRadius(){
    return this->radius;
}
void setHeight(double height){
    this->height = height;
}
double getHeight(){
    return this->height;
}
};
double Cylinder :: PI = 3.14;
int main()
{
    Cylinder c2(3,4);
    c2.calculateVolume();
    cout<<endl;
    c2.setHeight(5);
    c2.calculateVolume();
}