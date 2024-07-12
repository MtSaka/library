#pragma once
#include "../../template/template.hpp"
#include "modint.hpp"

template <typename T>
struct MontgomeryReduction {
    static_assert(is_integral<T>::value, "template argument must be integral");
    static_assert(is_unsigned<T>::value, "template argument must be unsigned");

   private:
    using large_t = typename double_size_uint<T>::type;
    static constexpr int lg = numeric_limits<T>::digits;
    T mod;
    T r;
    T r2;
    T minv;
    T calc_inv() const {
        T t = 0, res = 0;
        rep(i, lg) {
            if (~t & 1) {
                t += mod;
                res += static_cast<T>(1) << i;
            }
            t >>= 1;
        }
        return res;
    }

   public:
    MontgomeryReduction(T x) { set_mod(x); }
    static constexpr int get_lg() { return lg; }
    void set_mod(T x) {
        assert(x > 0);
        assert(x & 1);
        assert(x <= INF<T>);
        mod = x;
        r = (-static_cast<T>(mod)) % mod;
        r2 = (-static_cast<large_t>(mod)) % mod;
        minv = calc_inv();
    }
    inline T get_r() const { return r; }
    inline T get_mod() const { return mod; }
    T reduce(large_t x) const {
        large_t tmp = (x + static_cast<large_t>(static_cast<T>(x) * minv) * mod) >> lg;
        return tmp >= mod ? tmp - mod : tmp;
    }
    T transform(large_t x) const { return reduce(x * r2); }
};
template <typename T, int id>
struct MontgomeryModInt : internal::modint_base {
    static_assert(is_integral<T>::value, "template argument must be integral");
    static_assert(is_unsigned<T>::value, "template argument must be unsigned");

   private:
    using large_t = typename double_size_uint<T>::type;
    T val;
    static MontgomeryReduction<T> reduction;

   public:
    MontgomeryModInt() : val(0) {}
    template <typename U, typename enable_if<is_integral<U>::value && is_unsigned<U>::value>::type* = nullptr>
    MontgomeryModInt(U x) : val(reduction.transform(x < (static_cast<large_t>(reduction.get_mod()) << reduction.get_lg()) ? static_cast<large_t>(x) : static_cast<large_t>(x % reduction.get_mod()))) {}
    template <typename U, typename enable_if<is_integral<U>::value && is_signed<U>::value>::type* = nullptr>
    MontgomeryModInt(U x) : MontgomeryModInt(static_cast<typename std::make_unsigned<U>::type>(x < 0 ? -x : x)) {
        if (x < 0 && val) val = reduction.get_mod() - val;
    }
    T get() const { return reduction.reduce(val); }
    static T get_mod() { return reduction.get_mod(); }
    static void set_mod(T x) { reduction.set_mod(x); }
    MontgomeryModInt& operator++() {
        val += reduction.get_r();
        if (val >= reduction.get_mod()) val -= reduction.get_mod();
        return *this;
    }
    MontgomeryModInt operator++(int) {
        MontgomeryModInt res = *this;
        ++*this;
        return res;
    }
    MontgomeryModInt& operator--() {
        if (val < reduction.get_r()) val += reduction.get_mod();
        val -= reduction.get_r();
        return *this;
    }
    MontgomeryModInt operator--(int) {
        MontgomeryModInt res = *this;
        --*this;
        return res;
    }
    MontgomeryModInt& operator+=(const MontgomeryModInt& r) {
        val += r.val;
        if (val >= reduction.get_mod()) val -= reduction.get_mod();
        return *this;
    }
    MontgomeryModInt& operator-=(const MontgomeryModInt& r) {
        if (val < r.val) val += reduction.get_mod();
        val -= r.val;
        return *this;
    }
    MontgomeryModInt& operator*=(const MontgomeryModInt& r) {
        val = reduction.reduce(static_cast<large_t>(val) * r.val);
        return *this;
    }
    MontgomeryModInt pow(ull n) const {
        MontgomeryModInt res = 1, tmp = *this;
        while (n) {
            if (n & 1) res *= tmp;
            tmp *= tmp;
            n >>= 1;
        }
        return res;
    }
    MontgomeryModInt inv() const { return pow(reduction.get_mod() - 2); }
    MontgomeryModInt& operator/=(const MontgomeryModInt& r) { return *this *= r.inv(); }
    friend MontgomeryModInt operator+(const MontgomeryModInt& l, const MontgomeryModInt& r) { return MontgomeryModInt(l) += r; }
    friend MontgomeryModInt operator-(const MontgomeryModInt& l, const MontgomeryModInt& r) { return MontgomeryModInt(l) -= r; }
    friend MontgomeryModInt operator*(const MontgomeryModInt& l, const MontgomeryModInt& r) { return MontgomeryModInt(l) *= r; }
    friend MontgomeryModInt operator/(const MontgomeryModInt& l, const MontgomeryModInt& r) { return MontgomeryModInt(l) /= r; }
    friend bool operator==(const MontgomeryModInt& l, const MontgomeryModInt& r) { return l.val == r.val; }
    friend bool operator!=(const MontgomeryModInt& l, const MontgomeryModInt& r) { return l.val != r.val; }
    template <typename Sc>
    void scan(Sc& a) {
        ll x;
        a.scan(x);
        *this = x;
    }
    template <typename Pr>
    void print(Pr& a) const {
        a.print(get());
    }
    template <typename Pr>
    void debug(Pr& a) const {
        a.print(get());
    }
};
template <typename T, int id>
MontgomeryReduction<T>
    MontgomeryModInt<T, id>::reduction = MontgomeryReduction<T>(998244353);
using ArbitraryModInt = MontgomeryModInt<unsigned int, -1>;
/**
 * @brief MontgomeryModInt(モンゴメリ乗算)
 */