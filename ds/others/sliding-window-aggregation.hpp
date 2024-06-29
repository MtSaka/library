#pragma once
#include "../../template/template.hpp"

template <typename T, typename F>
struct SlidingWindowAggregation {
   private:
    vector<T> front_stack_sum, back_stack;
    F f;
    T id, front_sum, back_sum;
    void push_front(const T& x) {
        front_stack_sum.push_back(front_sum = f(x, front_sum));
    }
    void push_back(const T& x) {
        back_stack.push_back(x);
        back_sum = f(back_sum, x);
    }
    void transfer() {
        while(!back_stack.empty()) {
            push_front(back_stack.back());
            back_stack.pop_back();
        }
        back_sum = id;
    }

   public:
    SlidingWindowAggregation(F f, T id) : f(f), id(id), front_sum(id), back_sum(id) {}
    void push(const T& x) {
        if (front_stack_sum.empty()) {
            push_front(x);
            transfer();
        } else {
            push_back(x);
        }
    }
    void pop() {
        if (front_stack_sum.empty()) transfer();
        front_stack_sum.pop_back();
        front_sum = front_stack_sum.empty() ? id : front_stack_sum.back();
    }
    T get() const {
        return f(front_sum, back_sum);
    }
};
/**
 * @brief Sliding Window Aggregation(SWAG)
 */