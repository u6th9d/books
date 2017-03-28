#include "GetMinStack.hpp"
#include <iostream>

void test() {
    u6th9d::GetMinStack<int> minStack;
    minStack.push(9);
    std::cout << minStack.getMin() << std::endl;
    minStack.push(4);
    std::cout << minStack.getMin() << std::endl;
    minStack.push(2);
    std::cout << minStack.getMin() << std::endl;

    minStack.push(5);
    minStack.push(1);
    minStack.push(0);
    std::cout << minStack.getMin() << std::endl;

    minStack.pop();
    std::cout << minStack.getMin() << std::endl;
    minStack.pop();
    std::cout << minStack.getMin() << std::endl;
}


int main() {
    test();

    system("pause");
}