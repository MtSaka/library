// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/tree_diameter
#include "../../../graph/tree/tree-diameter.hpp"
#include "../../../template/template.hpp"
int main() {
    INT(n);
    TreeDiameter<ll> g(n);
    g.read(n - 1, 0, true);
    auto ans = g.build();
    print(ans, g.path.size() + 1);
    pr << g.path[0].from;
    for (const auto& e : g.path) pr << " " << e.to;
    pr << endl;
}