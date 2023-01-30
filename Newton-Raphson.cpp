#include <iostream>
#include <math.h>
using namespace std;
double f(double x) { return 30 * x * x * x * x * x - 1; }
double df(double x) { return 150 * x * x * x * x; }
int main() {
  double me;
  cout << "Max Error: ";
  cin >> me;
  double x = 10, cache = 10;
  int max_iter, count = 0;
  cout << "Max Iterations: ";
  cin >> max_iter;
  cout << "x0 = 10\n";
  while (true) {
    x = x - (f(x) / df(x));
    cout << "x" << count + 1 << " = " << x << endl;
    if (abs(x - cache) < me || count == max_iter)
      break;
    cache = x;
    count++;
  }
  cout << "Final root of the equation is x = " << x;
  return 0;
}