#pragma once
#include "../../template/template.hpp"

template <typename T>
struct Matrix {
   private:
    vector<vector<T>> data;

   public:
    Matrix() {}
    Matrix(int n, int m) : data(n, vector<T>(m, T())) {}
    Matrix(int n) : data(n, vector<T>(n, T())){};
    Matrix(const vector<vector<T>>& a) : data(a) {}
    size_t height() const { return data.size(); }
    size_t width() const { return (data.size() ? data[0].size() : 0); }
    inline const vector<T>& operator[](int k) const { return data[k]; }
    inline vector<T>& operator[](int k) { return data[k]; }
    static Matrix I(int n) {
        Matrix mat(n);
        for (int i = 0; i < n; i++) mat[i][i] = 1;
        return mat;
    }
    Matrix& operator+=(const Matrix& r) {
        const int n = height(), m = width();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) (*this)[i][j] += r[i][j];
        return *this;
    }
    Matrix& operator-=(const Matrix& r) {
        const int n = height(), m = width();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) (*this)[i][j] -= r[i][j];
        return *this;
    }
    Matrix& operator*=(const Matrix& r) {
        const int n = height(), m = r.width(), p = width();
        vector<vector<T>> res(n, vector<T>(m, T()));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < p; k++) res[i][j] += (*this)[i][k] * r[k][j];
        data.swap(res);
        return *this;
    }
    Matrix pow(long long k) const {
        Matrix res = Matrix::I(height());
        Matrix tmp = *this;
        while (k > 0) {
            if (k & 1) res *= tmp;
            tmp *= tmp;
            k >>= 1LL;
        }
        return res;
    }
    friend Matrix operator+(const Matrix& l, const Matrix& r) { return Matrix(l) += r; }
    friend Matrix operator-(const Matrix& l, const Matrix& r) { return Matrix(l) -= r; }
    friend Matrix operator*(const Matrix& l, const Matrix& r) { return Matrix(l) *= r; }
    T determinant() const {
        Matrix b(*this);
        const int n = height();
        if (n == 0) return 1;
        T res = 1;
        rep(i, n) {
            if (b.data[i][i] == T(0)) {
                rep(j, i + 1, n) {
                    if (b.data[j][i] != 0) {
                        swap(b.data[i], b.data[j]);
                        res = -res;
                        break;
                    }
                }
            }
            if (b.data[i][i] == T(0)) return T(0);
            {
                const T s = b.data[i][i];
                res *= s;
                const T invs = T(1) / s;
                rep(j, n) b.data[i][j] *= invs;
            }
            rep(j, i + 1, n) {
                const T s = b.data[j][i];
                rep(k, n) b.data[j][k] -= b.data[i][k] * s;
            }
        }
        rep(i, n) res *= b.data[i][i];
        return res;
    }
    template <typename Sc>
    void scan(Sc& a) {
        for (int i = 0; i < height(); i++)
            for (int j = 0; j < width(); j++) a.scan((*this)[i][j]);
    }
    template <typename Pr>
    void print(Pr& pr) const {
        pr.print(data);
    }
    template <typename Pr>
    void debug(Pr& pr) const {
        pr.print(data);
    }
};
/**
 * @brief Matrix(行列)
 */