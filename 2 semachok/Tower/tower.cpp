#include <iostream>

void move(char point1, char point2)
{
	std::cout << "from: " << point1 << " to: " << point2 << std::endl;
}

void moveTower(int amount_plates, char point1, char point2, char helper)
{
	if (amount_plates == 0)
	{
		return;
	}

	moveTower(amount_plates - 1, point1, helper, point2);
	move(point1, point2);
	moveTower(amount_plates - 1, helper, point2, point1);
}

int main()
{
	int n;

	std::cout << "Enter the quatity of plates: ";
	std::cin >> n;
	std::cout << std::endl;

	moveTower(n, 'A', 'B', 'C');
}