// competitive-verifier: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D
#include "../../../math/number/divisor.hpp"
#include "../../../template/template.hpp"
int main() {
    int a, b, c;
    sc >> a >> b >> c;
    int ans = 0;
    for (auto& x : divisor(c)) {
        ans += (a <= x && x <= b);
    }
    print(ans);
}