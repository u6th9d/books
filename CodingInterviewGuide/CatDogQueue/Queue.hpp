#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include "Object.hpp"
#include <list>
#include <memory>

namespace u6th9d {

    class Queue {
    public:
        template <typename R>
        void add(R& obj);

        std::shared_ptr<Object> pollAll();

        std::shared_ptr<Object> pollDog();

        std::shared_ptr<Object> pollCat();

        bool isEmpty() const;

        bool isDogEmpty() const;

        bool isCatEmpty() const;
    private:
        std::list<std::shared_ptr<Object>> list;
    };

    //void u6th9d::Queue::add(Object& obj) {
    //    list.push_back(std::make_shared<Object>(obj));  //wrong
    //}

    template <typename R>
    void u6th9d::Queue::add(R& obj) {
        list.push_back(std::make_shared<R>(obj));
    }

    inline std::shared_ptr<Object> u6th9d::Queue::pollAll() {
        auto elem = list.front();
        list.pop_front();
        return elem;
    }

    inline std::shared_ptr<Object> u6th9d::Queue::pollDog() {
        for (auto iter = list.begin(); iter != list.end(); iter++) {
            if (dynamic_cast<Dog*>(iter->get())) {
                auto elem = *iter;
                list.erase(iter);
                return elem;
            }
        }
        return std::shared_ptr<Object>();
    }

    inline std::shared_ptr<Object> u6th9d::Queue::pollCat() {
        for (auto iter = list.begin(); iter != list.end(); iter++) {
            if (dynamic_cast<Cat*>(iter->get())) {
                auto elem = *iter;
                list.erase(iter);
                return elem;
            }
        }
        return std::shared_ptr<Object>();
    }

    inline bool u6th9d::Queue::isEmpty() const {
        return list.empty();
    }

    inline bool u6th9d::Queue::isDogEmpty() const {
        for (auto iter = list.cbegin(); iter != list.cend(); iter++) {
            if (dynamic_cast<Dog*>(iter->get())) {
                return false;
            }
        }
        return true;
    }

    inline bool u6th9d::Queue::isCatEmpty() const {
        for (auto iter = list.cbegin(); iter != list.cend(); iter++) {
            if (dynamic_cast<Cat*>(iter->get())) {
                return false;
            }
        }
        return true;
    }
}

#endif