#pragma once
#include "../../template/template.hpp"

struct Rational {
    static long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
    long long num, den;
    Rational() : num(0), den(1) {}
    Rational(long long n) : num(n), den(1) {}
    Rational(long long n, long long d) : num(n), den(d) { normalize(); }
    void normalize() {
        long long g = gcd(num, den);
        num /= g;
        den /= g;
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }
    bool operator>(const Rational& f) const { return num * f.den > den * f.num; }
    bool operator<(const Rational& f) const { return num * f.den < den * f.num; }
    bool operator>=(const Rational& f) const { return num * f.den >= den * f.num; }
    bool operator<=(const Rational& f) const { return num * f.den <= den * f.num; }
    bool operator==(const Rational& f) const { return num * f.den == den * f.num; }
    bool operator!=(const Rational& f) const { return num * f.den != den * f.num; }
    Rational operator-() const { return Rational(-num, den); }
    Rational& operator-=(const Rational& f) {
        num = num * f.den - den * f.num;
        den *= f.den;
        normalize();
        return *this;
    }
    Rational& operator+=(const Rational& f) {
        num = num * f.den + den * f.num;
        den *= f.den;
        normalize();
        return *this;
    }
    Rational& operator*=(const Rational& f) {
        num *= f.num;
        den *= f.den;
        normalize();
        return *this;
    }
    Rational& operator/=(const Rational& f) {
        num *= f.den;
        den *= f.num;
        normalize();
        return *this;
    }
    friend Rational operator+(const Rational& lhs, const Rational& rhs) { return Rational(lhs) += rhs; }
    friend Rational operator-(const Rational& lhs, const Rational& rhs) { return Rational(lhs) -= rhs; }
    friend Rational operator*(const Rational& lhs, const Rational& rhs) { return Rational(lhs) *= rhs; }
    friend Rational operator/(const Rational& lhs, const Rational& rhs) { return Rational(lhs) /= rhs; }
    template<typename Sc>
    void scan(Sc& a) {
        a.scan(this->num);
        a.scan(this->den);
    }
    template<typename Pr>
    void print(Pr& a) const {
        a.print(this->num);
        a.print("/");
        a.print(this->den);
    }
    template<typename Pr>
    void debug(Pr& a) const {
        a.print(this->num);
        a.print("/");
        a.print(this->den);
    }
};
/**
 * @brief Fraction(有理数型)
 */