//посчитать сумму `S = 1 * 2 + 2 * 3 * 4 + 3 * 4 * 5 * 6 + 4 * 5 * 6 * 7 * 8 + ....` до N(натурального числа).
#include <iostream>

int sumofseries(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum = sum + i * (i * 1) * (i + 2);
	return sum;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	std::cout << "ввудите N" << std::endl;
	std::cin >> n;
	std::cout << sumofseries(n);
	return 0;

}