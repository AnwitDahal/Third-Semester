#include <iostream>
using namespace std;
class GCD {
public:
// Recursive function to calculate the GCD of two numbers
int calculateGCD(int a, int b) {
// Base case: if b is 0, return a
if (b == 0) {
return a;
}
// Recursive case: call the function with b and a % b
return calculateGCD(b, a % b);
}
};
int main() {
GCD g;
int num1, num2;
cout << "Enter two numbers to find the GCD: ";
cin >> num1 >> num2;
int result = g.calculateGCD(num1, num2);
cout << "The GCD of " << num1 << " and " << num2 << " is:"<<result;
return 0;
}
