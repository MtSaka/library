#pragma once
#include "../../template/template.hpp"

uint64_t kth_root_integer(uint64_t a, int k) {
    if (k == 1) return a;
    auto check = [&](uint64_t x) {
        uint64_t mul = 1;
        for (int j = 0; j < k; j++) {
            if (__builtin_mul_overflow(mul, x, &mul)) return false;
        }
        return mul <= a;
    };
    uint64_t ret = 0;
    for (int i = 31; i >= 0; i--) {
        if (check(ret | (1u << i))) ret |= 1u << i;
    }
    return ret;
}
/**
 * @brief Kth Root Integer
 */