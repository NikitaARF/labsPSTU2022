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

	for (int i = 0; i < 10 - 1; i++)
	{
		int minimum = i;
		for (int j = i; j < 10; j++)
		{
			if (array[j] < array[minimum])
			{
				minimum = j;
			}
		}
		swap(array[i], array[minimum])
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << array[i] << " ";
	}
	return 0;
}