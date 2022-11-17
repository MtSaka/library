---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/dynamic_segtree.hpp
    title: "Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u6728)"
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_range_sum3.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line 2 \"template/template.hpp\"\
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
    Data_Structure/dynamic_segtree.hpp\"\ntemplate<typename S,S (*op)(S,S),S (*e)()>\n\
    struct dynamic_segtree{\n  public:\n  dynamic_segtree():dynamic_segtree(numeric_limits<long\
    \ long>::max()>>1){}\n  dynamic_segtree(long long n):n(n),root(nullptr){}\n  void\
    \ set(int p,const S&x){inner_set(root,0,n,p,x);}\n  S get(long long p)const{return\
    \ inner_get(root,0,n,p);}\n  S operator[](long long p)const{return inner_get(root,0,n,p);}\n\
    \  S query(long long l,long long r)const{return inner_query(root,0,n,l,r);}\n\
    \  S all_query()const{return root?root->val:e();}\n  void reset(long long l,long\
    \ long r){inner_reset(root,0,n,l,r);}\n  private:\n  struct node;\n  using ptr=unique_ptr<node>;\n\
    \  struct node{\n    S val;\n    ptr l,r;\n    node(const S&val):val(val),l(nullptr),r(nullptr){}\n\
    \  };\n  const long long n;\n  ptr root;\n  void inner_set(ptr&nd,long long l,long\
    \ long r,long long p,const S&x){\n    if(!nd)nd=make_unique<node>(e());\n    if(r-l==1){nd->val=x;return;}\n\
    \    long long m=(l+r)>>1;\n    if(p<m)inner_set(nd->l,l,m,p,x);\n    else inner_set(nd->r,m,r,p,x);\n\
    \    nd->val=op(nd->l?nd->l->val:e(),nd->r?nd->r->val:e());\n  }\n  S inner_get(const\
    \ ptr&nd,long long l,long long r,long long p)const{\n    if(!nd)return e();\n\
    \    if(r-l==1)return nd->val;\n    long long m=(l+r)>>1;\n    if(p<m)return inner_get(nd->l,l,m,p);\n\
    \    return inner_get(nd->r,m,r,p);\n  }\n  S inner_query(const ptr&nd,long long\
    \ nl,long long nr,long long l,long long r)const{\n    if(!nd||nr<=l||r<=nl)return\
    \ e();\n    if(l<=nl&&nr<=r)return nd->val;\n    long long m=(nl+nr)>>1;\n   \
    \ return op(inner_query(nd->l,nl,m,l,r),inner_query(nd->r,m,nr,l,r));\n  }\n \
    \ void inner_reset(ptr&nd,long long nl,long long nr,long long l,long long r){\n\
    \    if(!nd||nr<=l||r<=nl)return;\n    if(l<=nl&&nr<=r){\n      nd.reset();return;\n\
    \    }\n    long long m=(l+r)>>1;\n    inner_reset(nd->l,nl,m,l,r);\n    inner_reset(nd->r,m,nr,l,r);\n\
    \    nd->val=op(nd->l?nd->l->val:e(),nd->r?nd->r->val:e());\n  }\n};\n/**\n *\
    \ @brief Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u6728)\n */\n#line 4 \"\
    test/yosupo/point_add_range_sum3.test.cpp\"\nlong long op(long long a,long long\
    \ b){return a+b;}\nlong long e(){return 0;}\nint main(){\n  int n,q;cin>>n>>q;\n\
    \  dynamic_segtree<long long,op,e>seg(n);\n  vi a(n);cin>>a;\n  for(int i=0;i<n;i++)seg.set(i,a[i]);\n\
    \  while(q--){\n    int t,l,r;cin>>t>>l>>r;\n    if(t)cout<<seg.query(l,r)<<endl;\n\
    \    else seg.set(l,seg[l]+r);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include\"../../template/template.hpp\"\n#include\"../../Data_Structure/dynamic_segtree.hpp\"\
    \nlong long op(long long a,long long b){return a+b;}\nlong long e(){return 0;}\n\
    int main(){\n  int n,q;cin>>n>>q;\n  dynamic_segtree<long long,op,e>seg(n);\n\
    \  vi a(n);cin>>a;\n  for(int i=0;i<n;i++)seg.set(i,a[i]);\n  while(q--){\n  \
    \  int t,l,r;cin>>t>>l>>r;\n    if(t)cout<<seg.query(l,r)<<endl;\n    else seg.set(l,seg[l]+r);\n\
    \  }\n}"
  dependsOn:
  - template/template.hpp
  - Data_Structure/dynamic_segtree.hpp
  isVerificationFile: true
  path: test/yosupo/point_add_range_sum3.test.cpp
  requiredBy: []
  timestamp: '2022-07-29 00:47:59+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_range_sum3.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_range_sum3.test.cpp
- /verify/test/yosupo/point_add_range_sum3.test.cpp.html
title: test/yosupo/point_add_range_sum3.test.cpp
---
