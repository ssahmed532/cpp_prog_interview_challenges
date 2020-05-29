#include <iostream>
#include <vector>
#include <cassert>



int findIndexOfLargestElement(const std::vector<int> &numbers)
{
    int idx = (-1);

    if (numbers.size() > 0)
    {
        // assume that the first element in the list is the largest
        idx = 0;

        const auto NumElements = numbers.size();
        for (size_t i = 1; i < NumElements; i++)
        {
            if (numbers[i] > numbers[idx])
            {
                idx = i;
            }
        }
    }

    return idx;
}


int main()
{
    auto numbers1 = {1, 2, 3, 4, 5, 6, 7, 9, 10};
    auto numbers2 = {3, 1, 4, 2, 8, 5, 7};
    auto numbers3 = {9, 9, 9, 9, 9, 9};
    auto numbers4 = {100, 3, -40, 12, 100, 40, 89, 94, 31};

    int idxOfLargest = findIndexOfLargestElement(numbers1);
    assert(idxOfLargest == 8);
    std::cout << "Test case #1 passed" << '\n';

    idxOfLargest = findIndexOfLargestElement(numbers2);
    assert(idxOfLargest == 4);
    std::cout << "Test case #2 passed" << '\n';

    idxOfLargest = findIndexOfLargestElement(numbers3);
    assert(idxOfLargest == 0);
    std::cout << "Test case #3 passed" << '\n';

    idxOfLargest = findIndexOfLargestElement(numbers4);
    assert(idxOfLargest == 0);
    std::cout << "Test case #4 passed" << '\n';

    const std::vector<int> EmptyList = {};
    idxOfLargest = findIndexOfLargestElement(EmptyList);
    assert(idxOfLargest == (-1));
    std::cout << "Test case #5 passed" << '\n';

    return 0;
}
