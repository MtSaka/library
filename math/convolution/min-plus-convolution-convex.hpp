#pragma once
#include "../../template/template.hpp"

template <typename T>
vector<T> min_plus_convolution_convex(const vector<T>& a, const vector<T>& b) {
    const int n = a.size(), m = b.size();
    vector<T> da(n), db(m);
    for (int i = 1; i < n; ++i) da[i] = a[i] - a[i - 1];
    for (int i = 1; i < m; ++i) db[i] = b[i] - b[i - 1];
    static constexpr T inft = infinity<T>::max;
    da[0] = a[0] - inft;
    db[0] = b[0] - inft;
    vector<T> ds;
    merge(da.begin(), da.end(), db.begin(), db.end(), back_inserter(ds));
    vector<T> res(n + m - 1);
    T sum = ds[0];
    for (int k = 1; k < (int)ds.size(); ++k) {
        sum += ds[k];
        res[k - 1] = sum + inft + inft;
    }
    return res;
}
/**
 * @brief Min-Plus Convolution (Convex and Convex)
 */