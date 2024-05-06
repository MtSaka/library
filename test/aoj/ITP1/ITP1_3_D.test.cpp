// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D
#include "../../../math/number/factor.hpp"
#include "../../../template/template.hpp"
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for (auto& x : factor(c)) {
        ans += (a <= x && x <= b);
    }
    print(ans);
}