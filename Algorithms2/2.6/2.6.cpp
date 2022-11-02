//Задача 2.6

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Rus");

start:
    float n;
    char star = '*';
    char space = ' ';
    int numspace;
    int numstar = 1;

    std::cout << "Введите длину катетов N:" << std::endl;
    std::cin >> n;

    if ((n <= 2) or ((int)n != n))
    {
        std::cout << "ошибка" << std::endl;
        goto start; 
    }

    numspace = 0;
    numstar = n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= numspace; j++)
        {
            std::cout << space;
        }

        for (int j = 1; j <= numstar; j++)
        {
            std::cout << star;
        }

        numspace++;
        numstar--;

        if (numstar < n)
        {
            std::cout << std::endl;
        }

        if (numstar == n)
        {
            break;
        }
    }
}