//Задача 2.8
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Rus");

start:
    float n;
    char stars = '*';
    char space = ' ';
    int numspace;
    int numstars = 1;

    std::cout << "Введите длину катетов N:" << std::endl;
    std::cin >> n;

    if ((n <= 2) or ((int)n != n))
    {
        std::cout << "ошибка, введите значение больше 2" << std::endl;
        goto start;
    }

    numspace = 0;
    numstars = n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= numstars; j++)
        {
            std::cout << stars;
        }

        if (numspace >= 1)
        {
            for (int j = 1; j <= numspace; j++)
            {
                std::cout << space;
            }
        }

        numstars--;
        numspace++;

        if (numstars < n)
        {
            std::cout << std::endl;
        }

        if (numstars == n)
        {
            break;
        }
    }
}
