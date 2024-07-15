// competitive-verifer: https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence
#include "../../../template/template.hpp"
#include "../../../math/fps/multipoint-evaluation-geometric.hpp"
using mint = ModInt<998244353>;
using fps = FormalPowerSeries<mint>;
int main() {
    LL(n, m);
    mint a, r;
    sc >> a >> r;
    fps f(n);
    sc >> f;
    print(multipoint_evaluation_geometric(f, a, r, m));
}