#include <iostream>
using namespace std;
class LCM {
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
// Function to calculate the LCM of two numbers using rec
int calculateLCM(int a, int b) {
// Calculate the GCD of the two numbers
int gcd = calculateGCD(a, b);
// Calculate the LCM using the formula: LCM = (a * b)
return (a * b) / gcd;
}
};
int main() {
LCM l;
int num1, num2;
cout << "Enter two numbers to find the LCM: ";
cin >> num1 >> num2;
int result = l.calculateLCM(num1, num2);
cout << "The LCM of " << num1 << " and " << num2 << " is:"<<result;
return 0;
}
