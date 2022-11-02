//Задача 2.4
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Rus");

start:
    float n;
    int numspace;
    int numstar = 1;
    char space = ' ';
    char star = '*';
    std::cout << "Введите основание равнобедренного треугольника N" << std::endl;
    std::cin >> n;

    if ((n <= 3) or ((int)n != n) or ((int)n % 2 != 1))
    {
        std::cout << "ошибка введите N нечетное и больше 3-ёх" << std::endl;
        goto start;
    }

    numspace = n / 2;
    std::cout << std::endl;

    for (int i = 1; i <= n; i += 2)
    {
        for (int j = 1; j <= numspace; j++)
        {
            std::cout << space;
        }

        for (int j = 1; j <= numstar; j++)
        {
            std::cout << star;
        }

        if (numstar != n)
        {
            std::cout << std::endl;
        }

        numspace--;
        numstar += 2;
    }

    std::cout << std::endl;
}