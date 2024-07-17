#pragma once
#include "../../template/template.hpp"
#include "montgomery-modint.hpp"
#include "../number/primitive-root.hpp"

ll mod_sqrt(const ll& a_, const ll& p) {
    if (a_ % p == 0) return 0;
    if (p == 2) return a_ % p;
    using mint = ArbitraryModInt;
    mint::set_mod(p);
    const mint a = a_;
    if (a.pow((p - 1) / 2) != mint(1)) return -1;
    if ((p & 3) == 3) return a.pow((p + 1) / 4).get();
    ll q = p - 1;
    int m = 0;
    mint z = primitive_root(p);
    while (!(q & 1)) q >>= 1, m++;
    mint c = z.pow(q), t = a.pow(q), r = a.pow((q + 1) / 2);
    while (t != mint(1)) {
        mint pow_t = t * t;
        int m_update = 0;
        for (int j = 1; j < m; j++) {
            if (pow_t == mint(1)) {
                m_update = j;
                break;
            }
            pow_t *= pow_t;
        }
        const mint b = c.pow(1LL << (m - m_update - 1));
        m = m_update;
        c = b * b, t *= c, r *= b;
    }
    return r.get();
}
/**
 * @brief Mod Square Root(平方剰余)
 */