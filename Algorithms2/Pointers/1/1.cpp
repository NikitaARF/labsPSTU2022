#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	int num1;
	int num2;
	int* pnum1;
	int* pnum2;

	std::cout << "¬ведите значение первой переменной" << std::endl;
	std::cin >> num1;

	pnum1 = &num1;

	std::cout << "¬ведите значение второй переменной" << std::endl;
	std::cin >> num2;

	pnum2 = &num2;

	int tmp = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = tmp;

	std::cout << "ѕосле замены значение первой переменной равн€етс€ " << *pnum1 << std::endl;
	std::cout << "ѕосле замены значение второй переменной равн€етс€ " << *pnum2 << std::endl;

	return 0;
}
