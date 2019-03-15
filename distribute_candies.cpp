#include <iostream>
#include <set>
#include <vector>

//
// Example 1:
//		Input: candies = [1,1,2,2,3,3]
//		Output: 3
//
// Example 2:
//		Input: candies = [1,1,2,3]
//		Output: 2
//
// Example 3:
//		Input candies = [1,2,3,4,5,6]
//		Output: 3
//


// My solution to the "575. Distribute Candies" challenge on LeetCode:
//      https://leetcode.com/problems/distribute-candies/
//
class Solution {
public:
    static int distributeCandies(const std::vector<int>& candies)
    {
    	std::set<int> uniqueCandies(candies.begin(), candies.end());

    	return std::min(uniqueCandies.size(), (candies.size() / 2));
    }
};


int main(void)
{
	const std::vector<int> input1 = {1,1,2,2,3,3};
	std::cout << "For Input 1, max. # of types of candies for sister: " << Solution::distributeCandies(input1) << '\n';

	const std::vector<int> input2 = {1,1,2,3};
	std::cout << "For Input 2, max. # of types of candies for sister: " << Solution::distributeCandies(input2) << '\n';

	const std::vector<int> input3 = {1,2,3,4,5,6};
	std::cout << "For Input 3, max. # of types of candies for sister: " << Solution::distributeCandies(input3) << '\n';

	const std::vector<int> input4 = {1,1,1,1,1,1,1,1};
	std::cout << "For Input 4, max. # of types of candies for sister: " << Solution::distributeCandies(input4) << '\n';

	const std::vector<int> input5 = {1,1,1,2,1,1,1,1};
	std::cout << "For Input 5, max. # of types of candies for sister: " << Solution::distributeCandies(input5) << '\n';

	return 0;
}
