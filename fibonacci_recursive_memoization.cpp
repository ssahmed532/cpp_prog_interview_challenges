#include <cstdlib>
#include <chrono>
#include <exception>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>


/**
 * @brief      Recursive Fibonacci implementation
 *
 * @param[in]  seqNum  The sequence number
 *
 * @return     The Nth number in the Fibonacci sequence
 */
int fibonacci(int seqNum, std::map<int, int> &memo)
{
    if (seqNum == 0)
    {
        return 0;
    }
    else if (seqNum == 1)
    {
        return 1;
    }
    else if (memo.find(seqNum) == memo.end())
    {        
        std::cout << "Computing recursive solution for Fibonacci sequence # " << seqNum << '\n';
        memo[seqNum] = fibonacci(seqNum - 1, memo) + fibonacci(seqNum - 2, memo);
    }
    else if (memo.find(seqNum) != memo.end())
    {
        std::cout << "Found memoized solution for Fibonacci sequence # " << seqNum << '\n';
    }

    return memo[seqNum];
}


//
// Compile cmd:
//      g++ -Wall -std=c++17 fibonacci_recursive_memoization.cpp -o fibonacci_recursive_memo
//
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./a.out <Nth number to get from Fibonacci sequence" << '\n';
        std::exit(1);
    }

    std::map<int, int> fiboMemo;

    const std::string temp(argv[1]);
    try
    {
        const int N = std::stoi(temp);

        auto timeStart = std::chrono::high_resolution_clock::now();
        const int FibN = fibonacci(N, fiboMemo);;
        auto timeEnd = std::chrono::high_resolution_clock::now();

        std::cout << N << "th Fibonacci number in sequence is: " << FibN << '\n';
        std::cout << "Elapsed time is: " << std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count() << " milliseconds" << '\n';
    }
    catch (const std::invalid_argument& ex)
    {
        std::cerr << "ERROR: invalid argument: " << temp << '\n';
        std::exit(2);
    }
    catch (const std::out_of_range& ex)
    {
        std::cerr << "ERROR: argument: " << temp << " is out of range" << '\n';
        std::exit(2);
    }
    catch (const std::exception& ex)
    {
        std::cerr << "ERROR: caught exception: " << ex.what() << '\n';
        std::exit(2);            
    }

    return 0;
}
