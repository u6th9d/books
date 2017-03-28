#include "Queue.hpp"
#include "Object.hpp"

void test() {
    u6th9d::Queue queue;
    auto cat = u6th9d::Cat();
    queue.add(cat);
    auto dog = u6th9d::Dog();
    queue.add(dog);
    std::cout << queue.isCatEmpty() << std::endl;
    queue.pollCat();
    std::cout << queue.isCatEmpty() << std::endl;
}

int main() {
    test();

    system("pause");
}