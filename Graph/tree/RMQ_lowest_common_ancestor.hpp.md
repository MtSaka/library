---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/sparse_table.hpp
    title: Sparse Table
  - icon: ':question:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_5_C_2.test.cpp
    title: test/aoj/GRL/GRL_5_C_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca2.test.cpp
    title: test/yosupo/lca2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "RMQ Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148\
      )"
    links: []
  bundledCode: "#line 2 \"Graph/graph_template.hpp\"\ntemplate<typename T=int>\nstruct\
    \ Edge{\n  int from,to;\n  T cost;\n  int idx;\n  Edge(){}\n  Edge(int from,int\
    \ to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n  operator\
    \ int()const{return to;}\n  bool operator<(const Edge&e)const{return cost<e.cost;}\n\
    };\ntemplate<typename T=int>\nstruct Graph{\n  vector<vector<Edge<T>>>g;\n  int\
    \ es;\n  Graph(){}\n  explicit Graph(int n):g(n),es(0){}\n  size_t size()const{return\
    \ g.size();}\n  size_t edge_size()const{return es;}\n  void add_directed_edge(int\
    \ from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es++);\n  }\n\
    \  void add_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es);\n\
    \    g[to].emplace_back(to,from,cost,es++);\n  }\n  inline vector<Edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<Edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighed=false,bool direct=false){\n\
    \    int a,b;\n    T c;\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n      a+=padding;\n\
    \      b+=padding;\n      c=1;\n      if(weighed)cin>>c;\n      if(direct)add_directed_edge(a,b,c);\n\
    \      else add_edge(a,b,c);\n    }\n  }\n};\ntemplate<typename T=int>\nusing\
    \ Edges=vector<Edge<T>>;\n/**\n * @brief Graph Template(\u30B0\u30E9\u30D5\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8)\n*/\n#line 1 \"Data_Structure/sparse_table.hpp\"\
    \ntemplate<typename T,typename F>\nstruct sparse_table{\n  F f;\n  vector<vector<T>>table;\n\
    \  vector<int>log_table;\n  sparse_table()=default;\n  sparse_table(const vector<T>&v,const\
    \ F&f):f(f){\n    const int n=(int)v.size();\n    const int lg=32-__builtin_clz(n);\n\
    \    table.assign(lg,vector<T>(n));\n    for(int i=0;i<n;i++)table[0][i]=v[i];\n\
    \    for(int i=1;i<lg;i++)for(int j=0;j+(1<<i)<=n;j++)table[i][j]=f(table[i-1][j],table[i-1][j+(1<<(i-1))]);\n\
    \    log_table.resize(n+1);\n    for(int i=2;i<=n;i++)log_table[i]=1+log_table[i>>1];\n\
    \  }\n  T query(int l,int r){\n    int a=log_table[r-l];\n    return f(table[a][l],table[a][r-(1<<a)]);\n\
    \  }\n};\ntemplate<typename T,typename F>\nsparse_table<T,F>make_sparse_table(const\
    \ vector<T>&v,const F&f){\n  return sparse_table<T,F>(v,f);\n} \n/**\n * @brief\
    \ Sparse Table\n*/\n#line 4 \"Graph/tree/RMQ_lowest_common_ancestor.hpp\"\ntemplate<typename\
    \ T=int>\nstruct RMQ_LCA:Graph<T>{\n  using Graph<T>::g;\n  using F=function<int(int,int)>;\n\
    \  vector<int>ord,dep,in;\n  RMQ_LCA(int n):Graph<T>(n){}\n  RMQ_LCA(const Graph<T>&g):Graph<T>(g){}\n\
    \  void build(int root=0){\n    in.resize(g.size());\n    dfs(root,-1,0);\n  \
    \  vector<int>v(g.size()*2-1);\n    iota(v.begin(),v.end(),0);\n    F f=[&](int\
    \ a,int b){return dep[a]<dep[b]?a:b;};\n    st=sparse_table<int,F>(v,f);\n  }\n\
    \  int lca(int u,int v){\n    if(in[u]>in[v])swap(u,v);\n    return u==v?u:ord[st.query(in[u],in[v])];\n\
    \  }\n  private:\n  sparse_table<int,F>st;\n  void dfs(int idx,int par,int d){\n\
    \    in[idx]=(int)ord.size();\n    ord.emplace_back(idx);\n    dep.emplace_back(d);\n\
    \    for(auto &e:g[idx])if(e!=par){\n      dfs(e,idx,d+1);\n      ord.emplace_back(idx);\n\
    \      dep.emplace_back(d);\n    }\n  }\n};\n/**\n * @brief RMQ Lowest Common\
    \ Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)\n*/\n"
  code: "#pragma once\n#include\"../graph_template.hpp\"\n#include\"../../Data_Structure/sparse_table.hpp\"\
    \ntemplate<typename T=int>\nstruct RMQ_LCA:Graph<T>{\n  using Graph<T>::g;\n \
    \ using F=function<int(int,int)>;\n  vector<int>ord,dep,in;\n  RMQ_LCA(int n):Graph<T>(n){}\n\
    \  RMQ_LCA(const Graph<T>&g):Graph<T>(g){}\n  void build(int root=0){\n    in.resize(g.size());\n\
    \    dfs(root,-1,0);\n    vector<int>v(g.size()*2-1);\n    iota(v.begin(),v.end(),0);\n\
    \    F f=[&](int a,int b){return dep[a]<dep[b]?a:b;};\n    st=sparse_table<int,F>(v,f);\n\
    \  }\n  int lca(int u,int v){\n    if(in[u]>in[v])swap(u,v);\n    return u==v?u:ord[st.query(in[u],in[v])];\n\
    \  }\n  private:\n  sparse_table<int,F>st;\n  void dfs(int idx,int par,int d){\n\
    \    in[idx]=(int)ord.size();\n    ord.emplace_back(idx);\n    dep.emplace_back(d);\n\
    \    for(auto &e:g[idx])if(e!=par){\n      dfs(e,idx,d+1);\n      ord.emplace_back(idx);\n\
    \      dep.emplace_back(d);\n    }\n  }\n};\n/**\n * @brief RMQ Lowest Common\
    \ Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)\n*/"
  dependsOn:
  - Graph/graph_template.hpp
  - Data_Structure/sparse_table.hpp
  isVerificationFile: false
  path: Graph/tree/RMQ_lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2022-07-02 01:33:27+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lca2.test.cpp
  - test/aoj/GRL/GRL_5_C_2.test.cpp
documentation_of: Graph/tree/RMQ_lowest_common_ancestor.hpp
layout: document
redirect_from:
- /library/Graph/tree/RMQ_lowest_common_ancestor.hpp
- /library/Graph/tree/RMQ_lowest_common_ancestor.hpp.html
title: "RMQ Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
---
