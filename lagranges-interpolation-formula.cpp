#include <iostream>
using namespace std;
double expression(int term, double arrX[], double arrY[], int x) {
  double num = 1;
  double den = 1;
  for (int i = 0; i < 4; i++) {
    if (i != term) {
      num = num * (x - arrX[i]);
    }
    if (i != term) {
      den = den * (arrX[term] - arrX[i]);
    }
  }
  return (num / den) * arrY[term];
}

int main() {
  int n, a;
  double ans = 0;
  cout << "Enter number of terms : \n";
  cin >> n;
  double x[n], y[n];
  for (int i = 0; i < n; i++) {
    cout << "enter x[" << i << "]\n";
    cin >> x[i];
    cout << "enter y[" << i << "]\n";
    cin >> y[i];
  }

  cout << "Enter the value of x : \n";
  cin >> a;
  for (int s = 0; s < n; s++) {
    ans = ans + (expression(s, x, y, a));
  }
  cout << ans;
}