---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/rerooting.hpp
    title: "ReRooting(\u5168\u65B9\u4F4D\u6728DP)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
  bundledCode: "#line 1 \"test/aoj/GRL/GRL_5_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\
    \n#line 2 \"template/template.hpp\"\n//#pragma GCC target(\"avx\")\n//#pragma\
    \ GCC optimize(\"O3\")\n//#pragma GCC optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\n\
    using namespace std;\nusing ll=long long;\nusing ld=long double;\nusing vl=vector<ll>;\n\
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
    \u30D7\u30EC\u30FC\u30C8)\n*/\n#line 1 \"Graph/rerooting.hpp\"\n/**\n * @brief\
    \ ReRooting(\u5168\u65B9\u4F4D\u6728DP)\n*/\ntemplate<typename S,typename T=S>\n\
    struct ReRooting{\n  struct Edge{\n    int from,to;\n    S cost;\n    T dp,ndp;\n\
    \  };\n  using F=function<T(T,T)>;\n  using G=function<T(T,Edge)>;\n  vector<vector<Edge>>\
    \ g;\n  const F f;\n  const G gg;\n  const T id;\n  vector<T> subdp,dp;\n  void\
    \ add_edge(int u,int v,const S &d) {\n    g[u].emplace_back(Edge{u,v,d,id,id});\n\
    \    g[v].emplace_back(Edge{v,u,d,id,id});\n  }\n  ReRooting(int n,const F &f,const\
    \ G &g,const T &id=T{}):g(n),f(f),gg(g),id(id),subdp(n,id),dp(n,id) {}\n  void\
    \ dfs_sub(int x,int p) {\n    for(auto &e:g[x])if(e.to!=p){\n      dfs_sub(e.to,x);\n\
    \      e.dp=gg(subdp[e.to], e);\n      subdp[x]=f(subdp[x], e.dp);\n    }\n  }\n\
    \  void dfs_all(int x,int p,T top) {\n    T now = id;\n    for(auto &e:g[x]){\n\
    \      e.ndp=now;\n      if(e.to==p)e.dp=gg(top, e);\n      now=f(now,e.dp);\n\
    \    }\n    dp[x]=now;\n    now=id;\n    for(int i=(int)g[x].size()-1;i>=0;i--){\n\
    \      auto &e=g[x][i];\n      if(e.to!= p)dfs_all(e.to,x,f(e.ndp,now));\n   \
    \   now=f(now,e.dp);\n    }\n  }\n  vector<T>solve(){\n    dfs_sub(0,-1);\n  \
    \  dfs_all(0,-1,id);\n    return dp;\n  }\n};\n#line 4 \"test/aoj/GRL/GRL_5_B.test.cpp\"\
    \nlong long f(long long a,long long b){\n  return max(a,b);\n}\nlong long g(long\
    \ long a,ReRooting<long long>::Edge b){\n  return a+b.cost;\n}\nint main(){\n\
    \  int n;\n  cin>>n;\n  ReRooting<long long>r(n,f,g);\n  for(int i=0;i<n-1;i++){\n\
    \    int s,t;\n    long long w;\n    cin>>s>>t>>w;\n    r.add_edge(s,t,w);\n \
    \ }\n  auto ans=r.solve();\n  for(auto i:ans)cout<<i<<endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../Graph/rerooting.hpp\"\
    \nlong long f(long long a,long long b){\n  return max(a,b);\n}\nlong long g(long\
    \ long a,ReRooting<long long>::Edge b){\n  return a+b.cost;\n}\nint main(){\n\
    \  int n;\n  cin>>n;\n  ReRooting<long long>r(n,f,g);\n  for(int i=0;i<n-1;i++){\n\
    \    int s,t;\n    long long w;\n    cin>>s>>t>>w;\n    r.add_edge(s,t,w);\n \
    \ }\n  auto ans=r.solve();\n  for(auto i:ans)cout<<i<<endl;\n}"
  dependsOn:
  - template/template.hpp
  - Graph/rerooting.hpp
  isVerificationFile: true
  path: test/aoj/GRL/GRL_5_B.test.cpp
  requiredBy: []
  timestamp: '2021-12-30 12:21:29+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_5_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_5_B.test.cpp
- /verify/test/aoj/GRL/GRL_5_B.test.cpp.html
title: test/aoj/GRL/GRL_5_B.test.cpp
---
