// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/eertree
#include "../../../template/template.hpp"
#include "../../../string/eertree.hpp"
int main() {
    STR(s);
    Eertree<char> tree;
    auto r = tree.add_string(s);
    print(tree.distinct_palindrome());
    rep(i, 2, tree.nodes.size()) {
        print(tree.nodes[i].par() - 1, tree.nodes[i].suffix_link() - 1);
    }
    rep(i, s.size()) pr << r[i] - 1 << " \n"[i == s.size() - 1];
}
