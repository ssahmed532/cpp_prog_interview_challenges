#include <iostream>
#include <string>
#include <utility>


// input: AABBBCCCCDEEFGGG
// input: aabcddbbbea
// input: ABCDE         >> None found
// input: AABCDEE       >> A , 2
// input: AAAAA         >> A , 5
// input: SALMAN        >> None found
// input: SAALMAAN      >> A , 2
// input: baaaa         >> a , 4
// input: bbaaaa        >> a , 4
// input: bbbaaaa       >> a , 4
// input: bbbbaaaa      >> b , 4
// input: bbbbbaaaa     >> b , 5
// input: saalmaaan     >> a , 3
// input: aabcde        >> a , 2
// input: abbb          >> b , 3
// input: aabcdeee      >> e , 3
// input: baaaacccc     >> a , 4
// input: baaaaccccc    >> c , 5
// input: aabcddbbbea   >> b , 3
// input: ABCDEE        >> E , 2
// input: AABCDEE       >> A , 2
// input: AAABCDEE      >> A , 3
// input: AAABBCDDEEEEE >> E , 5
// input: AAABBCCCDDDDDDDDDDEE  >> D , 10
// input: AABCDDBBBEA           >> B , 3

/**
 * @brief      Gets the longest repeating character. Improved version of
 *             function.
 *
 * @param[in]  input  The input string
 *
 * @return     The longest repeating character 2.
 */
std::pair<char, int> getLongestRepeatingChar2(const std::string &input)
{
    if (input.empty())
        return std::make_pair('\0', 0);

    char prevCh = input[0];
    int currMaxLen = 1;
    char currCh = '\0';

    std::pair<char, int> result = std::make_pair('\0', 0);

    for (int i = 1; i < input.size(); i++)
    {
        currCh = input[i];
        if (currCh == prevCh)
        {
            ++currMaxLen;
        }
        else
        {
            if ((currMaxLen >= 2) && (currMaxLen > result.second))
            {
                result.first = prevCh;
                result.second = currMaxLen;
            }

            prevCh = currCh;
            currMaxLen = 1;
        }
    }

    // this is needed when the longest repeating subsequence is at the end
    // of the input string e.g. ABCDEE, and its length is greater than an
    // earlier repeating subsequence
    if ((currMaxLen >= 2) && (currMaxLen > result.second))
    {
        result.first = prevCh;
        result.second = currMaxLen;
    }

    return result;
}

// initial version of solution
std::pair<char, int> getLongestRepeatingChar(const std::string &input)
{
    if (input.empty())
        return std::make_pair('\0', 0);

    char repeatingCh = input[0];
    int maxLength = 1;

    std::pair<char, int> longestSeq;
    longestSeq.first = '\0';
    longestSeq.second = 0;

    for (int i = 1; i < input.size(); i++)
    {
        char currCh = input[i];
        if (currCh == repeatingCh)
            ++maxLength;
        else
        {
            if (maxLength >= 2 && (maxLength > longestSeq.second))
            {
                longestSeq.first = repeatingCh;
                longestSeq.second = maxLength;
            }

            repeatingCh = currCh;
            maxLength = 1;
        }
    }

    if (maxLength >= 2 && (maxLength > longestSeq.second))
    {
        longestSeq.first = repeatingCh;
        longestSeq.second = maxLength;
    }

    return longestSeq;
}


//
// Input: geeeek
// Output: e,4
//
// Input: aaaabbcbbb
// Output: a,4
//
// Input: abcdef
// Output: '\0', 0
//
// Input: abbbccddbbbbbefg
// Output: b,5
//
int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./a.out <some char string>" << '\n';
		std::exit(1);
	}

    const std::string input = argv[1];

    //const std::pair<char, int> result = getLongestRepeatingChar(input);
    const std::pair<char, int> result = getLongestRepeatingChar2(input);
    if (result.second == 0)
    {
        //std::cout << "No consecutive, repeating chars found in input string" << '\n';
        std::cout << "None found" << '\n';
    }
    else
    {
        //std::cout << "Longest repeating char is " << result.first << " of length " << result.second << '\n';
        std::cout << result.first << " , " << result.second << '\n';
    }

	return 0;
}
