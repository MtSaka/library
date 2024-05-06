// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
#include "../../../template/template.hpp"
int main() {
    long long m, n;
    cin >> m >> n;
    print(mod_pow(m, n, 1000000007));
}