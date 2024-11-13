// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_set_range_frequency
#include "../../../template/template.hpp"
#include "../../../ds/segment/binary-indexed-tree-01.hpp"
int main() {
    INT(n, q);
    vi a(n);
    sc >> a;
    vector<pair<int, int>> query;
    vector<vector<pair<int, int>>> dat(n + q);
    unordered_map<int, int> mp;
    mp.reserve(n + q);
    rep(i, n) {
        auto it = mp.find(a[i]);
        a[i] = (it == mp.end() ? mp[a[i]] = mp.size() : it->second);
        dat[a[i]].emplace_back(1, i);
    }
    rep(q) {
        INT(t);
        if (t == 0) {
            INT(i, v);
            auto it = mp.find(v);
            v = (it == mp.end() ? mp[v] = mp.size() : it->second);
            dat[a[i]].emplace_back(0, i);
            a[i] = v;
            dat[a[i]].emplace_back(1, i);
        } else {
            INT(l, r, x);
            auto it = mp.find(x);
            x = (it == mp.end() ? mp[x] = mp.size() : it->second);
            dat[x].eb(2, query.size());
            query.eb(l, r);
        }
    }
    rep(i, n) dat[a[i]].emplace_back(0, i);
    q = query.size();
    vi ans(q);
    BinaryIndexedTree01 bit(n);
    for (auto [v, x] : mp) {
        for (auto& [t, i] : dat[x]) {
            if (t == 0) bit.add(i, -1);
            if (t == 1) bit.add(i, 1);
            if (t == 2) {
                auto [l, r] = query[i];
                ans[i] = bit.sum(l, r);
            }
        }
    }
    for (auto& x : ans) print(x);
}