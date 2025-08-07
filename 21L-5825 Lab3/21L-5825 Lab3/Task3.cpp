#include <iostream>
using namespace std;
class tollBooth
{
int num_cars;
double money;
public:
tollBooth()
{
num_cars = 0;
money = 0;
}
void paying_car()
{
num_cars++;
money += 0.5;
}
void no_pay_car()
{
num_cars++;
}
void display()
{
cout << "Total number of cars : "<<num_cars <<endl;
cout << "Totam money collected : $"<<money << endl;
}
};
int main()
{
int i=78 ;
tollBooth machine;
cout << "Enter 1 for Paying car / Enter 2 for Non-Paying car / ";
cout << "Enter 0 key to Print total / Enter -1 to Exit" << endl;
while (i != -1)
{
cout<< "Enter an option :" << endl;
cin >> i;
if (i == 1)
{
machine.paying_car();
}
if (i == 2)
{
machine.no_pay_car();
}
if (i==-1)
{
machine.display();
return 0;
}
}

}

