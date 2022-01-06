---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  - icon: ':heavy_check_mark:'
    path: Graph/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/aoj/GRL/GRL_5_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
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
    \ eb emplace_back\n#define END(...) {print(__VA_ARGS__);return;}\nusing namespace\
    \ std;\nusing ll=long long;\nusing ull=unsigned long long;\nusing ld=long double;\n\
    using vl=vector<ll>;\nusing vi=vector<int>;\nusing vs=vector<string>;\nusing vc=vector<char>;\n\
    using vvl=vector<vl>;\nusing pi=pair<int,int>;\nusing pl=pair<ll,ll>;\nusing vvc=vector<vc>;\n\
    using vd=vector<double>;\nusing vp=vector<pl>;\nusing vb=vector<bool>;\nconst\
    \ int dx[8]={1,0,-1,0,1,-1,-1,1};\nconst int dy[8]={0,1,0,-1,1,1,-1,-1};\nconst\
    \ ll MOD=1000000007;\nconst ll mod=998244353;\nconst ld EPS=1e-8;\nconst ld PI=3.1415926535897932384626;\n\
    template<typename T,typename U>\nostream &operator<<(ostream&os,const pair<T,U>&p){os<<p.first<<\"\
    \ \"<<p.second;return os;}\ntemplate<typename T,typename U>\nistream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return\
    \ is;}\ntemplate<typename T>\nostream &operator<<(ostream&os,const vector<T>&v){for(int\
    \ i=0;i<(int)v.size();i++){os<<v[i]<<(i+1!=v.size()?\" \":\"\");}return os;}\n\
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
    template<class T>const T infinity<T>::max;\ntemplate<class T>const T infinity<T>::min;\n\
    #endif\ntemplate<typename T>const T inf=infinity<T>::value;\ninline int popcnt(ull\
    \ x){\n#if __cplusplus>=202002L\nreturn popcount(x);\n#endif\nx=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);return\
    \ (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);\n}\nvoid dump(const char&t){cerr<<t;}\n\
    void dump(const string&t){cerr<<t;}\nvoid dump(const bool&t){cerr<<(t?\"true\"\
    :\"false\");}\ntemplate<typename T>\nvoid dump(const T&t,enable_if_t<is_integral<T>::value>*\
    \ =nullptr){string tmp;if(t==infinity<T>::value||t==infinity<T>::MAX)tmp=\"inf\"\
    ;if(t==infinity<T>::mvalue||t==infinity<T>::MIN)tmp=\"-inf\";if(tmp.empty())tmp=to_string(t);cerr<<tmp;}\n\
    template <typename T>\nvoid dump(const T&t,enable_if_t<!is_void<typename T::iterator>::value>*\
    \ =nullptr){cerr<<\"{\";for(auto it=t.begin();it!=t.end();){dump(*it);cerr<<(++it==t.end()?\"\
    \":\",\");}cerr<<\"}\";}\ntemplate<typename T,typename U>\nvoid dump(const pair<T,U>&t){cerr<<\"\
    (\";dump(t.first);cerr<<\",\";dump(t.second);cerr<<\")\";}\nvoid trace(){cerr<<endl;}\n\
    template<typename Head,typename... Tail>\nvoid trace(Head&&head,Tail&&... tail){dump(head);if(sizeof...(tail))cerr<<\"\
    ,\";trace(forward<Tail>(tail)...);}\n#ifdef ONLINE_JUDGE\n#define debug(...)\n\
    #else\n#define debug(...) cerr<<#__VA_ARGS__<<\"=\";trace(__VA_ARGS__);\n#endif\n\
    struct IOSetup{IOSetup(){cin.tie(nullptr);ios::sync_with_stdio(false);cout.tie(0);cout<<fixed<<setprecision(12);cerr<<fixed<<setprecision(12);}};\n\
    /**\n * @brief Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 1 \"\
    Graph/lowest_common_ancestor.hpp\"\n/**\n * @brief Lowest Common Ancestor(\u6700\
    \u5C0F\u5171\u901A\u7956\u5148)\n*/\n#line 1 \"Graph/graph_template.hpp\"\n/**\n\
    \ * @brief Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    )\n*/\ntemplate<typename T=int>\nstruct Edge{\n  int from,to;\n  T cost;\n  int\
    \ idx;\n  Edge(){}\n  Edge(int from,int to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n\
    \  operator int()const{return to;}\n  bool operator<(const Edge&e)const{return\
    \ cost<e.cost;}\n};\ntemplate<typename T=int>\nstruct Graph{\n  vector<vector<Edge<T>>>g;\n\
    \  int es;\n  Graph(){}\n  explicit Graph(int n):g(n),es(0){}\n  size_t size()const{return\
    \ g.size();}\n  size_t edge_size()const{return es;}\n  void add_directed_edge(int\
    \ from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es++);\n  }\n\
    \  void add_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es);\n\
    \    g[to].emplace_back(to,from,cost,es++);\n  }\n  inline vector<Edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<Edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighed=false,bool direct=false){\n\
    \    int a,b;\n    T c;\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n      a+=padding;\n\
    \      b+=padding;\n      c=1;\n      if(weighed)cin>>c;\n      if(direct)add_directed_edge(a,b,c);\n\
    \      else add_edge(a,b,c);\n    }\n  }\n};\ntemplate<typename T=int>\nusing\
    \ Edges=vector<Edge<T>>;\n#line 5 \"Graph/lowest_common_ancestor.hpp\"\ntemplate<typename\
    \ T>\nstruct LCA{\n  int lg=0;\n  vector<int>dep;\n  const Graph<T>&g;\n  vector<vector<int>>table;\n\
    \  LCA(int n):g(n),dep(n){\n    g.read(n-1);\n    while((1<<lg)<n)lg++;\n    table.assign(lg,vector<int>(n,-1));\n\
    \    build();\n  }\n  LCA(const Graph<T>&g):g(g),dep(g.size()){\n    while((1<<lg)<g.size())lg++;\n\
    \    table.assign(lg,vector<int>(g.size(),-1));\n    build();\n  }\n  void dfs(int\
    \ idx,int par,int d){\n    table[0][idx]=par;\n    dep[idx]=d;\n    for(auto &e:g[idx]){\n\
    \      if(e!=par)dfs(e,idx,d+1);\n    }\n  }\n  void build(){\n    dfs(0,-1,0);\n\
    \    for(int k=0;k+1<lg;k++){\n      for(int i=0;i<table[k].size();i++){\n   \
    \     if(table[k][i]==-1)table[k+1][i]=-1;\n        else table[k+1][i]=table[k][table[k][i]];\n\
    \      }\n    }\n  }\n  int query(int u,int v){\n    if(dep[u]>dep[v])swap(u,v);\n\
    \    for(int i=lg-1;i>=0;i--){\n      if(((dep[v]-dep[u])>>i)&1)v=table[i][v];\n\
    \    }\n    if(u==v)return u;\n    for(int i=lg-1;i>=0;i--){\n      if(table[i][u]!=table[i][v]){\n\
    \        u=table[i][u];\n        v=table[i][v];\n      }\n    }\n    return table[0][u];\n\
    \  }\n};\n#line 4 \"test/aoj/GRL/GRL_5_C.test.cpp\"\nint main(){\n  int n;\n \
    \ cin>>n;\n  Graph<int>g(n);\n  for(int i=0;i<n;i++){\n    int k;\n    cin>>k;\n\
    \    while(k--){\n      int j;\n      cin>>j;\n      g.add_edge(i,j);\n    }\n\
    \  }\n  int q;\n  cin>>q;\n  if(n==1){\n    while(q--)cout<<0<<endl;\n    return\
    \ 0;\n  }\n  LCA<int>lca(g);\n  while(q--){\n    int a,b;\n    cin>>a>>b;\n  \
    \  cout<<lca.query(a,b)<<endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../Graph/lowest_common_ancestor.hpp\"\
    \nint main(){\n  int n;\n  cin>>n;\n  Graph<int>g(n);\n  for(int i=0;i<n;i++){\n\
    \    int k;\n    cin>>k;\n    while(k--){\n      int j;\n      cin>>j;\n     \
    \ g.add_edge(i,j);\n    }\n  }\n  int q;\n  cin>>q;\n  if(n==1){\n    while(q--)cout<<0<<endl;\n\
    \    return 0;\n  }\n  LCA<int>lca(g);\n  while(q--){\n    int a,b;\n    cin>>a>>b;\n\
    \    cout<<lca.query(a,b)<<endl;\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Graph/lowest_common_ancestor.hpp
  - Graph/graph_template.hpp
  isVerificationFile: true
  path: test/aoj/GRL/GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2022-01-05 17:03:50+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_5_C.test.cpp
- /verify/test/aoj/GRL/GRL_5_C.test.cpp.html
title: test/aoj/GRL/GRL_5_C.test.cpp
---
