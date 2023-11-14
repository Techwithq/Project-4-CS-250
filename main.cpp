#include <iostream>
#include <stack>
#include "EvenStack.h"

using namespace std;

int main() {
    EvenStack myStack;
    myStack.push(44);
    myStack.push(66);
    myStack.push(99);
    myStack.push(88);
    myStack.pop();
    myStack.emptyStack();

    stack <int> aStack;

    aStack.push(2);
    aStack.push(9);
    aStack.push(6);
    aStack.push(2);
    aStack.push(3);
    aStack.push(5);
    aStack.push(4);

    EvenStack newStack;
    newStack.push(32);
    newStack.getEvenNumbers(aStack);

    cout << endl;
    cout << "aStack has " << aStack.size() << " elements" << endl;
    cout << "myStack has " << myStack.size() << " elements" << endl;
    cout << "newStack has " << newStack.size() << " elements" << endl;

    cout << endl;
    while (!newStack.empty()) {
       cout <<  newStack.top() << "  ";
       newStack.pop();
    }
    cout << endl;

    return 0;
}
