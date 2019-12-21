#include <iostream>
#include <string>

using namespace std;

//
// Problem statement:
//
// You are distributing N candies to K children. You give 1 candy to the
// first child, 2 candies to the second child, 3 candies to the third child
// and so on till K children have received the candies. You then start from
// the first child again and give him/her K+1 candies, K+2 candies to the
// second child and so on till all the candies are distributed.
//
// example1: N=7, K=4
// output:   {1, 2, 3, 1}
//
// example2: N=10, K=3
// output:   {5, 2, 3}
//


struct Result
{
    int size;
    int* candiesDist;

    Result()
    {
        size = (-1);
        candiesDist = nullptr;
    }

    Result(int K)
    {
        candiesDist = new int[K];
        size = K;
    }

    ~Result()
    {
        if (candiesDist != nullptr)
            delete [] candiesDist;
    }
};


Result distributeCandies(int N, int K)
{
    cout << "distributeCandies(): N=" << N << ", K=" << K << '\n';

    Result result(K);

    int candiesLeft = N;

    int i = 0;
    int baseAmount = 1;
    while ((candiesLeft > 0) && (i < K))
    {
        int dist = std::min((i + baseAmount), candiesLeft);
        result.candiesDist[i] = dist;
        cout << "Child " << (i+1) << " gets: " << dist << '\n';
        candiesLeft -= dist;
        ++i;
    }
    cout << "Candies left: " << candiesLeft << '\n';

    i = 0;
    baseAmount = K;
    while ((candiesLeft > 0) && (i < K))
    {
        int dist = std::min((i + baseAmount + 1), candiesLeft);
        result.candiesDist[i] += dist;
        candiesLeft -= dist;
        ++i;
    }

    return result;
}


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cerr << "Usage: ./a.out <N = number of candies> <K = number of children>" << '\n';
        return 1;
    }

    int N = (-1);
    int K = (-1);

    N = stoi(argv[1]);
    K = stoi(argv[2]);

    cout << "N = " << N << '\n';
    cout << "K = " << K << '\n';

    Result result = distributeCandies(N, K);
    for (int i = 0; i < result.size; i++)
    {
        cout << "Child #" << (i+1) << " gets " << result.candiesDist[i] << " candies" << '\n';
    }

    return 0;
}
