#include<iostream>
#include<string>

int main()
{
    setlocale(LC_ALL, "RUS");
    int countC, countV;
    countC = countV = 0;

    std::string s;
    std::cout << "Введите строку:" << std::endl;
    std::cin >> s;

    const char* sptr = s.c_str();
    for (int i = 0; i < s.length(); i++)
    {
        switch (*sptr)
        {
        case 'А':
        case 'Е':
        case 'И':
        case 'О':
        case 'У':
        case 'Э':
        case 'Ю':
        case 'Ы':
        case 'Я':
        case 'а':
        case 'е':
        case 'и':
        case 'о':
        case 'у':
        case 'э':
        case 'ю':
        case 'ы':
        case 'я':
            countV++;
            break;
        default:
            countC++;
            break;
        }

        *sptr++;

    }

    std::cout << "Количество гласных = " << countV << std::endl;
    std::cout << "Количество согласных = " << countC << std::endl;

    return 0;
}