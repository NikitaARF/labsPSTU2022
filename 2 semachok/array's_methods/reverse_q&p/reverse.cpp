#include <iostream>

int main()
{
	int mas[10];
	int p, q, helper;

	for (int i = 0; i < 10; i++)
	{
		std::cin >> mas[i];
	}

	std::cout << "enter values of p and q" << std::endl;
	std::cin >> p >> q;

	for (int i = 0; i < (q - p + 1) / 2; i++)
	{
		helper = mas[p + i];
		mas[p + i] = mas[q - i];
		mas[q - i] = helper;
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << mas[i] << " ";
	}
}