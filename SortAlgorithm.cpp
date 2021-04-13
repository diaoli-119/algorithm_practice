#include <iostream>
#include <ctime>

template<typename T>
T* generateRandomArr(int n, int l, int r)
{
	T* arr = new T[n];
	srand(time_t(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (r - l + 1) + l;
	}
	return arr;
}

template<typename T>
void selectionSort(T* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}
		std::swap(arr[i], arr[minIndex]);
	}
}

template<typename T>
void insertionSort(T* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j > 0 && arr[j] < arr[j - 1]; j--)
		{
			std::swap(arr[j], arr[j - 1]);
		}
	}
}


void __merge(int* arr, int l, int mid, int r)
{
	int *temp = new int[r - l + 1];
	for (int i = l; i <= r; i++)
	{
		temp[i - l] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++)
	{
		if (i > mid)
		{
			arr[k] = temp[j - l];
			j++;
		}
		else if (j > r)
		{
			arr[k] = temp[i - l];
			i++;
		}
		else if (temp[i - l] < temp[j - l])
		{
			arr[k] = temp[i - l];
			i++;
		}
		else
		{
			arr[k] = temp[j - l];
			j++;
		}
	}
	delete[] temp;
	temp = NULL;
}

void __mergeSort(int* arr, int left, int right)
{
	if(left >= right) return;
	int mid = (left + right) / 2;
	__mergeSort(arr, left, mid);
	__mergeSort(arr, mid + 1, right);
	__merge(arr, left, mid, right);
}

void mergeSort(int* arr, int n)
{
	__mergeSort(arr, 0, n - 1);
}

int __partition(int* arr, int l, int r)
{
	int v = arr[l];
	int j = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (arr[i] < v)
		{
			std::swap(arr[i], arr[++j]);
		}
	}
	std::swap(arr[l], arr[j]);
	return j;
}

void __quickSort(int* arr, int l, int r)
{
	if (l >= r) return;
	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

void quickSort(int* arr, int n)
{
	__quickSort(arr, 0, n - 1);
}
