#pragma once
#include "../../template/template.hpp"
#include "bit-vector.hpp"

template <typename T, int LOG, typename U>
struct WaveletMatrixSum {
   private:
    size_t size;
    BitVector matrix[LOG];
    int mid[LOG];
    vector<U> sum[LOG];

   public:
    WaveletMatrixSum() {}
    WaveletMatrixSum(vector<T> v, vector<U> dat) : size(v.size()) {
        vector<int> left(size), right(size), ord(size);
        iota(ord.begin(), ord.end(), 0);
        for (int level = LOG - 1; level >= 0; level--) {
            matrix[level] = BitVector(size + 1);
            sum[level].assign(size + 1, U());
            int l = 0, r = 0;
            for (size_t i = 0; i < size; i++) {
                if ((v[ord[i]] >> level) & 1)
                    right[r++] = ord[i], matrix[level].set(i);
                else
                    left[l++] = ord[i];
            }
            mid[level] = l;
            matrix[level].build();
            swap(ord, left);
            for (int i = 0; i < r; i++) ord[l + i] = right[i];
            for (size_t i = 0; i < size; i++) {
                sum[level][i + 1] = sum[level][i] + dat[ord[i]];
            }
        }
    }
    T access(int i) const {
        T ret = 0;
        for (int level = LOG - 1; level >= 0; level--) {
            bool f = matrix[level][i];
            if (f) ret |= T(1) << level;
            i = mid[level] * f + matrix[level].rank(f, i);
        }
        return ret;
    }
    T operator[](int i) const { return access(i); }
    pair<int, int> succ(bool f, int l, int r, int level) const {
        return {matrix[level].rank(f, l) + mid[level] * f, matrix[level].rank(f, r) + mid[level] * f};
    }
    int rank(int r, const T& x) const {
        int l = 0;
        for (int level = LOG - 1; level >= 0; level--) {
            tie(l, r) = succ((x >> level) & 1, l, r, level);
        }
        return r - l;
    }
    T kth_smallest(int l, int r, int k) const {
        T ret = 0;
        for (int level = LOG - 1; level >= 0; level--) {
            int cnt = matrix[level].rank(false, r) - matrix[level].rank(false, l);
            bool f = (cnt <= k);
            if (f) {
                ret |= T(1) << level;
                k -= cnt;
            }
            tie(l, r) = succ(f, l, r, level);
        }
        return ret;
    }
    T kth_largest(int l, int r, int k) const { return kth_smallest(l, r, r - l - 1 - k); }
    int range_freq(int l, int r, T high) const {
        int ret = 0;
        for (int level = LOG - 1; level >= 0; level--) {
            bool f = (high >> level) & 1;
            if (f) ret += matrix[level].rank(false, r) - matrix[level].rank(false, l);
            tie(l, r) = succ(f, l, r, level);
        }
        return ret;
    }
    int range_freq(int l, int r, T low, T high) const { return range_freq(l, r, high) - range_freq(l, r, low); }
    int prev_val(int l, int r, T x) const {
        int cnt = range_freq(l, r, x);
        return (cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1));
    }
    int next_val(int l, int r, T x) const {
        int cnt = range_freq(l, r, x);
        return (cnt == r - l ? T(-1) : kth_smallest(l, r, cnt));
    }
    U range_sum(int l, int r, T high) const {
        U ret = 0;
        for (int level = LOG - 1; level >= 0; level--) {
            bool f = ((high >> level) & 1);
            if (f) {
                ret += sum[level][matrix[level].rank(false, r)] - sum[level][matrix[level].rank(false, l)];
            }
            tie(l, r) = succ(f, l, r, level);
        }
        return ret;
    }
    U range_sum(int l, int r, T low, T high) const { return range_sum(l, r, high) - range_sum(l, r, low); }
    pair<int, U> range(int l, int r, T high) const {
        int ret1 = 0;
        U ret2 = 0;
        for (int level = LOG - 1; level >= 0; level--) {
            bool f = (high >> level) & 1;
            if (f) {
                ret1 += matrix[level].rank(false, r) - matrix[level].rank(false, l);
                ret2 += sum[level][matrix[level].rank(false, r)] - sum[level][matrix[level].rank(false, l)];
            }
            tie(l, r) = succ(f, l, r, level);
        }
        return {ret1, ret2};
    }
    pair<int, U> range(int l, int r, T low, T high) const {
        auto [cnt_high, sum_high] = range(l, r, high);
        auto [cnt_low, sum_low] = range(l, r, low);
        return {cnt_high - cnt_low, sum_high - sum_low};
    }
};

template <typename T, int LOG, typename U>
struct CompressedWaveletMatrixSum {
   private:
    WaveletMatrixSum<int, LOG, U> w;
    vector<T> v;
    inline int get(const T& x) const { return lower_bound(v.begin(), v.end(), x) - v.begin(); }

   public:
    CompressedWaveletMatrixSum() {}
    CompressedWaveletMatrixSum(const vector<T>& x, const vector<U>& d) : v(x) {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        vector<int> t(x.size());
        for (int i = 0; i < (int)x.size(); i++) t[i] = get(x[i]);
        w = WaveletMatrixSum<int, LOG, U>(t, d);
    }
    T access(int i) const { return v[w.access(i)]; }
    T operator[](int i) const { return access(i); }
    int rank(int r, const T& x) const {
        auto idx = get(x);
        if (idx == (int)v.size() || v[idx] != x) return 0;
        return w.rank(r, idx);
    }
    T kth_smallest(int l, int r, int k) const {
        return v[w.kth_smallest(l, r, k)];
    }
    T kth_largest(int l, int r, int k) const {
        return v[w.kth_largest(l, r, k)];
    }
    int range_freq(int l, int r, T high) const {
        return w.range_freq(l, r, get(high));
    }
    int range_freq(int l, int r, T low, T high) const {
        return w.range_freq(l, r, get(low), get(high));
    }
    T prev_val(int l, int r, T high) const {
        auto ret = w.prev_val(l, r, get(high));
        return ret == -1 ? T(-1) : v[ret];
    }
    T next_val(int l, int r, T low) const {
        auto ret = w.next_val(l, r, get(low));
        return ret == -1 ? T(-1) : v[ret];
    }
    U range_sum(int l, int r, T high) const {
        return w.range_sum(l, r, get(high));
    }
    U range_sum(int l, int r, T low, T high) const {
        return w.range_sum(l, r, get(low), get(high));
    }
    pair<int, U> range(int l, int r, T high) const {
        return w.range(l, r, get(high));
    }
    pair<int, U> range(int l, int r, T low, T high) const {
        return w.range(l, r, get(low), get(high));
    }
};
/**
 * @brief Wavelet Matrixb with Rectangle Sum
 */