// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
#include "../../../ds/union-find/weighted-union-find.hpp"
#include "../../../template/template.hpp"
int main() {
    int n, m;
    sc >> n >> m;
    WeightedUnionFind<Monoid::Sum<int>> tree(n);
    while (m--) {
        int a, b, c, d;
        sc >> a >> b >> c;
        if (a == 0) {
            sc >> d;
            tree.merge(b, c, d);
        } else {
            if (tree.same(b, c)) {
                print(tree.diff(b, c));
            } else {
                print('?');
            }
        }
    }
}