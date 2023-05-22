#include <iostream>
#include "set.h"

int main() {
    Set s1(2), s2(3);
    std::cout << "started s1 = " << s1 << std::endl;
    std::cout << "started s2 = " << s2 << std::endl;
    std::cout << std::endl;

    std::cout << "enter elements will be in s1: "; std::cin >> s1;
    std::cout << "enter elements will be in s2: "; std::cin >> s2;
    std::cout << std::endl;

    std::cout << "ready s1 = " << s1 << std::endl;
    std::cout << "ready s2 = " << s2 << std::endl;
    std::cout << std::endl;

    s1[1] = 100;
    std::cout << "s1 after change = " << s1 << std::endl;
    std::cout << std::endl;

    s2 = s1;
    std::cout << "s2 after assignment to a = " << s2 << std::endl;
    std::cout << std::endl;

    Set s3 = s1 * s2;
    std::cout << "s1 * s2 = " << s1 << std::endl;
    std::cout << std::endl;

    Set s4(5);
    std::cout << "started s4 = " << s4 << std::endl;
    std::cout << std::endl;

    std::cin >> s4;
    std::cout << "ready s4 = " << s4 << std::endl;
    std::cout << std::endl;

    s3 = s1 * s4;
    std::cout << "s1 * s2 = " << s3 << std::endl;
    std::cout << std::endl;

    std::cout << "the lenght of s1 = " << s1() << std::endl;
    std::cout << std::endl;

    std::cout << *(s1.first()) << std::endl;
    std::cout << std::endl;

    Iterator i = s1.first();
    ++i;
    std::cout << "increment operation " << *i << std::endl;
    std::cout << std::endl;

    for (i = s1.first(); i != s1.last(); ++i) { std::cout << *i << " "; }
    return 0;
}