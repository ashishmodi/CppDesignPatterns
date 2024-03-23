#include <iostream>
#include "DesignPatternTester.h"
using namespace std;

int main() {
    DesignPatternTester tester;
    cout << "$-$-$-$-$-$-$-$-$-$ Creational Design patterns $-$-$-$-$-$-$-$-$-$" << endl;
    tester.testFactory();
    tester.testAbstractFactory();
    tester.testBuilder();

    return 0;
}