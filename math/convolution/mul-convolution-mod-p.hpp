#include "../number/primitive-root.hpp"
#include "convolution.hpp"

template <typename T>
vector<T> multiplicative_convolution_mod_p(int p, const vector<T>& a, const vector<T>& b) {
    const int r = primitive_root(p);
    vector<int> exp_mod_p(p - 1), log_mod_p(p);
    exp_mod_p[0] = 1;
    rep(i, p - 2) exp_mod_p[i + 1] = (ll)exp_mod_p[i] * r % p;
    rep(i, p - 1) log_mod_p[exp_mod_p[i]] = i;
    vector<T> fa(p - 1), fb(p - 1);
    rep(i, p - 1) fa[i] = a[exp_mod_p[i]], fb[i] = b[exp_mod_p[i]];
    auto fc = convolution(fa, fb);
    rep(i, p - 1, fc.size()) fc[i - (p - 1)] += fc[i];
    vector<T> c(p);
    rep(i, 1, p) c[i] = fc[log_mod_p[i]];
    const T suma = accumulate(all(a), T()), sumb = accumulate(all(b), T());
    c[0] = suma * b[0] + sumb * a[0] - a[0] * b[0];
    return c;
}
/**
 * @brief Convolution on the Multiplicative Monoid of Z/pZ
 */