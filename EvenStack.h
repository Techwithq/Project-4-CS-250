// EvenStack.h
#ifndef EVENSTACK_H
#define EVENSTACK_H

#include <stack>
#include <iostream>

class EvenStack {
private:
    std::stack<int> stack;

public:
    bool empty() const {
        return stack.empty();
    }

    int size() const {
        return stack.size();
    }

    int top() const {
        if (!stack.empty()) {
            return stack.top();
        }
        throw std::runtime_error("Stack is empty");
    }

    void push(int value) {
        if (value % 2 == 0) {
            stack.push(value);
        } else {
            std::cout << "Only even numbers are allowed. '" << value << "' is not pushed." << std::endl;
        }
    }

    void pop() {
        if (!stack.empty()) {
            stack.pop();
        } else {
            throw std::runtime_error("Cannot pop from an empty stack");
        }
    }

    void getEvenNumbers(std::stack<int> &inputStack) {
        std::stack<int> tempStack;
        while (!inputStack.empty()) {
            int value = inputStack.top();
            inputStack.pop();
            if (value % 2 == 0) {
                tempStack.push(value);
            }
        }

        while (!tempStack.empty()) {
            int value = tempStack.top();
            tempStack.pop();
            inputStack.push(value);
            this->push(value);
        }
    }

    void emptyStack() {
        while (!stack.empty()) {
            std::cout << stack.top() << " ";
            stack.pop();
        }
        std::cout << std::endl;
    }
};

#endif // EVENSTACK_H

