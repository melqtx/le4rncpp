/*
following the norm of being a cs major, and making a calculator that barely works.
ahhaaha, give me my job now.
sir, msft is calling you


*/

Here is the code without comments:

```cpp
#include <cctype>
#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

char getOperator() {
  char op;
  cout << "Enter the operator (+, -, *, /, ^, sqrt, sin, cos, tan): ";
  cin >> op;
  while (!(op == '+' || op == '-' || op == '*' || op == '/' || op == '^' ||
           op == 's' || op == 'c' || op == 't' || op == 'r')) {
    cout << "Invalid operator. Please enter a valid operator (+, -, *, /, ^, "
            "sqrt, sin, cos, tan): ";
    cin >> op;
  }
  return op;
}

double getNumber() {
  double num;
  cout << "Enter the number: ";
  cin >> num;
  return num;
}

double performBasicOperation(double num1, double num2, char op) {
  switch (op) {
  case '+':
    return num1 + num2;
  case '-':
    return num1 - num2;
  case '*':
    return num1 * num2;
  case '/':
    if (num2 != 0)
      return num1 / num2;
    else
      throw runtime_error("Error: Division by zero");
  default:
    throw runtime_error("Error: Invalid operator");
  }
}

double performPowerOperation(double num1, double num2) {
  return pow(num1, num2);
}

double performTrigonometricOperation(double num, char op) {
  switch (op) {
  case 's':
    return sin(num);
  case 'c':
    return cos(num);
  case 't':
    return tan(num);
  default:
    throw runtime_error("Error: Invalid operator");
  }
}

double performSquareRootOperation(double num) {
  if (num >= 0)
    return sqrt(num);
  else
    throw runtime_error("Error: Negative number");
}

double performOperation(double num1, double num2, char op) {
  switch (op) {
  case '+':
  case '-':
  case '*':
  case '/':
  case '^':
    return performBasicOperation(num1, num2, op);
  case 's':
  case 'c':
  case 't':
    return performTrigonometricOperation(num1, op);
  case 'r':
    return performSquareRootOperation(num1);
  default:
    throw runtime_error("Error: Invalid operator");
  }
}

int main() {
  double num1, num2;
  char op;

  try {
    num1 = getNumber();
    op = getOperator();
    if (op == 's' || op == 'c' || op == 't') {
      num2 = getNumber();
      cout << "Result: " << performOperation(num1, num2, op) << "\n";
    } else {
      cout << "Result: " << performOperation(num1, 0, op) << "\n";
    }
  } catch (exception &e) {
    cout << "Error: " << e.what() << "\n";
  }

  return 0;
}
```
