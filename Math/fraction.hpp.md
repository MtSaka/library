---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1236.test.cpp
    title: test/yukicoder/1236.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Fraction(\u6709\u7406\u6570\u578B)"
    links: []
  bundledCode: "#line 1 \"Math/fraction.hpp\"\n/**\n * @brief Fraction(\u6709\u7406\
    \u6570\u578B)\n*/\nstruct fraction{\n  static long long gcd(long long a,long long\
    \ b){return b?gcd(b,a%b):a;}\n  long long num,den;\n  fraction():num(0),den(1){}\n\
    \  fraction(long long n):num(n),den(1){}\n  fraction(long long n,long long d):num(n),den(d){normalize();}\n\
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
    \ is, fraction& f){is>>f.num>>f.den;return is;}\n};\n"
  code: "/**\n * @brief Fraction(\u6709\u7406\u6570\u578B)\n*/\nstruct fraction{\n\
    \  static long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}\n  long\
    \ long num,den;\n  fraction():num(0),den(1){}\n  fraction(long long n):num(n),den(1){}\n\
    \  fraction(long long n,long long d):num(n),den(d){normalize();}\n  void normalize(){\n\
    \    long long g=gcd(num,den);\n    num/=g;den/=g;\n    if(den<0){num=-num;den=-den;}\n\
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
    \ is, fraction& f){is>>f.num>>f.den;return is;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/fraction.hpp
  requiredBy: []
  timestamp: '2021-12-24 23:43:49+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1236.test.cpp
documentation_of: Math/fraction.hpp
layout: document
redirect_from:
- /library/Math/fraction.hpp
- /library/Math/fraction.hpp.html
title: "Fraction(\u6709\u7406\u6570\u578B)"
---
