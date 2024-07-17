// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
#include "../../../ds/union-find/union-find.hpp"
#include "../../../template/template.hpp"
int main() {
    int n, q;
    sc >> n >> q;
    UnionFind d(n);
    rep(q) {
        int t, x, y;
        sc >> t >> x >> y;
        if (t == 0)
            d.merge(x, y);
        else
            print(d.same(x, y));
    }
}