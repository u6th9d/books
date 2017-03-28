#include "Queue.hpp"
#include <iostream>

void test() {
    u6th9d::Queue<int> queue;
    queue.push(9);
    queue.push(4);
    queue.push(2);
    queue.push(5);
    std::cout << queue.front() << std::endl;
    std::cout << queue.back() << std::endl;
    queue.front() -= 1;
    queue.back() += 1;
    std::cout << queue.front() << std::endl;
    std::cout << queue.back() << std::endl;
    queue.pop();
    queue.pop();
    queue.push(1);
    std::cout << queue.front() << std::endl;
    std::cout << queue.back() << std::endl;
}

int main() {
    test();

    system("pause");
}