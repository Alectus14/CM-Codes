#include <iostream>
using namespace std;
double f(double x) { return 1 / (1 + x); }
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
    else
      ans += 2 * f(x);
    x += h;
  }
  ans *= h / 2;
  cout << "The value of definite integral is I = " << ans;
  return 0;
}