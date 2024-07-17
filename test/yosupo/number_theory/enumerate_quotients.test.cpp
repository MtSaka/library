// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/enumerate_quotients
#include "../../../template/template.hpp"
#include "../../../math/number/quotient-ranges.hpp"
int main() {
    LL(n);
    auto quo = quotient_ranges(n);
    print(quo.size());
    vl ans;
    ans.reserve(quo.size());
    for (auto [l, r] : quo) ans.push_back(l);
    reverse(all(ans));
    print(ans);
}