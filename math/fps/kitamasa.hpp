#include "fps.hpp"
template <typename T>
T bostan_mori(long long n, FormalPowerSeries<T> p, FormalPowerSeries<T> q) {
    while (n) {
        auto tmp = q;
        for (int i = 1; i < (int)tmp.size(); i += 2) tmp[i] = -tmp[i];
        p *= tmp, q *= tmp;
        for (int i = (n & 1LL); i < (int)p.size(); i += 2) p[i >> 1] = p[i];
        p.resize(((int)p.size() + 1 - (n & 1LL)) / 2);
        for (int i = 0; i < (int)q.size(); i += 2) q[i >> 1] = q[i];
        q.resize(((int)q.size() + 1) / 2);
        n >>= 1;
    }
    return p[0] / q[0];
}
template <typename T>
T kitamasa(long long n, FormalPowerSeries<T> c, const FormalPowerSeries<T>& a) {
    for (auto& i : c) i = -i;
    c.insert(c.begin(), 1);
    if (n < (int)a.size()) return a[n];
    auto p = a * c;
    p.resize(c.size() - 1);
    return bostan_mori(n, p, c);
}