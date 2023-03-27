#include <iostream>
#include <string>

using namespace std;

int count(string str) {
    int i = 0;
    while (str[i] != 0) {
        ++i;
    }
    return i;
}

int main() {
    system("chep 1251");
    system("cls");
    int x;
    cout << "Enter string: ";
    string str;
    getline(cin, str);
    x = count(str);
    for (int i = x - 1; i >= 0; --i) {
        cout << str[i];
    }
    return 0;
}