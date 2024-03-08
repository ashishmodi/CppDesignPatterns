#include <iostream>

#include "DesignPatternTester.h"

int main() {
    DesignPatternTester tester;
    tester.testFactory();
    tester.testAbstractFactory();
    tester.testBuilder();

    return 0;
}