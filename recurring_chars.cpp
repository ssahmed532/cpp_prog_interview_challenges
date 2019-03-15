#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <string>


bool util_isspace(char ch)
{
    return std::isspace(static_cast<unsigned char>(ch));
}


char findFirstRecurringChar(const std::string& input)
{
    char c = '\0';

    std::map<char, int> charsSeen;

    // convert input string into lowercase
    std::string data = input;
    //std::transform(data.begin(), data.end(), data.begin(), ::tolower);

    for (const auto &ch: data)
    {
        if (!util_isspace(ch))
        {
            if (charsSeen.find(ch) != charsSeen.end())
                return ch;
            else
                charsSeen[ch] = 1;
        }
    }

    return c;
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

    char ch = findFirstRecurringChar(argv[1]);
    if ('\0' == ch)
        std::cout << "No recurring character found in input string" << '\n';
    else
        std::cout << "First recurring char in input string is: " << ch << '\n';

    return 0;
}
