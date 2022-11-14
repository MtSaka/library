---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/lazy_segtree.hpp
    title: "Lazy Segment Tree(\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':question:'
    path: Math/modular/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n#line 2 \"template/template.hpp\"\
    \n//#pragma GCC target(\"avx\")\n//#pragma GCC optimize(\"O3\")\n//#pragma GCC\
    \ optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\n#define overload4(a,b,c,d,e,...)\
    \ e\n#define overload3(a,b,c,d,...) d\n#define rep1(a) for(ll i=0;i<(ll)(a);i++)\n\
    #define rep2(i,a) for(ll i=0;i<(ll)(a);i++)\n#define rep3(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)\n\
    #define rep4(i,a,b,c) for(ll i=(ll)(a);i<(ll)(b);i+=(ll)(c))\n#define rep(...)\
    \ overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rrep1(a)\
    \ for(ll i=(ll)(a)-1;i>=0;i--)\n#define rrep2(i,a) for(ll i=(ll)(a)-1;i>=0;i--)\n\
    #define rrep3(i,a,b) for(ll i=(ll)(b)-1;i>=(ll)(a);i--)\n#define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)\n\
    #define fore(...) for (auto&& __VA_ARGS__)\n#define all1(i) begin(i),end(i)\n\
    #define all2(i,a) begin(i),begin(i)+a\n#define all3(i,a,b) begin(i)+a,begin(i)+b\n\
    #define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)\n#define rall(n)\
    \ (n).rbegin(),(n).rend()\n#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)\n#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)\n#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)\n#define pb push_back\n#define\
    \ eb emplace_back\n#define END(...) {print(__VA_ARGS__);return;}\nusing namespace\
    \ std;\nusing ll=long long;\nusing ull=unsigned long long;\nusing ld=long double;\n\
    using vl=vector<ll>;\nusing vi=vector<int>;\nusing vs=vector<string>;\nusing vc=vector<char>;\n\
    using vvl=vector<vl>;\nusing pi=pair<int,int>;\nusing pl=pair<ll,ll>;\nusing vvc=vector<vc>;\n\
    using vd=vector<double>;\nusing vp=vector<pl>;\nusing vb=vector<bool>;\nconstexpr\
    \ int dx[8]={1,0,-1,0,1,-1,-1,1};\nconstexpr int dy[8]={0,1,0,-1,1,1,-1,-1};\n\
    constexpr ll MOD=1000000007;\nconstexpr ll mod=998244353;\nconstexpr ld EPS=1e-8;\n\
    constexpr ld PI=3.1415926535897932384626;\ntemplate<typename T,typename U>\nostream\
    \ &operator<<(ostream&os,const pair<T,U>&p){os<<p.first<<\" \"<<p.second;return\
    \ os;}\ntemplate<typename T,typename U>\nistream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return\
    \ is;}\ntemplate<typename T>\nostream &operator<<(ostream&os,const vector<T>&v){for(auto\
    \ it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?\" \":\"\");}return os;}\n\
    template<typename T>\nistream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return\
    \ is;}\nvoid scan(){}\ntemplate<class Head,class... Tail>\nvoid scan(Head&head,Tail&...\
    \ tail){cin>>head;scan(tail...);}\ntemplate<class T>\nvoid print(const T &t){cout<<t<<'\\\
    n';}\ntemplate<class Head, class... Tail>\nvoid print(const Head &head, const\
    \ Tail &... tail){cout<<head<<' ';print(tail...);}\ntemplate<class... T>\nvoid\
    \ fin(const T &... a){print(a...);exit(0);}\ntemplate<typename T,typename U>\n\
    inline bool chmax(T&a,U b){return a<b&&(a=b,true);}\ntemplate<typename T,typename\
    \ U>\ninline bool chmin(T&a,U b){return a>b&&(a=b,true);}\ntemplate<typename T>\n\
    class infinity{\n  public:\n  static constexpr T MAX=numeric_limits<T>::max();\n\
    \  static constexpr T MIN=numeric_limits<T>::min();\n  static constexpr T value=numeric_limits<T>::max()/2;\n\
    \  static constexpr T mvalue=numeric_limits<T>::min()/2;\n};\n#if __cplusplus\
    \ <= 201402L\ntemplate<class T>constexpr T infinity<T>::value;\ntemplate<class\
    \ T>constexpr T infinity<T>::mvalue;\ntemplate<class T>constexpr T infinity<T>::MAX;\n\
    template<class T>constexpr T infinity<T>::MIN;\n#endif\ntemplate<typename T>constexpr\
    \ T INF=infinity<T>::value;\nconstexpr long long inf=INF<ll>;\ninline int popcnt(ull\
    \ x){\n#if __cplusplus>=202002L\nreturn popcount(x);\n#endif\nx=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);return\
    \ (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);\n}\ntemplate<typename T,typename=void>\n\
    struct is_specialize:false_type{};\ntemplate<typename T>\nstruct is_specialize<T,typename\
    \ conditional<false,typename T::iterator, void>::type>:true_type{};\ntemplate<typename\
    \ T>\nstruct is_specialize<T,typename conditional<false,decltype(T::first),void>::type>:true_type{};\n\
    template<typename T>\nstruct is_specialize<T,enable_if_t<is_integral<T>::value,void>>:true_type{};\n\
    void dump(const char&t){cerr<<t;}\nvoid dump(const string&t){cerr<<t;}\nvoid dump(const\
    \ bool&t){cerr<<(t?\"true\":\"false\");}\ntemplate <typename T,enable_if_t<!is_specialize<T>::value,nullptr_t>\
    \ =nullptr>\nvoid dump(const T&t){cerr<<t;}\ntemplate<typename T>\nvoid dump(const\
    \ T&t,enable_if_t<is_integral<T>::value>* =nullptr){string tmp;if(t==infinity<T>::value||t==infinity<T>::MAX)tmp=\"\
    inf\";if(is_signed<T>::value&&(t==infinity<T>::mvalue||t==infinity<T>::MIN))tmp=\"\
    -inf\";if(tmp.empty())tmp=to_string(t);cerr<<tmp;}\ntemplate<typename T,typename\
    \ U>\nvoid dump(const pair<T,U>&);\ntemplate<typename T>\nvoid dump(const T&t,enable_if_t<!is_void<typename\
    \ T::iterator>::value>* =nullptr){cerr<<\"{\";for(auto it=t.begin();it!=t.end();){dump(*it);cerr<<(++it==t.end()?\"\
    \":\",\");}cerr<<\"}\";}\ntemplate<typename T,typename U>\nvoid dump(const pair<T,U>&t){cerr<<\"\
    (\";dump(t.first);cerr<<\",\";dump(t.second);cerr<<\")\";}\nvoid trace(){cerr<<endl;}\n\
    template<typename Head,typename... Tail>\nvoid trace(Head&&head,Tail&&... tail){dump(head);if(sizeof...(tail))cerr<<\"\
    ,\";trace(forward<Tail>(tail)...);}\n#ifdef ONLINE_JUDGE\n#define debug(...) (void(0))\n\
    #else\n#define debug(...) do{cerr<<#__VA_ARGS__<<\"=\";trace(__VA_ARGS__);}while(0)\n\
    #endif\nstruct IOSetup{IOSetup(){cin.tie(nullptr);ios::sync_with_stdio(false);cout.tie(0);cout<<fixed<<setprecision(12);cerr<<fixed<<setprecision(12);}};\n\
    template<class F>struct REC{F f;REC(F&&f_):f(std::forward<F>(f_)){}template<class...Args>auto\
    \ operator()(Args&&...args)const{return f(*this, std::forward<Args>(args)...);}};\n\
    /**\n * @brief Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 2 \"\
    Math/modular/modint.hpp\"\ntemplate<int m>\nstruct modint{\n  private:\n  unsigned\
    \ int x;\n  static constexpr unsigned int umod(){return m;}\n  public:\n  static\
    \ modint raw(int v){\n    modint ret;\n    ret.x=v;\n    return ret;\n  }\n  constexpr\
    \ modint():x(0){}\n  constexpr modint(int y){\n    int v=y%m;\n    if(v<0)v+=m;\n\
    \    x=(unsigned int)v;\n  }\n  constexpr modint(long long y){\n    long long\
    \ v=y%(long long)m;\n    if(v<0)v+=m;\n    x=(unsigned int)v;\n  }\n  constexpr\
    \ modint(unsigned int y){\n    x=(unsigned int)(y%umod());\n  }\n  modint& operator++(){x++;if(x==umod())x=0;return\
    \ *this;}\n  modint& operator--(){if(x==0)x=umod();x--;return *this;}\n  modint\
    \ operator++(int){\n    modint ret=*this;\n    ++*this;\n    return ret;\n  }\n\
    \  modint operator--(int){\n    modint ret=*this;\n    --*this;\n    return ret;\n\
    \  }\n  modint& operator+=(const modint&p){if((x+=p.x)>=umod())x-=umod();return\
    \ *this;}\n  modint& operator-=(const modint&p){if((x-=p.x)>=umod())x+=umod();return\
    \ *this;}\n  modint& operator*=(const modint&p){\n    unsigned long long y=x;\n\
    \    y*=p.x;\n    x=(unsigned int)(y%umod());\n    return *this;\n  }\n  modint&\
    \ operator/=(const modint&p){return *this*=p.inv();}\n  modint operator+()const{return\
    \ *this;}\n  modint operator-()const{return modint()-*this;}\n  modint pow(long\
    \ long n)const{\n    modint ret(1),mul=*this;\n    while(n){\n      if(n&1)ret*=mul;\n\
    \      mul*=mul;\n      n>>=1;\n    }\n    return ret;\n  }\n  modint inv()const{\n\
    \    long long a=x,b=m,u=1,v=0;\n    while(b){\n      long long t=a/b;\n     \
    \ swap(a-=t*b,b);\n      swap(u-=t*v,v);\n    }\n    return modint(u);\n  }\n\
    \  friend modint operator+(const modint&l,const modint&r){return modint(l)+=r;}\n\
    \  friend modint operator-(const modint&l,const modint&r){return modint(l)-=r;}\n\
    \  friend modint operator*(const modint&l,const modint&r){return modint(l)*=r;}\n\
    \  friend modint operator/(const modint&l,const modint&r){return modint(l)/=r;}\n\
    \  friend bool operator==(const modint&l,const modint&r){return l.x==r.x;}\n \
    \ friend bool operator!=(const modint&l,const modint&r){return l.x!=r.x;}\n  friend\
    \ ostream &operator<<(ostream &os,const modint&p) {\n    return os<<p.val();\n\
    \  }\n  friend istream &operator>>(istream &is, modint &a) {\n    long long t;\n\
    \    is>>t;\n    a=modint(t);\n    return (is);\n  }\n  static constexpr int get_mod(){return\
    \ m;}\n  int val()const{return (int)x;}\n};\n/**\n * @brief modint\n*/\n#line\
    \ 2 \"Data_Structure/lazy_segtree.hpp\"\ntemplate<class S,S (*op)(S,S),S (*e)(),class\
    \ F,S (*mapping)(F,S),F (*composition)(F,F),F (*id)()>\nstruct lazy_segtree{\n\
    \  private:\n  int _n,size=1,idx=0;\n  vector<S>seq;\n  vector<F>lazy;\n  void\
    \ update(int k){seq[k]=op(seq[k<<1],seq[k<<1^1]);}\n  void all_apply(int k,F f){\n\
    \    seq[k]=mapping(f,seq[k]);\n    if(k<size)lazy[k]=composition(f,lazy[k]);\n\
    \  }\n  void eval(int k){\n    all_apply(k<<1,lazy[k]);\n    all_apply(k<<1^1,lazy[k]);\n\
    \    lazy[k]=id();\n  }\n  public:\n  lazy_segtree():lazy_segtree(0){}\n  lazy_segtree(int\
    \ n):lazy_segtree(vector<S>(n,e())){}\n  lazy_segtree(const vector<S>&v):_n(int(v.size())){\n\
    \    while(size<_n)size<<=1,idx++;\n    seq=vector<S>(size<<1,e());\n    lazy=vector<F>(size,id());\n\
    \    for(int i=0;i<_n;i++)seq[size+i]=v[i];\n    for(int i=size-1;i>=1;i--)update(i);\n\
    \  }\n  void set(int p,S x){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n\
    \    seq[p]=x;\n    for(int i=1;i<=idx;i++)update(p>>i);\n  }\n  S operator[](int\
    \ p){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n    return seq[p];\n\
    \  }\n  S query(int l,int r){\n    if(l==r)return e();\n    S sml=e(),smr=e();\n\
    \    l+=size,r+=size;\n    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n\
    \      if(((r>>i)<<i)!=r)eval(r>>i);\n    }\n    while(l<r){\n      if(l&1)sml=op(sml,seq[l++]);\n\
    \      if(r&1)smr=op(seq[--r],smr);\n      l>>=1,r>>=1;\n    }\n    return op(sml,smr);\n\
    \  }\n  S all_query()const{return seq[1];}\n  void apply(int p,F f){\n    p+=size;\n\
    \    for(int i=idx;i>=1;i--)eval(p>>i);\n    seq[p]=mapping(f,seq[p]);\n    for(int\
    \ i=1;i<=idx;i++)update(p>>i);\n  }\n  void apply(int l,int r,F f){\n    if(l==r)return\
    \ ;\n    l+=size;\n    r+=size;\n    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n\
    \      if(((r>>i)<<i)!=r)eval(r>>i);\n    }\n    int l2=l,r2=r;\n    while(l<r){\n\
    \      if(l&1)all_apply(l++,f);\n      if(r&1)all_apply(--r,f);\n      l>>=1;\n\
    \      r>>=1;\n    }\n    l=l2,r=r2;\n    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n\
    \      if(((r>>i)<<i)!=r)update(r>>i);\n    }\n  }\n};\n/**\n * @brief Lazy Segment\
    \ Tree(\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n*/\n#line 5 \"test/yosupo/range_affine_range_sum.test.cpp\"\
    \nusing mint=modint<mod>;\nusing Pi=pair<mint,int >;\nusing qi=pair<mint,mint>;\n\
    Pi op(Pi a,Pi b){return {a.first+b.first,a.second+b.second};}\nPi mapping(qi a,Pi\
    \ b){return {a.first*b.first+a.second*mint(b.second),b.second};}\nqi composition(qi\
    \ b,qi a){return {a.first*b.first,a.second*b.first+b.second};}\nPi e(){return\
    \ Pi(0,0);}\nqi id(){return qi(1,0);}\nint main(){\n  INT(n,q);\n  vector<Pi>a(n,{0,1});\n\
    \  rep(i,n)cin>>a[i].first;\n  lazy_segtree<Pi,op,e,qi,mapping,composition,id>s(a);\n\
    \  while(q--){\n    LL(t);\n    if(t){\n      INT(l,r);\n      print(s.query(l,r).first);\n\
    \    }\n    else{\n      INT(l,r);\n      mint b,c;\n      scan(b,c);\n      s.apply(l,r,qi(b,c));\n\
    \    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include\"../../template/template.hpp\"\n#include\"../../Math/modular/modint.hpp\"\
    \n#include\"../../Data_Structure/lazy_segtree.hpp\"\nusing mint=modint<mod>;\n\
    using Pi=pair<mint,int >;\nusing qi=pair<mint,mint>;\nPi op(Pi a,Pi b){return\
    \ {a.first+b.first,a.second+b.second};}\nPi mapping(qi a,Pi b){return {a.first*b.first+a.second*mint(b.second),b.second};}\n\
    qi composition(qi b,qi a){return {a.first*b.first,a.second*b.first+b.second};}\n\
    Pi e(){return Pi(0,0);}\nqi id(){return qi(1,0);}\nint main(){\n  INT(n,q);\n\
    \  vector<Pi>a(n,{0,1});\n  rep(i,n)cin>>a[i].first;\n  lazy_segtree<Pi,op,e,qi,mapping,composition,id>s(a);\n\
    \  while(q--){\n    LL(t);\n    if(t){\n      INT(l,r);\n      print(s.query(l,r).first);\n\
    \    }\n    else{\n      INT(l,r);\n      mint b,c;\n      scan(b,c);\n      s.apply(l,r,qi(b,c));\n\
    \    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Math/modular/modint.hpp
  - Data_Structure/lazy_segtree.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-07-18 21:10:31+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.test.cpp
- /verify/test/yosupo/range_affine_range_sum.test.cpp.html
title: test/yosupo/range_affine_range_sum.test.cpp
---
