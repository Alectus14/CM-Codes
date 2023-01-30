#include <iostream>
#include <math.h>
using namespace std;

double function(double x) { return (pow(x, 3) - x - 4); }

void findRoot(double lowerBound, double upperBound) {
  double mid;
  if (function(lowerBound) * function(upperBound) < 0) {
    while (abs(lowerBound - upperBound) >= 0.0001) {
      mid = (lowerBound + upperBound) / 2;
      if (function(lowerBound) * function(mid) < 0) {
        upperBound = mid;
      } else {
        lowerBound = mid;
      }
    }
  } else {
    cout << "Your bounds are incorrect!" << endl;
    return;
  }

  cout << "\nThe root of the equation is: " << mid << endl << endl;
}
int main() {
  int lowerBound = 1, upperBound = 2;
  cout << "Enter the lower bound of the function: ";
  cin >> lowerBound;
  cout << "Enter the upper bound of the function: ";
  cin >> upperBound;

  findRoot(lowerBound, upperBound);

  return 0;
}