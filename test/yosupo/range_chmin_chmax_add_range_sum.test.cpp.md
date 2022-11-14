---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/segtree_beats.hpp
    title: Segment Tree Beats!(Rnage Chmin Chmax Add Update Range Sum Min Max)
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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_chmin_chmax_add_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
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
    Data_Structure/segtree_beats.hpp\"\ntemplate<class T>\nstruct segtree_beats{\n\
    \  private:\n  static constexpr T INF=numeric_limits<T>::max();\n  struct S{\n\
    \    T sum=0,b1=0,s1=0,b2=-INF,s2=INF,b_cnt=1,s_cnt=1,add=0;\n    S(){}\n    S(const\
    \ T&a):sum(a),b1(a),s1(a){}\n  };\n  vector<S>seq;\n  int size=1,idx=0;\n  void\
    \ update(int k){\n    S&s=seq[k];\n    S&l=seq[2*k];\n    S&r=seq[2*k+1];\n  \
    \  s.sum=l.sum+r.sum;\n    if(l.b1==r.b1){\n      s.b1=l.b1;\n      s.b2=max(l.b2,r.b2);\n\
    \      s.b_cnt=l.b_cnt+r.b_cnt;\n    }\n    else{\n      s.b1=max(l.b1,r.b1);\n\
    \      s.b2=max(l.b1>r.b1?l.b2:l.b1,l.b1>r.b1?r.b1:r.b2);\n      s.b_cnt=l.b1>r.b1?l.b_cnt:r.b_cnt;\n\
    \    }\n    if(l.s1==r.s1){\n      s.s1=l.s1;\n      s.s2=min(l.s2,r.s2);\n  \
    \    s.s_cnt=l.s_cnt+r.s_cnt;\n    }\n    else{\n      s.s1=min(l.s1,r.s1);\n\
    \      s.s2=min(l.s1>r.s1?l.s1:l.s2,l.s1>r.s1?r.s2:r.s1);\n      s.s_cnt=l.s1>r.s1?r.s_cnt:l.s_cnt;\n\
    \    }\n  }\n  void eval_add(int k,T x){\n    S&s=seq[k];\n    s.sum+=x<<(idx+__builtin_clz(k)-31);\n\
    \    s.b1+=x,s.s1+=x;\n    if(s.b2!=-INF)s.b2+=x;\n    if(s.s2!=INF)s.s2+=x;\n\
    \    s.add+=x;\n  }\n  void eval_min(int k,T x){\n    S&s=seq[k];\n    s.sum+=(x-s.b1)*s.b_cnt;\n\
    \    if(s.s1==s.b1)s.s1=x;\n    if(s.s2==s.b1)s.s2=x;\n    s.b1=x;\n  }\n  void\
    \ eval_max(int k,T x){\n    S&s=seq[k];\n    s.sum+=(x-s.s1)*s.s_cnt;\n    if(s.b1==s.s1)s.b1=x;\n\
    \    if(s.b2==s.s1)s.b2=x;\n    s.s1=x;\n  }\n  void eval(int k){\n    S&s=seq[k];\n\
    \    if(s.add!=0){\n      eval_add(k*2,s.add);\n      eval_add(k*2+1,s.add);\n\
    \      s.add=0;\n    }\n    if(s.b1<seq[2*k].b1)eval_min(2*k,s.b1);\n    if(s.s1>seq[2*k].s1)eval_max(2*k,s.s1);\n\
    \    if(s.b1<seq[2*k+1].b1)eval_min(2*k+1,s.b1);\n    if(s.s1>seq[2*k+1].s1)eval_max(2*k+1,s.s1);\n\
    \  }\n  void apply_min(int k,T x){\n    if(seq[k].b1<=x)return;\n    if(seq[k].b2<x){\n\
    \      eval_min(k,x);\n      return;\n    }\n    eval(k);\n    apply_min(2*k,x);\n\
    \    apply_min(2*k+1,x);\n    update(k);\n  }\n  void apply_max(int k,T x){\n\
    \    if(seq[k].s1>=x)return;\n    if(seq[k].s2>x){\n      eval_max(k,x);\n   \
    \   return;\n    }\n    eval(k);\n    apply_max(2*k,x);\n    apply_max(2*k+1,x);\n\
    \    update(k);\n  }\n  void inner_chmin(int l,int r,T x){\n    if(l==r)return;\n\
    \    l+=size,r+=size;\n    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n\
    \      if(((r>>i)<<i)!=r)eval(r>>i);\n    }\n    int l2=l,r2=r;\n    while(l<r){\n\
    \      if(l&1)apply_min(l++,x);\n      if(r&1)apply_min(--r,x);\n      l>>=1;\n\
    \      r>>=1;\n    }\n    l=l2,r=r2;\n    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n\
    \      if(((r>>i)<<i)!=r)update(r>>i);\n    }\n  }\n  void inner_chmax(int l,int\
    \ r,T x){\n    if(l==r)return;\n    l+=size,r+=size;\n    for(int i=idx;i>=1;i--){\n\
    \      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n  \
    \  }\n    int l2=l,r2=r;\n    while(l<r){\n      if(l&1)apply_max(l++,x);\n  \
    \    if(r&1)apply_max(--r,x);\n      l>>=1;\n      r>>=1;\n    }\n    l=l2,r=r2;\n\
    \    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n      if(((r>>i)<<i)!=r)update(r>>i);\n\
    \    }\n  }\n  void inner_add(int l,int r,T x){\n    if(l==r)return;\n    l+=size,r+=size;\n\
    \    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    int l2=l,r2=r;\n    while(l<r){\n      if(l&1)eval_add(l++,x);\n \
    \     if(r&1)eval_add(--r,x);\n      l>>=1;\n      r>>=1;\n    }\n    l=l2,r=r2;\n\
    \    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n      if(((r>>i)<<i)!=r)update(r>>i);\n\
    \    }\n  }\n  void inner_update(int l,int r,T x){\n    if(l==r)return;\n    l+=size,r+=size;\n\
    \    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    int l2=l,r2=r;\n    while(l<r){\n      if(l&1)apply_min(l++,x),apply_max(l,x);\n\
    \      if(r&1)apply_min(--r,x),apply_max(r,x);\n      l>>=1;\n      r>>=1;\n \
    \   }\n    l=l2,r=r2;\n    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n\
    \      if(((r>>i)<<i)!=r)update(r>>i);\n    }\n  }\n  T inner_min(int l,int r){\n\
    \    if(l==r)return INF;\n    T sml=INF,smr=INF;\n    l+=size,r+=size;\n    for(int\
    \ i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    while(l<r){\n      if(l&1)sml=min(sml,seq[l++].s1);\n      if(r&1)smr=min(seq[--r].s1,smr);\n\
    \      l>>=1,r>>=1;\n    }\n    return min(sml,smr);\n  }\n  T inner_max(int l,int\
    \ r){\n    if(l==r)return -INF;\n    T sml=-INF,smr=-INF;\n    l+=size,r+=size;\n\
    \    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    while(l<r){\n      if(l&1)sml=max(sml,seq[l++].b1);\n      if(r&1)smr=max(seq[--r].b1,smr);\n\
    \      l>>=1,r>>=1;\n    }\n    return max(sml,smr);\n  }\n  T inner_sum(int l,int\
    \ r){\n    if(l==r)return 0;\n    T sml=0,smr=0;\n    l+=size,r+=size;\n    for(int\
    \ i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    while(l<r){\n      if(l&1)sml+=seq[l++].sum;\n      if(r&1)smr+=seq[--r].sum;\n\
    \      l>>=1,r>>=1;\n    }\n    return sml+smr;\n  }\n  public:\n  segtree_beats(){}\n\
    \  segtree_beats(int n):segtree_beats(vector<T>(n)){}\n  segtree_beats(const vector<T>&v){\n\
    \    const int n=v.size();\n    while(size<n)size<<=1,idx++;\n    seq.resize(2*size);\n\
    \    for(int i=0;i<n;i++)seq[i+size]=v[i];\n    for(int i=size-1;i;i--)update(i);\n\
    \  }\n  void range_chmin(int l,int r,T x){inner_chmin(l,r,x);}\n  void range_chmax(int\
    \ l,int r,T x){inner_chmax(l,r,x);}\n  void range_add(int l,int r,T x){inner_add(l,r,x);}\n\
    \  void range_update(int l,int r,T x){inner_update(l,r,x);}\n  T range_min(int\
    \ l,int r){return inner_min(l,r);}\n  T range_max(int l,int r){return inner_max(l,r);}\n\
    \  T range_sum(int l,int r){return inner_sum(l,r);}\n};\n/**\n * @brief Segment\
    \ Tree Beats!(Rnage Chmin Chmax Add Update Range Sum Min Max)\n*/\n#line 4 \"\
    test/yosupo/range_chmin_chmax_add_range_sum.test.cpp\"\nint main(){\n  int n,q;cin>>n>>q;\n\
    \  vl a(n);cin>>a;\n  segtree_beats<ll>seg(a);\n  while(q--){\n    int t;cin>>t;\n\
    \    if(t==0){\n      int l,r;ll x;\n      cin>>l>>r>>x;\n      seg.range_chmin(l,r,x);\n\
    \    }\n    else if(t==1){\n      int l,r;ll x;\n      cin>>l>>r>>x;\n      seg.range_chmax(l,r,x);\n\
    \    }\n    else if(t==2){\n      int l,r;ll x;\n      cin>>l>>r>>x;\n      seg.range_add(l,r,x);\n\
    \    }\n    else{\n      int l,r;cin>>l>>r;\n      print(seg.range_sum(l,r));\n\
    \    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include\"../../template/template.hpp\"\n#include\"../../Data_Structure/segtree_beats.hpp\"\
    \nint main(){\n  int n,q;cin>>n>>q;\n  vl a(n);cin>>a;\n  segtree_beats<ll>seg(a);\n\
    \  while(q--){\n    int t;cin>>t;\n    if(t==0){\n      int l,r;ll x;\n      cin>>l>>r>>x;\n\
    \      seg.range_chmin(l,r,x);\n    }\n    else if(t==1){\n      int l,r;ll x;\n\
    \      cin>>l>>r>>x;\n      seg.range_chmax(l,r,x);\n    }\n    else if(t==2){\n\
    \      int l,r;ll x;\n      cin>>l>>r>>x;\n      seg.range_add(l,r,x);\n    }\n\
    \    else{\n      int l,r;cin>>l>>r;\n      print(seg.range_sum(l,r));\n    }\n\
    \  }\n}"
  dependsOn:
  - template/template.hpp
  - Data_Structure/segtree_beats.hpp
  isVerificationFile: true
  path: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-07-05 01:49:06+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
---
