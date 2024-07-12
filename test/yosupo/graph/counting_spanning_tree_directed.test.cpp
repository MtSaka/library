// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/counting_spanning_tree_directed
#include "../../../template/template.hpp"
#include "../../../graph/mst/count-spanning-tree.hpp"
#include "../../../math/modular/modint.hpp"
using mint = ModInt<998244353>;

int main() {
    INT(n, m, r);
    Graph<mint> g(n);
    g.read(m, 0, false, true);
    print(count_spanning_tree<mint>(g, r));
}