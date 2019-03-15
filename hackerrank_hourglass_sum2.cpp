#include <algorithm>
#include <iostream>
#include <vector>


void printHourglass2(const std::vector<std::vector<int>> &array, int rowIndex, int colIndex)
{
    std::cout << array[rowIndex-1][colIndex-1] << array[rowIndex-1][colIndex] << array[rowIndex-1][colIndex+1] << '\n';
    std::cout << " " << array[rowIndex][colIndex] << " " << '\n';
    std::cout << array[rowIndex+1][colIndex-1] << array[rowIndex+1][colIndex] << array[rowIndex+1][colIndex+1] << '\n';
    std::cout << '\n';
}


int util_hourglassSum(const std::vector<std::vector<int>> &array, int row, int col)
{
    int sum = 0;
    
    sum += (array[row-1][col-1] + array[row-1][col] + array[row-1][col+1]);
    sum += array[row][col];
    sum += (array[row+1][col-1] + array[row+1][col] + array[row+1][col+1]);

    return sum;
}


// Complete the hourglassSum function below.
int hourglassSum(const std::vector<std::vector<int>> &arr)
{
    // this vector stores the sums of all possible 'hourglasses' in the given
    // input array
    std::vector<int> hourglassSums;

    const int MaxNumRows = arr.size();
    const int MaxNumCols = MaxNumRows;

    for (int i = 0; i < MaxNumRows; i++)
    {
        for (int j = 0; j < MaxNumCols; j++)
        {
            if ((i > 0) && i < (MaxNumRows-1) &&
                (j > 0) && j < (MaxNumCols-1))
            {
                const int sum = util_hourglassSum(arr, i, j);

                hourglassSums.push_back(sum);
            }
        }
    }

    // get an iter to the max (valued) element in the hourglassSums vector
    auto result =
        std::max_element(hourglassSums.begin(), hourglassSums.end());

    return *result;
}


int main(void)
{
    const std::vector<std::vector<int>> ARR1 =
    {
        {1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    const std::vector<std::vector<int>> ARR2 =
    {
        {-9, -9, -9,  1, 1, 1},
        { 0, -9,  0,  4, 3, 2},
        {-9, -9, -9,  1, 2, 3},
        { 0,  0,  8,  6, 6, 0},
        { 0,  0,  0, -2, 0, 0},
        { 0,  0,  1,  2, 4, 0}
    };

    const std::vector<std::vector<int>> ARR3 =
    {
        {1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {0, 0, 2, 4, 4, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 1, 2, 4, 0}
    };

    const std::vector<std::vector<int>> ARR4 =
    {
        {1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {0, 9, 2, -4, -4, 0},
        {0, 0, 0, -2, 0, 0},
        {0, 0, -1, -2, -4, 0}
    };

    std::cout << "Max. hourglasses sum in ARR1 is: " << hourglassSum(ARR1) << '\n';
    std::cout << "Max. hourglasses sum in ARR2 is: " << hourglassSum(ARR2) << '\n';
    std::cout << "Max. hourglasses sum in ARR3 is: " << hourglassSum(ARR3) << '\n';
    std::cout << "Max. hourglasses sum in ARR4 is: " << hourglassSum(ARR4) << '\n';

    return 0;
}
