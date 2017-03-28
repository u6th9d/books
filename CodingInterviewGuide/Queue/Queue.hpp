#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <stack>

namespace u6th9d {

    template<typename T>
    class Queue {
    public:
        Queue() { status = PUSH; }

        ~Queue() { }

        void push(const T& value);

        void pop();

        const T& front() const;

        T& front();

        const T& back() const;

        T& back();

    private:
        enum QueueRank { POP = 0, PUSH = 1 };
        void move(QueueRank state);
        std::stack<T> stacks[2];
        QueueRank status;
    };

    template<typename T>
    inline void Queue<T>::move(QueueRank state) {
        if (state == status) {
            return;
        }
        while (!stacks[status].empty()) {
            stacks[state].push(stacks[status].top());
            stacks[status].pop();
        }
        status = state;
    }

    template<typename T>
    inline void Queue<T>::push(const T& value) {
        move(PUSH);
        stacks[PUSH].push(value);
    }

    template<typename T>
    inline void Queue<T>::pop() {
        move(POP);
        stacks[POP].pop();
    }

    template<typename T>
    inline const T& Queue<T>::front() const {
        move(POP);
        return stacks[POP].top();
    }

    template<typename T>
    inline T& Queue<T>::front() {
        move(POP);
        return stacks[POP].top();
    }

    template<typename T>
    inline const T& Queue<T>::back() const {
        move(PUSH);
        return stacks[PUSH].top();
    }

    template<typename T>
    inline T& Queue<T>::back() {
        move(PUSH);
        return stacks[PUSH].top();
    }
}

#endif
