---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/mod_ntt.hpp
    title: "Arbitrary Mod Convolution(\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: Math/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':question:'
    path: template/template.hpp
    title: "Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"test/yosupo/convolution_mod_1000000007.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\n#line\
    \ 2 \"template/template.hpp\"\n//#pragma GCC target(\"avx\")\n//#pragma GCC optimize(\"\
    O3\")\n//#pragma GCC optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll=long long;\nusing ld=long double;\nusing vl=vector<ll>;\n\
    using vi=vector<int>;\nusing vs=vector<string>;\nusing vc=vector<char>;\nusing\
    \ vvl=vector<vl>;\nusing P=pair<ll,ll>;\nusing vvc=vector<vc>;\nusing vd=vector<double>;\n\
    using vp=vector<P>;\nusing vb=vector<bool>;\n#define overload4(_1,_2,_3,_4,name,...)\
    \ name\n#define overload3(_1,_2,_3,name,...) name\n#define rep1(a) for(__typeof(a)\
    \ i=0;i<a;i++)\n#define rep2(i,a) for(__typeof(a) i=0;i<a;i++)\n#define rep3(i,a,b)\
    \ for(__typeof(a) i=a;i<b;i++)\n#define rep4(i,a,b,c) for(__typeof(a) i=a;i<b;i+=c)\n\
    #define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\
    #define rrep1(a) for(__typeof(a) i=(a)-1;i>=0;i--)\n#define rrep2(i,a) for(__typeof(a)\
    \ i=(a)-1;i>=0;i--)\n#define rrep3(i,a,b) for(__typeof(a) i=(b)-1;i>=(a);i--)\n\
    #define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)\n#define\
    \ all1(i) begin(i),end(i)\n#define all2(i,a) begin(i),begin(i)+a\n#define all3(i,a,b)\
    \ begin(i)+a,begin(i)+b\n#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)\n\
    #define rall(n) (n).rbegin(),(n).rend()\n#define pb push_back\n#define eb emplace_back\n\
    #define MtSaka ios::sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(12)\n\
    #define max_(a) *max_element(all(a))\n#define min_(a) *min_element(all(a))\n#define\
    \ INT(...) int __VA_ARGS__;scan(__VA_ARGS__)\n#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)\n#define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)\n#define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)\n\
    const int dx[8]={1,0,-1,0,1,-1,-1,1};\nconst int dy[8]={0,1,0,-1,1,1,-1,-1};\n\
    const ll inf=2e18;\nconst ll MOD=1000000007;\nconst ll mod=998244353;\nconst double\
    \ pi=acos(-1);\ntemplate<typename T1,typename T2 >\nostream &operator<<(ostream&os,const\
    \ pair<T1,T2>&p){os<<p.first<<\" \"<<p.second;return os;}\ntemplate<typename T1,typename\
    \ T2>\nistream &operator>>(istream&is,pair<T1,T2>&p){is>>p.first>>p.second;return\
    \ is;}\ntemplate<typename T>\nostream &operator<<(ostream&os,const vector<T>&v){for(int\
    \ i=0;i<(int)v.size();i++){os<<v[i]<<(i+1!=v.size()?\" \":\"\");}return os;}\n\
    template<typename T>\nistream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return\
    \ is;}\nvoid scan(){}\ntemplate<class Head,class... Tail>\nvoid scan(Head&head,Tail&...\
    \ tail){cin>>head;scan(tail...);}\ntemplate<class T>\nvoid print(const T &t){cout<<t<<'\\\
    n';}\ntemplate<class Head, class... Tail>\nvoid print(const Head &head, const\
    \ Tail &... tail){cout<<head<<' ';print(tail...);}\ntemplate<class... T>\nvoid\
    \ fin(const T &... a){print(a...);exit(0);}\ntemplate<typename T>\nT sum_(vector<T>a){return\
    \ accumulate(all(a),T(0));}\ntemplate<typename T1,typename T2>\ninline bool chmax(T1&a,T2\
    \ b){return a<b&&(a=b,true);}\ntemplate<typename T1,typename T2>\ninline bool\
    \ chmin(T1&a,T2 b){return a>b&&(a=b,true);}\n/**\n * @brief Template(\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8)\n*/\n#line 1 \"Math/mod_ntt.hpp\"\n/**\n * @brief Arbitrary\
    \ Mod Convolution(\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)\n*/\n#line 1 \"Math/ntt.hpp\"\
    \n/**\n * @brief Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)\n*/\n#line\
    \ 1 \"Math/modint.hpp\"\n/**\n * @brief modint\n*/\ntemplate<long long m>\nstruct\
    \ modint{\n  long long x;\n  modint():x(0){}\n  modint(long long y):x(y>=0?y%m:(m-(-y)%m)%m){}\n\
    \  modint inv()const{long long a=x,b=m,u=1,v=0,t;\n    while(b){\n      t=a/b;\n\
    \      swap(a-=t*b,b);\n      swap(u-=t*v,v);\n    }\n    return modint(u);\n\
    \  }\n  modint &operator+=(const modint&p) {if((x+=p.x)>=m)x-=m;return *this;}\n\
    \  modint &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return *this;}\n \
    \ modint &operator*=(const modint&p) {x=x*p.x%m;return *this;}\n  modint &operator/=(const\
    \ modint&p){*this*=p.inv();return *this;}\n  modint operator-()const{return modint(-x);\
    \ }\n  modint operator+(const modint&p)const{return modint(*this)+=p; }\n  modint\
    \ operator-(const modint&p)const{return modint(*this)-=p; }\n  modint operator*(const\
    \ modint&p)const{return modint(*this)*=p; }\n  modint operator/(const modint&p)const{return\
    \ modint(*this)/=p; }\n  bool operator==(const modint&p)const{return x==p.x;}\n\
    \  bool operator!=(const modint&p)const{return x!=p.x;}\n  modint pow(long long\
    \ n) const {\n    modint ret(1),mul(x);\n    while(n){\n      if(n&1)ret*=mul;\n\
    \      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n  }\n  friend ostream\
    \ &operator<<(ostream &os,const modint&p) {\n    return os<<p.x;\n  }\n  friend\
    \ istream &operator>>(istream &is, modint &a) {\n    long long t;\n    is>>t;\n\
    \    a=modint<m>(t);\n    return (is);\n  }\n  static long long get_mod(){return\
    \ m;}\n};\n#line 5 \"Math/ntt.hpp\"\ntemplate<long long m>\nstruct NTT{\n  using\
    \ mint=modint<m>;\n  mint g=2;\n  int limit=0;\n  vector<mint>root,inv_root;\n\
    \  mint primitive_root(long long mo){\n    if(mo==167772161)return mint(3);\n\
    \    if(mo==469762049)return mint(3);\n    if(mo==754974721)return mint(11);\n\
    \    if(mo==998244353)return mint(3);\n    if(mo==1224736769)return mint(3);\n\
    \    return mint(0);\n  }\n  NTT(){\n    g=primitive_root(m);\n    long long now=m-1;\n\
    \    while(!(now&1))now>>=1,limit++;\n    root.resize(limit+1,1),inv_root.resize(limit+1,1);\n\
    \    root[limit]=g.pow(now);\n    inv_root[limit]/=root[limit];\n    for(int i=limit-1;i>=0;i--){\n\
    \      root[i]=root[i+1]*root[i+1];\n      inv_root[i]=inv_root[i+1]*inv_root[i+1];\n\
    \    }\n  }\n  void dft(vector<mint>&a,int inv){\n    int sz=a.size();\n    if(sz==1)return;\n\
    \    int mask=sz-1;\n    vector<mint>b(sz);\n    for(int i=sz>>1;i>=1;i>>=1){\n\
    \      int e=__builtin_ffsll(sz/i)-1;\n      mint w=1,z=(inv==1?root[e]:inv_root[e]);\n\
    \      for(int j=0;j<sz;j+=i){\n        for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];\n\
    \        w*=z;\n      }\n      swap(a,b);\n    }\n  }\n  vector<mint>multiply(vector<mint>a,vector<mint>b){\n\
    \    int sz=1,mxsiz=a.size()+b.size()-1;\n    while(sz<mxsiz)sz<<=1;\n    a.resize(sz),b.resize(sz);\n\
    \    dft(a,1),dft(b,1);\n    for(int i=0;i<sz;i++)a[i]*=b[i];\n    dft(a,-1);\n\
    \    mint iz=mint(sz).inv();\n    for(int i=0;i<mxsiz;i++)a[i]*=iz;\n    a.resize(mxsiz);\n\
    \    return a;\n  }\n  template<typename T,std::enable_if_t<is_integral<T>::value>*\
    \ = nullptr>\n  vector<T>multiply(const vector<T>&a,const vector<T>&b){\n    using\
    \ mint=modint<m>;\n    vector<mint>a2(a.size()),b2(b.size());\n    for(int i=0;i<a.size();i++)a2[i]=a[i];\n\
    \    for(int i=0;i<b.size();i++)b2[i]=b[i];\n    auto c2=multiply(move(a2),move(b2));\n\
    \    vector<T>c(c2.size());\n    for(int i=0;i<c.size();i++)c[i]=c2[i].x;\n  \
    \  return c;\n  }\n};\n#line 5 \"Math/mod_ntt.hpp\"\nvector<long long>mod_convolution(vector<long\
    \ long>a,vector<long long>b,long long m){\n  NTT<167772161>ntt1;\n  NTT<469762049>ntt2;\n\
    \  NTT<1224736769>ntt3;\n  auto x=ntt1.multiply(a,b);\n  auto y=ntt2.multiply(a,b);\n\
    \  auto z=ntt3.multiply(a,b);\n  const long long m1=167772161,m2=469762049,m3=1224736769,m1_inv_m2=104391568,m12_inv_m3=721017874,m12_mod=78812994116517889%m;\n\
    \  vector<long long>res(x.size());\n  for(int i=0;i<x.size();i++){\n    long long\
    \ v1=(y[i]-x[i])*m1_inv_m2%m2;\n    if(v1<0)v1+=m2;\n    long long v2=(z[i]-(x[i]+m1*v1)%m3)*m12_inv_m3%m3;\n\
    \    if(v2<0)v2+=m3;\n    long long c=(x[i]+m1*v1+m12_mod*v2)%m;\n    if(c<0)c+=m;\n\
    \    res[i]=c;\n  }\n  return res;\n}\n#line 4 \"test/yosupo/convolution_mod_1000000007.test.cpp\"\
    \nint main(){\n  int n,m;\n  cin>>n>>m;\n  vector<long long>a(n),b(m);\n  scan(a,b);\n\
    \  print(mod_convolution(a,b,MOD));\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n#include\"../../template/template.hpp\"\n#include\"../../Math/mod_ntt.hpp\"\n\
    int main(){\n  int n,m;\n  cin>>n>>m;\n  vector<long long>a(n),b(m);\n  scan(a,b);\n\
    \  print(mod_convolution(a,b,MOD));\n}"
  dependsOn:
  - template/template.hpp
  - Math/mod_ntt.hpp
  - Math/ntt.hpp
  - Math/modint.hpp
  isVerificationFile: true
  path: test/yosupo/convolution_mod_1000000007.test.cpp
  requiredBy: []
  timestamp: '2021-12-29 21:42:40+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/convolution_mod_1000000007.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution_mod_1000000007.test.cpp
- /verify/test/yosupo/convolution_mod_1000000007.test.cpp.html
title: test/yosupo/convolution_mod_1000000007.test.cpp
---
