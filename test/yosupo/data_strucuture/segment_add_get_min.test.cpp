// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/segment_add_get_min
#include "../../../ds/cht/li-chao-tree.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n, q);
    vector<array<ll, 4>> A(n);
    for (auto& [l, r, a, b] : A) sc >> l >> r >> a >> b;
    vector<array<ll, 5>> B(q);
    for (auto& [t, l, r, a, b] : B) {
        sc >> t;
        if (t == 0)
            sc >> l >> r >> a >> b;
        else
            sc >> l;
    }
    compressor<ll> press;
    for (auto& [a, b, c, d, e] : B) {
        if (a == 1) press.push_back(b);
    }
    press.build();
    vector<ll> x(press.size());
    rep(i, press.size()) x[i] = press[i];
    LiChaoTree lct(x);
    for (auto& [a, b, c, d] : A) {
        lct.add_segment(press.get_index(a), press.get_index(b), c, d);
    }
    for (auto& [a, b, c, d, e] : B) {
        if (a == 0)
            lct.add_segment(press.get_index(b), press.get_index(c), d, e);
        else {
            ll res = lct.get_min(press.get_index(b));
            if (res == infinity<ll>::max)
                print("INFINITY");
            else
                print(res);
        }
    }
}