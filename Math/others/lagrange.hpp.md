---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/modular/modint.hpp
    title: modint
  - icon: ':x:'
    path: Math/others/combinatorics.hpp
    title: "Combinatorics(\u7D44\u307F\u5408\u308F\u305B)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Lagrange Polynomial(\u591A\u9805\u5F0F\u88DC\u9593)"
    links: []
  bundledCode: "#line 2 \"Math/modular/modint.hpp\"\ntemplate<long long m>\nstruct\
    \ modint{\n  long long x;\n  modint():x(0){}\n  modint(long long y):x(y>=0?y%mod:(mod-(-y)%mod)%mod){}\n\
    \  modint inv()const{\n    long long a=x,b=m,u=1,v=0,t;\n    while(b){\n     \
    \ t=a/b;\n      swap(a-=t*b,b);\n      swap(u-=t*v,v);\n    }\n    return modint(u);\n\
    \  }\n  modint &operator+=(const modint&p){if((x+=p.x)>=m)x-=m;return *this;}\n\
    \  modint &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return *this;}\n \
    \ modint &operator*=(const modint&p){x=x*p.x;if(x>=m)x%=m;return *this;}\n  modint\
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
    \ m;}\n};\n/**\n * @brief modint\n*/\n#line 3 \"Math/others/combinatorics.hpp\"\
    \ntemplate<long long m>\nstruct combination{\n  using mint=modint<m>;\n  vector<mint>dat,idat;\n\
    \  long long mx;\n  combination(long long mx_=300000):dat(mx_+1,1),idat(mx_+1,1),mx(mx_){\n\
    \    for(long long i=1;i<=mx;i++)dat[i]=dat[i-1]*mint(i);\n    idat[mx]/=dat[mx];\n\
    \    for(long long i=mx;i>0;i--)idat[i-1]=idat[i]*mint(i);\n  }\n  mint com(long\
    \ long n,long long k){\n    if(n<0||k<0||n<k)return mint(0);\n    return dat[n]*idat[k]*idat[n-k];\n\
    \  }\n  mint fac(long long n){\n    if(n<0)return mint(0);\n    return dat[n];\n\
    \  }\n  mint finv(long long n){\n    if(n<0)return mint(0);\n    return idat[n];\n\
    \  }\n  mint hom(long long n,long long k){\n    return com(n+k-1,k);\n  }\n  mint\
    \ per(long long n,long long k){\n    if(k<0||k>n)return mint(0);\n    return dat[n]*idat[n-k];\n\
    \  }\n};\ntemplate<long long p>\nstruct COMB{\n  vector<vector<modint<p>>>comb;\n\
    \  COMB(){\n    comb.assign(p,vector<modint<p>>(p));\n    comb[0][0]=1;\n    for(int\
    \ i=1;i<p;i++){\n      comb[i][0]=1;\n      for(int j=i;j>0;j--)comb[i][j]=comb[i-1][j-1]+comb[i-1][j];\n\
    \    }\n  }\n  modint<p>com(int n,int k){\n    modint<p>ret=1;\n    while(n>0||k>0){\n\
    \      int ni=n%p,ki=k%p;\n      ret*=comb[ni][ki];\n      n/=p;k/=p;\n    }\n\
    \    return ret;\n  }\n};\n/**\n * @brief Combinatorics(\u7D44\u307F\u5408\u308F\
    \u305B)\n*/\n#line 2 \"Math/others/lagrange.hpp\"\ntemplate<long long m>\nmodint<m>\
    \ lagrange_polynominal(const vector<modint<m>>&y,const long long&t){\n  using\
    \ mint=modint<m>;\n  const int n=y.size()-1;\n  combination<m>c(n);\n  if(t<=n)return\
    \ y[t];\n  mint ret;\n  vector<mint>dp(n+1,1),pd(n+1,1);\n  for(int i=0;i<n;i++)dp[i+1]=dp[i]*(t-i);\n\
    \  for(int i=n;i>0;i--)pd[i-1]=pd[i]*(t-i);\n  for(int i=0;i<=n;i++){\n    mint\
    \ tmp=y[i]*dp[i]*pd[i]*c.idat[i]*c.idat[n-i];\n    if((n-i)&1)ret-=tmp;\n    else\
    \ ret+=tmp;\n  }\n  return ret;\n}\n/**\n * @brief Lagrange Polynomial(\u591A\u9805\
    \u5F0F\u88DC\u9593)\n*/\n"
  code: "#include\"combinatorics.hpp\"\ntemplate<long long m>\nmodint<m> lagrange_polynominal(const\
    \ vector<modint<m>>&y,const long long&t){\n  using mint=modint<m>;\n  const int\
    \ n=y.size()-1;\n  combination<m>c(n);\n  if(t<=n)return y[t];\n  mint ret;\n\
    \  vector<mint>dp(n+1,1),pd(n+1,1);\n  for(int i=0;i<n;i++)dp[i+1]=dp[i]*(t-i);\n\
    \  for(int i=n;i>0;i--)pd[i-1]=pd[i]*(t-i);\n  for(int i=0;i<=n;i++){\n    mint\
    \ tmp=y[i]*dp[i]*pd[i]*c.idat[i]*c.idat[n-i];\n    if((n-i)&1)ret-=tmp;\n    else\
    \ ret+=tmp;\n  }\n  return ret;\n}\n/**\n * @brief Lagrange Polynomial(\u591A\u9805\
    \u5F0F\u88DC\u9593)\n*/"
  dependsOn:
  - Math/others/combinatorics.hpp
  - Math/modular/modint.hpp
  isVerificationFile: false
  path: Math/others/lagrange.hpp
  requiredBy: []
  timestamp: '2022-04-06 13:48:48+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/others/lagrange.hpp
layout: document
redirect_from:
- /library/Math/others/lagrange.hpp
- /library/Math/others/lagrange.hpp.html
title: "Lagrange Polynomial(\u591A\u9805\u5F0F\u88DC\u9593)"
---
