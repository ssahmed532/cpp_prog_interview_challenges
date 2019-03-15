#include <iostream>



void printHourglass(const int array[6][6], int rowIndex, int colIndex)
{
    std::cout << array[rowIndex-1][colIndex-1] << array[rowIndex-1][colIndex] << array[rowIndex-1][colIndex+1] << '\n';
    std::cout << " " << array[rowIndex][colIndex] << " " << '\n';
    std::cout << array[rowIndex+1][colIndex-1] << array[rowIndex+1][colIndex] << array[rowIndex+1][colIndex+1] << '\n';
    std::cout << '\n';
}

int main(void)
{
    const int SIZE = 6;
    int arr1[SIZE][SIZE] =
    {
        {1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    // for (const auto &row: arr1)
    // {
    //     for (const auto &elem: row)
    //     {
    //         std::cout << elem << " ";
    //     }
    //     std::cout << '\n';
    // }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            //std::cout << arr1[i][j] << " ";
            if ((i > 0) && i < (SIZE-1) &&
                (j > 0) && j < (SIZE-1))
            {
                std::cout << "Hourglass can be computed here!" << '\n';
                printHourglass(arr1, i, j);
            }
        }
        std::cout << '\n';
    }

    return 0;
}
