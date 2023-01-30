#include <iostream>
#include <math.h>

using namespace std;

double f(double x) { return sin(x); }
int main() {
  double u, l;
  int n;
  cout << "Lower Limit: ";
  cin >> l;
  cout << "Upper Limit: ";
  cin >> u;
  cout << "No. of terms: ";
  cin >> n;
  double h = (u - l) / n, x = l, ans = 0;
  for (int i = 0; i < n + 1; i++) {
    if (i == 0 || i == n)
      ans += f(x);
    else if (i % 2 == 0)
      ans += 2 * f(x);
    else
      ans += 4 * f(x);
    x += h;
  }
  ans *= h / 3;
  cout << "The value of definite integral is I = " << ans;
  return 0;
}