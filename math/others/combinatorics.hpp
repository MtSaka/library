#pragma once
#include "../../template/template.hpp"
#include "../modular/modint.hpp"

template <typename T>
struct Combinatorics {
   private:
    static vector<T> dat, idat;
    inline static void extend(int sz) {
        if (dat.size() == 0) dat = vector<T>(2, 1), idat = vector<T>(2, 1);
        if ((int)dat.size() < sz + 1) {
            int pre_sz = dat.size();
            dat.resize(sz + 1, 1);
            idat.resize(sz + 1, 1);
            for (int i = pre_sz; i <= sz; i++) dat[i] = dat[i - 1] * i;
            idat[sz] = T(1) / dat[sz];
            for (int i = sz - 1; i >= pre_sz; i--) idat[i] = idat[i + 1] * (i + 1);
        }
    }

   public:
    Combinatorics(int sz = 0) { extend(sz); }
    static inline T fac(ll n) {
        if (n < 0) return T();
        extend(n);
        return dat[n];
    }
    static inline T finv(ll n) {
        if (n < 0) return T();
        extend(n);
        return idat[n];
    }
    static T com(ll n, ll k) {
        if (k < 0 || n < k) return T();
        return fac(n) * finv(k) * finv(n - k);
    }
    static T hom(ll n, ll k) {
        if (n < 0 || k < 0) return T();
        return k == 0 ? 1 : com(n + k - 1, k);
    }
    static T per(ll n, ll k) {
        if (k < 0 || n < k) return T();
        return fac(n) * finv(n - k);
    }
};
template <typename T>
vector<T> Combinatorics<T>::dat = vector<T>(2, 1);
template <typename T>
vector<T> Combinatorics<T>::idat = vector<T>(2, 1);
template <long long p>
struct COMB {
   private:
    static vector<vector<ModInt<p>>> comb;
    static void init() {
        if (!comb.empty()) return;
        comb.assign(p, vector<ModInt<p>>(p));
        comb[0][0] = 1;
        for (int i = 1; i < p; i++) {
            comb[i][0] = 1;
            for (int j = i; j > 0; j--) comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

   public:
    COMB() {
        init();
    }
    ModInt<p> com(int n, int k) {
        init();
        ModInt<p> ret = 1;
        while (n > 0 || k > 0) {
            int ni = n % p, ki = k % p;
            ret *= comb[ni][ki];
            n /= p;
            k /= p;
        }
        return ret;
    }
};
template <long long p>
vector<vector<ModInt<p>>> COMB<p>::comb = vector<vector<ModInt<p>>>();
/**
 * @brief Combinatorics(組み合わせ)
 */