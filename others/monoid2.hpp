#pragma once
#include "../template/template.hpp"
#include "monoid.hpp"

namespace Monoid {
template <typename T>
struct Product {
    using value_type = T;
    static T op(const T& x, const T& y) { return x * y; }
    static T id() { return T(1); }
    static T inv(const T& x, const T& y) { return x / y; }
    static T get_inv(const T& x) { return T(1) / x; }
};
template <typename T>
struct Composite {
    using value_type = pair<T, T>;
    static pair<T, T> op(const pair<T, T>& x, const pair<T, T>& y) { return {x.first * y.first, x.second * y.first + y.second}; }
    static pair<T, T> id() { return {T(1), T(0)}; }
    static pair<T, T> get_inv(const pair<T, T>& x) { return {T{1} / x.first, -x.second / x.first}; }
    static pair<T, T> inv(const pair<T, T>& x, const pair<T, T>& y) { return op(x, get_inv(y)); }
};
template <typename T>
struct GCD {
    using value_type = T;
    static T op(const T& x, const T& y) { return gcd(x, y); }
    static T id() { return T(0); }
};
template <typename T>
struct LCM {
    using value_type = T;
    static T op(const T& x, const T& y) { return lcm(x, y); }
    static T id() { return T(1); }
};
template <typename T>
struct AffineSum {
    using M = Sum<T>;
    using E = Composite<T>;
    using U = typename E::value_type;
    static T mul_op(const U& a, int sz, const T& b) { return a.first * b + a.second * sz; }
};
}  // namespace Monoid