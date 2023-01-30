#include <iostream>
using namespace std;
float df(double x, double y) { return x + y * y; }
int main() {
  double x0 = 0, y0 = 1, x, h;
  cout << "x: ";
  cin >> x;
  cout << "h: ";
  cin >> h;
  int n = (x - x0) / h;
  for (int i = 1; i <= n; i++) {
    double k = 0, cache = 0;
    for (int j = 1; j <= 4; j++) {
      if (j == 1)
        cache = df(x0, y0);
      else if (j == 4)
        cache = df((x0 + h), (y0 + cache));
      else
        cache = df((x0 + (h / 2)), (y0 + (cache / 2)));
      cache *= h;
      if (j == 1 || j == 4)
        k += 2 * cache;
      else
        k += cache;
    }
    x0 += h;
    y0 += k / 6;
    cout << "Value of y at x = " << x0 << " is " << y0 << endl;
  }
}

/*
#include <iostream>
#include <math.h>
using namespace std;

double function(double x, double y) { return (pow(x, 2) + pow(y, 2)); }

double rungaKuttaMethod(double x0, double y0, double h) {
  double k1 = h * function(x0, y0);
  double k2 = h * function(x0 + (0.5 * h), y0 + (0.5 * k1));
  double k3 = h * function(x0 + (0.5 * h), y0 + (0.5 * k2));
  double k4 = h * function(x0 + h, y0 + k3);

  cout << "K1: " << k1 << endl;
  cout << "K2: " << k2 << endl;
  cout << "K3: " << k3 << endl;
  cout << "K4: " << k4 << endl;
  double y1 = y0 + (0.166667) * (k1 + 2 * k2 + 2 * k3 + k4);
  return y1;
}

int main() {
  double x0, y0, h;
  cout << "Enter the inital value of x: ";
  cin >> x0;
  cout << "Enter the inital value of y: ";
  cin >> y0;
  cout << "Enter the value of h: ";
  cin >> h;

  double Y = rungaKuttaMethod(x0, y0, h);
  cout << "The estimated value of Y is: " << Y << endl;

  return 0;
}

/*
#include <cmath>
#include <iostream>
using namespace std;

double function(double x, double y) { return (pow(x, 2) + pow(y, 2)); }

double first_order_runge_kutta_method(double x0, double y0, double h) {
  double y1 = y0 + h * function(x0, y0);
  return y1;
}

double second_order_runge_kutta_method(double x0, double y0, double h) {
  double k1 = h * function(x0, y0);
  double k2 = h * function(x0 + h, y0 + k1);

  double y1 = y0 + 0.5 * (k1 + k2);
  return y1;
}

double third_order_runge_kutta_method(double x0, double y0, double h) {
  double k1 = h * function(x0, y0);
  double k2 = h * function(x0 + (0.5 * h), y0 + (0.5 * k1));
  double k3 = h * function(x0 + h, y0 + (h * function(x0 + h, y0 + k1)));

  double y1 = y0 + 0.5 * (k1 + k2);
  return y1;
}

double fourth_order_runge_kutta_method(double x0, double y0, double h) {
  double k1 = h * function(x0, y0);
  double k2 = h * function(x0 + (0.5 * h), y0 + (0.5 * k1));
  double k3 = h * function(x0 + (0.5 * h), y0 + (0.5 * k2));
  double k4 = h * function(x0 + h, y0 + k3);

  double y1 = y0 + (0.166667) * (k1 + 2 * k2 + 2 * k3 + k4);
  return y1;
}

int main() {
  double x0, y0, h;
  cout << "Enter the inital value of x: ";
  cin >> x0;
  cout << "Enter the inital value of y: ";
  cin >> y0;
  cout << "Enter the value of h: ";
  cin >> h;

  double firstOrderY = first_order_runge_kutta_method(x0, y0, h);
  cout << firstOrderY << endl;
  double secondOrderY = second_order_runge_kutta_method(x0, y0, h);
  cout << secondOrderY << endl;
  double thirdOrderY = third_order_runge_kutta_method(x0, y0, h);
  cout << thirdOrderY << endl;
  double fourthOrderY = fourth_order_runge_kutta_method(x0, y0, h);
  cout << fourthOrderY << endl;

  return 0;
}
*/
