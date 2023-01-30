#include <cmath>
#include <iostream>
using namespace std;

double function(double x) { return x * x * x - 5 * x + 1; }
double sectantMethod(double x0, double x1, double f0, double f1) {
  return x1 - ((x1 - x0) * f1 / (f1 - f0));
}

int main() {
  double x0, x1;
  cout << "Enter the value of x0: ";
  cin >> x0;
  cout << "Enter the value of x1: ";
  cin >> x1;
  double x2, f0, f1, numDecimalPlaces;
  cout << "Enter the number of decimal places: ";
  cin >> numDecimalPlaces;
  f0 = function(x0);
  f1 = function(x1);
  x2 = sectantMethod(x0, x1, f0, f1);
  cout << "The value of x2 is " << x2 << endl;
  int temp = 3;
  while (abs(x2 - x1) > pow(0.1, numDecimalPlaces)) {
    x0 = x1;
    x1 = x2;
    f0 = f1;
    f1 = function(x2);
    x2 = sectantMethod(x0, x1, f0, f1);
    cout << "The value of x" << temp << " is " << x2 << endl;
    temp++;
  }
  cout << endl;
  cout << "The final root is: " << x2;

  return 0;
}
