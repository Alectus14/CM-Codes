#include <iostream>
#include <math.h>
using namespace std;

double f(double x) { return x * x * x - 5 * x; }

int main() {
  double me;
  int max_iter;
  cout << "Max Error: ";
  cin >> me;
  cout << "Max Iterations: ";
  cin >> max_iter;
  double a = 1.5, b = 2.5, root, cache;
  cout << "a = " << a << ", b = " << b << endl;
  int count = 1;
  while (true) {
    root = (a * f(b) - b * f(a)) / (f(b) - f(a));
    cout << "root" << count << " = " << root << endl;
    if ((count != 1 && abs(root - cache) < me) || f(root) == 0)
      break;
    count++;
    cache = root;
    a = b;
    b = root;
  }
  cout << "The final root of the equation is x = " << root;
  return 0;
}
