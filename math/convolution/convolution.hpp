#pragma once
#include "../../template/template.hpp"
#include "../modular/modint.hpp"
#include "../number/miller-rabin.hpp"
#include "../number/primitive-root.hpp"

template <unsigned int p>
struct NthRoot {
   private:
    static constexpr unsigned int lg = msb((p - 1) & (1 - p));
    array<unsigned int, lg + 1> root, inv_root;

   public:
    constexpr NthRoot() : root{}, inv_root{} {
        root[lg] = mod_pow(constexpr_primitive_root<p>(), (p - 1) >> lg, p);
        inv_root[lg] = mod_pow(root[lg], p - 2, p);
        rrep(i, lg) {
            root[i] = (ull)root[i + 1] * root[i + 1] % p;
            inv_root[i] = (ull)inv_root[i + 1] * inv_root[i + 1] % p;
        }
    }
    static constexpr unsigned int get_lg() { return lg; }
    constexpr unsigned int get(int n) const { return root[n]; }
    constexpr unsigned int inv(int n) const { return inv_root[n]; }
};
template <unsigned int p>
constexpr NthRoot<p> nth_root;
template <typename T, enable_if_t<is_modint<T>::value>* = nullptr>
void ntt(vector<T>& a) {
    constexpr unsigned int p = T::get_mod();
    const int sz = a.size();
    assert((unsigned int)sz <= ((1 - p) & (p - 1)));
    assert((sz & (sz - 1)) == 0);
    const int lg = msb(sz);
    static constexpr T im = nth_root<p>.get(2);
    for (int i = lg; i >= 1; i -= 2) {
        if (i == 1) {
            const T w = nth_root<p>.get(i);
            for (int j = 0; j < sz; j += (1u << 1)) {
                T z = 1;
                for (int k = j; k < j + (1u << (i - 1)); ++k) {
                    const T x = a[k], y = a[k + (1u << (i - 1))];
                    a[k] = x + y, a[k + (1u << (i - 1))] = (x - y) * z;
                    z *= w;
                }
            }
        } else {
            const T w = nth_root<p>.get(i);
            const int offset = 1 << (i - 2);
            for (int j = 0; j < sz; j += (1 << i)) {
                T z = 1;
                for (int k = j; k < j + (1 << (i - 2)); ++k) {
                    const T z2 = z * z, z3 = z2 * z;
                    const T c0 = a[k], c1 = a[k + offset], c2 = a[k + offset * 2], c3 = a[k + offset * 3];
                    const T c0c2 = c0 + c2, c0mc2 = c0 - c2, c1c3 = c1 + c3, c1mc3im = (c1 - c3) * im;
                    a[k] = c0c2 + c1c3;
                    a[k + offset] = (c0c2 - c1c3) * z2;
                    a[k + offset * 2] = (c0mc2 + c1mc3im) * z;
                    a[k + offset * 3] = (c0mc2 - c1mc3im) * z3;
                    z *= w;
                }
            }
        }
    } /*
     rep(i, sz) {
         const int j = reverse(i, lg);
         if (i < j) swap(a[i], a[j]);
     }
     rep(i, lg) {
         const T w = nth_root<p>.get(i + 1);
         rep(j, 0, sz, 1 << (i + 1)) {
             T z = 1;
             rep(k, 1 << i) {
                 T x = a[j + k], y = a[j + k + (1 << i)] * z;
                 a[j + k] = x + y, a[j + k + (1 << i)] = x - y;
                 z *= w;
             }
         }
     }*/
}
template <typename T, enable_if_t<is_modint<T>::value>* = nullptr>
void intt(vector<T>& a, const bool& f = true) {
    constexpr unsigned int p = T::get_mod();
    const int sz = a.size();
    assert((unsigned int)sz <= ((1 - p) & (p - 1)));
    assert((sz & (sz - 1)) == 0);
    const int lg = msb(sz);
    static constexpr T im = nth_root<p>.inv(2);
    for (int i = 2 - (lg & 1); i <= lg; i += 2) {
        if (i == 1) {
            const T w = nth_root<p>.inv(i);
            for (int j = 0; j < sz; j += (1u << i)) {
                T z = 1;
                for (int k = j; k < j + (1u << (i - 1)); ++k) {
                    const T x = a[k], y = a[k + (1u << (i - 1))] * z;
                    a[k] = x + y, a[k + (1u << (i - 1))] = x - y;
                    z *= w;
                }
            }
        } else {
            const T w = nth_root<p>.inv(i);
            const int offset = 1 << (i - 2);
            for (int j = 0; j < sz; j += (1u << i)) {
                T z = 1;
                for (int k = j; k < j + (1u << (i - 2)); ++k) {
                    const T z2 = z * z, z3 = z2 * z;
                    const T c0 = a[k], c1 = a[k + offset] * z2, c2 = a[k + offset * 2] * z, c3 = a[k + offset * 3] * z3;
                    const T c0c1 = c0 + c1, c0mc1 = c0 - c1, c2c3 = c2 + c3, c2mc3im = (c2 - c3) * im;
                    a[k] = c0c1 + c2c3;
                    a[k + offset] = c0mc1 + c2mc3im;
                    a[k + offset * 2] = c0c1 - c2c3;
                    a[k + offset * 3] = c0mc1 - c2mc3im;
                    z *= w;
                }
            }
        }
    }
    /*
    rep(i, sz) {
        const int j = reverse(i, lg);
        if (i < j) swap(a[i], a[j]);
    }
    rep(i, lg) {
        const T w = nth_root<p>.inv(i + 1);
        rep(j, 0, sz, 1 << (i + 1)) {
            T z = 1;
            rep(k, 1 << i) {
                T x = a[j + k], y = a[j + k + (1 << i)] * z;
                a[j + k] = x + y, a[j + k + (1 << i)] = x - y;
                z *= w;
            }
        }
    }*/
    if (f) {
        const T inv_sz = T(1) / sz;
        for (auto& x : a) x *= inv_sz;
    }
}
template <typename T>
vector<T> convolution_naive(const vector<T>& a, const vector<T>& b) {
    const int sz1 = a.size(), sz2 = b.size();
    vector<T> c(sz1 + sz2 - 1);
    rep(i, sz1) rep(j, sz2) c[i + j] += a[i] * b[j];
    return c;
}
template <unsigned int p>
vector<ModInt<p>> convolution_for_any_mod(const vector<ModInt<p>>& a, const vector<ModInt<p>>& b);
template <typename T, enable_if_t<is_modint<T>::value>* = nullptr>
vector<T> convole(vector<T> a, vector<T> b) {
    constexpr unsigned int p = T::get_mod();
    const int n = a.size() + b.size() - 1;
    const int lg = ceil_log2(n);
    const int sz = 1 << lg;
    a.resize(sz), b.resize(sz);
    ntt(a), ntt(b);
    rep(i, sz) a[i] *= b[i];
    intt(a);
    a.resize(n);
    return a;
}
template <typename T, enable_if_t<is_modint<T>::value>* = nullptr>
vector<T> convolution(const vector<T>& a, const vector<T>& b) {
    constexpr unsigned int p = T::get_mod();
    const unsigned int sz1 = a.size(), sz2 = b.size();
    if (sz1 == 0 || sz2 == 0) return {};
    if (sz1 <= 64 || sz2 <= 64) return convolution_naive(a, b);
    if constexpr (((p - 1) & (1 - p)) >= 128) {
        if (sz1 + sz2 - 1 <= ((p - 1) & (1 - p))) return convole(a, b);
    }
    return convolution_for_any_mod(a, b);
}

template <unsigned int p = 998244353>
vector<ll> convolution(const vector<ll>& a, const vector<ll>& b) {
    const int sz1 = a.size(), sz2 = b.size();
    vector<ModInt<p>> a1(sz1), b1(sz2);
    rep(i, sz1) a1[i] = a[i];
    rep(i, sz2) b1[i] = b[i];
    auto c1 = convolution(a1, b1);
    vector<ll> c(sz1 + sz2 - 1);
    rep(i, sz1 + sz2 - 1) c[i] = c1[i].get();
    return c;
}
template <unsigned int p>
vector<ModInt<p>> convolution_for_any_mod(const vector<ModInt<p>>& a, const vector<ModInt<p>>& b) {
    const int sz1 = a.size(), sz2 = b.size();
    assert(sz1 + sz2 - 1 <= (1 << 26));
    vector<ll> a1(sz1), b1(sz2);
    rep(i, sz1) a1[i] = a[i].get();
    rep(i, sz2) b1[i] = b[i].get();
    static constexpr ull MOD1 = 469762049;
    static constexpr ull MOD2 = 1811939329;
    static constexpr ull MOD3 = 2013265921;
    static constexpr ull INV1_2 = mod_pow(MOD1, MOD2 - 2, MOD2);
    static constexpr ull INV1_3 = mod_pow(MOD1, MOD3 - 2, MOD3);
    static constexpr ull INV2_3 = mod_pow(MOD2, MOD3 - 2, MOD3);
    auto c1 = convolution<MOD1>(a1, b1);
    auto c2 = convolution<MOD2>(a1, b1);
    auto c3 = convolution<MOD3>(a1, b1);
    vector<ModInt<p>> c(sz1 + sz2 - 1);
    rep(i, sz1 + sz2 - 1) {
        ull x1 = c1[i];
        ull x2 = (c2[i] - x1 + MOD2) * INV1_2 % MOD2;
        ull x3 = ((c3[i] - x1 + MOD3) * INV1_3 % MOD3 - x2 + MOD3) * INV2_3 % MOD3;
        c[i] = ModInt<p>(x1 + (x2 + x3 * MOD2) % p * MOD1);
    }
    return c;
}
/**
 * @brief Convolution(畳み込み)
 */