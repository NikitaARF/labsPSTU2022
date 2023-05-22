#include <iostream>
#include "pair.h"
#include "rational.h"
using namespace std;

int main() {
    Pair pair1;
    Pair pair2;

    cout << "enter pair1" << endl;
    cin >> pair1;
    cout << "pair1: " << pair1 << endl;
    cout << "enter pair2" << endl;
    cin >> pair2;
    cout << "pair2: " << pair2 << endl;

    Pair differencePair = pair1 - pair2;

    cout << "difference: " << differencePair << endl;

    Rational rational1;
    Rational rational2;

    cout << "enter rational1" << endl;
    cin >> rational1;
    cout << "rational1: " << rational1 << endl;
    cout << "enter rational2" << endl;
    cin >> rational2;
    cout << "rational2: " << rational2 << endl;

    Rational sumRational = rational1 + rational2;
    Rational differenceRational = rational1 - rational2;
    Rational productRational = rational1 * rational2;

    cout << "sum: " << sumRational << endl;
    cout << "difference: " << differenceRational << endl;
    cout << "product: " << productRational << endl;

    return 0;
}

