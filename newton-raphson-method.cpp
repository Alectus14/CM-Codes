#include <iostream>
#include <math.h>
using namespace std;

double function(double x) { return (pow(x, 3) - 3 * x - 5); }

double derivative(double x) { return (3 * pow(x, 2) - 3); }

int main() {
  double assumedRoot = 2;
  int numDecimalPlaces = 3;
  cout << "Enter the assumed root for the function: ";
  cin >> assumedRoot;
  cout << "Enter the number of decimal places: ";
  cin >> numDecimalPlaces;

  double root = 0;
  double accuracy = 0.5 * pow(0.1, numDecimalPlaces);

  while (true) {
    root = assumedRoot - (function(assumedRoot) / derivative(assumedRoot));
    if (abs(root - assumedRoot) < accuracy) {
      break;
    }
    assumedRoot = root;
  }

  assumedRoot = (round(assumedRoot * pow(10, numDecimalPlaces))) *
                pow(0.1, numDecimalPlaces);
  cout << assumedRoot << endl;

  return 0;
}