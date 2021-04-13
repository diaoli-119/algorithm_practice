#include <iostream>
#include <string>
#include <stack>

using std::endl;
using std::cout;
using std::stack;
using std::max;
int LongestValidParentheses(std::string s) {
	int left = 0, right = 0, maxLen = 0;
	int len = s.length();

	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(') left++;
		else right--;
		if ((left + right) == 0) maxLen = max(maxLen, right * (-2));
		else if ((left + right) < 0) left = right = 0;
	}
	left = right = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (s[i] == ')') right++;
		else left--;
		if ((left + right) == 0) maxLen = max(maxLen, left * (-2));
		else if ((left + right) < 0) left = right = 0;
	}
	return maxLen;
}

void callLongestValidParentheses()
{
	std::cout << LongestValidParentheses("()))");
}