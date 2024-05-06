#pragma once
#include "../../others/monoid.hpp"
#include "../../template/template.hpp"

template <typename M>
struct SegmentTree {
   private:
    using T = typename M::value_type;
    int n, size;
    vector<T> data;
    void update(int k) { data[k] = M::op(data[k << 1], data[k << 1 ^ 1]); }

   public:
    SegmentTree() : SegmentTree(0) {}
    SegmentTree(int n, const T& e = M::id()) : SegmentTree(vector<T>(n, e)) {}
    SegmentTree(const vector<T>& v) { init(v); }
    void init(const vector<T>& v) {
        n = v.size();
        size = 1 << ceil_log2(n);
        data.assign(size << 1, M::id());
        rep(i, n) data[size + i] = v[i];
        rrep(i, 1, size) update(i);
    }
    template <class Upd>
    void update(int k, const Upd& upd) {
        k += size;
        data[k] = upd(data[k]);
        while (k >>= 1) update(k);
    }
    void set(int k, const T& x) {
        update(k, [&](T) -> T { return x; });
    }
    void apply(int k, const T& x) {
        update(k, [&](T y) -> T { return M::op(y, x); });
    }
    T operator[](int k) const { return data[size + k]; }
    T prod(int l, int r) const {
        l += size, r += size;
        T sml = M::id(), smr = M::id();
        while (l != r) {
            if (l & 1) sml = M::op(sml, data[l++]);
            if (r & 1) smr = M::op(data[--r], smr);
            l >>= 1, r >>= 1;
        }
        return M::op(sml, smr);
    }
    T all_prod() const { return data[1]; }
    template <class F>
    int max_right(int l, const F& f) const {
        if (l == n) return n;
        l += size;
        T sum = M::id();
        do {
            while ((l & 1) == 0) l >>= 1;
            if (!f(M::op(sum, data[l]))) {
                while (l < size) {
                    l <<= 1;
                    if (f(M::op(sum, data[l]))) sum = M::op(sum, data[l++]);
                }
                return l - size;
            }
            sum = M::op(sum, data[l++]);
        } while ((l & -l) != l);
        return n;
    }
    template <class F>
    int min_left(int r, const F& f) const {
        if (r == 0) return 0;
        r += size;
        T sum = M::id();
        do {
            --r;
            while ((r & 1) && r > 1) r >>= 1;
            if (!f(M::op(data[r], sum))) {
                while (r < size) {
                    r = (r << 1) ^ 1;
                    if (f(M::op(data[r], sum))) sum = M::op(data[r--], sum);
                }
                return r + 1 - size;
            }
            sum = M::op(data[r], sum);
        } while ((r & -r) != r);
        return 0;
    }
};
template <typename T, T max_value = infinity<T>::max>
using RangeMinimumQuery = SegmentTree<Monoid::Min<T, max_value>>;
template <typename T, T min_value = infinity<T>::min>
using RangeMaximumQuery = SegmentTree<Monoid::Max<T, min_value>>;
template <typename T>
using RangeSumQuery = SegmentTree<Monoid::Sum<T>>;
/**
 * @brief Segment Tree(セグメント木)
 */