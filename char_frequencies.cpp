#include <iostream>
#include <map>


/**
 * @brief      Gets the character frequencies.
 *
 * @param[in]  input  The input
 *
 * @return     The character frequencies.
 */
std::map<char, int> getCharFrequencies(const std::string& input)
{
    std::map<char, int> charFreq;

    for (const auto &ch: input)
    {
        ++charFreq[ch];
    }

    return charFreq;
}


/**
 * @brief      Gets the most frequent characters in the given input string.
 *
 * @param[in]  input  The input
 *
 * @return     The character frequencies 2.
 */
std::multimap<int, char, std::greater<int>> getCharFrequencies2(const std::string& input)
{
    // map of char->count
    std::map<char, int> charFreq = getCharFrequencies(input);

    // second map to store reverse info:
    //      frequency -> char
    std::multimap<int, char, std::greater<int>> freqMap;

    for (const auto &entry: charFreq)
        freqMap.insert(std::make_pair(entry.second, entry.first));

    return freqMap;
}


void printCharFrequencies(const std::map<char, int> charFreq)
{
    for (const auto &entry: charFreq)
    {
        std::cout << "Char " << entry.first << " -> " << entry.second << '\n';
    }
}


//
// ABCA             -> A
// BCABA            -> B
// ABCD             -> NONE
// SALMAN           -> A
// SYEDSALMAN.AHMED -> S
//
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./a.out <some char string>" << '\n';
        std::exit(1);
    }

    // get the frequencies of all characters in the input string
    auto charFreq = getCharFrequencies(argv[1]);
    printCharFrequencies(charFreq);

    // list the most frequently occuring chars in the input string
    auto revFreq = getCharFrequencies2(argv[1]);
    for (const auto &entry: revFreq)
        std::cout << "Frequency: " << entry.first << ", char: " << entry.second << '\n';

    return 0;
}
