#include <iostream>
using namespace std;

double f(double x) { return 1 / (1 + x * x); }

bool isOdd(int x) {
  if (x % 2 == 1)
    return true;
  return false;
}

int main() {
  double upper, lower, stepSize, integration, k;
  int subIntervals;

  cout << "Enter lower limit: ";
  cin >> lower;
  cout << "Enter upper limit: ";
  cin >> upper;
  cout << "Enter number of sub-intervals: ";
  cin >> subIntervals;

  stepSize = (upper - lower) / subIntervals;

  integration = f(lower) + f(upper);

  for (int i = 1; i < subIntervals; i++) {
    if (isOdd(i)) {
      integration += 4 * f(lower + i * stepSize);
    } else {
      integration += 2 * f(lower + i * stepSize);
    }
  }

  cout << "The value is: " << integration * stepSize / 3;

  return 0;
}
