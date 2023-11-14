// EvenStack.h
#ifndef EVENSTACK_H
#define EVENSTACK_H

#include <stack>
#include <iostream>
#include <vector>

class EvenStack {
private:
    std::vector<int> elements;

public:
    bool empty() const {
        return elements.empty();
    }

    int size() const {
        return elements.size();
    }

    int top() const {
        if (!elements.empty()) {
            return elements.back();
        }
        throw std::runtime_error("Stack is empty");
    }

    void push(int value) {
        if (value % 2 == 0) {
            elements.push_back(value);
        } else {
            std::cout << "Only even numbers are allowed. '" << value << "' is not pushed." << std::endl;
        }
    }

    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
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
                elements.push_back(value);
            }
            tempStack.push(value);
        }

        while (!tempStack.empty()) {
            inputStack.push(tempStack.top());
            tempStack.pop();
        }
    }

    void emptyStack() {
        while (!elements.empty()) {
            std::cout << elements.back() << " ";
            elements.pop_back();
        }
        std::cout << std::endl;
    }
};

#endif // EVENSTACK_H
