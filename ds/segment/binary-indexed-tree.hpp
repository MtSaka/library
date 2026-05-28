#pragma once
#include "../../others/monoid.hpp"
#include "../../template/template.hpp"

template <typename M, bool = Monoid::is_monoid<M>::value>
struct BinaryIndexedTree {
   private:
    template <typename, bool>
    friend struct BinaryIndexedTree;
    using T = typename M::value_type;
    int n;
    vector<T> data;

   public:
    BinaryIndexedTree() : BinaryIndexedTree(0) {}
    BinaryIndexedTree(int n_) { init(n_); }
    BinaryIndexedTree(const vector<T>& v) {
        n = (int)v.size();
        data.clear();
        data.emplace_back(M::id());
        data.insert(data.end(), v.begin(), v.end());
        rep(i, 1, n + 1) {
            int j = i + (i & -i);
            if (j <= n) data[j] = M::op(data[i], data[j]);
        }
    }
    void init(int n_) {
        n = n_;
        data.assign(n + 1, M::id());
    }
    void apply(int k, T x) {
        for (k++; k <= n; k += k & -k) {
            data[k] = M::op(data[k], x);
        }
    }
    T prod(int k) const {
        T res = M::id();
        for (; k > 0; k -= k & -k) {
            res = M::op(res, data[k]);
        }
        return res;
    }
    template <bool dummy = true, typename enable_if<Monoid::has_inv<M>::value && dummy>::type* = nullptr>
    T prod(int l, int r) const {
        return M::inv(prod(r), prod(l));
    }
    T operator[](int k) const { return prod(k, k + 1); }
    void set(int k, T x) { apply(k, M::inv(x, (*this)[k])); }
};
template <typename T>
struct BinaryIndexedTree<T, false> : BinaryIndexedTree<Monoid::Sum<T>> {
   private:
    using Base = BinaryIndexedTree<Monoid::Sum<T>>;

   public:
    using Base::Base;
    void add(int k, T x) { this->apply(k, x); }
    T sum(int k) const { return this->prod(k); }
    T sum(int l, int r) const { return this->prod(l, r); }

    int lower_bound(T x) const {
        int i = 0;
        for (int k = 1 << (__lg(this->n) + 1); k > 0; k >>= 1) {
            if (i + k <= this->n && this->data[i + k] < x) {
                x -= this->data[i + k];
                i += k;
            }
        }
        return i + 1;
    }
    int upper_bound(T x) const {
        int i = 0;
        for (int k = 1 << (__lg(this->n) + 1); k > 0; k >>= 1) {
            if (i + k <= this->n && this->data[i + k] <= x) {
                x -= this->data[i + k];
                i += k;
            }
        }
        return i + 1;
    }
};
/**
 * @brief Binary Indexed Tree(Fenwick Tree, BIT)
 */