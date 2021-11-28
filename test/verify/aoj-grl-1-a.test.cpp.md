---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/dijkstra.cpp
    title: Graph/dijkstra.cpp
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/verify/aoj-grl-1-a.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#line 1 \"template/template.cpp\"\n//GIVE ME AC!!!!!!!!!!!!!!!!!\n//#pragma\
    \ GCC target(\"avx\")\n//#pragma GCC optimize(\"O3\")\n//#pragma GCC optimize(\"\
    unroll-loops\")\n#include<bits/stdc++.h>\nusing namespace std;\nusing ll=long\
    \ long;\nusing ld=long double;\nusing vl=vector<ll>;\nusing vi=vector<int>;\n\
    using vs=vector<string>;\nusing vc=vector<char>;\nusing vvl=vector<vl>;\nusing\
    \ P=pair<ll,ll>;\nusing vvc=vector<vc>;\nusing vd=vector<double>;\nusing vp=vector<P>;\n\
    using vb=vector<bool>;\n#define overload4(_1,_2,_3,_4,name,...) name\n#define\
    \ overload3(_1,_2,_3,name,...) name\n#define rep1(a) for(__typeof(a) i=0;i<a;i++)\n\
    #define rep2(i,a) for(__typeof(a) i=0;i<a;i++)\n#define rep3(i,a,b) for(__typeof(a)\
    \ i=a;i<b;i++)\n#define rep4(i,a,b,c) for(__typeof(a) i=a;i<b;i+=c)\n#define rep(...)\
    \ overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n#define rrep1(a)\
    \ for(__typeof(a) i=(a)-1;i>=0;i--)\n#define rrep2(i,a) for(__typeof(a) i=(a)-1;i>=0;i--)\n\
    #define rrep3(i,a,b) for(__typeof(a) i=(b)-1;i>=(a);i--)\n#define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)\n\
    #define all1(i) begin(i),end(i)\n#define all2(i,a) begin(i),begin(i)+a\n#define\
    \ all3(i,a,b) begin(i)+a,begin(i)+b\n#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)\n\
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
    \ chmin(T1&a,T2 b){return a>b&&(a=b,true);}\n#line 1 \"Graph/dijkstra.cpp\"\n\
    using P=pair<long long,long long>;\nstruct Edge {\n  long long to;\n  long long\
    \ cost;\n};\nusing Graph=vector<vector<Edge>>;\nvector<long long>dijkstra(Graph\
    \ g,int s){\n  int n=g.size();\n  vector<long long>d(n,2e18);\n  d[s]=0;\n  priority_queue<P,vector<P>,greater<P>>q;\n\
    \  q.push({0,s});\n  while(!q.empty()){\n    auto [c,v]=q.top();\n    q.pop();\n\
    \    if(d[v]>=c){\n      for(auto p:g[v]){\n        int w=p.to;\n        if(d[w]>d[v]+p.cost){\n\
    \          d[w]=d[v]+p.cost;\n          q.push({d[w],w});\n        }\n      }\n\
    \    }\n  }\n  return d;\n}\npair<long long,vector<long long>>dijkstra_path(Graph\
    \ g,int s, int t){\n  int n=g.size();\n  vector<long long>d(n,2e18);\n  d[s]=0;\n\
    \  vector<long long>prev(n);\n  priority_queue<P,vector<P>,greater<P>>q;\n  q.push({0,s});\n\
    \  while(!q.empty()){\n    auto [c,v]=q.top();\n    q.pop();\n    if(d[v]>=c){\n\
    \      for(auto p:g[v]){\n        int w=p.to;\n        if(d[w]>d[v]+p.cost){\n\
    \          d[w]=d[v]+p.cost;\n          q.push({d[w],w});\n          prev[w]=v;\n\
    \        }\n      }\n    }\n  }\n  if(d[t]==2e18)return {-1,vector<long long>()};\n\
    \  else{\n    vector<long long>path;\n    path.push_back(t);\n    while(path.back()!=s){\n\
    \      path.push_back(prev[path.back()]);\n    }\n    reverse(path.begin(),path.end());\n\
    \    return {d[t],path};\n  }\n}\n#line 4 \"test/verify/aoj-grl-1-a.test.cpp\"\
    \nint main(){\n  INT(v,e,r);\n  Graph g(v);\n  for(int i=0;i<e;i++){\n    INT(a,b,c);\n\
    \    Edge d;\n    d.to=b;\n    d.cost=c;\n    g[a].push_back(d);\n  }\n  vector<long\
    \ long>dists=dijkstra(g,r);\n  for(long long dist:dists){\n    if(dist==inf)print(\"\
    INF\");\n    else print(dist);\n  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#include\"../../template/template.cpp\"\n#include\"../../Graph/dijkstra.cpp\"\
    \nint main(){\n  INT(v,e,r);\n  Graph g(v);\n  for(int i=0;i<e;i++){\n    INT(a,b,c);\n\
    \    Edge d;\n    d.to=b;\n    d.cost=c;\n    g[a].push_back(d);\n  }\n  vector<long\
    \ long>dists=dijkstra(g,r);\n  for(long long dist:dists){\n    if(dist==inf)print(\"\
    INF\");\n    else print(dist);\n  }\n}"
  dependsOn:
  - template/template.cpp
  - Graph/dijkstra.cpp
  isVerificationFile: true
  path: test/verify/aoj-grl-1-a.test.cpp
  requiredBy: []
  timestamp: '2021-11-28 22:21:46+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/aoj-grl-1-a.test.cpp
layout: document
redirect_from:
- /verify/test/verify/aoj-grl-1-a.test.cpp
- /verify/test/verify/aoj-grl-1-a.test.cpp.html
title: test/verify/aoj-grl-1-a.test.cpp
---
