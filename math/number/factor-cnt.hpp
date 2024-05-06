#pragma once
#include "../../template/template.hpp"

template <typename T>
int factor_cnt(T N) {
    int ans = 1;
    for (T i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            int e = 0;
            while (N % i == 0) {
                N /= i;
                e++;
            }
            ans *= e + 1;
        }
    }
    if (N != 1) ans *= 2;
    return ans;
}
/**
 * @brief Factor Count(約数個数)
 */