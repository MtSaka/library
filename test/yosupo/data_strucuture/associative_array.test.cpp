// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/associative_array
#include "../../../ds/others/hash-map.hpp"
#include "../../../template/template.hpp"
int main() {
    int q;
    cin >> q;
    HashMap<ll, ll> mp;
    while (q--) {
        int t;
        cin >> t;
        if (t) {
            ll k;
            cin >> k;
            print(mp[k]);
        } else {
            ll k, v;
            cin >> k >> v;
            mp[k] = v;
        }
    }
}