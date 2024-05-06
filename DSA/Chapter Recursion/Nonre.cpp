#include <iostream>
using namespace std;
class Factorial {
public:
// Function to calculate the factorial of a number withou
int calculateFactorial(int n) {
int factorial = 1;
for (int i = 1; i <= n; i++) {
factorial *= i;
}
return factorial;
}
};
int main() {
Factorial f;
int number;
cout << "Enter a number to calculate the factorial: ";
cin >> number;
int result = f.calculateFactorial(number);
cout << "The factorial of " << number << " is: " << result;
return 0;
}
