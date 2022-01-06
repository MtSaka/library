---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Math/combinatorics.hpp
    title: "Combinatorics(\u7D44\u307F\u5408\u308F\u305B)"
  - icon: ':question:'
    path: Math/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Lagrange Polynomial(\u591A\u9805\u5F0F\u88DC\u9593)"
    links: []
  bundledCode: "#line 1 \"Math/lagrange.hpp\"\n/**\n * @brief Lagrange Polynomial(\u591A\
    \u9805\u5F0F\u88DC\u9593)\n*/\n#line 1 \"Math/combinatorics.hpp\"\n/**\n * @brief\
    \ Combinatorics(\u7D44\u307F\u5408\u308F\u305B)\n*/\n#line 1 \"Math/modint.hpp\"\
    \n/**\n * @brief modint\n*/\ntemplate<long long m>\nstruct modint{\n  long long\
    \ x;\n  modint():x(0){}\n  modint(long long y){\n    if(y<0){\n      y%=m;\n \
    \     if(y==0)x=y;\n      else x=m+y;\n    }\n    else if(y<m)x=y;\n    else x=y%m;\n\
    \  }\n  modint inv()const{\n    long long a=x,b=m,u=1,v=0,t;\n    while(b){\n\
    \      t=a/b;\n      swap(a-=t*b,b);\n      swap(u-=t*v,v);\n    }\n    return\
    \ modint(u);\n  }\n  modint &operator+=(const modint&p){if((x+=p.x)>=m)x-=m;return\
    \ *this;}\n  modint &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return *this;}\n\
    \  modint &operator*=(const modint&p){x=x*p.x;if(x>=m)x%=m;return *this;}\n  modint\
    \ &operator/=(const modint&p){*this*=p.inv();return *this;}\n  modint operator-()const{return\
    \ modint(-x); }\n  modint operator+(const modint&p)const{return modint(*this)+=p;\
    \ }\n  modint operator-(const modint&p)const{return modint(*this)-=p; }\n  modint\
    \ operator*(const modint&p)const{return modint(*this)*=p; }\n  modint operator/(const\
    \ modint&p)const{return modint(*this)/=p; }\n  bool operator==(const modint&p)const{return\
    \ x==p.x;}\n  bool operator!=(const modint&p)const{return x!=p.x;}\n  modint pow(long\
    \ long n)const{\n    modint ret(1),mul(x);\n    while(n){\n      if(n&1)ret*=mul;\n\
    \      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n  }\n  friend ostream\
    \ &operator<<(ostream &os,const modint&p) {\n    return os<<p.x;\n  }\n  friend\
    \ istream &operator>>(istream &is, modint &a) {\n    long long t;\n    is>>t;\n\
    \    a=modint<m>(t);\n    return (is);\n  }\n  static long long get_mod(){return\
    \ m;}\n};\n#line 5 \"Math/combinatorics.hpp\"\ntemplate<long long m>\nstruct combination{\n\
    \  using mint=modint<m>;\n  vector<mint>dat,idat;\n  long long mx;\n  combination(long\
    \ long mx_=300000):dat(mx_+1,1),idat(mx_+1,1),mx(mx_){\n    for(long long i=1;i<=mx;i++)dat[i]=dat[i-1]*mint(i);\n\
    \    idat[mx]/=dat[mx];\n    for(long long i=mx;i>0;i--)idat[i-1]=idat[i]*mint(i);\n\
    \  }\n  mint com(long long n,long long k){\n    if(n<0||k<0||n<k)return mint(0);\n\
    \    return dat[n]*idat[k]*idat[n-k];\n  }\n  mint fac(long long n){\n    if(n<0)return\
    \ mint(0);\n    return dat[n];\n  }\n};\n#line 5 \"Math/lagrange.hpp\"\ntemplate<long\
    \ long m>\nmodint<m> lagrange_polynominal(const vector<modint<m>>&y,const long\
    \ long&t){\n  using mint=modint<m>;\n  const int n=y.size()-1;\n  combination<m>c(n);\n\
    \  if(t<=n)return y[t];\n  mint ret;\n  vector<mint>dp(n+1,1),pd(n+1,1);\n  for(int\
    \ i=0;i<n;i++)dp[i+1]=dp[i]*(t-i);\n  for(int i=n;i>0;i--)pd[i-1]=pd[i]*(t-i);\n\
    \  for(int i=0;i<=n;i++){\n    mint tmp=y[i]*dp[i]*pd[i]*c.idat[i]*c.idat[n-i];\n\
    \    if((n-i)&1)ret-=tmp;\n    else ret+=tmp;\n  }\n  return ret;\n}\n"
  code: "/**\n * @brief Lagrange Polynomial(\u591A\u9805\u5F0F\u88DC\u9593)\n*/\n\
    #include\"combinatorics.hpp\"\ntemplate<long long m>\nmodint<m> lagrange_polynominal(const\
    \ vector<modint<m>>&y,const long long&t){\n  using mint=modint<m>;\n  const int\
    \ n=y.size()-1;\n  combination<m>c(n);\n  if(t<=n)return y[t];\n  mint ret;\n\
    \  vector<mint>dp(n+1,1),pd(n+1,1);\n  for(int i=0;i<n;i++)dp[i+1]=dp[i]*(t-i);\n\
    \  for(int i=n;i>0;i--)pd[i-1]=pd[i]*(t-i);\n  for(int i=0;i<=n;i++){\n    mint\
    \ tmp=y[i]*dp[i]*pd[i]*c.idat[i]*c.idat[n-i];\n    if((n-i)&1)ret-=tmp;\n    else\
    \ ret+=tmp;\n  }\n  return ret;\n}"
  dependsOn:
  - Math/combinatorics.hpp
  - Math/modint.hpp
  isVerificationFile: false
  path: Math/lagrange.hpp
  requiredBy: []
  timestamp: '2022-01-05 16:38:42+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/lagrange.hpp
layout: document
redirect_from:
- /library/Math/lagrange.hpp
- /library/Math/lagrange.hpp.html
title: "Lagrange Polynomial(\u591A\u9805\u5F0F\u88DC\u9593)"
---