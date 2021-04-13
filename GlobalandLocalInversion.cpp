#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::vector;
using std::cout;
using std::cin;

bool isIdealPermutation(vector<int>& nums) 
{
	int size = nums.size();
	if (size == 2) return true;

	int local = 0, global = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (nums[i] < nums[i + 1]) local++;
		for (int j = i + 1; j < size; j++)
		{
			if (nums[i] > nums[j]) global++;
		}
	}
	return (local == global);
}

void callGlobalandLocalInversion()
{
	int n;
	cout << "input length of the array:";
	cin >> n;
	vector<int> intVec = { 0,1,2 };
	srand(time_t(NULL));
	for (int i = 0; i < n; i++)
	{
		intVec[i] = rand() % n;
	}
	cout << isIdealPermutation(intVec);
}