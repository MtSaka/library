#pragma once
#include "../../template/template.hpp"
#include "bit-vector.hpp"

template <typename T, int LOG>
struct WaveletMatrix {
   private:
    size_t size;
    BitVector matrix[LOG];
    int mid[LOG];

   public:
    WaveletMatrix() {}
    WaveletMatrix(vector<T> v) : size(v.size()) {
        vector<T> left(size), right(size);
        for (int level = LOG - 1; level >= 0; level--) {
            matrix[level] = BitVector(size + 1);
            int l = 0, r = 0;
            for (size_t i = 0; i < size; i++) {
                if ((v[i] >> level) & 1)
                    right[r++] = v[i], matrix[level].set(i);
                else
                    left[l++] = v[i];
            }
            mid[level] = l;
            matrix[level].build();
            swap(v, left);
            for (int i = 0; i < r; i++) v[l + i] = right[i];
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
};

template <typename T, int LOG>
struct CompressedWaveletMatrix {
   private:
    WaveletMatrix<int, LOG> w;
    vector<T> v;
    int get(const T& x) const { return lower_bound(v.begin(), v.end(), x) - v.begin(); }

   public:
    CompressedWaveletMatrix() {}
    CompressedWaveletMatrix(const vector<T>& x) : v(x) {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        vector<int> t(x.size());
        for (int i = 0; i < (int)x.size(); i++) t[i] = get(x[i]);
        w = WaveletMatrix<int, LOG>(t);
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
};
/**
 * @brief Wavelet Matrix
 */