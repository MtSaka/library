---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/dual_segtree.hpp
    title: "Dual Segment Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: Data_Structure/lazy_segtree.hpp
    title: "Lazy Segment Tree(\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: Data_Structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: Data_Structure/segtree_monoids.hpp
    title: "Monoids(\u30E2\u30CE\u30A4\u30C9)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E
  bundledCode: "#line 1 \"test/aoj/DSL/DSL_2_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E\"\
    \n#line 2 \"template/template.hpp\"\n//#pragma GCC target(\"avx\")\n//#pragma\
    \ GCC optimize(\"O3\")\n//#pragma GCC optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\n\
    #define overload4(a,b,c,d,e,...) e\n#define overload3(a,b,c,d,...) d\n#define\
    \ rep1(a) for(ll i=0;i<(ll)(a);i++)\n#define rep2(i,a) for(ll i=0;i<(ll)(a);i++)\n\
    #define rep3(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)\n#define rep4(i,a,b,c) for(ll\
    \ i=(ll)(a);i<(ll)(b);i+=(ll)(c))\n#define rep(...) overload4(__VA_ARGS__, rep4,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n#define rrep1(a) for(ll i=(ll)(a)-1;i>=0;i--)\n\
    #define rrep2(i,a) for(ll i=(ll)(a)-1;i>=0;i--)\n#define rrep3(i,a,b) for(ll i=(ll)(b)-1;i>=(ll)(a);i--)\n\
    #define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)\n#define\
    \ fore(...) for (auto&& __VA_ARGS__)\n#define all1(i) begin(i),end(i)\n#define\
    \ all2(i,a) begin(i),begin(i)+a\n#define all3(i,a,b) begin(i)+a,begin(i)+b\n#define\
    \ all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)\n#define rall(n)\
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
    Data_Structure/segtree.hpp\"\ntemplate<class S,S (*op)(S,S),S (*e)()>\nstruct\
    \ segtree{\n  private:\n  int _n,size=1,idx=0;\n  vector<S>seq;\n  void update(int\
    \ k){seq[k]=op(seq[k<<1],seq[k<<1^1]);}\n  public:\n  segtree():segtree(0){};\n\
    \  segtree(int n):segtree(vector<S>(n,e())){}\n  segtree(const vector<S>&v):_n(int(v.size())){\n\
    \    while(size<_n)size<<=1,idx++;\n    seq=vector<S>(size<<1,e());\n    for(int\
    \ i=0;i<_n;i++)seq[size+i]=v[i];\n    for(int i=size-1;i>=1;i--)update(i);\n \
    \ }\n  void set(int p,S x){\n    p+=size;\n    seq[p]=x;\n    for(int i=1;i<=idx;i++)update(p>>i);\n\
    \  }\n  S operator[](int p)const{return seq[p+size];}\n  S query(int l,int r)const{\n\
    \    S sml=e(),smr=e();\n    l+=size,r+=size;\n    while(l<r){\n      if(l&1)sml=op(sml,seq[l++]);\n\
    \      if(r&1)smr=op(seq[--r],smr);\n      l>>=1,r>>=1;\n    }\n    return op(sml,smr);\n\
    \  }\n  S all_query()const{return seq[1];}\n  template<typename F>\n  int find_right(int\
    \ l,const F&f)const{\n    if(l==_n)return _n;\n    l+=size;\n    S sum=e();\n\
    \    do{\n      while(!(l&1))l>>=1;\n      if(!f(op(sum,seq[l]))){\n        while(l<size){\n\
    \          l<<=1;\n          if(f(op(sum,seq[l])))sum=op(sum,seq[l++]);\n    \
    \    }\n        return l-size;\n      }\n      sum=op(sum,seq[l++]);\n    }while((l&-l)!=l);\n\
    \    return _n;\n  }\n  template<typename F>\n  int find_left(int r,const F&f)const{\n\
    \    if(!r)return 0;\n    r+=size;\n    S sum=e();\n    do{\n      r--;\n    \
    \  while(r>1&&(r&1))r>>=1;\n      if(!f(op(seq[r],sum))){\n        while(r<size){\n\
    \          (r<<=1)++;\n          if(f(op(seq[r],sum)))sum=op(seq[r--],sum);\n\
    \        }\n        return r+1-size;\n      }\n      sum=op(seq[r],sum);\n   \
    \ }while((r&-r)!=r);\n    return 0;\n  }\n};\n/**\n * @brief Segment Tree(\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728)\n * @docs docs/segtree.md\n*/\n#line 2 \"Data_Structure/lazy_segtree.hpp\"\
    \ntemplate<class S,S (*op)(S,S),S (*e)(),class F,S (*mapping)(F,S),F (*composition)(F,F),F\
    \ (*id)()>\nstruct lazy_segtree{\n  private:\n  int _n,size=1,idx=0;\n  vector<S>seq;\n\
    \  vector<F>lazy;\n  void update(int k){seq[k]=op(seq[k<<1],seq[k<<1^1]);}\n \
    \ void all_apply(int k,F f){\n    seq[k]=mapping(f,seq[k]);\n    if(k<size)lazy[k]=composition(f,lazy[k]);\n\
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
    \ Tree(\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n*/\n#line 2 \"Data_Structure/dual_segtree.hpp\"\
    \ntemplate<class S,class F,S (*mapping)(F,S),F (*composition)(F,F),F (*id)()>\n\
    struct dual_segtree{\n  private:\n  int _n,size=1,idx=0;\n  vector<S>seq;\n  vector<F>lazy;\n\
    \  void all_apply(int k,F f){\n    if(k<size)lazy[k]=composition(f,lazy[k]);\n\
    \    else if(k<size+_n)seq[k-size]=mapping(f,seq[k-size]);\n  }\n  void eval(int\
    \ k){\n    all_apply(k<<1,lazy[k]);\n    all_apply(k<<1^1,lazy[k]);\n    lazy[k]=id();\n\
    \  }\n  public:\n  dual_segtree():dual_segtree(0){}\n  dual_segtree(int n,S e=S()):dual_segtree(vector<S>(n,e)){};\n\
    \  dual_segtree(const vector<S>&v):_n(v.size()){\n    while(size<_n)size<<=1,idx++;\n\
    \    seq=v;lazy=vector<F>(size,id());\n  }\n  void set(int p,S x){\n    p+=size;\n\
    \    for(int i=idx;i>=1;i--)eval(p>>i);\n    seq[p-size]=x;\n  }\n  S operator[](int\
    \ p){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n    return seq[p-size];\n\
    \  }\n  void apply(int p,F f){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n\
    \    seq[p-size]=mapping(f,seq[p-size]);\n  }\n  void apply(int l,int r,F f){\n\
    \    if(l==r)return;\n    l+=size;r+=size;\n    for(int i=idx;i>=1;i--){\n   \
    \   if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n    }\n\
    \    while(l<r){\n      if(l&1)all_apply(l++,f);\n      if(r&1)all_apply(--r,f);\n\
    \      l>>=1,r>>=1;\n    }\n  }\n};\n/**\n *@brief Dual Segment Tree(\u53CC\u5BFE\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n*/\n#line 6 \"Data_Structure/segtree_monoids.hpp\"\
    \nnamespace monoid_segtree{\n  template<class T>static constexpr T op1(T a,T b){return\
    \ min<T>(a,b);}\n  template<class T>static constexpr T op2(T a,T b){return max<T>(a,b);}\n\
    \  template<class T>static constexpr T op3(T a,T b){return a+b;}\n  template<class\
    \ T>static constexpr T e1(){return infinity<T>::MAX;}\n  template<class T>static\
    \ constexpr T e2(){return infinity<T>::MIN;}\n  template<class T>static constexpr\
    \ T e3(){return T(0);}\n  template<class T>using RmQ=segtree<T,op1<T>,e1<T>>;\n\
    \  template<class T>using RMQ=segtree<T,op2<T>,e2<T>>;\n  template<class T>using\
    \ RSQ=segtree<T,op3<T>,e3<T>>;\n}\nusing monoid_segtree::RmQ;\nusing monoid_segtree::RMQ;\n\
    using monoid_segtree::RSQ;\nnamespace monoid_lazy_segtree{\n  template<class T>struct\
    \ S{T value;int size;S(const T&a):value(a),size(1){}S(const T&a,const int&size):value(a),size(size){}operator\
    \ T()const{return value;}};\n  template<class T>static constexpr T op1(T a,T b){return\
    \ min<T>(a,b);}\n  template<class T>static constexpr T op2(T a,T b){return max<T>(a,b);}\n\
    \  template<class T>static constexpr S<T> op3(S<T>a,S<T>b){return {a.value+b.value,a.size+b.size};}\n\
    \  template<class T>static constexpr T e1(){return infinity<T>::MAX;}\n  template<class\
    \ T>static constexpr T e2(){return infinity<T>::MIN;}\n  template<class T>static\
    \ constexpr S<T> e3(){return {T(0),0};}\n  template<class T>static constexpr T\
    \ mapping1(T a,T b){return a==infinity<T>::MAX?b:a;}\n  template<class T>static\
    \ constexpr S<T> mapping2(T a,S<T>b){if(a!=infinity<T>::MAX)b.value=a*b.size;return\
    \ b;}\n  template<class T>static constexpr S<T> mapping3(T a,S<T>b){return {b.value+a*b.size,b.size};}\n\
    \  template<class T>static constexpr T mapping4(T a,T b){return a+b;}\n  template<class\
    \ T>static constexpr T mapping5(T a,T b){return min<T>(a,b);}\n  template<class\
    \ T>static constexpr T mapping6(T a,T b){return max<T>(a,b);}\n  template<class\
    \ T>static constexpr T composition1(T a,T b){return a==infinity<T>::MAX?b:a;}\n\
    \  template<class T>static constexpr T composition2(T a,T b){return a+b;}\n  template<class\
    \ T>static constexpr T composition3(T a,T b){return min<T>(a,b);}\n  template<class\
    \ T>static constexpr T composition4(T a,T b){return max<T>(a,b);}\n  template<class\
    \ T>static constexpr T id1(){return infinity<T>::MAX;}\n  template<class T>static\
    \ constexpr T id2(){return T(0);}\n  template<class T>static constexpr T id3(){return\
    \ infinity<T>::MIN;}\n  template<class T>using RUQRmQ=lazy_segtree<T,op1<T>,e1<T>,T,mapping1<T>,composition1<T>,id1<T>>;\n\
    \  template<class T>using RUQRMQ=lazy_segtree<T,op2<T>,e2<T>,T,mapping1<T>,composition1<T>,id1<T>>;\n\
    \  template<class T>using RUQRSQ=lazy_segtree<S<T>,op3<T>,e3<T>,T,mapping2<T>,composition1<T>,id1<T>>;\n\
    \  template<class T>using RAQRSQ=lazy_segtree<S<T>,op3<T>,e3<T>,T,mapping3<T>,composition2<T>,id2<T>>;\n\
    \  template<class T>using RAQRmQ=lazy_segtree<T,op1<T>,e1<T>,T,mapping4<T>,composition2<T>,id2<T>>;\n\
    \  template<class T>using RAQRMQ=lazy_segtree<T,op2<T>,e2<T>,T,mapping4<T>,composition2<T>,id2<T>>;\n\
    \  template<class T>using RChminRmQ=lazy_segtree<T,op1<T>,e1<T>,T,mapping5<T>,composition3<T>,id1<T>>;\n\
    \  template<class T>using RChminRMQ=lazy_segtree<T,op2<T>,e2<T>,T,mapping5<T>,composition3<T>,id1<T>>;\n\
    \  template<class T>using RChmaxRmQ=lazy_segtree<T,op1<T>,e1<T>,T,mapping6<T>,composition4<T>,id3<T>>;\n\
    \  template<class T>using RChmaxRMQ=lazy_segtree<T,op2<T>,e2<T>,T,mapping6<T>,composition4<T>,id3<T>>;\n\
    }\nusing monoid_lazy_segtree::RUQRmQ;\nusing monoid_lazy_segtree::RUQRMQ;\nusing\
    \ monoid_lazy_segtree::RUQRSQ;\nusing monoid_lazy_segtree::RAQRSQ;\nusing monoid_lazy_segtree::RAQRmQ;\n\
    using monoid_lazy_segtree::RAQRMQ;\nusing monoid_lazy_segtree::RChminRmQ;\nusing\
    \ monoid_lazy_segtree::RChminRMQ;\nusing monoid_lazy_segtree::RChmaxRmQ;\nusing\
    \ monoid_lazy_segtree::RChmaxRMQ;\nnamespace monoid_dual_segtree{\n  template<class\
    \ T>static constexpr T mapping1(T a,T b){return a==infinity<T>::MAX?b:a;}\n  template<class\
    \ T>static constexpr T mapping2(T a,T b){return min<T>(a,b);}\n  template<class\
    \ T>static constexpr T mapping3(T a,T b){return max<T>(a,b);}\n  template<class\
    \ T>static constexpr T mapping4(T a,T b){return a+b;}\n  template<class T>static\
    \ constexpr T composition1(T a,T b){return a==infinity<T>::MAX?b:a;}\n  template<class\
    \ T>static constexpr T composition2(T a,T b){return min<T>(a,b);}\n  template<class\
    \ T>static constexpr T composition3(T a,T b){return max<T>(a,b);}\n  template<class\
    \ T>static constexpr T composition4(T a,T b){return a+b;}\n  template<class T>static\
    \ constexpr T id1(){return infinity<T>::MAX;}\n  template<class T>static constexpr\
    \ T id2(){return infinity<T>::MIN;}\n  template<class T>static constexpr T id3(){return\
    \ T(0);}\n  template<class T>using RUQ=dual_segtree<T,T,mapping1<T>,composition1<T>,id1<T>>;\n\
    \  template<class T>using RChminQ=dual_segtree<T,T,mapping2<T>,composition2<T>,id1<T>>;\n\
    \  template<class T>using RChmaxQ=dual_segtree<T,T,mapping3<T>,composition3<T>,id2<T>>;\n\
    \  template<class T>using RAQ=dual_segtree<T,T,mapping4<T>,composition4<T>,id3<T>>;\n\
    }\nusing monoid_dual_segtree::RUQ;\nusing monoid_dual_segtree::RChminQ;\nusing\
    \ monoid_dual_segtree::RChmaxQ;\nusing monoid_dual_segtree::RAQ;\n/**\n * @brief\
    \ Monoids(\u30E2\u30CE\u30A4\u30C9)\n */\n#line 4 \"test/aoj/DSL/DSL_2_E.test.cpp\"\
    \nint main(){\n  int n,q;cin>>n>>q;\n  RAQ<int>seg(n,0);\n  while(q--){\n    int\
    \ t;cin>>t;\n    if(t==0){\n      int l,r,x;cin>>l>>r>>x;\n      seg.apply(l-1,r,x);\n\
    \    }\n    else{\n      int k;cin>>k;\n      print(seg[k-1]);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E\"\n#include\"\
    ../../../template/template.hpp\"\n#include\"../../../Data_Structure/segtree_monoids.hpp\"\
    \nint main(){\n  int n,q;cin>>n>>q;\n  RAQ<int>seg(n,0);\n  while(q--){\n    int\
    \ t;cin>>t;\n    if(t==0){\n      int l,r,x;cin>>l>>r>>x;\n      seg.apply(l-1,r,x);\n\
    \    }\n    else{\n      int k;cin>>k;\n      print(seg[k-1]);\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Data_Structure/segtree_monoids.hpp
  - Data_Structure/segtree.hpp
  - Data_Structure/lazy_segtree.hpp
  - Data_Structure/dual_segtree.hpp
  isVerificationFile: true
  path: test/aoj/DSL/DSL_2_E.test.cpp
  requiredBy: []
  timestamp: '2022-07-04 00:22:36+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_2_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_2_E.test.cpp
- /verify/test/aoj/DSL/DSL_2_E.test.cpp.html
title: test/aoj/DSL/DSL_2_E.test.cpp
---
