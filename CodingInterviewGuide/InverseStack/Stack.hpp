#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <stack>

namespace u6th9d {
    template<typename T>
    class Stack: public std::stack<T> {
    public:
        Stack() { }

        ~Stack() { }

        void InverseStack();
    };

    template<typename T>
    inline void Stack<T>::InverseStack() {

    }
}
#endif
