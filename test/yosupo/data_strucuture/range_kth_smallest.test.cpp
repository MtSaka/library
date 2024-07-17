// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_kth_smallest
#include "../../../ds/wavelet/wavelet-matrix.hpp"
#include "../../../template/template.hpp"
int main() {
    int n, q;
    sc >> n >> q;
    vi a(n);
    sc >> a;
    CompressedWaveletMatrix<int, 18> w(a);
    rep(q) {
        int l, r, k;
        sc >> l >> r >> k;
        print(w.kth_smallest(l, r, k));
    }
}