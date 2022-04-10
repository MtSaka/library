---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/BIT.hpp
    title: Binary Indexed Tree(BIT)
  - icon: ':heavy_check_mark:'
    path: Others/mo.hpp
    title: Mo's Algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/yosupo/static_range_inversions_query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\n\
    #line 1 \"template/template.hpp\"\n//#pragma GCC target(\"avx\")\n//#pragma GCC\
    \ optimize(\"O3\")\n//#pragma GCC optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\n\
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
    using vd=vector<double>;\nusing vp=vector<pl>;\nusing vb=vector<bool>;\nconst\
    \ int dx[8]={1,0,-1,0,1,-1,-1,1};\nconst int dy[8]={0,1,0,-1,1,1,-1,-1};\nconst\
    \ ll MOD=1000000007;\nconst ll mod=998244353;\nconst ld EPS=1e-8;\nconst ld PI=3.1415926535897932384626;\n\
    template<typename T,typename U>\nostream &operator<<(ostream&os,const pair<T,U>&p){os<<p.first<<\"\
    \ \"<<p.second;return os;}\ntemplate<typename T,typename U>\nistream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return\
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
    class infinity{\n  public:\n  static const T MAX=numeric_limits<T>::max();\n \
    \ static const T MIN=numeric_limits<T>::min();\n  static const T value=numeric_limits<T>::max()/2;\n\
    \  static const T mvalue=numeric_limits<T>::min()/2;\n};\n#if __cplusplus <= 201402L\n\
    template<class T>const T infinity<T>::value;\ntemplate<class T>const T infinity<T>::mvalue;\n\
    template<class T>const T infinity<T>::MAX;\ntemplate<class T>const T infinity<T>::MIN;\n\
    #endif\ntemplate<typename T>const T INF=infinity<T>::value;\nconst long long inf=INF<ll>;\n\
    inline int popcnt(ull x){\n#if __cplusplus>=202002L\nreturn popcount(x);\n#endif\n\
    x=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);return\
    \ (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);\n}\ntemplate<typename T,typename=void>\n\
    struct is_specialize:false_type{};\ntemplate<typename T>\nstruct is_specialize<T,typename\
    \ conditional<false,typename T::iterator, void>::type>:true_type{};\ntemplate<typename\
    \ T>\nstruct is_specialize<T,typename conditional<false,decltype(T::first),void>::type>:true_type{};\n\
    template<typename T>\nstruct is_specialize<T,enable_if_t<is_integral<T>::value,void>>:true_type{};\n\
    void dump(const char&t){cerr<<t;}\nvoid dump(const string&t){cerr<<t;}\nvoid dump(const\
    \ bool&t){cerr<<(t?\"true\":\"false\");}\ntemplate <typename T,enable_if_t<!is_specialize<T>::value,nullptr_t>\
    \ =nullptr>\nvoid dump(const T&t){cerr<<t;}\ntemplate<typename T>\nvoid dump(const\
    \ T&t,enable_if_t<is_integral<T>::value>* =nullptr){string tmp;if(t==infinity<T>::value||t==infinity<T>::MAX)tmp=\"\
    inf\";if(t==infinity<T>::mvalue||t==infinity<T>::MIN)tmp=\"-inf\";if(tmp.empty())tmp=to_string(t);cerr<<tmp;}\n\
    template <typename T>\nvoid dump(const T&t,enable_if_t<!is_void<typename T::iterator>::value>*\
    \ =nullptr){cerr<<\"{\";for(auto it=t.begin();it!=t.end();){dump(*it);cerr<<(++it==t.end()?\"\
    \":\",\");}cerr<<\"}\";}\ntemplate<typename T,typename U>\nvoid dump(const pair<T,U>&t){cerr<<\"\
    (\";dump(t.first);cerr<<\",\";dump(t.second);cerr<<\")\";}\nvoid trace(){cerr<<endl;}\n\
    template<typename Head,typename... Tail>\nvoid trace(Head&&head,Tail&&... tail){dump(head);if(sizeof...(tail))cerr<<\"\
    ,\";trace(forward<Tail>(tail)...);}\n#ifdef ONLINE_JUDGE\n#define debug(...) (void(0))\n\
    #else\n#define debug(...) do{cerr<<#__VA_ARGS__<<\"=\";trace(__VA_ARGS__);}while(0)\n\
    #endif\nstruct IOSetup{IOSetup(){cin.tie(nullptr);ios::sync_with_stdio(false);cout.tie(0);cout<<fixed<<setprecision(12);cerr<<fixed<<setprecision(12);}};\n\
    /**\n * @brief Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 2 \"\
    Data_Structure/BIT.hpp\"\ntemplate<typename T>\nstruct BIT{\n  long long N;\n\
    \  vector<T>bit;\n  BIT(long long n){\n    N=1;\n    while(N<n)N<<=1;\n    bit=vector<T>(N+1,0);\n\
    \  }\n  void add(int i,T x){\n    i++;\n    while(i<=N){\n      bit[i]+=x;\n \
    \     i+=i&-i;    \n    }\n  }\n  T sum(int i){\n    T ans=0;\n    while(i>0)ans+=bit[i],i-=i&-i;\n\
    \    return ans;\n  }\n  T query(int l,int r){\n    return sum(r)-sum(l);\n  }\n\
    };\n/**\n * @brief Binary Indexed Tree(BIT)\n*/\n#line 2 \"Others/mo.hpp\"\nstruct\
    \ Mo{\n  int n;\n  vector<int>left,right;\n  Mo(int n):n(n){}\n  void add(int\
    \ l,int r){\n    left.push_back(l);\n    right.push_back(r);\n  }\n  template<typename\
    \ AL,typename AR,typename DL,typename DR,typename REM>\n  void run(const AL&add_left,const\
    \ AR&add_right,const DL&delete_left,const DR&delete_right,const REM&rem){\n  \
    \  int q=left.size(),width=max<int>(1,n/sqrt(q));\n    vector<int>order(q);\n\
    \    iota(order.begin(),order.end(),0);\n    sort(order.begin(),order.end(),[&](int\
    \ a,int b){\n      int ablock=left[a]/width,bblock=left[b]/width;\n      if(ablock!=bblock)return\
    \ ablock<bblock;\n      return (ablock&1)?(right[a]>right[b]):(right[a]<right[b]);\n\
    \    });\n    int l=0,r=0;\n    for(auto idx:order){\n      while(l>left[idx])add_left(--l);\n\
    \      while(r<right[idx])add_right(r++);\n      while(l<left[idx])delete_left(l++);\n\
    \      while(r>right[idx])delete_right(--r); \n      rem(idx);\n    }\n  }\n \
    \ template<typename A,typename D,typename REM>\n  void run(const A&add,const D&del,const\
    \ REM&rem){\n    run(add,add,del,del,rem);\n  }\n};\n/**\n * @brief Mo's Algorithm\n\
    */\n#line 5 \"test/yosupo/static_range_inversions_query.test.cpp\"\nint main(){\n\
    \  int n,q;\n  cin>>n>>q;\n  vector<int>a(n);\n  cin>>a;\n  Mo mo(n);\n  for(int\
    \ i=0;i<q;i++){\n    int l,r;cin>>l>>r;\n    mo.add(l,r);\n  }\n  vector<int>b{a};\n\
    \  sort(b.begin(),b.end());\n  b.erase(unique(b.begin(),b.end()),b.end());\n \
    \ for(auto&i:a)i=lower_bound(b.begin(),b.end(),i)-b.begin();\n  BIT<int>bit(b.size()+1);\n\
    \  ll inv=0,sum=0;\n  vector<ll>ans(q);\n  auto add_left=[&](int idx){\n    inv+=bit.sum(a[idx]);\n\
    \    bit.add(a[idx],1);\n    sum++;\n  };\n  auto add_right=[&](int idx){\n  \
    \  inv+=sum-bit.sum(a[idx]+1);\n    bit.add(a[idx],1);\n    sum++;\n  };\n  auto\
    \ delete_left=[&](int idx){\n    inv-=bit.sum(a[idx]);\n    bit.add(a[idx],-1);\n\
    \    sum--;\n  };\n  auto delete_right=[&](int idx){\n    inv-=sum-bit.sum(a[idx]+1);\n\
    \    bit.add(a[idx],-1);\n    sum--;\n  };\n  auto rem=[&](int idx){ans[idx]=inv;};\n\
    \  mo.run(add_left,add_right,delete_left,delete_right,rem);\n  for(auto i:ans)print(i);\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include\"../../template/template.hpp\"\n#include\"../../Data_Structure/BIT.hpp\"\
    \n#include\"../../Others/mo.hpp\"\nint main(){\n  int n,q;\n  cin>>n>>q;\n  vector<int>a(n);\n\
    \  cin>>a;\n  Mo mo(n);\n  for(int i=0;i<q;i++){\n    int l,r;cin>>l>>r;\n   \
    \ mo.add(l,r);\n  }\n  vector<int>b{a};\n  sort(b.begin(),b.end());\n  b.erase(unique(b.begin(),b.end()),b.end());\n\
    \  for(auto&i:a)i=lower_bound(b.begin(),b.end(),i)-b.begin();\n  BIT<int>bit(b.size()+1);\n\
    \  ll inv=0,sum=0;\n  vector<ll>ans(q);\n  auto add_left=[&](int idx){\n    inv+=bit.sum(a[idx]);\n\
    \    bit.add(a[idx],1);\n    sum++;\n  };\n  auto add_right=[&](int idx){\n  \
    \  inv+=sum-bit.sum(a[idx]+1);\n    bit.add(a[idx],1);\n    sum++;\n  };\n  auto\
    \ delete_left=[&](int idx){\n    inv-=bit.sum(a[idx]);\n    bit.add(a[idx],-1);\n\
    \    sum--;\n  };\n  auto delete_right=[&](int idx){\n    inv-=sum-bit.sum(a[idx]+1);\n\
    \    bit.add(a[idx],-1);\n    sum--;\n  };\n  auto rem=[&](int idx){ans[idx]=inv;};\n\
    \  mo.run(add_left,add_right,delete_left,delete_right,rem);\n  for(auto i:ans)print(i);\n\
    }"
  dependsOn:
  - template/template.hpp
  - Data_Structure/BIT.hpp
  - Others/mo.hpp
  isVerificationFile: true
  path: test/yosupo/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2022-03-05 17:47:05+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_inversions_query.test.cpp
- /verify/test/yosupo/static_range_inversions_query.test.cpp.html
title: test/yosupo/static_range_inversions_query.test.cpp
---
