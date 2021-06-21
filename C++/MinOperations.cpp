#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int MinOperations(int n)
{
	int* arr = new int[n];
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		arr[i] = 2 * i + 1;
	}
	int oper = 0;
	for (int j = 0, k = n - 1; j < k; j++, k--)
	{
		oper +=  (k - j); // ((2*k+1) - (2*j+1))/2
	}
	return oper;
}

void callMinOperations()
{
	int n;
	cout << "input array size:";
	cin >> n;
	cout << MinOperations(n);
}