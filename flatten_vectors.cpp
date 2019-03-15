#include <iostream>
#include <vector>


void printVector(const std::vector<std::vector<int>> &data)
{
    std::cout << "Unflattened vector has " << data.size() << " element(s) in it" << '\n';
    for (auto const& item: data)
    {
        std::cout << "Item has " << item.size() << " element(s) in it:" << '\n';
        for (auto const& num: item)
        {
            std::cout << '\t' << num << '\n';
        }
    }
}


void printVector(const std::vector<int> &data)
{
    std::cout << "Vector has " << data.size() << " element(s) in it:" << '\n';
    for (auto const& num: data)
    {
        std::cout << '\t' << num << '\n';
    }
}


std::vector<int> flatten(const std::vector<std::vector<int>> &data)
{
    std::vector<int> flattened;

    for (auto const& item: data)
    {
        for (auto const& num: item)
        {
            flattened.push_back(num);
        }
    }

    return flattened;
}


int main(void)
{
    std::vector<std::vector<int>> unflattened = 
    {
        {0},
        {1, 2},
        {3, 4, 5},
        {6},
        {7},
        {8, 9, 10}
    };

    printVector(unflattened);

    std::vector<int> flattenedVec = flatten(unflattened);
    std::cout << "Flattened Vector is:" << '\n';
    printVector(flattenedVec);

    return 0;
}
