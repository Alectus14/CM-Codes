#include <cmath>
#include <iostream>
using namespace std;

double function(double x) { return pow(x, 3) - 7 * pow(x, 2) + 16 * x - 12; }
double derivative(double x) { return 3 * pow(x, 2) - 14 * x + 16; }

int main() {
  double assumedRoot{1};
  size_t numDecimalPlaces{3};
  cout << "Enter the assumed root: ";
  cin >> assumedRoot;

  cout << "Enter the number of decimal places: ";
  cin >> numDecimalPlaces;

  double root{};
  double accuracy = 0.5 * pow(0.1, numDecimalPlaces);

  while (true) {
    root = assumedRoot - function(assumedRoot) / derivative(assumedRoot);
    if (abs(root - assumedRoot) < accuracy) {
      break;
    }
    assumedRoot = root;
  }

  assumedRoot = (round(assumedRoot*pow(10, numDecimalPlaces)))*pow(0.1, numDecimalPlaces);
  cout << "The root of the equation is: " << assumedRoot;
  return 0;
}
