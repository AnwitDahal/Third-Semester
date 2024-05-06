#include <iostream>
using namespace std;
class Fibonacci {
public:
// Function to generate the Fibonacci series up to a give
void generateFibonacci(int n) {
int first = 0, second = 1, next;
cout << "Fibonacci Series: ";
// Print the first two terms
cout << first << " " << second << " ";
// Generate and print the Fibonacci series up to n te
for (int i = 2; i < n; i++) {
next = first + second;
cout << next << " ";
first = second;
second = next;
}
cout << endl;
}
};
int main() {
Fibonacci f;
int numTerms;
cout << "Enter the number of Fibonacci terms to generate:";
cin >> numTerms;
f.generateFibonacci(numTerms);
return 0;
}
