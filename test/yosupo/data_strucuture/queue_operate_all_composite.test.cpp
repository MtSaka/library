// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/queue_operate_all_composite
#include "../../../template/template.hpp"
#include "../../../ds/others/sliding-window-aggregation.hpp"
#include "../../../math/modular/modint.hpp"
using mint = ModInt<998244353>;

int main() {
    using S = pair<mint, mint>;
    auto f = [](S a, S b) { return S(a.first * b.first, a.second * b.first + b.second); };
    SlidingWindowAggregation swag(f, S(1, 0));
    INT(q);
    while (q--) {
        LL(t);
        if (t == 0) {
            mint a, b;
            cin >> a >> b;
            swag.push(S{a, b});
        } else if (t == 1) {
            swag.pop();
        } else if (t == 2) {
            mint x;
            cin >> x;
            auto [a, b] = swag.get();
            print(a * x + b);
        }
    }
}