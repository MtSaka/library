// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sharp_p_subset_sum
#include "../../../math/fps/subset-sum.hpp"
#include "../../../template/template.hpp"
int main() {
    int n, t;
    sc >> n >> t;
    vector<ModInt<998244353>> cnt(t + 1);
    while (n--) {
        int s;
        sc >> s;
        cnt[s] += 1;
    }
    auto ans = subset_sum(cnt);
    for (int i = 1; i <= t; i++) pr << ans[i] << " \n"[i == t];
}