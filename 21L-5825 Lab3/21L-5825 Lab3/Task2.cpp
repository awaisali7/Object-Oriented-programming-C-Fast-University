#include <iostream>
#include <iomanip>

using namespace std;

class Angle
{
private:

 int degrees;
 float minutes;
 char directions;

public:

 Angle(int deg, float min, char dir)
 {
 degrees = deg;
 minutes = min;
 directions = dir;
 }


 void getAngle()
 {
 cout << "Enter degrees: ";
 cin >> degrees;
 cout << "Enter minutes: ";
 cin >> minutes;
 cout << "Enter direction (N/S/E/W): ";
 cin >> directions;
 }

 void DisplayAngle()
 {
 cout << degrees << "\xF8" << fixed << setprecision(1) << minutes << "\' " << directions << endl;
 }


};

int main()
{
 Angle location(149, 34.8, 'W');

 location.DisplayAngle();
 cout << endl;

 char choice;

 do
 {
 Angle newAngle(0, 0.0, ' ');

 cout << "\nEnter value for new angle :- " << endl;
 newAngle.getAngle();

 cout << "The angle values are :- " << endl;
 newAngle.DisplayAngle();

 cout << "\nDo you want to enter another angle ? ";
 cout << "Y for Yes and No for No : ";
 cin >> choice;

 } while (choice == 'y' || choice == 'Y');

 return 0;
}
