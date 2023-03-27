#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <windows.h>
using namespace std;
int main()
{   

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream f1("F1.txt");
    string str;
    int n;
    cout << "enter numbers of strings: ";
    cin >> n;
    string numbers = "0123456789";
    int flag = false;

    cin.get();
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        f1 << str << endl;
    }
    f1.close();

    ifstream f3("F1.txt");
    ofstream f2("F2.txt");

    if (!f3.is_open() && !f2.is_open()) {
        return 1;
    }

    while (getline(f3, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            for (int a = 0; a < numbers.size(); a++)
            {
                if (str[i] == numbers[a])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                break;
            }
        }
        if (flag == 0)
        {
            f2 << str << endl;
        }
        flag = 0;
    }
    f3.close();
    f2.close();



    cout << endl << endl;
    ifstream end("F2.txt");
    string s;
    while (getline(end, s)) {
        cout << s << endl;
    }
    end.close();

    ifstream end2("F2.txt");
    int c = 0;
    if (!end2.is_open()) {
        return 1;
    }


    while (getline(end2, s)) {
        if (s[0] == 'А') {
            c++;
        }
    }
    end2.close();
    cout << c << endl;
}
