#include <iostream>

int main()
{
	int mas1[5];
	int mas2[5];
	std::cout << "write array: " << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cin >> mas1[i];
	}

	int j = 0;
	for (int i = 4; i != -1; i--)
	{
		mas2[j] = mas1[i];
		j = j + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		std::cout << mas2[i] << " ";
	}
}