---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1236.test.cpp
    title: test/yukicoder/1236.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Fraction(\u6709\u7406\u6570\u578B)"
    links: []
  bundledCode: "#line 1 \"Math/others/fraction.hpp\"\nstruct fraction{\n  static long\
    \ long gcd(long long a,long long b){return b?gcd(b,a%b):a;}\n  long long num,den;\n\
    \  fraction():num(0),den(1){}\n  fraction(long long n):num(n),den(1){}\n  fraction(long\
    \ long n,long long d):num(n),den(d){normalize();}\n  void normalize(){\n    long\
    \ long g=gcd(num,den);\n    num/=g;den/=g;\n    if(den<0){num=-num;den=-den;}\n\
    \  }\n  bool operator>(const fraction &f)const{return num*f.den>den*f.num;}\n\
    \  bool operator<(const fraction &f)const{return num*f.den<den*f.num;}\n  bool\
    \ operator>=(const fraction &f)const{return num*f.den>=den*f.num;}\n  bool operator<=(const\
    \ fraction &f)const{return num*f.den<=den*f.num;}\n  bool operator==(const fraction\
    \ &f)const{return num*f.den==den*f.num;}\n  bool operator!=(const fraction &f)const{return\
    \ num*f.den!=den*f.num;}\n  fraction operator-()const{return fraction(-num,den);}\n\
    \  fraction &operator-=(const fraction &f){num=num*f.den-den*f.num;den*=f.den;normalize();return\
    \ *this;}\n  fraction &operator+=(const fraction &f){num=num*f.den+den*f.num;den*=f.den;normalize();return\
    \ *this;}\n  fraction &operator*=(const fraction &f){num*=f.num;den*=f.den;normalize();return\
    \ *this;}\n  fraction &operator/=(const fraction &f){num*=f.den;den*=f.num;normalize();return\
    \ *this;}\n  friend fraction operator+(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)+=rhs;}\n  friend fraction operator-(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)-=rhs;}\n  friend fraction operator*(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)*=rhs;}\n  friend fraction operator/(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)/=rhs;}\n  friend ostream& operator<<(ostream& os, const fraction&\
    \ f){os<<f.num<<\"/\"<<f.den;return os;}\n  friend istream& operator>>(istream&\
    \ is, fraction& f){is>>f.num>>f.den;return is;}\n};\n/**\n * @brief Fraction(\u6709\
    \u7406\u6570\u578B)\n*/\n"
  code: "struct fraction{\n  static long long gcd(long long a,long long b){return\
    \ b?gcd(b,a%b):a;}\n  long long num,den;\n  fraction():num(0),den(1){}\n  fraction(long\
    \ long n):num(n),den(1){}\n  fraction(long long n,long long d):num(n),den(d){normalize();}\n\
    \  void normalize(){\n    long long g=gcd(num,den);\n    num/=g;den/=g;\n    if(den<0){num=-num;den=-den;}\n\
    \  }\n  bool operator>(const fraction &f)const{return num*f.den>den*f.num;}\n\
    \  bool operator<(const fraction &f)const{return num*f.den<den*f.num;}\n  bool\
    \ operator>=(const fraction &f)const{return num*f.den>=den*f.num;}\n  bool operator<=(const\
    \ fraction &f)const{return num*f.den<=den*f.num;}\n  bool operator==(const fraction\
    \ &f)const{return num*f.den==den*f.num;}\n  bool operator!=(const fraction &f)const{return\
    \ num*f.den!=den*f.num;}\n  fraction operator-()const{return fraction(-num,den);}\n\
    \  fraction &operator-=(const fraction &f){num=num*f.den-den*f.num;den*=f.den;normalize();return\
    \ *this;}\n  fraction &operator+=(const fraction &f){num=num*f.den+den*f.num;den*=f.den;normalize();return\
    \ *this;}\n  fraction &operator*=(const fraction &f){num*=f.num;den*=f.den;normalize();return\
    \ *this;}\n  fraction &operator/=(const fraction &f){num*=f.den;den*=f.num;normalize();return\
    \ *this;}\n  friend fraction operator+(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)+=rhs;}\n  friend fraction operator-(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)-=rhs;}\n  friend fraction operator*(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)*=rhs;}\n  friend fraction operator/(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)/=rhs;}\n  friend ostream& operator<<(ostream& os, const fraction&\
    \ f){os<<f.num<<\"/\"<<f.den;return os;}\n  friend istream& operator>>(istream&\
    \ is, fraction& f){is>>f.num>>f.den;return is;}\n};\n/**\n * @brief Fraction(\u6709\
    \u7406\u6570\u578B)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/others/fraction.hpp
  requiredBy: []
  timestamp: '2022-01-29 16:22:31+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1236.test.cpp
documentation_of: Math/others/fraction.hpp
layout: document
redirect_from:
- /library/Math/others/fraction.hpp
- /library/Math/others/fraction.hpp.html
title: "Fraction(\u6709\u7406\u6570\u578B)"
---
