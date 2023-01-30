#include <iostream>
using namespace std;
int order;
double a[100][100], a_inv[100][100] = {0}, b[100];
void input() {
  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      cout << "a[" << i << "][" << j << "] = ";
      cin >> a[i][j];
    }
    cout << "b[" << i << "] = ";
    cin >> b[i];
  }
}
void print_inverse() {
  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      cout << a_inv[i][j] << "  ";
    }
    cout << endl;
  }
}
void solve() {
  for (int i = 0; i < order; i++) {
    double temp = a[i][i];
    for (int j = 0; j < order; j++) {
      a[i][j] /= temp;
      a_inv[i][j] /= temp;
    }
    b[i] /= temp;
    for (int j = 0; j < order; j++) {
      if (j == i)
        continue;
      double mul = a[j][i];
      for (int k = 0; k < order; k++) {
        a[j][k] -= mul * a[i][k];
        a_inv[j][k] -= mul * a_inv[i][k];
      }
      b[j] -= mul * b[i];
    }
  }
}
int main() {
  cout << "Enter the number of linear equations: ";
  cin >> order;
  input();
  for (int i = 0; i < order; i++)
    a_inv[i][i] = 1;
  solve();
  cout << "Inverse of the matrix is: \n";
  print_inverse();
  cout << "Solution of the linear equations is: \n";
  for (int i = 0; i < order; i++) {
    cout << "x" << i << " = " << b[i] << endl;
  }
}