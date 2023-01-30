#include <cmath>
#include <iostream>
using namespace std;

double func(double x) { return x * x * x - x - 4; }

void calculateRoot(double lowerBound, double upperBound) {
  const int numDecimalPlaces{3};
  double mid;
  double accuracy = 0.5 * pow(10, -numDecimalPlaces);

  if (func(lowerBound) * func(upperBound) < 0) {
    while (abs(upperBound - lowerBound) >= accuracy) {
      mid = (lowerBound + upperBound) / 2;

      if (func(lowerBound) * func(mid) < 0) {
        upperBound = mid;
      } else {
        lowerBound = mid;
      }
    }

    cout << "The root of the eqaution is: " << mid << endl;
  } else {
    cout << "Your bounds are INCORRECT!" << endl;
  }
}

int main() {
  double lowerBound{}, upperBound{};
  cout << "Enter the lower bound value: ";
  cin >> lowerBound;
  cout << "Enter the upper bound value: ";
  cin >> upperBound;

  calculateRoot(lowerBound, upperBound);
  return 0;
}
