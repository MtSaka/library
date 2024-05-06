#pragma once
#include "../../template/template.hpp"

vector<long long> factor(long long N) {
    vector<long long> ans;
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            ans.push_back(i);
            if (i * i != N) ans.push_back(N / i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
/**
 * @brief Factor Enumeration(約数列挙)
 */