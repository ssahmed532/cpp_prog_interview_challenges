#include <iostream>
#include <vector>



void printVector(const std::vector<int> &numbers)
{
    std::cout << "Vector has " << numbers.size() << " number(s) in it:" << '\n';
    for (auto const& num: numbers)
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}


std::vector<int> calculatePrefixSum(const std::vector<int> &input)
{
    std::vector<int> prefixSumArray(input.size(), 0);

    prefixSumArray[0] = input[0];
    for (uint32_t i = 1; i < input.size(); i++)
    {
        prefixSumArray[i] = prefixSumArray[i - 1] + input[i];
    }

    return prefixSumArray;
}


int main(void)
{
    const std::vector<int> array1 = {1, 3, 4, 5, 2, 7, 8, 11};
    printVector(calculatePrefixSum(array1));

    const std::vector<int> array2 = {10, 20, 10, 5, 15};
    printVector(calculatePrefixSum(array2));

    return 0;
}
