#pragma once
#include "../../template/template.hpp"
template <typename T>
struct TopKSum {
   private:
    int k;
    T sum;
    multiset<T> big, small;

   public:
    TopK(int k_) : k(k_), sum(0) {}
    void insert(T x) {
        big.insert(x);
        sum += x;
        if ((int)big.size() > k) {
            auto it = big.begin();
            sum -= *it;
            small.insert(*it);
            big.erase(it);
        }
    }
    void erase(T x) {
        if (small.count(x)) {
            small.erase(small.find(x));
        } else {
            big.erase(big.find(x));
            sum -= x;
            if (small.size()) {
                auto it = prev(small.end());
                sum += *it;
                big.insert(*it);
                small.erase(it);
            }
        }
    }
    T get() const { return sum; }
    void changek(int tok) {
        k = tok;
        while ((int)big.size() > k) {
            auto it = big.begin();
            small.insert(*it);
            sum -= *it;
            big.erase(it);
        }
        while ((int)big.size() < k) {
            auto it = prev(small.end());
            sum += *it;
            big.insert(*it);
            small.erase(it);
        }
    }
};
/**
 * @brief Top K Sum
 */