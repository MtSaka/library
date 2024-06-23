// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/cartesian_tree
#include "../../../graph/tree/catersian-tree.hpp"
#include "../../../template/template.hpp"

int main() {
    int n;
    sc >> n;
    vector<int> a(n);
    sc >> a;
    auto v = CatersianTree(a).get();
    rep(i, n) if (v[i] == -1) v[i] = i;
    print(v);
}