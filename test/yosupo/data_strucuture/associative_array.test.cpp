// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/associative_array
#include "../../../ds/others/hash-map.hpp"
#include "../../../template/template.hpp"
int main() {
    int q;
    sc >> q;
    HashMap<ll, ll> mp;
    while (q--) {
        int t;
        sc >> t;
        if (t) {
            ll k;
            sc >> k;
            print(mp[k]);
        } else {
            ll k, v;
            sc >> k >> v;
            mp[k] = v;
        }
    }
}