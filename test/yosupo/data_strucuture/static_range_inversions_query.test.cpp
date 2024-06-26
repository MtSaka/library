// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/static_range_inversions_query
#include "../../../ds/segment/binary-indexed-tree.hpp"
#include "../../../others/mo.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    vector<int> a(n);
    sc >> a;
    Mo mo(n);
    rep(i, q) {
        INT(l, r);
        mo.add(l, r);
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (auto& i : a) i = lower_bound(b.begin(), b.end(), i) - b.begin();
    BinaryIndexedTree<int> bit(b.size() + 1);
    ll inv = 0, sum = 0;
    vector<ll> ans(q);
    auto add_left = [&](int idx) {
        inv += bit.sum(a[idx]);
        bit.add(a[idx], 1);
        sum++;
    };
    auto add_right = [&](int idx) {
        inv += sum - bit.sum(a[idx] + 1);
        bit.add(a[idx], 1);
        sum++;
    };
    auto delete_left = [&](int idx) {
        inv -= bit.sum(a[idx]);
        bit.add(a[idx], -1);
        sum--;
    };
    auto delete_right = [&](int idx) {
        inv -= sum - bit.sum(a[idx] + 1);
        bit.add(a[idx], -1);
        sum--;
    };
    auto rem = [&](int idx) { ans[idx] = inv; };
    mo.run(add_left, add_right, delete_left, delete_right, rem);
    for (auto i : ans) print(i);
}