#include <iostream>
#include <vector>

using namespace std;




void printVector(const std::vector<std::vector<int>> data)
{
	for (auto const& item: data)
	{
		cout << "Item has " << item.size() << " element(s) in it:" << '\n';
		for (auto const& num: item)
		{
			cout << '\t' << num << '\n';
		}
	}
}


std::vector<int> flatten(const std::vector<std::vector<int>> data)
{
	std::vector<int> flattened;

	for (auto const& item: data)
	{
		for (auto const& num: item)
		{
			flattened.push_back(num);
		}
	}

	return flattened;
}



int main(void)
{
	cout << "Hello, World!" << '\n';

	std::vector<std::vector<int>> unflattened = 
	{
		{0},
		{1, 2},
		{3, 4, 5},
		{6},
		{7},
		{8, 9, 10}
	};

	printVector(unflattened);

	std::vector<int> flattenedVec = flatten(unflattened);
	cout << "Flattened Vector is:" << '\n';
	for (auto const& num: flattenedVec)
	{
		cout << num << '\n';
	}

	return 0;
}
