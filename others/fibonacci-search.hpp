#pragma once
#include "../template/template.hpp"
template <typename T>
struct FibonacciSearch {
   private:
    static vector<T> fib;
    static void extend(T n) {
        while (fib.back() < n) {
            fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
        }
    }

   public:
    template <typename F, typename Comp>
    static pair<T, function_return_type<F>> minimize(T left, T right, F&& f, Comp cmp) {
        extend(right - left + 2);
        int idx = 0;
        while (fib[idx] <= right - left + 1) idx++;
        T l = left - 1, r = left - 1 + fib[idx];
        auto ans = f(r - fib[--idx]);
        bool hasl = true;
        for (; idx > 2; --idx) {
            T m1 = r - fib[idx], m2 = l + fib[idx];
            if (m2 > right) {
                r = m2;
                if (!hasl) ans = f(m1);
                hasl = false;
                continue;
            }
            auto v1 = (hasl ? ans : f(m1)), v2 = (hasl ? f(m2) : ans);
            if (cmp(v1, v2)) {
                r = m2;
                ans = v1;
                hasl = false;
            } else {
                l = m1;
                ans = v2;
                hasl = true;
            }
        }
        return {l + 1, ans};
    }
    template <typename F>
    static std::pair<T, function_return_type<F>> minimize(T left, T right, F&& f) {
        return minimize(left, right, std::forward<F>(f), std::less<function_return_type<F>>());
    }
    template <typename F>
    static std::pair<T, function_return_type<F>> maximize(T left, T right, F&& f) {
        return minimize(left, right, std::forward<F>(f), std::greater<function_return_type<F>>());
    }
};
template <typename T>
vector<T> FibonacciSearch<T>::fib = {0, 1, 1};
/**
 * @brief Fibonacci Search
 */