#include <iostream>
#include <cstring>

int main() {
    // Dynamically allocate memory for an integer
    int* num = new int;
    *num = 42;
    std::cout << "Integer: " << *num << std::endl;

    // Dynamically allocate memory for a character
    char* ch = new char;
    *ch = 'A';
    std::cout << "Character: " << *ch << std::endl;

    // Dynamically allocate memory for a string
    char* str = new char[6];
    std::strcpy(str, "Hello");
    std::cout << "String: " << str << std::endl;

    // Free the dynamically allocated memory
    delete num;
    delete ch;
    delete[] str;

    return 0;
}
