#include <iostream>
#include <numeric>
#include <vector>


void printVector(const std::vector<int> &numbers)
{
    //std::cout << "Vector has " << numbers.size() << " number(s) in it:" << '\n';
    for (auto const& num: numbers)
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}


// Complete the candies function below.
long candies(int n, std::vector<int> arr)
{
    std::vector<int> distribution(arr.size(), 1);

    for (size_t i = 1; i < arr.size(); i++)
    {
        const int prevChildDist = distribution[i-1];
        if (arr[i] > arr[i-1])
        {
            distribution[i] = (prevChildDist + 1);
        }
        else if (arr[i] < arr[i-1])
        {
            // if (prevChildDist > 1)
            // {
            //     distribution[i] = (prevChildDist - 1);
            // }
            // else
            // {
                distribution[i] = 1;
            //}
        }
    }

    printVector(distribution);

    return std::accumulate(distribution.begin(), distribution.end(), 0);
}


int main(void)
{
    std::vector<int> studentRatings1 = {1, 2, 2};
    std::cout << "Student ratings are: " << '\n';
    printVector(studentRatings1);
    std::cout << "Min. # of candies needed: " << candies(studentRatings1.size(), studentRatings1);
    std::cout << '\n';

    std::vector<int> studentRatings2 = {4, 6, 4, 5, 6, 2};
    std::cout << "Student ratings are: " << '\n';
    printVector(studentRatings2);
    std::cout << "Min. # of candies needed: " << candies(studentRatings2.size(), studentRatings2);
    std::cout << '\n';

    std::vector<int> studentRatings3 = {2, 4, 2, 6, 1, 7, 8, 9, 2, 1};
    std::cout << "Student ratings are: " << '\n';
    printVector(studentRatings3);
    std::cout << "Min. # of candies needed: " << candies(studentRatings3.size(), studentRatings3);
    std::cout << '\n';

    std::vector<int> studentRatings4 = {2, 4, 3, 5, 2, 6, 4, 5};
    std::cout << "Student ratings are: " << '\n';
    printVector(studentRatings4);
    std::cout << "Min. # of candies needed: " << candies(studentRatings4.size(), studentRatings4);
    std::cout << '\n';

    std::vector<int> studentRatings5 = {9, 2, 3, 6, 5, 4, 3, 2, 2, 2};
    std::cout << "Student ratings are: " << '\n';
    printVector(studentRatings5);
    std::cout << "Min. # of candies needed: " << candies(studentRatings5.size(), studentRatings5);
    std::cout << '\n';

    return 0;
}
