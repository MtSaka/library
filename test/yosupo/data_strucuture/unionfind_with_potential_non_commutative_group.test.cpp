// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group
#include "../../../template/template.hpp"
#include "../../../ds/union-find/weighted-union-find.hpp"
#include "../../../math/modular/modint.hpp"
#include "../../../math/others/matrix.hpp"
using mint = ModInt<998244353>;
using Mat = Matrix<mint>;
struct Prod {
    using value_type = Mat;
    static Mat id() { return Mat::I(2); }
    static Mat op(const Mat& x, const Mat& y) { return x * y; }
    static Mat get_inv(const Mat& x) {
        Mat ret(2, 2);
        ret[0][0] = x[1][1], ret[0][1] = -x[0][1], ret[1][0] = -x[1][0], ret[1][1] = x[0][0];
        ret *= (x[0][0] * x[1][1] - x[0][1] * x[1][0]).inv();
        return ret;
    }
};
int main() {
    INT(n, q);
    WeightedUnionFind<Prod> uf(n);
    rep(q) {
        INT(t, x, y);
        if (t == 0) {
            Mat a(2, 2);
            sc >> a;
            if (!uf.merge(x, y, a).second)
                print(0);
            else
                print(1);
        } else {
            if (!uf.same(x, y))
                print(-1);
            else {
                print(uf.diff(x, y));
            }
        }
    }
}