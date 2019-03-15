#include <iostream>
#include <vector>


std::vector<int> rotateLeft(const std::vector<int> a, int numRot)
{
    // make a copy of the input array/vector
    std::vector<int> result = a;

    for (int i = 0; i < numRot; i++)
    {
        int tmp = result[0];
        result.erase(result.begin());
        result.push_back(tmp);
    }

    return result;
}


void printVector(const std::vector<int> &numbers)
{
    std::cout << "Vector has " << numbers.size() << " number(s) in it:" << '\n';
    for (auto const& num: numbers)
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}


int main(void)
{
    std::vector<int> v1 = {1, 2, 3, 4, 5};

    std::cout << "Original vector is:" << '\n';
    printVector(v1);

    std::vector<int> rotated = rotateLeft(v1, 3);
    printVector(rotated);

    return 0;
}
