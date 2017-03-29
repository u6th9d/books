#ifndef _GETMAXWINDOW_HPP_
#define _GETMAXWINDOW_HPP_

#include <deque>
#include <vector>
#include <cassert>

namespace u6th9d {
    template <typename T>
    std::vector<T> getMaxWindow(const std::vector<T>& vec, int windowSize) {
        std::vector<T> result;
        assert(vec.size() >= windowSize);
        if (vec.size() < windowSize) {
            return result;
        }
        std::deque<T>window(vec.cbegin(), vec.cbegin() + windowSize);
        result.push_back(*getMax(window));
        for (auto iter = vec.cbegin() + windowSize; iter != vec.cend(); iter++) {
            window.push_back(*iter);
            window.pop_front();
            result.push_back(*getMax(window));
        }
        return result;
    }

    template<typename T>
    static typename std::deque<T>::const_iterator getMax(const std::deque<T>& window) {
        auto result = window.cbegin();
        for (auto iter = window.cbegin(); iter != window.cend(); iter++) {
            if (std::less<T>()(*result, *iter)) {
                result = iter;
            }
        }
        return result;
    }
}

#endif