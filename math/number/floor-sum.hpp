#pragma once

// \sum_{i=0}^{n-1} floor((a*i+b)/m)
template <typename T>
T floor_sum(T n, T m, T a, T b) {
    T ans = 0;
    if (a < 0) {
        const T a2 = a % m + m;
        ans -= n * (n - 1) / 2 * ((a2 - a) / m);
        a = a2;
    }
    if (b < 0) {
        const T b2 = b % m + m;
        ans -= n * ((b2 - b) / m);
        b = b2;
    }
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }
        T y_max = a * n + b;
        if (y_max < m) break;
        n = y_max / m;
        b = y_max % m;
        swap(m, a);
    }
    return ans;
}