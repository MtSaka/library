---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: Math/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/division_of_polynomials.test.cpp
    title: test/yosupo/division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
    links: []
  bundledCode: "#line 1 \"Math/fps.hpp\"\n/**\n * @brief Formal Power Series(\u5F62\
    \u5F0F\u7684\u51AA\u7D1A\u6570)\n*/\n#line 1 \"Math/ntt.hpp\"\n/**\n * @brief\
    \ Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)\n*/\n#line 1 \"Math/modint.hpp\"\
    \n/**\n * @brief modint\n*/\ntemplate<long long m>\nstruct modint{\n  long long\
    \ x;\n  modint():x(0){}\n  modint(long long y):x(y>=0?y%m:(m-(-y)%m)%m){}\n  modint\
    \ inv()const{long long a=x,b=m,u=1,v=0,t;\n    while(b){\n      t=a/b;\n     \
    \ swap(a-=t*b,b);\n      swap(u-=t*v,v);\n    }\n    return modint(u);\n  }\n\
    \  modint &operator+=(const modint&p) {if((x+=p.x)>=m)x-=m;return *this;}\n  modint\
    \ &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return *this;}\n  modint &operator*=(const\
    \ modint&p) {x=x*p.x%m;return *this;}\n  modint &operator/=(const modint&p){*this*=p.inv();return\
    \ *this;}\n  modint operator-()const{return modint(-x); }\n  modint operator+(const\
    \ modint&p)const{return modint(*this)+=p; }\n  modint operator-(const modint&p)const{return\
    \ modint(*this)-=p; }\n  modint operator*(const modint&p)const{return modint(*this)*=p;\
    \ }\n  modint operator/(const modint&p)const{return modint(*this)/=p; }\n  bool\
    \ operator==(const modint&p)const{return x==p.x;}\n  bool operator!=(const modint&p)const{return\
    \ x!=p.x;}\n  modint pow(long long n) const {\n    modint ret(1),mul(x);\n   \
    \ while(n){\n      if(n&1)ret*=mul;\n      mul*=mul;\n      n>>=1;\n    }\n  \
    \  return ret;\n  }\n  friend ostream &operator<<(ostream &os,const modint&p)\
    \ {\n    return os<<p.x;\n  }\n  friend istream &operator>>(istream &is, modint\
    \ &a) {\n    long long t;\n    is>>t;\n    a=modint<m>(t);\n    return (is);\n\
    \  }\n  static long long get_mod(){return m;}\n};\n#line 5 \"Math/ntt.hpp\"\n\
    template<long long m>\nstruct NTT{\n  using mint=modint<m>;\n  mint g=2;\n  int\
    \ limit=0;\n  vector<mint>root,inv_root;\n  mint primitive_root(long long mo){\n\
    \    if(mo==167772161)return mint(3);\n    if(mo==469762049)return mint(3);\n\
    \    if(mo==754974721)return mint(11);\n    if(mo==998244353)return mint(3);\n\
    \    if(mo==1224736769)return mint(3);\n    return mint(0);\n  }\n  NTT(){\n \
    \   g=primitive_root(m);\n    long long now=m-1;\n    while(!(now&1))now>>=1,limit++;\n\
    \    root.resize(limit+1,1),inv_root.resize(limit+1,1);\n    root[limit]=g.pow(now);\n\
    \    inv_root[limit]/=root[limit];\n    for(int i=limit-1;i>=0;i--){\n      root[i]=root[i+1]*root[i+1];\n\
    \      inv_root[i]=inv_root[i+1]*inv_root[i+1];\n    }\n  }\n  void dft(vector<mint>&a,int\
    \ inv){\n    int sz=a.size();\n    if(sz==1)return;\n    int mask=sz-1;\n    vector<mint>b(sz);\n\
    \    for(int i=sz>>1;i>=1;i>>=1){\n      int e=__builtin_ffsll(sz/i)-1;\n    \
    \  mint w=1,z=(inv==1?root[e]:inv_root[e]);\n      for(int j=0;j<sz;j+=i){\n \
    \       for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];\n\
    \        w*=z;\n      }\n      swap(a,b);\n    }\n  }\n  vector<mint>multiply(vector<mint>a,vector<mint>b){\n\
    \    int sz=1,mxsiz=a.size()+b.size()-1;\n    while(sz<mxsiz)sz<<=1;\n    a.resize(sz),b.resize(sz);\n\
    \    dft(a,1),dft(b,1);\n    for(int i=0;i<sz;i++)a[i]*=b[i];\n    dft(a,-1);\n\
    \    mint iz=mint(sz).inv();\n    for(int i=0;i<mxsiz;i++)a[i]*=iz;\n    a.resize(mxsiz);\n\
    \    return a;\n  }\n  template<typename T,std::enable_if_t<is_integral<T>::value>*\
    \ = nullptr>\n  vector<T>multiply(const vector<T>&a,const vector<T>&b){\n    using\
    \ mint=modint<m>;\n    vector<mint>a2(a.size()),b2(b.size());\n    for(int i=0;i<a.size();i++)a2[i]=a[i];\n\
    \    for(int i=0;i<b.size();i++)b2[i]=b[i];\n    auto c2=multiply(move(a2),move(b2));\n\
    \    vector<T>c(c2.size());\n    for(int i=0;i<c.size();i++)c[i]=c2[i].x;\n  \
    \  return c;\n  }\n};\n#line 5 \"Math/fps.hpp\"\ntemplate<long long m>\nstruct\
    \ FPS{\n  using mint=modint<m>;\n  vector<mint>val;\n  NTT<m>ntt;\n  FPS(){}\n\
    \  FPS(int sz):val(sz){}\n  FPS(const vector<mint>&a):val(a){}\n  FPS(vector<mint>&&a):val(move(a)){}\n\
    \  FPS(const FPS &other):val(other.val){}\n  FPS(FPS &&other):val(move(other.val)){}\n\
    \  mint &operator[](int i){return val[i];}\n  size_t size()const{return val.size();}\n\
    \  void resize(const int sz){val.resize(sz);}\n  void shrink(){while(!val.empty()&&val.back()==mint(0))val.pop_back();}\n\
    \  FPS &operator=(const FPS &other){\n    val=other.val;\n    return *this;\n\
    \  }\n  FPS &operator=(FPS &&other){\n    val=move(other.val);\n    return *this;\n\
    \  }\n  FPS inv(int mx=-1)const{\n    if(mx==-1)mx=size();\n    FPS g(1);\n  \
    \  g[0]=mint(1)/val[0];\n    int now=1;\n    while(now<mx){\n      now<<=1;\n\
    \      FPS t=(*this);\n      t.resize(now);\n      t*=-g;\n      t[0]+=2,g*=t;\n\
    \      g.resize(now);\n    }\n    g.resize(mx);\n    return g;\n  }\n  FPS operator+(const\
    \ FPS&r)const{return FPS(*this)+=r;}\n  FPS operator-(const FPS&r)const{return\
    \ FPS(*this)-=r;}\n  FPS operator*(const FPS&r)const{return FPS(*this)*=r;}\n\
    \  FPS operator/(const FPS&r)const{return FPS(*this)/=r;}\n  FPS operator%(const\
    \ FPS&r)const{return FPS(*this)%=r;}\n  FPS operator-()const{\n    FPS ret(val);\n\
    \    for(int i=0;i<val.size();i++)ret[i]=-ret[i];\n    return ret;\n  }\n  FPS\
    \ operator+=(FPS r){\n    if(r.size()>val.size())val.resize(r.size());\n    for(int\
    \ i=0;i<r.size();i++)val[i]+=r[i];\n    return *this;\n  }\n  FPS operator-=(FPS\
    \ r){\n    if(r.size()>val.size())val.resize(r.size());\n    for(int i=0;i<r.size();i++)val[i]-=r[i];\n\
    \    return *this;\n  }\n  FPS operator*=(FPS r){\n    val=ntt.multiply(val,r.val);\n\
    \    return *this;\n  }\n  FPS operator/=(FPS r){\n    if(val.size()<r.size()){\n\
    \      val.clear();\n      return *this;\n    }\n    int sz=val.size()-r.size()+1;\n\
    \    reverse(val.begin(),val.end());\n    reverse(r.val.begin(),r.val.end());\n\
    \    val.resize(sz);\n    (*this)*=r.inv(sz);\n    val.resize(sz);\n    reverse(val.begin(),val.end());\n\
    \    return (*this);\n  }\n  FPS operator%=(FPS r){\n    if(val.size()<r.size())return\
    \ (*this);\n    (*this)-=(*this)/r*r;\n    val.resize(r.size()-1);\n    shrink();\n\
    \    return (*this);\n  }\n  FPS diff()const{\n    int n=size();\n    FPS ret(max(0,n-1));\n\
    \    for(int i=1;i<n;i++)ret[i-1]=val[i]*mint(i);\n    return ret;\n  }\n  FPS\
    \ integral()const{\n    int n=size();\n    FPS ret(n+1);\n    for(int i=0;i<n;i++)ret[i+1]=val[i]/mint(i+1);\n\
    \    return ret;\n  }\n  FPS log(int mx=-1)const{\n    int n=size();\n    if(mx==-1)mx=n;\n\
    \    FPS res=diff()*inv(mx);\n    res.resize(mx-1);\n    return res.integral();\n\
    \  }\n};\n"
  code: "/**\n * @brief Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)\n\
    */\n#include\"ntt.hpp\"\ntemplate<long long m>\nstruct FPS{\n  using mint=modint<m>;\n\
    \  vector<mint>val;\n  NTT<m>ntt;\n  FPS(){}\n  FPS(int sz):val(sz){}\n  FPS(const\
    \ vector<mint>&a):val(a){}\n  FPS(vector<mint>&&a):val(move(a)){}\n  FPS(const\
    \ FPS &other):val(other.val){}\n  FPS(FPS &&other):val(move(other.val)){}\n  mint\
    \ &operator[](int i){return val[i];}\n  size_t size()const{return val.size();}\n\
    \  void resize(const int sz){val.resize(sz);}\n  void shrink(){while(!val.empty()&&val.back()==mint(0))val.pop_back();}\n\
    \  FPS &operator=(const FPS &other){\n    val=other.val;\n    return *this;\n\
    \  }\n  FPS &operator=(FPS &&other){\n    val=move(other.val);\n    return *this;\n\
    \  }\n  FPS inv(int mx=-1)const{\n    if(mx==-1)mx=size();\n    FPS g(1);\n  \
    \  g[0]=mint(1)/val[0];\n    int now=1;\n    while(now<mx){\n      now<<=1;\n\
    \      FPS t=(*this);\n      t.resize(now);\n      t*=-g;\n      t[0]+=2,g*=t;\n\
    \      g.resize(now);\n    }\n    g.resize(mx);\n    return g;\n  }\n  FPS operator+(const\
    \ FPS&r)const{return FPS(*this)+=r;}\n  FPS operator-(const FPS&r)const{return\
    \ FPS(*this)-=r;}\n  FPS operator*(const FPS&r)const{return FPS(*this)*=r;}\n\
    \  FPS operator/(const FPS&r)const{return FPS(*this)/=r;}\n  FPS operator%(const\
    \ FPS&r)const{return FPS(*this)%=r;}\n  FPS operator-()const{\n    FPS ret(val);\n\
    \    for(int i=0;i<val.size();i++)ret[i]=-ret[i];\n    return ret;\n  }\n  FPS\
    \ operator+=(FPS r){\n    if(r.size()>val.size())val.resize(r.size());\n    for(int\
    \ i=0;i<r.size();i++)val[i]+=r[i];\n    return *this;\n  }\n  FPS operator-=(FPS\
    \ r){\n    if(r.size()>val.size())val.resize(r.size());\n    for(int i=0;i<r.size();i++)val[i]-=r[i];\n\
    \    return *this;\n  }\n  FPS operator*=(FPS r){\n    val=ntt.multiply(val,r.val);\n\
    \    return *this;\n  }\n  FPS operator/=(FPS r){\n    if(val.size()<r.size()){\n\
    \      val.clear();\n      return *this;\n    }\n    int sz=val.size()-r.size()+1;\n\
    \    reverse(val.begin(),val.end());\n    reverse(r.val.begin(),r.val.end());\n\
    \    val.resize(sz);\n    (*this)*=r.inv(sz);\n    val.resize(sz);\n    reverse(val.begin(),val.end());\n\
    \    return (*this);\n  }\n  FPS operator%=(FPS r){\n    if(val.size()<r.size())return\
    \ (*this);\n    (*this)-=(*this)/r*r;\n    val.resize(r.size()-1);\n    shrink();\n\
    \    return (*this);\n  }\n  FPS diff()const{\n    int n=size();\n    FPS ret(max(0,n-1));\n\
    \    for(int i=1;i<n;i++)ret[i-1]=val[i]*mint(i);\n    return ret;\n  }\n  FPS\
    \ integral()const{\n    int n=size();\n    FPS ret(n+1);\n    for(int i=0;i<n;i++)ret[i+1]=val[i]/mint(i+1);\n\
    \    return ret;\n  }\n  FPS log(int mx=-1)const{\n    int n=size();\n    if(mx==-1)mx=n;\n\
    \    FPS res=diff()*inv(mx);\n    res.resize(mx-1);\n    return res.integral();\n\
    \  }\n};"
  dependsOn:
  - Math/ntt.hpp
  - Math/modint.hpp
  isVerificationFile: false
  path: Math/fps.hpp
  requiredBy: []
  timestamp: '2021-12-28 02:04:29+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/division_of_polynomials.test.cpp
documentation_of: Math/fps.hpp
layout: document
redirect_from:
- /library/Math/fps.hpp
- /library/Math/fps.hpp.html
title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
---
