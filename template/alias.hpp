#pragma once
#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128_t;
using u128 = __uint128_t;
using pi = std::pair<int, int>;
using pl = std::pair<ll, ll>;
using vi = std::vector<int>;
using vl = std::vector<ll>;
using vs = std::vector<std::string>;
using vc = std::vector<char>;
using vvl = std::vector<vl>;
using vd = std::vector<double>;
using vp = std::vector<pl>;
using vb = std::vector<bool>;
template <typename T>
struct infinity {
    static constexpr T max = std::numeric_limits<T>::max();
    static constexpr T min = std::numeric_limits<T>::min();
    static constexpr T value = std::numeric_limits<T>::max() / 2;
    static constexpr T mvalue = std::numeric_limits<T>::min() / 2;
};
template <typename T>
constexpr T INF = infinity<T>::value;
constexpr ll inf = INF<ll>;
constexpr ld EPS = 1e-8;
constexpr ld PI = 3.1415926535897932384626;
constexpr int dx[8] = {-1, 0, 1, 0, 1, -1, -1, 1};
constexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};