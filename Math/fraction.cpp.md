---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/fraction.cpp\"\nstruct fraction{\n  static long long\
    \ gcd(long long a,long long b){return b?gcd(b,a%b):a;}\n  long long num,den;\n\
    \  fraction():num(0),den(1){}\n  fraction(long long n):num(n),den(1){}\n  fraction(long\
    \ long n,long long d):num(n),den(d){\n    long long g=gcd(n,d);\n    num/=g;den/=g;\n\
    \    if(den<0){num=-num;den=-den;}\n  }\n  bool operator>(const fraction &f)const{return\
    \ num*f.den>den*f.num;}\n  bool operator<(const fraction &f)const{return num*f.den<den*f.num;}\n\
    \  bool operator>=(const fraction &f)const{return num*f.den>=den*f.num;}\n  bool\
    \ operator<=(const fraction &f)const{return num*f.den<=den*f.num;}\n  bool operator==(const\
    \ fraction &f)const{return num*f.den==den*f.num;}\n  bool operator!=(const fraction\
    \ &f)const{return num*f.den!=den*f.num;}\n  fraction operator-()const{return fraction(-num,den);}\n\
    \  fraction &operator-=(const fraction &f){num=num*f.den-den*f.num;den*=f.den;return\
    \ *this;}\n  fraction &operator+=(const fraction &f){num=num*f.den+den*f.num;den*=f.den;return\
    \ *this;}\n  fraction &operator*=(const fraction &f){num*=f.num;den*=f.den;return\
    \ *this;}\n  fraction &operator/=(const fraction &f){num*=f.den;den*=f.num;return\
    \ *this;}\n  friend fraction operator+(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)+=rhs;}\n  friend fraction operator-(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)-=rhs;}\n  friend fraction operator*(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)*=rhs;}\n  friend fraction operator/(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)/=rhs;}\n  friend ostream& operator<<(ostream& os, const fraction&\
    \ f){os<<f.num<<\"/\"<<f.den;return os;}\n  friend istream& operator>>(istream&\
    \ is, fraction& f){is>>f.num>>f.den;return is;}\n};\n"
  code: "struct fraction{\n  static long long gcd(long long a,long long b){return\
    \ b?gcd(b,a%b):a;}\n  long long num,den;\n  fraction():num(0),den(1){}\n  fraction(long\
    \ long n):num(n),den(1){}\n  fraction(long long n,long long d):num(n),den(d){\n\
    \    long long g=gcd(n,d);\n    num/=g;den/=g;\n    if(den<0){num=-num;den=-den;}\n\
    \  }\n  bool operator>(const fraction &f)const{return num*f.den>den*f.num;}\n\
    \  bool operator<(const fraction &f)const{return num*f.den<den*f.num;}\n  bool\
    \ operator>=(const fraction &f)const{return num*f.den>=den*f.num;}\n  bool operator<=(const\
    \ fraction &f)const{return num*f.den<=den*f.num;}\n  bool operator==(const fraction\
    \ &f)const{return num*f.den==den*f.num;}\n  bool operator!=(const fraction &f)const{return\
    \ num*f.den!=den*f.num;}\n  fraction operator-()const{return fraction(-num,den);}\n\
    \  fraction &operator-=(const fraction &f){num=num*f.den-den*f.num;den*=f.den;return\
    \ *this;}\n  fraction &operator+=(const fraction &f){num=num*f.den+den*f.num;den*=f.den;return\
    \ *this;}\n  fraction &operator*=(const fraction &f){num*=f.num;den*=f.den;return\
    \ *this;}\n  fraction &operator/=(const fraction &f){num*=f.den;den*=f.num;return\
    \ *this;}\n  friend fraction operator+(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)+=rhs;}\n  friend fraction operator-(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)-=rhs;}\n  friend fraction operator*(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)*=rhs;}\n  friend fraction operator/(const fraction&lhs,const fraction&rhs){return\
    \ fraction(lhs)/=rhs;}\n  friend ostream& operator<<(ostream& os, const fraction&\
    \ f){os<<f.num<<\"/\"<<f.den;return os;}\n  friend istream& operator>>(istream&\
    \ is, fraction& f){is>>f.num>>f.den;return is;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/fraction.cpp
  requiredBy: []
  timestamp: '2021-12-22 16:52:59+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/fraction.cpp
layout: document
redirect_from:
- /library/Math/fraction.cpp
- /library/Math/fraction.cpp.html
title: Math/fraction.cpp
---
