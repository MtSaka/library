#pragma once
#include "../../others/monoid.hpp"
#include "../../template/template.hpp"

template <typename M>
struct DisjointSparseTable {
   private:
    using T = typename M::value_type;
    int lg, n;
    vector<int> log_table;
    vector<vector<T>> table;
    T internal_prod(int l, int r) const {
        r--;
        if (l == r) return table[0][l];
        int d = log_table[r ^ l];
        return M::op(table[d][l], table[d][r]);
    }

   public:
    DisjointSparseTable() = default;
    DisjointSparseTable(const vector<T>& v) { init(v); }
    void init(const vector<T>& v) {
        n = v.size(), lg = ceil_log2(n + 1);
        table.resize(lg, vector<T>(n));
        table[0] = v;
        int shift = 1;
        rep(i, 1, lg) {
            shift <<= 1;
            rep(j, 0, n, shift << 1) {
                int l = min<int>(j + shift, n);
                table[i][l - 1] = v[l - 1];
                rrep(k, j, l - 1) table[i][k] = M::op(v[k], table[i][k + 1]);
                if (n == l) break;
                table[i][l] = v[l];
                int r = min<int>(l + shift, n);
                rep(k, l + 1, r) table[i][k] = M::op(table[i][k - 1], v[k]);
            }
        }
        log_table.resize(1 << lg);
        rep(i, 2, 1 << lg) log_table[i] = log_table[i >> 1] + 1;
    }
    template <bool dummy = true, typename enable_if<Monoid::has_id<M>::value && dummy>::type* = nullptr>
    T prod(int l, int r) const {
        if (l == r) return M::id();
        return internal_prod(l, r);
    }
    template <bool dummy = true, typename enable_if<!Monoid::has_id<M>::value && dummy>::type* = nullptr>
    T prod(int l, int r) const {
        return internal_prod(l, r);
    }
};