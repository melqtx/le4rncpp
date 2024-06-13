#include <iostream>
using namespace std;

double e(double x, double n) {
  static double p = 1, f = 1;

  double r;
  if (n == 0) {
    return 1;
  } else {
    r = e(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
  }
}

int main() {
  double x, n;
  cout << "enter base and power: ";
  cin >> x >> n;

  cout << e(x, n) << '\n';

  return 0;
}
