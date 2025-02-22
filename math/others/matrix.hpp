#pragma once
#include "../../template/template.hpp"

template <typename T>
struct Matrix : vector<vector<T>> {
   private:
    using Base = vector<vector<T>>;

   public:
    Matrix() {}
    Matrix(int n, int m) : Base(n, vector<T>(m, T())) {}
    Matrix(int n) : Base(n, vector<T>(n, T())) {};
    Matrix(const vector<vector<T>>& a) : Base(a) {}
    size_t height() const { return this->size(); }
    size_t width() const { return (this->size() ? (*this)[0].size() : 0); }
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
        return *this = move(res);
    }
    Matrix& operator*=(const T& r) {
        const int n = height(), m = width();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) (*this)[i][j] *= r;
        return *this;
    }
    Matrix& operator^=(long long k) {
        Matrix res = Matrix::I(height());
        Matrix tmp = *this;
        while (k > 0) {
            if (k & 1) res *= tmp;
            tmp *= tmp;
            k >>= 1LL;
        }
        return *this = move(res);
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
    friend Matrix operator*(const Matrix& l, const T& r) { return Matrix(l) *= r; }
    T determinant() const {
        Matrix b(*this);
        const int n = height();
        if (n == 0) return 1;
        T res = 1;
        rep(i, n) {
            if (b[i][i] == T(0)) {
                rep(j, i + 1, n) {
                    if (b[j][i] != 0) {
                        swap(b[i], b[j]);
                        res = -res;
                        break;
                    }
                }
            }
            if (b[i][i] == T(0)) return T(0);
            {
                const T s = b[i][i];
                res *= s;
                const T invs = T(1) / s;
                rep(j, n) b[i][j] *= invs;
            }
            rep(j, i + 1, n) {
                const T s = b[j][i];
                rep(k, n) b[j][k] -= b[i][k] * s;
            }
        }
        rep(i, n) res *= b[i][i];
        return res;
    }
};
/**
 * @brief Matrix(行列)
 */