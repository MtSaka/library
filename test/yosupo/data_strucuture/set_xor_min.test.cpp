// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/set_xor_min
#include "../../../ds/others/binary-trie.hpp"
#include "../../../template/template.hpp"
int main() {
    BinaryTrie<int> bt;
    int q;
    sc >> q;
    rep(q) {
        int t, x;
        sc >> t >> x;
        if (t == 0) {
            if (!bt.count(x)) bt.insert(x);
        } else if (t == 1) {
            if (bt.count(x)) bt.erase(x);
        } else {
            print(bt.min_element(x));
        }
    }
}