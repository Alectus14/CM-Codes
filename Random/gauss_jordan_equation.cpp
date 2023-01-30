#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter number of variables: ";
  cin >> n;
  double m[n][n + 1];
  for (int i = 0; i < n; i++) {
    cout << "Enter equation " << i + 1 << ": " << endl;
    for (int j = 0; j < n + 1; j++) {
      if (j == n)
        cout << "Solution: ";
      else
        cout << "Coefficient of variable " << j + 1 << ": ";
      cin >> m[i][j];
    }
  }
  for (int j = 0; j < n; j++) {
    double d;
    for (int i = 0; i < n; i++) {
      if (i != j) {
        d = m[i][j] / m[j][j];
        for (int k = 0; k < n + 1; k++)
          m[i][k] -= m[j][k] * d;
      }
    }
    d = m[j][j];
    for (int i = 0; i < n + 1; i++)
      m[j][i] /= d;
  }
  cout << endl;
  for (int i = 0; i < n; i++)
    cout << "variable " << i + 1 << ": " << m[i][n] << endl;
  return 0;
}
