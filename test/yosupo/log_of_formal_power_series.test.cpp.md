---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/fps.hpp
    title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: Math/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/log_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/log_of_formal_power_series
  bundledCode: "#line 1 \"test/yosupo/log_of_formal_power_series.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\n#line\
    \ 2 \"template/template.hpp\"\n//#pragma GCC target(\"avx\")\n//#pragma GCC optimize(\"\
    O3\")\n//#pragma GCC optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\n#define\
    \ overload4(a,b,c,d,e,...) e\n#define overload3(a,b,c,d,...) d\n#define rep1(a)\
    \ for(ll i=0;i<(ll)(a);i++)\n#define rep2(i,a) for(ll i=0;i<(ll)(a);i++)\n#define\
    \ rep3(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)\n#define rep4(i,a,b,c) for(ll i=(ll)(a);i<(ll)(b);i+=(ll)(c))\n\
    #define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\
    #define rrep1(a) for(ll i=(ll)(a)-1;i>=0;i--)\n#define rrep2(i,a) for(ll i=(ll)(a)-1;i>=0;i--)\n\
    #define rrep3(i,a,b) for(ll i=(ll)(b)-1;i>=(ll)(a);i--)\n#define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)\n\
    #define all1(i) begin(i),end(i)\n#define all2(i,a) begin(i),begin(i)+a\n#define\
    \ all3(i,a,b) begin(i)+a,begin(i)+b\n#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)\n\
    #define rall(n) (n).rbegin(),(n).rend()\n#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)\n#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)\n#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)\n#define pb push_back\n#define\
    \ eb emplace_back\n#define END(...) {print(__VA_ARGS__);return;}\nusing namespace\
    \ std;\nusing ll=long long;\nusing ull=unsigned long long;\nusing ld=long double;\n\
    using vl=vector<ll>;\nusing vi=vector<int>;\nusing vs=vector<string>;\nusing vc=vector<char>;\n\
    using vvl=vector<vl>;\nusing pi=pair<int,int>;\nusing pl=pair<ll,ll>;\nusing vvc=vector<vc>;\n\
    using vd=vector<double>;\nusing vp=vector<pl>;\nusing vb=vector<bool>;\nconst\
    \ int dx[8]={1,0,-1,0,1,-1,-1,1};\nconst int dy[8]={0,1,0,-1,1,1,-1,-1};\nconst\
    \ ll MOD=1000000007;\nconst ll mod=998244353;\nconst ld EPS=1e-8;\nconst ld PI=3.1415926535897932384626;\n\
    template<typename T,typename U>\nostream &operator<<(ostream&os,const pair<T,U>&p){os<<p.first<<\"\
    \ \"<<p.second;return os;}\ntemplate<typename T,typename U>\nistream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return\
    \ is;}\ntemplate<typename T>\nostream &operator<<(ostream&os,const vector<T>&v){for(int\
    \ i=0;i<(int)v.size();i++){os<<v[i]<<(i+1!=v.size()?\" \":\"\");}return os;}\n\
    template<typename T>\nistream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return\
    \ is;}\nvoid scan(){}\ntemplate<class Head,class... Tail>\nvoid scan(Head&head,Tail&...\
    \ tail){cin>>head;scan(tail...);}\ntemplate<class T>\nvoid print(const T &t){cout<<t<<'\\\
    n';}\ntemplate<class Head, class... Tail>\nvoid print(const Head &head, const\
    \ Tail &... tail){cout<<head<<' ';print(tail...);}\ntemplate<class... T>\nvoid\
    \ fin(const T &... a){print(a...);exit(0);}\ntemplate<typename T,typename U>\n\
    inline bool chmax(T&a,U b){return a<b&&(a=b,true);}\ntemplate<typename T,typename\
    \ U>\ninline bool chmin(T&a,U b){return a>b&&(a=b,true);}\ntemplate<typename T>\n\
    class infinity{\n  public:\n  static const T MAX=numeric_limits<T>::max();\n \
    \ static const T MIN=numeric_limits<T>::min();\n  static const T value=numeric_limits<T>::max()/2;\n\
    \  static const T mvalue=numeric_limits<T>::min()/2;\n};\n#if __cplusplus <= 201402L\n\
    template<class T>const T infinity<T>::value;\ntemplate<class T>const T infinity<T>::mvalue;\n\
    template<class T>const T infinity<T>::max;\ntemplate<class T>const T infinity<T>::min;\n\
    #endif\ntemplate<typename T>const T inf=infinity<T>::value;\ninline int popcnt(ull\
    \ x){\n#if __cplusplus>=202002L\nreturn popcount(x);\n#endif\nx=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);return\
    \ (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);\n}\nvoid dump(const char&t){cerr<<t;}\n\
    void dump(const string&t){cerr<<t;}\nvoid dump(const bool&t){cerr<<(t?\"true\"\
    :\"false\");}\ntemplate<typename T>\nvoid dump(const T&t,enable_if_t<is_integral<T>::value>*\
    \ =nullptr){string tmp;if(t==infinity<T>::value||t==infinity<T>::MAX)tmp=\"inf\"\
    ;if(t==infinity<T>::mvalue||t==infinity<T>::MIN)tmp=\"-inf\";if(tmp.empty())tmp=to_string(t);cerr<<tmp;}\n\
    template <typename T>\nvoid dump(const T&t,enable_if_t<!is_void<typename T::iterator>::value>*\
    \ =nullptr){cerr<<\"{\";for(auto it=t.begin();it!=t.end();){dump(*it);cerr<<(++it==t.end()?\"\
    \":\",\");}cerr<<\"}\";}\ntemplate<typename T,typename U>\nvoid dump(const pair<T,U>&t){cerr<<\"\
    (\";dump(t.first);cerr<<\",\";dump(t.second);cerr<<\")\";}\nvoid trace(){cerr<<endl;}\n\
    template<typename Head,typename... Tail>\nvoid trace(Head&&head,Tail&&... tail){dump(head);if(sizeof...(tail))cerr<<\"\
    ,\";trace(forward<Tail>(tail)...);}\n#ifdef ONLINE_JUDGE\n#define debug(...)\n\
    #else\n#define debug(...) cerr<<#__VA_ARGS__<<\"=\";trace(__VA_ARGS__);\n#endif\n\
    struct IOSetup{IOSetup(){cin.tie(nullptr);ios::sync_with_stdio(false);cout.tie(0);cout<<fixed<<setprecision(12);cerr<<fixed<<setprecision(12);}};\n\
    /**\n * @brief Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 1 \"\
    Math/fps.hpp\"\n/**\n * @brief Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\
    \u6570)\n*/\n#line 1 \"Math/ntt.hpp\"\n/**\n * @brief Number Theoretic Transform(\u6570\
    \u8AD6\u5909\u63DB)\n*/\n#line 1 \"Math/modint.hpp\"\n/**\n * @brief modint\n\
    */\ntemplate<long long m>\nstruct modint{\n  long long x;\n  modint():x(0){}\n\
    \  modint(long long y){\n    if(y<0){\n      y%=m;\n      if(y==0)x=y;\n     \
    \ else x=m+y;\n    }\n    else if(y<m)x=y;\n    else x=y%m;\n  }\n  modint inv()const{\n\
    \    long long a=x,b=m,u=1,v=0,t;\n    while(b){\n      t=a/b;\n      swap(a-=t*b,b);\n\
    \      swap(u-=t*v,v);\n    }\n    return modint(u);\n  }\n  modint &operator+=(const\
    \ modint&p){if((x+=p.x)>=m)x-=m;return *this;}\n  modint &operator-=(const modint&p){if((x+=m-p.x)>=m)x-=m;return\
    \ *this;}\n  modint &operator*=(const modint&p){x=x*p.x;if(x>=m)x%=m;return *this;}\n\
    \  modint &operator/=(const modint&p){*this*=p.inv();return *this;}\n  modint\
    \ operator-()const{return modint(-x); }\n  modint operator+(const modint&p)const{return\
    \ modint(*this)+=p; }\n  modint operator-(const modint&p)const{return modint(*this)-=p;\
    \ }\n  modint operator*(const modint&p)const{return modint(*this)*=p; }\n  modint\
    \ operator/(const modint&p)const{return modint(*this)/=p; }\n  bool operator==(const\
    \ modint&p)const{return x==p.x;}\n  bool operator!=(const modint&p)const{return\
    \ x!=p.x;}\n  modint pow(long long n)const{\n    modint ret(1),mul(x);\n    while(n){\n\
    \      if(n&1)ret*=mul;\n      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n\
    \  }\n  friend ostream &operator<<(ostream &os,const modint&p) {\n    return os<<p.x;\n\
    \  }\n  friend istream &operator>>(istream &is, modint &a) {\n    long long t;\n\
    \    is>>t;\n    a=modint<m>(t);\n    return (is);\n  }\n  static long long get_mod(){return\
    \ m;}\n};\n#line 5 \"Math/ntt.hpp\"\ntemplate<long long m>\nstruct NTT{\n  using\
    \ mint=modint<m>;\n  static modint<m> g;\n  static int limit;\n  static vector<modint<m>>root,inv_root;\n\
    \  static mint primitive_root(const long long&mo){\n    if(mo==167772161)return\
    \ mint(3);\n    if(mo==469762049)return mint(3);\n    if(mo==754974721)return\
    \ mint(11);\n    if(mo==998244353)return mint(3);\n    if(mo==1224736769)return\
    \ mint(3);\n    return mint(0);\n  }\n  static void init(){\n    if(root.empty()){\n\
    \      g=primitive_root(m);\n      long long now=m-1;\n      while(!(now&1))now>>=1,limit++;\n\
    \      root.resize(limit+1,1),inv_root.resize(limit+1,1);\n      root[limit]=g.pow(now);\n\
    \      inv_root[limit]/=root[limit];\n      for(int i=limit-1;i>=0;i--){\n   \
    \     root[i]=root[i+1]*root[i+1];\n        inv_root[i]=inv_root[i+1]*inv_root[i+1];\n\
    \      }\n    }\n  }\n  NTT(){};\n  static void dft(vector<mint>&a,int inv){\n\
    \    init();\n    const int sz=a.size();\n    if(sz==1)return;\n    const int\
    \ mask=sz-1;\n    vector<mint>b(sz);\n    for(int i=sz>>1;i>=1;i>>=1){\n     \
    \ int e=__builtin_ffsll(sz/i)-1;\n      mint w=1,z=(inv==1?root[e]:inv_root[e]);\n\
    \      for(int j=0;j<sz;j+=i){\n        for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];\n\
    \        w*=z;\n      }\n      swap(a,b);\n    }\n  }\n  static vector<mint>multiply(vector<mint>a,vector<mint>b){\n\
    \    int sz=1;\n    const int mxsiz=a.size()+b.size()-1;\n    while(sz<mxsiz)sz<<=1;\n\
    \    a.resize(sz),b.resize(sz);\n    dft(a,1),dft(b,1);\n    for(int i=0;i<sz;i++)a[i]*=b[i];\n\
    \    dft(a,-1);\n    mint iz=mint(sz).inv();\n    for(int i=0;i<mxsiz;i++)a[i]*=iz;\n\
    \    a.resize(mxsiz);\n    return a;\n  }\n  template<typename T,std::enable_if_t<is_integral<T>::value>*\
    \ = nullptr>\n  static vector<T>multiply(const vector<T>&a,const vector<T>&b){\n\
    \    using mint=modint<m>;\n    vector<mint>a2(a.size()),b2(b.size());\n    for(int\
    \ i=0;i<a.size();i++)a2[i]=a[i];\n    for(int i=0;i<b.size();i++)b2[i]=b[i];\n\
    \    auto c2=multiply(a2,b2);\n    vector<T>c(c2.size());\n    for(int i=0;i<c.size();i++)c[i]=c2[i].x;\n\
    \    return c;\n  }\n};\ntemplate<long long m>\nint NTT<m>::limit=0;\ntemplate<long\
    \ long m>\nvector<modint<m>>NTT<m>::root=vector<modint<m>>();\ntemplate<long long\
    \ m>\nvector<modint<m>>NTT<m>::inv_root=vector<modint<m>>();\ntemplate<long long\
    \ m>\nmodint<m>NTT<m>::g=modint<m>();\n#line 5 \"Math/fps.hpp\"\ntemplate<long\
    \ long Mod>\nstruct FPS:vector<modint<Mod>>{\n  using mint=modint<Mod>;\n  using\
    \ vector<mint>::vector;\n  using vector<mint>::operator=;\n  void shrink(){while(!(*this).empty()&&(*this).back()==mint(0))(*this).pop_back();}\n\
    \  FPS inv(int d=-1)const{\n    NTT<Mod>ntt;\n    const int n=(*this).size();\n\
    \    if(d==-1)d=n;\n    FPS res{(*this)[0].inv()};\n    for(int m=1;m<d;m<<=1){\n\
    \      FPS f((*this).begin(),(*this).begin()+min(n,2*m));\n      FPS g(res);\n\
    \      f.resize(2*m),g.resize(2*m);\n      ntt.dft(f,1),ntt.dft(g,1);\n      for(int\
    \ i=0;i<2*m;i++)f[i]*=g[i];\n      ntt.dft(f,-1);\n      f.erase(f.begin(),f.begin()+m);\n\
    \      f.resize(2*m);ntt.dft(f,1);\n      for(int i=0;i<2*m;i++)f[i]*=g[i];\n\
    \      ntt.dft(f,-1);\n      mint iz=mint(2*m).inv();iz*=-iz;\n      for(int i=0;i<m;i++)f[i]*=iz;\n\
    \      res.insert(res.end(),f.begin(),f.begin()+m);\n    }\n    res.resize(d);\n\
    \    return res;\n  }\n  FPS operator+(const mint&r)const{return FPS(*this)+=r;}\n\
    \  FPS operator-(const mint&r)const{return FPS(*this)-=r;}\n  FPS operator*(const\
    \ mint&r)const{return FPS(*this)*=r;}\n  FPS operator/(const mint&r)const{return\
    \ FPS(*this)/=r;}\n  FPS operator+(const FPS&r)const{return FPS(*this)+=r;}\n\
    \  FPS operator-(const FPS&r)const{return FPS(*this)-=r;}\n  FPS operator<<(const\
    \ int&d)const{return FPS(*this)<<=d;}\n  FPS operator>>(const int&d)const{return\
    \ FPS(*this)>>=d;}\n  FPS operator*(const FPS&r)const{return FPS(*this)*=r;}\n\
    \  FPS operator/(const FPS&r)const{return FPS(*this)/=r;}\n  FPS operator%(const\
    \ FPS&r)const{return FPS(*this)%=r;}\n  FPS operator-()const{\n    FPS ret(*this);\n\
    \    for(auto &i:ret)i=-i;\n    return ret;\n  }\n  FPS &operator+=(const mint&r){\n\
    \    if((*this).empty())(*this).resize(1);\n    (*this)[0]+=r;\n    return *this;\n\
    \  }\n  FPS &operator-=(const mint&r){\n    if((*this).empty())(*this).resize(1);\n\
    \    (*this)[0]-=r;\n    return *this;\n  }\n  FPS &operator*=(const mint&r){\n\
    \    for(auto &i:*this)i*=r;\n    return *this;\n  }\n  FPS &operator/=(const\
    \ mint&r){\n    (*this)*=r.inv();\n    return *this;\n  }\n  FPS &operator+=(const\
    \ FPS&r){\n    const int n=(*this).size(),m=r.size();\n    (*this).resize(max(n,m));\n\
    \    for(int i=0;i<m;i++)(*this)[i]+=r[i];\n    return *this;\n  }\n  FPS &operator-=(const\
    \ FPS&r){\n    const int n=(*this).size(),m=r.size();\n    (*this).resize(max(n,m));\n\
    \    for(int i=0;i<m;i++)(*this)[i]-=r[i];\n    return *this;\n  }\n  FPS &operator<<=(const\
    \ int&d){\n    (*this).insert((*this).begin(),d,mint(0));\n    return *this;\n\
    \  }\n  FPS &operator>>=(const int&d){\n    (*this).erase((*this).begin(),(*this).begin()+d);\n\
    \    return *this;\n  }\n  FPS &operator*=(const FPS&r){\n    (*this)=NTT<Mod>::multiply((*this),r);\n\
    \    return *this;\n  }\n  FPS &operator/=(FPS r){\n    const int n=(*this).size(),m=r.size();\n\
    \    if(n<m){\n      (*this).clear();\n      return *this;\n    }\n    const int\
    \ sz=n-m+1;\n    reverse((*this).begin(),(*this).end());\n    reverse(r.begin(),r.end());\n\
    \    (*this).resize(sz);\n    (*this)*=r.inv(sz);\n    (*this).resize(sz);\n \
    \   reverse((*this).begin(),(*this).end());\n    return (*this);\n  }\n  FPS &operator%=(const\
    \ FPS&r){\n    const int n=(*this).size(),m=r.size();\n    if(n<m)return (*this);\n\
    \    (*this)-=(*this)/r*r;\n    (*this).resize(m-1);\n    shrink();\n    return\
    \ (*this);\n  }\n  pair<FPS,FPS>div_mod(const FPS&r){\n    FPS p=*this/r,q=*this-p*r;\n\
    \    q.shrink();\n    return {p,q};\n  }\n  mint operator()(const mint&x)const{\n\
    \    mint ret(0),w(1);\n    for(auto &e:*this){\n      ret+=e*w;\n      w*=x;\n\
    \    }\n    return ret;\n  }\n  FPS diff()const{\n    const int n=(*this).size();\n\
    \    FPS ret(max(0,n-1));\n    for(int i=1;i<n;i++)ret[i-1]=(*this)[i]*mint(i);\n\
    \    return ret;\n  }\n  FPS integral()const{\n    const int n=(*this).size();\n\
    \    vector<mint>inv(n+1);\n    inv[1]=mint(1);\n    for(int i=2;i<=n;i++)inv[i]=-inv[Mod%i]*mint(Mod/i);\n\
    \    FPS ret(n+1);\n    for(int i=0;i<n;i++)ret[i+1]=(*this)[i]*inv[i+1];\n  \
    \  return ret;\n  }\n  FPS log(int d=-1)const{\n    const int n=(*this).size();\n\
    \    if(d==-1)d=n;\n    FPS res=diff()*inv(d);\n    res.resize(d-1);\n    return\
    \ res.integral();\n  }\n};\n#line 4 \"test/yosupo/log_of_formal_power_series.test.cpp\"\
    \nint main(){\n  int n;\n  cin>>n;\n  FPS<mod>fps(n);\n  cin>>fps;\n  print(fps.log());\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\
    \n#include\"../../template/template.hpp\"\n#include\"../../Math/fps.hpp\"\nint\
    \ main(){\n  int n;\n  cin>>n;\n  FPS<mod>fps(n);\n  cin>>fps;\n  print(fps.log());\n\
    }"
  dependsOn:
  - template/template.hpp
  - Math/fps.hpp
  - Math/ntt.hpp
  - Math/modint.hpp
  isVerificationFile: true
  path: test/yosupo/log_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2022-01-05 16:51:06+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/log_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/log_of_formal_power_series.test.cpp
- /verify/test/yosupo/log_of_formal_power_series.test.cpp.html
title: test/yosupo/log_of_formal_power_series.test.cpp
---
