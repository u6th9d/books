#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

#include <string>
#include <iostream>

namespace u6th9d {
    struct Object {
        virtual void print() = 0;
    };

    class Cat : public Object {
    public:
        Cat(std::string s = "Cat") : name(s) { }
        void print() override {
            std::cout << name << std::endl;
        }
    private:
        std::string name;
    };

    class Dog : public Object {
    public:
        Dog(std::string s = "Cat") : name(s) { }
        void print() override {
            std::cout << name << std::endl;
        }
    private:
        std::string name;
    };
}

#endif