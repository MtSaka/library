#pragma once
#include "../../template/template.hpp"

ull kth_root_integer(ull a, int k) {
    if (a == 0 || a == 1 || k == 1) return a;
    if (k >= 64) return 1;
    if (k == 2) return sqrtl(a);
    auto check = [&](ull x) {
        ull mul = 1;
        int now = k;
        for (; now;) {
            if (now & 1) {
                if (__builtin_mul_overflow(mul, x, &mul)) return false;
            }
            if (now >>= 1) {
                if (__builtin_mul_overflow(x, x, &x)) return false;
            }
        }
        return mul <= a;
    };
    ull ret = 0;
    for (int i = 64 / k; i >= 0; i--) {
        if (check(ret | (1u << i))) ret |= 1u << i;
    }
    return ret;
}
/**
 * @brief Kth Root Integer
 */