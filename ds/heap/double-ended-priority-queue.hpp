#pragma once

#include "../../template/template.hpp"

template <typename T>
struct DoubleEndedPriorityQueue {
   private:
    priority_queue<T> pq1, rpq2;
    priority_queue<T, vector<T>, greater<T>> pq2, rpq1;

   public:
    DoubleEndedPriorityQueue() {}
    template <typename U>
    DoubleEndedPriorityQueue(U first, U last) : pq1(first, last), pq2(first, last) {}
    void push(const T& x) {
        pq1.emplace(x);
        pq2.emplace(x);
    }
    T get_max() {
        while (!rpq2.empty() && pq1.top() == rpq2.top()) {
            rpq2.pop();
            pq1.pop();
        }
        return pq1.top();
    }
    T get_min() {
        while (!rpq1.empty() && pq2.top() == rpq1.top()) {
            rpq1.pop();
            pq2.pop();
        }
        return pq2.top();
    }
    T pop_max() {
        T res = get_max();
        rpq1.emplace(res);
        return pq1.pop(), res;
    }
    T pop_min() {
        T res = get_min();
        rpq2.emplace(res);
        return pq2.pop(), res;
    }
};
/**
 * @brief Double-Ended Priority Queue
 */