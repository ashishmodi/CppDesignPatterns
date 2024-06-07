#include <iostream>
#include "DesignPatternTester.h"
using namespace std;

int main() {
    DesignPatternTester tester;
    cout << "$-$-$-$-$-$-$-$-$-$ Creational Design patterns $-$-$-$-$-$-$-$-$-$" << endl;
    tester.testFactory();
    tester.testAbstractFactory();
    tester.testBuilder();
    tester.testPrototype();
    tester.testSingleton();
    cout << "$-$-$-$-$-$-$-$-$-$ Structural Design patterns $-$-$-$-$-$-$-$-$-$" << endl;
    tester.testAdapter();
    tester.testBridge();
    tester.testComposite();
    tester.testDecorator();
    tester.testFacade();
    tester.testFlyweight();
    tester.testPrototype();
    tester.testProxy();
    cout << "$-$-$-$-$-$-$-$-$-$ Behavioral Design patterns $-$-$-$-$-$-$-$-$-$" << endl;
    tester.testChainOfResponsibility();
    return 0;
}