---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Rollback Disjoint Set Union(Union Find)
    links: []
  bundledCode: "#line 2 \"Data_Structure/rollback_dsu.hpp\"\nstruct rollback_dsu{\n\
    \  private:\n  vector<int>p;\n  stack<pair<int,int>>history;\n  int internal_snap;\n\
    \  public:\n  rollback_dsu(int sz):p(sz,-1),internal_snap(0){}\n  int root(int\
    \ x){return p[x]<0?x:root(p[x]);}\n  bool same(int x,int y){return root(x)==root(y);}\n\
    \  int size(int x){return -p[root(x)];}\n  int merge(int x,int y){\n    x=root(x),y=root(y);\n\
    \    history.emplace(x,p[x]);\n    history.emplace(y,p[y]);\n    if(x==y)return\
    \ x;\n    if(p[x]>p[y])swap(x,y);\n    p[x]+=p[y];p[y]=x;\n    return x;\n  }\n\
    \  void undo(){\n    p[history.top().first]=history.top().second;\n    history.pop();\n\
    \    p[history.top().first]=history.top().second;\n    history.pop();\n  }\n \
    \ void snapshot(){internal_snap=int(history.size()>>1);}\n  int get_state(){return\
    \ int(history.size()>>1);}\n  void rollback(int state=-1){\n    if(state==-1)state=internal_snap;\n\
    \    state<<=1;\n    while((int)history.size()>state)undo();\n  }\n};\n/**\n *\
    \ @brief Rollback Disjoint Set Union(Union Find)\n*/\n"
  code: "#pragma once\nstruct rollback_dsu{\n  private:\n  vector<int>p;\n  stack<pair<int,int>>history;\n\
    \  int internal_snap;\n  public:\n  rollback_dsu(int sz):p(sz,-1),internal_snap(0){}\n\
    \  int root(int x){return p[x]<0?x:root(p[x]);}\n  bool same(int x,int y){return\
    \ root(x)==root(y);}\n  int size(int x){return -p[root(x)];}\n  int merge(int\
    \ x,int y){\n    x=root(x),y=root(y);\n    history.emplace(x,p[x]);\n    history.emplace(y,p[y]);\n\
    \    if(x==y)return x;\n    if(p[x]>p[y])swap(x,y);\n    p[x]+=p[y];p[y]=x;\n\
    \    return x;\n  }\n  void undo(){\n    p[history.top().first]=history.top().second;\n\
    \    history.pop();\n    p[history.top().first]=history.top().second;\n    history.pop();\n\
    \  }\n  void snapshot(){internal_snap=int(history.size()>>1);}\n  int get_state(){return\
    \ int(history.size()>>1);}\n  void rollback(int state=-1){\n    if(state==-1)state=internal_snap;\n\
    \    state<<=1;\n    while((int)history.size()>state)undo();\n  }\n};\n/**\n *\
    \ @brief Rollback Disjoint Set Union(Union Find)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/rollback_dsu.hpp
  requiredBy: []
  timestamp: '2022-06-01 18:39:17+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/rollback_dsu.hpp
layout: document
redirect_from:
- /library/Data_Structure/rollback_dsu.hpp
- /library/Data_Structure/rollback_dsu.hpp.html
title: Rollback Disjoint Set Union(Union Find)
---
