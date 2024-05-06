// linear search using recursion
#include <iostream>
#define ARRAY_SIZE 5

int linear_search(int array[], int last_pos, int search)
{
    if (last_pos < 0)
    {
        return -1;
    }


    if (array[last_pos] == search)
    {
        return last_pos;
    }

    return linear_search(array, last_pos - 1, search);
}

int main()
{
    int array[ARRAY_SIZE] = {42,69,420, 6969, 42069};

    std::cout << "\nThe input array:" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << array[i] << " ";
    }

    int search;
    std::cout << "\n\nEnter the element to be searched: ";
    std::cin >> search;

    int result_pos = linear_search(array, ARRAY_SIZE - 1, search);
    if (result_pos != -1)
    {
        std::cout << std::endl << search << " found at position " << result_pos << std::endl;
        return 0;
    }

    std::cout << search << " not found in the given array" << std::endl; 

    return 0;
}
