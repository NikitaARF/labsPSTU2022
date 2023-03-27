#include <iostream>

const int MinutesPerHour = 60;

// function: from "hours + minutes" to "minutes"
void timeConvert(int* end_Minutes, int Hours, int Minutes) {
    *end_Minutes = Hours * MinutesPerHour + Minutes;
}

// function: from "minutes" to "hours + minutes"
void timeConvert(int* end_Hours, int* end_Minutes, int Minutes) {
    *end_Hours = Minutes / MinutesPerHour;
    *end_Minutes = Minutes % MinutesPerHour;
}

void test1() {
    int Hours;
    std::cout << "enter hours: ";
    std::cin >> Hours;

    int Minutes;
    std::cout << "enter minutes: ";
    std::cin >> Minutes;

    int end_Minutes;
    timeConvert(&end_Minutes, Hours, Minutes);

    std::cout << Hours << " hours + " << Minutes << " minutes -> " << end_Minutes << " minutes " << std::endl;
}

void test2() {

    int Minutes;
    std::cout << "enter minutes: ";
    std::cin >> Minutes;

    int end_Hours, end_Minutes;
    timeConvert(&end_Hours, &end_Minutes, Minutes);

    std::cout << Minutes << " minutes -> " << end_Hours << " hours " << end_Minutes << " minutes " << std::endl;
}

int main() {

    test1();
    test2();
}