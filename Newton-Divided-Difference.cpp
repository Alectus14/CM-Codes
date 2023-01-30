#include <iostream>
using namespace std;
int main() {
  int n;
  cout << "Enter the number of terms: ";
  cin >> n;
  double x[n], y[n], fx;
  for (int i = 0; i < n; i++) {
    cout << "x" << i << ", y" << i << " = ";
    cin >> x[i] >> y[i];
  }
  cout << "Enter the value of x for which y is required: ";
  cin >> fx;
  double fy = y[0], m = 1;
  int mi = n - 1;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < mi; j++) {
      y[j] = (y[j + 1] - y[j]) / (x[j + i + 1] - x[j]);
    }
    mi--;
    m *= fx - x[i];
    fy += m * y[0];
  }
  cout << "f(" << fx << ") = " << fy;
  return 0;
}