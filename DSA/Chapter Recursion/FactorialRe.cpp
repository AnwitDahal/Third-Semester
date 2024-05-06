#include <iostream>
using namespace std;
class Factorial {
public:
// Recursive function to calculate the factorial of a num
int calculateFactorial(int n) {
if (n == 0 || n == 1) {
return 1;
} else {
return n * calculateFactorial(n - 1);
}
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
