#pragma once
#include "../../template/template.hpp"
#include "sparse-table.hpp"

template <typename T>
struct PlusMinusOneRMQ {
   private:
    int bucket;
    vector<T> v;
    vector<int> bidx, bbit;
    SparseTable<Monoid::Min<T>> st;
    vector<vector<vector<int>>> lookup_table;
    void init(const vector<T>& vs) {
        int n = vs.size();
        bucket = max(1, (int)__lg(n) / 2);
        int sz = (n + bucket - 1) / bucket;
        bidx.assign(sz, -1);
        vector<int> bmin(sz);
        bbit.assign(sz, 0);
        for (int i = 0; i < sz; ++i) {
            int l = i * bucket, r = min(n, (i + 1) * bucket);
            bidx[i] = l;
            bmin[i] = vs[l];
            for (int j = l + 1; j < r; ++j) {
                if (vs[j] < bmin[i]) bmin[i] = vs[j], bidx[i] = j;
                if (vs[j] > vs[j - 1]) bbit[i] |= 1 << (j - l - 1);
            }
        }
        st = SparseTable<Monoid::MinIdx<T>>(bmin);
        lookup_table.assign(1 << (bucket - 1), vector<vector<int>>(bucket, vector<int>(bucket)));
        vector<int> a(bucket);
        for (int bit = 0; bit < 1 << (bucket - 1); ++bit) {
            for (int i = 0; i < bucket - 1; ++i) a[i + 1] = a[i] + ((bit >> i) & 1 ? 1 : -1);
            for (int l = 0; l < bucket; ++l) {
                int mi = bucket + 1;
                int mi_idx = -1;
                for (int i = l; i < bucket; ++i) {
                    if (a[i] < mi) mi = a[i], mi_idx = i;
                    lookup_table[bit][l][i] = mi_idx;
                }
            }
        }
    }
    pair<T, int> prod(int l, int r) const {
        if (l == r) return {infinity<T>::max(), -1};
        int lb = l / bucket, rb = r / bucket;
        if (lb == rb) {
            int pos = lb * bucket + lookup_table[bbit[lb]][l % bucket][r % bucket - 1];
            return {v[pos], pos};
        }
        int pos = lb * bucket + lookup_table[bbit[lb]][l % bucket][bucket - 1];
        if (r % bucket > 0) {
            int rpos = rb * bucket + lookup_table[bbit[rb]][0][r % bucket - 1];
            if (v[rpos] < v[pos]) pos = rpos;
        }
        if (lb + 1 == rb) return {v[pos], pos};
        auto [bst, bpos] = st.prod(lb + 1, rb);
        if (bst < v[pos]) pos = bidx[bpos];
        return {v[pos], pos};
    }
};
/**
 * @brief Plus Minus One RMQ
 * @ref https://info.atcoder.jp/entry/algorithm_lectures/linear_time_lca
 */
