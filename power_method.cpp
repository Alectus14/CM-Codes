#include <cmath>
#include <iostream>
using namespace std;
double A[3][3], X[3] = {1, 0, 0}, Y[3] = {0, 0, 0}, err = 0.01, l;
int step = 0;

void power() {
  double T[3] = {0, 0, 0};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      T[i] += A[i][j] * X[j];
  l = 0;
  for (int i = 0; i < 3; i++)
    l = max(l, abs(T[i]));
  step++;
  cout << "Approximate eigen value at step " << step << ": " << l << endl;
  for (int i = 0; i < 3; i++) {
    Y[i] = X[i];
    X[i] = T[i] / l;
  }
}

int main() {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      cout << "Enter element at [" << i << "," << j << "]: ";
      cin >> A[i][j];
    }
  bool proceed = true;
  while (proceed) {
    power();
    for (int i = 0; i < 3; i++) {
      proceed = abs(X[i] - Y[i]) >= err;
      if (proceed)
        break;
    }
  }
  cout << "Final eigen value: " << l;
  return 0;
}