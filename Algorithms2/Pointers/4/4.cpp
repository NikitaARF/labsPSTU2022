#include<iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	int tmp; 
	int* ptr = &tmp;
	int max;
	int min;

	std::cout << "������� ����� ������������������:" << std::endl;
	std::cin >> n;
	std::cout << "������� ������ �����:" << std::endl;
	std::cin >> tmp;

	max = *ptr;
	min = *ptr;

	for (int i = 2; i <= n; i++)
	{
		std::cin >> *ptr;

		if (*ptr > max) 
		{ 
			max = *ptr; 
		}
		else if (*ptr < min) 
		{ 
			min = *ptr; 
		}
	}

	std::cout << "������������ ������� ������������������ �����: " << max << std::endl;
	std::cout << "����������� ������� ������������������ �����: " << min << std::endl;

	return 0;
}