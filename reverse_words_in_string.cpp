#include <iostream>
#include <sstream>
#include <stack>

using namespace std;


const std::string DELIMITER = " ";

std::string reverseWords(const std::string &input)
{
    size_t pos = 0;
    std::string token;

    std::stack<string> wordsStack;

    // String tokenization code is borrowed from:
    //      https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
    //

    auto start = 0U;
    auto end = input.find(DELIMITER, start);

    // TODO
    //      1) Use String Tokenizer from Boost library
    //
    while (end != std::string::npos)
    {
        token = input.substr(start, end - start);
        if (token.length() > 0)
        {
            wordsStack.push(token);
        }

        start = end + DELIMITER.length();

        end = input.find(DELIMITER, start);
    }
    token = input.substr(start, end-start);
    if (token.length() > 0)
    {
        wordsStack.push(token);
    }

    // now construct the reversed string
    stringstream ss;
    while (!wordsStack.empty())
    {
        string word = wordsStack.top();
        ss << word;

        wordsStack.pop();

        if (!wordsStack.empty())
        {
            ss << DELIMITER;
        }
    }

    return ss.str();
}


int main(void)
{
    const std::string input1 = "GeeksforGeeks: A Computer Science Portal for Geeks.   ";
    std::cout << "Reversed string is:" << '\n';
    std::cout << reverseWords(input1);
    std::cout << '\n';

    const std::string input2 = "God help us all";
    std::cout << "Reversed string is:" << '\n';
    std::cout << reverseWords(input2);
    std::cout << '\n';

    const std::string input3 = "Common Sense is remarkably uncommon these days";
    std::cout << "Reversed string is:" << '\n';
    std::cout << reverseWords(input3);
    std::cout << '\n';

    return 0;
}
