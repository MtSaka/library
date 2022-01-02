---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/modpow.hpp
    title: "Mod Pow(\u3079\u304D\u4E57)"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/aoj/NTL/NTL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
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
    \ \"Math/modpow.hpp\"\n/**\n * @brief Mod Pow(\u3079\u304D\u4E57)\n*/\ntemplate<typename\
    \ T,typename S>\nT modpow(T a,S b,T m){\n  T ret=1;\n  while(b){\n    if(b&1)ret=ret*a%m;\n\
    \    a=a*a%m;\n    b>>=1;\n  }\n  return ret;\n}\n#line 4 \"test/aoj/NTL/NTL_1_B.test.cpp\"\
    \nint main(){\n  long long m,n;\n  cin>>m>>n;\n  print(modpow(m,n,(long long)MOD));\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../Math/modpow.hpp\"\
    \nint main(){\n  long long m,n;\n  cin>>m>>n;\n  print(modpow(m,n,(long long)MOD));\n\
    }"
  dependsOn:
  - template/template.hpp
  - Math/modpow.hpp
  isVerificationFile: true
  path: test/aoj/NTL/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2022-01-02 21:23:34+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL/NTL_1_B.test.cpp
- /verify/test/aoj/NTL/NTL_1_B.test.cpp.html
title: test/aoj/NTL/NTL_1_B.test.cpp
---
