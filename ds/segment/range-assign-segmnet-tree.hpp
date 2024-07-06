#pragma once

#include "lazy-segment-tree.hpp"

template <typename M_>
struct RangeAssignSegmnetTree {
    static_assert(Monoid::is_monoid<M_>::value, "M must be monoid");

   private:
    using T = typename M_::value_type;
    struct Action {
        using M = M_;
        using E = Monoid::Assign<T*>;
        static T mul_op(T* const& x, int b, const T&) {
            return *(x + ceil_log2(b));
        }
    };
    int n;
    LazySegmentTree<Action> seg;
    vector<T> memo;
    int idx;

   public:
    RangeAssignSegmnetTree() : RangeAssignSegmnetTree(0) {}
    RangeAssignSegmnetTree(int n, const T& e = M_::id()) : RangeAssignSegmnetTree(vector<T>(n, e)) {}
    RangeAssignSegmnetTree(const vector<T>& v) : n(v.size()), seg(v), memo(n), idx(0) {}
    template <typename Upd>
    void update(int k, const Upd& upd) {
        seg.update(k, upd);
    }
    void set(int l, int r, const T& x) {
        const int sz = r - l;
        if (sz == 0) return;
        const int off = msb(sz) + 1;
        if (idx + off > n) {
            seg.eval_all();
            idx = 0;
        }
        memo[idx] = x;
        rep(i, off - 1) memo[idx + i + 1] = M_::op(memo[idx + i], memo[idx + i]);
        seg.apply(l, r, memo.data() + idx);
        idx += off;
    }
    void set(int k, const T& x) { seg.set(k, x); }
    T prod(int l, int r) { return seg.prod(l, r); }
    T operator[](int k) { return seg[k]; }
    T all_prod() { return seg.all_prod(); }
};
