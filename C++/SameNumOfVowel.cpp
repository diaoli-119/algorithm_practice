#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::strstr;

bool halvesAreAlike(string s) {

	int len = s.length();

	int lVowNum = 0, rVowNum = 0;

	for (int i = 0; i < len; i++)
	{
		if (s[i] <= 90) s[i] = s[i] + 32;
	}

	for (int l = 0, r = len - 1; l < r; l++, r--)
	{
		if (s[l] == 'i') lVowNum++;
		else if (s[l] < 'i')
		{
			if (s[l] == 'a') lVowNum++;
			else if (s[l] == 'e') lVowNum++;
		}
		else
		{
			if (s[l] == 'o') lVowNum++;
			else if (s[l] == 'u') lVowNum++;
		}

		if (s[r] == 'i') rVowNum++;
		else if (s[r] < 'i')
		{
			if (s[r] == 'a') rVowNum++;
			else if (s[r] == 'e') rVowNum++;
		}
		else
		{
			if (s[r] == 'o') rVowNum++;
			else if (s[r] == 'u') rVowNum++;
		}
	}

	if (lVowNum != rVowNum) return false;

	return true;
}