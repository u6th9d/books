#ifndef _GETMINSTACK_HPP_
#define _GETMINSTACK_HPP_

#include <stack>

namespace u6th9d {
    template <typename T>
    class GetMinStack {
    public:
        GetMinStack() { }

        ~GetMinStack() { }

        void push(const T& value);

        void pop();

        const T& top() const;

        T& top();

        bool empty();

        const T& getMin() const;

        T& getMin();
    private:
        std::stack<T> valueStack;
        std::stack<T> minValStack;
    };

    template<typename T>
    inline void GetMinStack<T>::push(const T& value) {
        valueStack.push(value);
        if (minValStack.empty()) {
            minValStack.push(value);
        }
        if (std::less<T>()(value, getMin())) {
            minValStack.push(value);
        } else {
            minValStack.push(getMin());
        }
    }

    template<typename T>
    inline void GetMinStack<T>::pop() {
        valueStack.pop();
        minValStack.pop();
    }

    template<typename T>
    inline const T& GetMinStack<T>::top() const {
        return valueStack.top();
    }

    template<typename T>
    inline T& GetMinStack<T>::top() {
        return valueStack.top();
    }

    template<typename T>
    inline bool GetMinStack<T>::empty() {
        return valueStack.empty();
    }

    template<typename T>
    inline const T& GetMinStack<T>::getMin() const {
        return minValStack.top();
    }

    template<typename T>
    inline T& GetMinStack<T>::getMin() {
        return minValStack.top();
    }
}

#endif