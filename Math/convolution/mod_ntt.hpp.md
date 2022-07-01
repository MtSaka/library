---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Math/convolution/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':question:'
    path: Math/modular/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Arbitrary Mod Convolution(\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F\
      )"
    links: []
  bundledCode: "#line 2 \"Math/modular/modint.hpp\"\ntemplate<long long m>\nstruct\
    \ modint{\n  long long x;\n  constexpr modint():x(0){}\n  constexpr modint(long\
    \ long y):x(y>=0?y%m:(m-(-y)%m)%m){}\n  modint inv()const{\n    long long a=x,b=m,u=1,v=0,t;\n\
    \    while(b){\n      t=a/b;\n      swap(a-=t*b,b);\n      swap(u-=t*v,v);\n \
    \   }\n    return modint(u);\n  }\n  modint &operator+=(const modint&p){if((x+=p.x)>=m)x-=m;return\
    \ *this;}\n  modint &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return *this;}\n\
    \  modint &operator*=(const modint&p){x=x*p.x;if(x>=m)x%=m;return *this;}\n  modint\
    \ &operator/=(const modint&p){*this*=p.inv();return *this;}\n  friend modint operator+(const\
    \ modint&l,const modint&r){return modint(l)+=r;}\n  friend modint operator-(const\
    \ modint&l,const modint&r){return modint(l)-=r;}\n  friend modint operator*(const\
    \ modint&l,const modint&r){return modint(l)*=r;}\n  friend modint operator/(const\
    \ modint&l,const modint&r){return modint(l)/=r;}\n  modint operator-()const{return\
    \ modint(-x);}\n  modint operator+()const{return *this;}\n  modint &operator++(){x++;if(x==m)x=0;return\
    \ *this;}\n  modint &operator--(){if(x==0)x=m;x--;return *this;}\n  modint operator++(int){modint\
    \ ret(*this);++*this;return ret;}\n  modint operator--(int){modint ret(*this);--*this;return\
    \ ret;}\n  friend bool operator==(const modint&l,const modint&r){return l.x==r.x;}\n\
    \  friend bool operator!=(const modint&l,const modint&r){return l.x!=r.x;}\n \
    \ modint pow(long long n)const{\n    modint ret(1),mul(x);\n    while(n){\n  \
    \    if(n&1)ret*=mul;\n      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n\
    \  }\n  friend ostream &operator<<(ostream &os,const modint&p) {\n    return os<<p.x;\n\
    \  }\n  friend istream &operator>>(istream &is, modint &a) {\n    long long t;\n\
    \    is>>t;\n    a=modint<m>(t);\n    return (is);\n  }\n  static long long get_mod(){return\
    \ m;}\n};\n/**\n * @brief modint\n*/\n#line 3 \"Math/convolution/ntt.hpp\"\ntemplate<long\
    \ long m>\nstruct NTT{\n  using mint=modint<m>;\n  private:\n  static modint<m>\
    \ g;\n  static int limit;\n  static vector<modint<m>>root,inv_root;\n  static\
    \ mint primitive_root(const long long&mo){\n    if(mo==167772161)return mint(3);\n\
    \    if(mo==469762049)return mint(3);\n    if(mo==754974721)return mint(11);\n\
    \    if(mo==998244353)return mint(3);\n    if(mo==1224736769)return mint(3);\n\
    \    return mint(0);\n  }\n  static void init(){\n    if(root.empty()){\n    \
    \  g=primitive_root(m);\n      long long now=m-1;\n      while(!(now&1))now>>=1,limit++;\n\
    \      root.resize(limit+1,1),inv_root.resize(limit+1,1);\n      root[limit]=g.pow(now);\n\
    \      inv_root[limit]/=root[limit];\n      for(int i=limit-1;i>=0;i--){\n   \
    \     root[i]=root[i+1]*root[i+1];\n        inv_root[i]=inv_root[i+1]*inv_root[i+1];\n\
    \      }\n    }\n  }\n  public:\n  NTT(){init();};\n  static void dft(vector<mint>&a,int\
    \ inv){\n    init();\n    const int sz=a.size();\n    if(sz==1)return;\n    const\
    \ int mask=sz-1;\n    vector<mint>b(sz);\n    for(int i=sz>>1;i>=1;i>>=1){\n \
    \     int e=__builtin_ffsll(sz/i)-1;\n      mint w=1,z=(inv==1?root[e]:inv_root[e]);\n\
    \      for(int j=0;j<sz;j+=i){\n        for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];\n\
    \        w*=z;\n      }\n      swap(a,b);\n    }\n  }\n  static vector<mint>multiply(vector<mint>a,vector<mint>b){\n\
    \    int sz=1;\n    const int mxsiz=a.size()+b.size()-1;\n    while(sz<mxsiz)sz<<=1;\n\
    \    a.resize(sz),b.resize(sz);\n    dft(a,1),dft(b,1);\n    for(int i=0;i<sz;i++)a[i]*=b[i];\n\
    \    dft(a,-1);\n    a.resize(mxsiz);\n    mint iz=mint(sz).inv();\n    for(int\
    \ i=0;i<mxsiz;i++)a[i]*=iz;\n    return a;\n  }\n  template<typename T,std::enable_if_t<is_integral<T>::value>*\
    \ = nullptr>\n  static vector<T>multiply(const vector<T>&a,const vector<T>&b){\n\
    \    using mint=modint<m>;\n    vector<mint>a2(a.size()),b2(b.size());\n    for(int\
    \ i=0;i<(int)a.size();i++)a2[i]=a[i];\n    for(int i=0;i<(int)b.size();i++)b2[i]=b[i];\n\
    \    auto c2=multiply(a2,b2);\n    vector<T>c(c2.size());\n    for(int i=0;i<(int)c.size();i++)c[i]=c2[i].x;\n\
    \    return c;\n  }\n};\ntemplate<long long m>\nint NTT<m>::limit=0;\ntemplate<long\
    \ long m>\nvector<modint<m>>NTT<m>::root=vector<modint<m>>();\ntemplate<long long\
    \ m>\nvector<modint<m>>NTT<m>::inv_root=vector<modint<m>>();\ntemplate<long long\
    \ m>\nmodint<m>NTT<m>::g=modint<m>();\n/**\n * @brief Number Theoretic Transform(\u6570\
    \u8AD6\u5909\u63DB)\n*/\n#line 2 \"Math/convolution/mod_ntt.hpp\"\nvector<long\
    \ long>mod_convolution(vector<long long>a,vector<long long>b,long long m){\n \
    \ const long long m1=167772161,m2=469762049,m3=1224736769,m1_inv_m2=104391568,m12_inv_m3=721017874,m12_mod=78812994116517889%m;\n\
    \  auto x=NTT<m1>::multiply(a,b);\n  auto y=NTT<m2>::multiply(a,b);\n  auto z=NTT<m3>::multiply(a,b);\n\
    \  vector<long long>res(x.size());\n  for(int i=0;i<(int)x.size();i++){\n    long\
    \ long v1=(y[i]-x[i])*m1_inv_m2%m2;\n    if(v1<0)v1+=m2;\n    long long v2=(z[i]-(x[i]+m1*v1)%m3)*m12_inv_m3%m3;\n\
    \    if(v2<0)v2+=m3;\n    long long c=(x[i]+m1*v1+m12_mod*v2)%m;\n    if(c<0)c+=m;\n\
    \    res[i]=c;\n  }\n  return res;\n}\n/**\n * @brief Arbitrary Mod Convolution(\u4EFB\
    \u610Fmod\u7573\u307F\u8FBC\u307F)\n*/\n"
  code: "#include\"ntt.hpp\"\nvector<long long>mod_convolution(vector<long long>a,vector<long\
    \ long>b,long long m){\n  const long long m1=167772161,m2=469762049,m3=1224736769,m1_inv_m2=104391568,m12_inv_m3=721017874,m12_mod=78812994116517889%m;\n\
    \  auto x=NTT<m1>::multiply(a,b);\n  auto y=NTT<m2>::multiply(a,b);\n  auto z=NTT<m3>::multiply(a,b);\n\
    \  vector<long long>res(x.size());\n  for(int i=0;i<(int)x.size();i++){\n    long\
    \ long v1=(y[i]-x[i])*m1_inv_m2%m2;\n    if(v1<0)v1+=m2;\n    long long v2=(z[i]-(x[i]+m1*v1)%m3)*m12_inv_m3%m3;\n\
    \    if(v2<0)v2+=m3;\n    long long c=(x[i]+m1*v1+m12_mod*v2)%m;\n    if(c<0)c+=m;\n\
    \    res[i]=c;\n  }\n  return res;\n}\n/**\n * @brief Arbitrary Mod Convolution(\u4EFB\
    \u610Fmod\u7573\u307F\u8FBC\u307F)\n*/"
  dependsOn:
  - Math/convolution/ntt.hpp
  - Math/modular/modint.hpp
  isVerificationFile: false
  path: Math/convolution/mod_ntt.hpp
  requiredBy: []
  timestamp: '2022-07-01 11:02:29+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/convolution_mod_1000000007.test.cpp
documentation_of: Math/convolution/mod_ntt.hpp
layout: document
redirect_from:
- /library/Math/convolution/mod_ntt.hpp
- /library/Math/convolution/mod_ntt.hpp.html
title: "Arbitrary Mod Convolution(\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
---