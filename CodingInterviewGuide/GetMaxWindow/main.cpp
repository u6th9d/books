#include "GetMaxWindow.hpp"
#include <iostream>

void test() {
    auto result = u6th9d::getMaxWindow<int>({ 9,4,2,5,1,0,8,7,3,6 }, 3);
    for (auto item : result) {
        std::cout << item << std::endl;
    }
}

int main() {
    test();

    system("pause");
}