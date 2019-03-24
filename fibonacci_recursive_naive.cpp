#include <cstdlib>
#include <chrono>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>


/**
 * @brief      Recursive Fibonacci implementation
 *
 * @param[in]  seqNum  The sequence number
 *
 * @return     The Nth number in the Fibonacci sequence
 */
int fibonacci(int seqNum)
{
    if (seqNum == 0)
        return 0;
    else if (seqNum == 1)
        return 1;
    else
        return fibonacci(seqNum - 1) + fibonacci(seqNum - 2);
}


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./a.out <Nth number to get from Fibonacci sequence" << '\n';
        std::exit(1);
    }

    const std::string temp(argv[1]);
    try
    {
        const int N = std::stoi(temp);

        auto timeStart = std::chrono::high_resolution_clock::now();
        const int FibN = fibonacci(N);
        auto timeEnd = std::chrono::high_resolution_clock::now();

        std::cout << N << "th Fibonacci number in sequence is: " << FibN << '\n';
        std::cout << "Elapsed time is: " << std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count() << " milliseconds" << '\n';
    }
    //catch (const std::exception& ex)
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

    return 0;
}
