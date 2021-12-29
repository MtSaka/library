---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo/point_set_range_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n#line\
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
    \u30D7\u30EC\u30FC\u30C8)\n*/\n#line 1 \"Data_Structure/segtree.hpp\"\n/**\n *\
    \ @brief Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n*/\ntemplate<class\
    \ S,S (*op)(S,S),S (*e)()>\nstruct segtree{\n  private:\n  int _n,size,idx=0;\n\
    \  vector<S>seq;\n  void update(int k){seq[k]=op(seq[2*k],seq[2*k+1]);}\n  public:\n\
    \  segtree():segtree(0){};\n  segtree(int n):segtree(vector<S>(n,e())){}\n  segtree(const\
    \ vector<S>&v):_n(int(v.size())){\n    while((1<<idx)<_n)idx++;\n    size=1<<idx;\n\
    \    seq=vector<S>(2*size,e());\n    for(int i=0;i<_n;i++)seq[size+i]=v[i];\n\
    \    for(int i=size-1;i>=1;i--)update(i);\n  }\n  void set(int p,S x){\n    p+=size;\n\
    \    seq[p]=x;\n    for(int i=1;i<=idx;i++)update(p>>i);\n  }\n  S operator[](int\
    \ p){return seq[p+size];}\n  S query(int l,int r)const{\n    S sml=e(),smr=e();\n\
    \    l+=size,r+=size;\n    while(l<r){\n      if(l&1)sml=op(sml,seq[l++]);\n \
    \     if(r&1)smr=op(seq[--r],smr);\n      l>>=1,r>>=1;\n    }\n    return op(sml,smr);\n\
    \  }\n  S all_query()const{\n    return seq[1];\n  }\n};\n#line 1 \"Math/modint.hpp\"\
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
    \  }\n  static long long get_mod(){return m;}\n};\n#line 5 \"test/yosupo/point_set_range_composite.test.cpp\"\
    \nusing mint=modint<mod>;\nusing S=pair<mint,mint>;\nS op(S a,S b){return S{a.first*b.first,a.second*b.first+b.second};}\n\
    S e(){return S{mint(1),mint(0)};}\nint main(){\n  int n,q;\n  cin>>n>>q;\n  vector<S>a(n);\n\
    \  cin>>a;\n  segtree<S,op,e>s(a);\n  while(q--){\n    int t;\n    cin>>t;\n \
    \   if(t){\n      int l,r,x;\n      cin>>l>>r>>x;\n      auto [n,m]=s.query(l,r);\n\
    \      cout<<n*mint(x)+m<<endl;\n    }\n    else{\n      int p;\n      cin>>p;\n\
    \      mint c,d;\n      cin>>c>>d;\n      s.set(p,S{c,d});\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include\"../../template/template.hpp\"\n#include\"../../Data_Structure/segtree.hpp\"\
    \n#include\"../../Math/modint.hpp\"\nusing mint=modint<mod>;\nusing S=pair<mint,mint>;\n\
    S op(S a,S b){return S{a.first*b.first,a.second*b.first+b.second};}\nS e(){return\
    \ S{mint(1),mint(0)};}\nint main(){\n  int n,q;\n  cin>>n>>q;\n  vector<S>a(n);\n\
    \  cin>>a;\n  segtree<S,op,e>s(a);\n  while(q--){\n    int t;\n    cin>>t;\n \
    \   if(t){\n      int l,r,x;\n      cin>>l>>r>>x;\n      auto [n,m]=s.query(l,r);\n\
    \      cout<<n*mint(x)+m<<endl;\n    }\n    else{\n      int p;\n      cin>>p;\n\
    \      mint c,d;\n      cin>>c>>d;\n      s.set(p,S{c,d});\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Data_Structure/segtree.hpp
  - Math/modint.hpp
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2021-12-29 21:42:40+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.test.cpp
- /verify/test/yosupo/point_set_range_composite.test.cpp.html
title: test/yosupo/point_set_range_composite.test.cpp
---
