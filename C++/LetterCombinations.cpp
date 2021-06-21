#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::strstr;

const vector<string> collection = {
	"", "", "abc", "def", "ghi", "jkl",
	"mno", "pqrs", "tuv", "wxyz"
};

vector<string> letterCombinations(string digits) 
{
	if (!digits.size()) return {};
	vector<string> result;
	result.push_back("");

	for (auto elem : digits)
	{
		vector<string> tempStrVec;
			for (auto rElem : result)
				for (auto singal : collection[elem - 48])
					tempStrVec.push_back(rElem + singal);
		result.swap(tempStrVec);
	}
	return result;
}

void callLetterCombinations()
{
	int num;
	cout << "input a number:";
	cin >> num;
	vector<string> ret = letterCombinations(std::to_string(num));
}