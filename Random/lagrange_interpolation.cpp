#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter number of terms: ";
  cin >> n;
  double x[n], y[n], value, result = 0;
  for (int i = 0; i < n; i++) {
    cout << "Enter x" << i << ": ";
    cin >> x[i];
    cout << "Enter y" << i << ": ";
    cin >> y[i];
  }
  cout << "Enter value of x: ";
  cin >> value;
  for (int i = 0; i < n; i++) {
    double num = y[i];
    double den = 1;
    for (int j = 0; j < n; j++)
      if (i != j) {
        num *= (value - x[j]);
        den *= (x[i] - x[j]);
      }
    result += num / den;
  }
  cout << "Value of y at x = " << value << " is " << result;
  return 0;
}
