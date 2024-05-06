// implementation of binary search
#include <iostream>
#define ARRAY_SIZE 5

int binary_search(int left, int right, int search, int array[])
{
    int mid = (left + right) / 2;

    if (array[mid] == search)
    {
        return mid;
    }
    else if (array[mid] < search)
    {
        left = mid;
        return binary_search(left, right, search, array);
    }
    else
    {
        right = mid;
        return binary_search(left, right, search, array);
    }
}

int main()
{
    int array[ARRAY_SIZE] = {1, 2, 9, 12, 15};

    std::cout << "\nThe input array:" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << array[i] << " ";
    }

    int search;
    std::cout << "\n\nEnter the element to be searched: ";
    std::cin >> search;

    int result_pos = binary_search(0, ARRAY_SIZE, search, array);
    std::cout << std::endl << search << " found at position " << result_pos << std::endl;

    return 0;
}
