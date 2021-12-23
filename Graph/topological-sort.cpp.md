---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Graph/graph_template.cpp
    title: Graph/graph_template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/graph_template.cpp\"\ntemplate<typename T=int>\nstruct\
    \ Edge{\n  int from,to;\n  T cost;\n  int idx;\n  Edge(){}\n  Edge(int from,int\
    \ to,T cost=1,int idx=-1):from(from),to(to),cost(cost),idx(idx){}\n  operator\
    \ int()const{return to;}\n};\ntemplate<typename T=int>\nstruct Graph{\n  vector<vector<Edge>>g;\n\
    \  int es;\n  Graph(){}\n  explicit Graph(int n):g(n),es(0){}\n  size_t size()const{return\
    \ g.size();}\n  size_t edge_size()const{return es;}\n  void add_directed_edge(int\
    \ from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es++);\n  }\n\
    \  void add_edge(int from,int to,T cost=1){\n    g[from].emplace_back(from,to,cost,es);\n\
    \    g[to].emplace_back(to,from,cost,es++);\n  }\n  inline vector<Edge<T>>&operator[](int\
    \ idx){return g[idx];}\n  inline const vector<Edge<T>>&operator[](int idx)const{return\
    \ g[idx];}\n  void read(int m,int padding=-1,bool weighed=false,bool direct=false){\n\
    \    int a,b;\n    T c;\n    for(int i=0;i<m;i++){\n      cin>>a>>b;\n      a+=padding;\n\
    \      b+=padding;\n      c=1;\n      if(weighed)cin>>c;\n      if(direct)add_directed_edge(a,b,c);\n\
    \      else add_edge(a,b,c);\n    }\n  }\n};\n#line 2 \"Graph/topological-sort.cpp\"\
    \ntemplate<typename T>\nvector<int>t_sort(const Graph<T>&g){\n  int n=g.size();\n\
    \  vector<int>deg(n,0);\n  for(int i=0;i<n;i++){\n    for(auto &e:g[i]){\n   \
    \   deg[e]++;\n    }\n  }\n  queue<int>q;\n  for(int i=0;i<n;i++)if(deg[i]==0)q.push(i);\n\
    \  vector<int>ans;\n  while(!q.empty()){\n    int v=q.front();\n    q.pop();\n\
    \    ans.push_back(v);\n    for(int w:g[v]){\n      deg[w]--;\n      if(deg[w]==0)q.push(w);\n\
    \    }\n  }\n  return ans;\n}\n"
  code: "#include\"graph_template.cpp\"\ntemplate<typename T>\nvector<int>t_sort(const\
    \ Graph<T>&g){\n  int n=g.size();\n  vector<int>deg(n,0);\n  for(int i=0;i<n;i++){\n\
    \    for(auto &e:g[i]){\n      deg[e]++;\n    }\n  }\n  queue<int>q;\n  for(int\
    \ i=0;i<n;i++)if(deg[i]==0)q.push(i);\n  vector<int>ans;\n  while(!q.empty()){\n\
    \    int v=q.front();\n    q.pop();\n    ans.push_back(v);\n    for(int w:g[v]){\n\
    \      deg[w]--;\n      if(deg[w]==0)q.push(w);\n    }\n  }\n  return ans;\n}"
  dependsOn:
  - Graph/graph_template.cpp
  isVerificationFile: false
  path: Graph/topological-sort.cpp
  requiredBy: []
  timestamp: '2021-12-23 00:13:02+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/topological-sort.cpp
layout: document
redirect_from:
- /library/Graph/topological-sort.cpp
- /library/Graph/topological-sort.cpp.html
title: Graph/topological-sort.cpp
---
