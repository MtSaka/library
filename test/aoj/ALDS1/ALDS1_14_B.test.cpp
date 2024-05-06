// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
#include "../../../string/rolling-hash.hpp"
#include "../../../template/template.hpp"
int main() {
    STR(t, p);
    RollingHash rh;
    auto rh1 = rh.get_hash(t);
    auto rh2 = rh.get_hash(p);
    for (int i = 0; i + p.size() <= t.size(); i++) {
        if (rh1.get_hash(i, i + p.size()) == rh2.get_all()) print(i);
    }
}