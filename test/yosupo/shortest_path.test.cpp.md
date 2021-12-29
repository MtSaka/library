---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/dijkstra_path.hpp
    title: "Dijkstra With Path(\u7D4C\u8DEF\u4ED8\u304D\u5358\u4E00\u59CB\u70B9\u6700\
      \u77ED\u8DEF)"
  - icon: ':question:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/yosupo/shortest_path.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"template/template.hpp\"\
    \n//#pragma GCC target(\"avx\")\n//#pragma GCC optimize(\"O3\")\n//#pragma GCC\
    \ optimize(\"unroll-loops\")\n#include<bits/stdc++.h>\nusing namespace std;\n\
    using ll=long long;\nusing ld=long double;\nusing vl=vector<ll>;\nusing vi=vector<int>;\n\
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
    \ chmin(T1&a,T2 b){return a>b&&(a=b,true);}\n/**\n * @brief Template(\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8)\n*/\n#line 1 \"Graph/dijkstra_path.hpp\"\n/**\n * @brief\
    \ Dijkstra With Path(\u7D4C\u8DEF\u4ED8\u304D\u5358\u4E00\u59CB\u70B9\u6700\u77ED\
    \u8DEF)\n*/\n#line 1 \"Graph/graph_template.hpp\"\n/**\n * @brief Graph Template(\u30B0\
    \u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\ntemplate<typename T=int>\n\
    struct Edge{\n  int from,to;\n  T cost;\n  int idx;\n  Edge(){}\n  Edge(int from,int\
    \ to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n  operator\
    \ int()const{return to;}\n};\ntemplate<typename T=int>\nstruct Graph{\n  vector<vector<Edge<T>>>g;\n\
    \  int es;\n  Graph(){}\n  explicit Graph(int n):g(n),es(0){}\n  size_t size()const{return\
    \ g.size();}\n  size_t edge_size()const{return es;}\n  void add_directed_edge(int\
    \ from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es++);\n  }\n\
    \  void add_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es);\n\
    \    g[to].emplace_back(to,from,cost,es++);\n  }\n  inline vector<Edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<Edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighed=false,bool direct=false){\n\
    \    int a,b;\n    T c;\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n      a+=padding;\n\
    \      b+=padding;\n      c=1;\n      if(weighed)cin>>c;\n      if(direct)add_directed_edge(a,b,c);\n\
    \      else add_edge(a,b,c);\n    }\n  }\n};\n#line 5 \"Graph/dijkstra_path.hpp\"\
    \ntemplate<typename T=int>\npair<T,vector<int>>dijkstra_path(const Graph<T>&g,int\
    \ s,int t){\n  int n=g.size();\n  T MAX=numeric_limits<T>::max()/2;\n  vector<T>d(n,MAX);\n\
    \  d[s]=0;\n  vector<int>prev(n);\n  priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>>q;\n\
    \  q.emplace(0,s);\n  while(!q.empty()){\n    auto [d_u,u]=q.top();q.pop();\n\
    \    if(d[u]<d_u)continue;\n    for(auto &e:g[u]){\n      if(d[e]>d[u]+e.cost){\n\
    \        d[e]=d[u]+e.cost;\n        prev[e]=u;\n        q.emplace(d[e],e);\n \
    \     }\n    }\n  }\n  if(d[t]==MAX)return {-1,{}};\n  vector<int>path;\n  path.emplace_back(t);\n\
    \  while(path.back()!=s){\n    path.emplace_back(prev[path.back()]);\n  }\n  reverse(path.begin(),path.end());\n\
    \  return {d[t],path};\n}\n#line 4 \"test/yosupo/shortest_path.test.cpp\"\nint\
    \ main(){\n  int n,m,s,t;\n  cin>>n>>m>>s>>t;\n  Graph<long long>g(n);\n  g.read(m,0,true,true);\n\
    \  auto d=dijkstra_path(g,s,t);\n  if(d.first==-1){\n    cout<<d.first<<endl;\n\
    \    return 0;\n  }\n  cout<<d.first<<\" \"<<d.second.size()-1<<endl;\n  for(int\
    \ i=0;i<d.second.size()-1;i++)cout<<d.second[i]<<\" \"<<d.second[i+1]<<endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\"\
    ../../template/template.hpp\"\n#include\"../../Graph/dijkstra_path.hpp\"\nint\
    \ main(){\n  int n,m,s,t;\n  cin>>n>>m>>s>>t;\n  Graph<long long>g(n);\n  g.read(m,0,true,true);\n\
    \  auto d=dijkstra_path(g,s,t);\n  if(d.first==-1){\n    cout<<d.first<<endl;\n\
    \    return 0;\n  }\n  cout<<d.first<<\" \"<<d.second.size()-1<<endl;\n  for(int\
    \ i=0;i<d.second.size()-1;i++)cout<<d.second[i]<<\" \"<<d.second[i+1]<<endl;\n\
    }"
  dependsOn:
  - template/template.hpp
  - Graph/dijkstra_path.hpp
  - Graph/graph_template.hpp
  isVerificationFile: true
  path: test/yosupo/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2021-12-29 21:42:40+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/shortest_path.test.cpp
- /verify/test/yosupo/shortest_path.test.cpp.html
title: test/yosupo/shortest_path.test.cpp
---
