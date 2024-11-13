#pragma once
#include "../../template/template.hpp"
#include "../../others/monoid.hpp"

template <typename M, bool = Monoid::is_monoid<M>::value>
struct WeightedUnionFind {
   private:
    using T = typename M::value_type;
    vector<int> par;
    vector<T> val;  // a_r^{-1} a_i
   public:
    WeightedUnionFind() {}
    WeightedUnionFind(int n) : par(n, -1), val(n, M::id()) {}
    int root(int x) {
        if (par[x] < 0) return x;
        const int r = root(par[x]);
        val[x] = M::op(val[par[x]], val[x]);
        return par[x] = r;
    }
    T weight(int x) { return root(x), val[x]; }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -par[root(x)]; }
    pair<bool, bool> merge(int x, int y, T w) {
        w = M::op(weight(x), M::get_inv(M::op(weight(y), w)));
        x = root(x), y = root(y);
        if (x == y) {
            if (w == M::id()) return {false, true};
            return {false, false};
        }
        if (par[x] > par[y]) swap(x, y), w = M::get_inv(w);
        par[x] += par[y];
        par[y] = x;
        val[y] = w;
        return {true, true};
    }
    // a_y^{-1} a_x
    T diff(int x, int y) { return M::op(M::get_inv(weight(y)), weight(x)); }
};
/**
 * @brief Weighted Disjoint Set Union(重み付きUnion Find)
 */