#pragma once
#include "../../template/template.hpp"

template <typename T>
struct SlopeTrick {
   private:
    priority_queue<T> lque;
    priority_queue<T, vector<T>, greater<>> rque;
    T addl, addr, mi;
    void pushr(T x) {
        if (x != inf) rque.emplace(x - addr);
    }
    void pushl(T x) {
        if (x != -inf) lque.emplace(x - addl);
    }
    T topr() const { return (rque.empty() ? inf : rque.top() + addr); }
    T topl() const { return (lque.empty() ? -inf : lque.top() + addl); }
    T popr() {
        T res = topr();
        if (!rque.empty()) rque.pop();
        return res;
    }
    T popl() {
        T res = topl();
        if (!lque.empty()) lque.pop();
        return res;
    }

   public:
    SlopeTrick() : addl(0), addr(0), mi(0) {}
    SlopeTrick(const vector<T>& l, const vector<T>& r) : lque(all(l)), rque(all(r)), addl(0), addr(0), mi(0) {}
    T getmin() const { return mi; }
    pair<T, T> getminargs() const { return {topl(), topr()}; }
    void add(T a) { mi += a; }
    //+max(a-x,0)
    void addminus(T a) {
        mi += max(T(0), a - topr());
        pushr(a);
        pushl(popr());
    }
    //+max(x-a,0)
    void addplus(T a) {
        mi += max(T(0), topl() - a);
        pushl(a);
        pushr(popl());
    }
    //+|x-a|
    void addabs(T a) {
        addminus(a);
        addplus(a);
    }
    void shift(T a) { addl += a, addr += a; }
    // g(x)=min[x-b<=y<=x-a]f(y)
    void sliding_window(T a, T b) {
        addr += b, addl += a;
    }
};
/**
 * @brief Slope Trick
 */