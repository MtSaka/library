#include "../../template/template.hpp"
#include "binary-indexed-tree.hpp"
struct BinaryIndexedTree01 {
    int n, m;
    vector<ull> data;
    BinaryIndexedTree<int> bit;
    BinaryIndexedTree01() {}
    BinaryIndexedTree01(int n_) : n(n_), m(n_ / 64 + 1), data(m, 0), bit(m) {}
    BinaryIndexedTree01(const vector<int>& a) : n(a.size()), m(a.size() / 64 + 1), data(m, 0) {
        vector<int> cnt;
        rep(i, n) data[i / 64] |= ull(a[i]) << (i % 64), cnt[i / 64] += a[i];
        bit = BinaryIndexedTree<int>(cnt);
    }
    void add(int k, int x) {
        if (x == 1)
            data[k / 64] |= 1ull << (k % 64), bit.add(k / 64, 1);
        else
            data[k / 64] &= ~(1ull << (k % 64)), bit.add(k / 64, -1);
    }
    int sum(int k) const {
        int ans = bit.sum(k / 64);
        ans += popcnt(data[k / 64] & ((1ull << (k % 64)) - 1));
        return ans;
    }
    int sum(int l, int r) const { return sum(r) - sum(l); }
    int operator[](int k) const { return (data[k / 64] >> (k % 64)) & 1; }
};