---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/fast_prime.hpp
    title: "Fast Prime Factorization(\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3)"
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
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/yosupo/factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#line 2 \"template/template.hpp\"\n//#pragma GCC target(\"avx\")\n//#pragma\
    \ GCC optimize(\"O3\")\n//#pragma GCC optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\n\
    #define overload4(a,b,c,d,e,...) e\n#define overload3(a,b,c,d,...) d\n#define\
    \ rep1(a) for(ll i=0;i<(ll)(a);i++)\n#define rep2(i,a) for(ll i=0;i<(ll)(a);i++)\n\
    #define rep3(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)\n#define rep4(i,a,b,c) for(ll\
    \ i=(ll)(a);i<(ll)(b);i+=(ll)(c))\n#define rep(...) overload4(__VA_ARGS__, rep4,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n#define rrep1(a) for(ll i=(ll)(a)-1;i>=0;i--)\n\
    #define rrep2(i,a) for(ll i=(ll)(a)-1;i>=0;i--)\n#define rrep3(i,a,b) for(ll i=(ll)(b)-1;i>=(ll)(a);i--)\n\
    #define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)\n#define\
    \ all1(i) begin(i),end(i)\n#define all2(i,a) begin(i),begin(i)+a\n#define all3(i,a,b)\
    \ begin(i)+a,begin(i)+b\n#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)\n\
    #define rall(n) (n).rbegin(),(n).rend()\n#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)\n#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)\n#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)\n#define pb push_back\n#define\
    \ eb emplace_back\n#define END(...) print(__VA_ARGS__);return;\nusing namespace\
    \ std;\nusing ll=long long;\nusing ull=unsigned long long;\nusing ld=long double;\n\
    using vl=vector<ll>;\nusing vi=vector<int>;\nusing vs=vector<string>;\nusing vc=vector<char>;\n\
    using vvl=vector<vl>;\nusing pi=pair<int,int>;\nusing pl=pair<ll,ll>;\nusing vvc=vector<vc>;\n\
    using vd=vector<double>;\nusing vp=vector<pl>;\nusing vb=vector<bool>;\nconst\
    \ int dx[8]={1,0,-1,0,1,-1,-1,1};\nconst int dy[8]={0,1,0,-1,1,1,-1,-1};\nconst\
    \ ll MOD=1000000007;\nconst ll mod=998244353;\nconst ld EPS=1e-8;\nconst ld PI=3.1415926535897932384626;\n\
    template<typename T1,typename T2 >\nostream &operator<<(ostream&os,const pair<T1,T2>&p){os<<p.first<<\"\
    \ \"<<p.second;return os;}\ntemplate<typename T1,typename T2>\nistream &operator>>(istream&is,pair<T1,T2>&p){is>>p.first>>p.second;return\
    \ is;}\ntemplate<typename T>\nostream &operator<<(ostream&os,const vector<T>&v){for(int\
    \ i=0;i<(int)v.size();i++){os<<v[i]<<(i+1!=v.size()?\" \":\"\");}return os;}\n\
    template<typename T>\nistream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return\
    \ is;}\nvoid scan(){}\ntemplate<class Head,class... Tail>\nvoid scan(Head&head,Tail&...\
    \ tail){cin>>head;scan(tail...);}\ntemplate<class T>\nvoid print(const T &t){cout<<t<<'\\\
    n';}\ntemplate<class Head, class... Tail>\nvoid print(const Head &head, const\
    \ Tail &... tail){cout<<head<<' ';print(tail...);}\ntemplate<class... T>\nvoid\
    \ fin(const T &... a){print(a...);exit(0);}\ntemplate<typename T1,typename T2>\n\
    inline bool chmax(T1&a,T2 b){return a<b&&(a=b,true);}\ntemplate<typename T1,typename\
    \ T2>\ninline bool chmin(T1&a,T2 b){return a>b&&(a=b,true);}\ntemplate<typename\
    \ T>\nclass infinity{\n  public:\n  static const T MAX=numeric_limits<T>::max();\n\
    \  static const T MIN=numeric_limits<T>::min();\n  static const T value=numeric_limits<T>::max()/2;\n\
    \  static const T mvalue=numeric_limits<T>::min()/2;\n};\ntemplate<typename T>const\
    \ T inf=infinity<T>::value;\ninline int popcnt(ull x){\n#if __cplusplus>=202002L\n\
    \  return popcount(x);\n#endif\n  x=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);\n\
    \  x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);\n  x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);\n\
    \  x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);\n  x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);\n\
    \  return (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);\n}\nvoid dump(const\
    \ char&t){cerr<<t;}\nvoid dump(const string&t){cerr<<t;}\nvoid dump(const bool&t){cerr<<(t?\"\
    true\":\"false\");}\ntemplate<typename T>\nvoid dump(const T&t,enable_if_t<is_integral<T>::value>*\
    \ =nullptr){\n  string tmp;\n  if(t==infinity<T>::value||t==infinity<T>::MAX)tmp=\"\
    inf\";\n  if(t==infinity<T>::mvalue||t==infinity<T>::MIN)tmp=\"-inf\";\n  if(tmp.empty())tmp=to_string(t);\n\
    \  cerr<<tmp;\n}\ntemplate <typename T>\nvoid dump(const T&t,enable_if_t<!is_void<typename\
    \ T::iterator>::value>* =nullptr){\n  cerr<<\"{\";\n  for(auto it=t.begin();it!=t.end();){\n\
    \    dump(*it);\n    cerr<<(++it==t.end()?\"\":\", \");\n  }\n  cerr<<\"}\";\n\
    }\ntemplate<typename T,typename U>\nvoid dump(const pair<T,U>&t){\n  cerr<<\"\
    (\";\n  dump(t.first);\n  cerr<<\",\";\n  dump(t.second);\n  cerr<<\")\";\n}\n\
    void trace(){cerr<<endl;}\ntemplate<typename Head,typename... Tail>\nvoid trace(Head&&head,Tail&&...\
    \ tail){\n  dump(head);\n  if(sizeof...(tail))cerr<<\",\";\n  trace(forward<Tail>(tail)...);\n\
    }\n#ifdef ONLINE_JUDGE\n#define debug(...) cerr<<#__VA_ARGS__<<\"=\";trace(__VA_ARGS__);\n\
    #else\n#define debug(...) cerr<<#__VA_ARGS__<<\"=\";trace(__VA_ARGS__);\n#endif\n\
    struct IOSetup{\n  IOSetup(){\n    cin.tie(0);\n    ios::sync_with_stdio(0);\n\
    \    cout<<fixed<<setprecision(12);\n    cerr<<fixed<<setprecision(12);\n  }\n\
    };\n/**\n * @brief Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 1\
    \ \"Math/fast_prime.hpp\"\n/**\n * @brief Fast Prime Factorization(\u9AD8\u901F\
    \u7D20\u56E0\u6570\u5206\u89E3)\n*/\nnamespace fastprime{\n  using i128=__uint128_t;\n\
    \  long long inner_modmul(long long x,long long y,long long p){\n    return i128(x)*y%p;\n\
    \  }\n  long long inner_modpow(long long n,long long m,long long p){\n    long\
    \ long res=1;\n    while(m){\n      if(m&1)res=inner_modmul(res,n,p);\n      n=inner_modmul(n,n,p);\n\
    \      m>>=1;\n    }\n    return res;\n  }\n  bool miller_rabin(long long n,vector<long\
    \ long>p){\n    long long s=__builtin_ctzll(n-1),d=n>>s;\n    for(long long a:p){\n\
    \      if(n<=a)break;\n      long long t=d,y=inner_modpow(a,t,n);\n      while(t!=n-1&&y!=1&&y!=n-1){\n\
    \        y=inner_modmul(y,y,n);\n        t=inner_modmul(t,2,n);\n      }\n   \
    \   if(y!=n-1&&!(t&1))return false;\n    }\n    return true;\n  }\n  bool is_prime(long\
    \ long n){\n    if(n<=2)return n==2;\n    if(!(n&1))return false;\n    if(n<=4759123141)return\
    \ miller_rabin(n,{2,7,61});\n    return miller_rabin(n,{2,325,9375,28178,450775,9780504,1795265022});\n\
    \  }\n  long long factor(long long n){\n    if(!(n&1))return 2;\n    else if(is_prime(n))return\
    \ n;\n    int c=2;\n    while(true){\n      auto f=[&](long long x){\n       \
    \ x=inner_modmul(x,x,n)+c;\n        if(x>=n)x-=n;\n        return x;\n      };\n\
    \      long long x=c,g=1,q=1,xs,y;\n      int m=128;\n      int l=1;\n      while(g==1){\n\
    \        y=x;\n        for(int i=1;i<l;i++)x=f(x);\n        int k=0;\n       \
    \ while(k<l&&g==1){\n          xs=x;\n          for(int i=0;i<m&&i<l-k;i++){\n\
    \            x=f(x);\n            q=inner_modmul(q,llabs(y-x),n);\n          }\n\
    \          g=__gcd(q,n);\n          k+=m;\n        }\n        l*=2;\n      }\n\
    \      if(g==n){\n        do{\n          xs=f(xs);\n          g=__gcd(llabs(xs-y),n);\n\
    \        }while(g==1);\n      }\n      if(g!=n)return g;\n      c++;\n    }\n\
    \  }\n  vector<long long>factorize_sub(long long n){\n    if(n==1)return {};\n\
    \    long long p=factor(n);\n    if(p==n)return {p};\n    vector<long long>l=factorize_sub(n/p);\n\
    \    vector<long long>r=factorize_sub(p);\n    l.insert(l.end(),r.begin(),r.end());\n\
    \    return l;\n  }\n  vector<long long>factorize(long long n,bool sorted=true){\n\
    \    vector<long long>res=factorize_sub(n);\n    if(sorted)sort(res.begin(),res.end());\n\
    \    return res;\n  }\n};\n#line 4 \"test/yosupo/factorize.test.cpp\"\nint main(){\n\
    \  int q;\n  cin>>q;\n  while(q--){\n    long long x;\n    cin>>x;\n    auto ret=fastprime::factorize(x);\n\
    \    print(ret.size(),ret);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include\"\
    ../../template/template.hpp\"\n#include\"../../Math/fast_prime.hpp\"\nint main(){\n\
    \  int q;\n  cin>>q;\n  while(q--){\n    long long x;\n    cin>>x;\n    auto ret=fastprime::factorize(x);\n\
    \    print(ret.size(),ret);\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Math/fast_prime.hpp
  isVerificationFile: true
  path: test/yosupo/factorize.test.cpp
  requiredBy: []
  timestamp: '2022-01-02 21:23:34+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/factorize.test.cpp
- /verify/test/yosupo/factorize.test.cpp.html
title: test/yosupo/factorize.test.cpp
---