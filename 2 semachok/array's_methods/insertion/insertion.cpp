#include <iostream>

void swap(int& a, int& b)
{
	int helper = a;
	a = b;
	b = helper;
}


int main()
{
	int array[10];

	for (int i = 0; i < 10; i++)
	{
		std::cin >> array[i];
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
		{
			swap(array[j - 1], array[j]);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << array[i] << " ";
	}
	return 0;
}