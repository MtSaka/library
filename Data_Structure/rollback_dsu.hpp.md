---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/persistent_unionfind2.test.cpp
    title: test/yosupo/persistent_unionfind2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Rollback Disjoint Set Union(Union Find)
    links: []
  bundledCode: "#line 2 \"Data_Structure/rollback_dsu.hpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\nstruct rollback_dsu{\n  private:\n  vector<int>p;\n  stack<pair<int,int>>history;\n\
    \  public:\n  rollback_dsu(int sz):p(sz,-1){}\n  int root(int x)const{return p[x]<0?x:root(p[x]);}\n\
    \  bool same(int x,int y)const{return root(x)==root(y);}\n  int size(int x)const{return\
    \ -p[root(x)];}\n  int merge(int x,int y){\n    x=root(x),y=root(y);\n    history.emplace(x,p[x]);\n\
    \    history.emplace(y,p[y]);\n    if(x==y)return x;\n    if(p[x]>p[y])swap(x,y);\n\
    \    p[x]+=p[y];p[y]=x;\n    return x;\n  }\n  void undo(){\n    p[history.top().first]=history.top().second;history.pop();\n\
    \    p[history.top().first]=history.top().second;history.pop();\n  }\n  void snapshot(){while(!history.empty())history.pop();}\n\
    \  void rollback(){\n    while(!history.empty())undo();\n  }\n  vector<vector<int>>groups()const{\n\
    \    const int n=p.size();\n    vector<vector<int>>result(n);\n    for(int i=0;i<n;i++)result[root(i)].push_back(i);\n\
    \    result.erase(remove_if(result.begin(),result.end(),[](const vector<int>&v){return\
    \ v.empty();}),result.end());\n    return result;\n  }\n};\n/**\n * @brief Rollback\
    \ Disjoint Set Union(Union Find)\n*/\n"
  code: "#pragma once\n#include<bits/stdc++.h>\nusing namespace std;\nstruct rollback_dsu{\n\
    \  private:\n  vector<int>p;\n  stack<pair<int,int>>history;\n  public:\n  rollback_dsu(int\
    \ sz):p(sz,-1){}\n  int root(int x)const{return p[x]<0?x:root(p[x]);}\n  bool\
    \ same(int x,int y)const{return root(x)==root(y);}\n  int size(int x)const{return\
    \ -p[root(x)];}\n  int merge(int x,int y){\n    x=root(x),y=root(y);\n    history.emplace(x,p[x]);\n\
    \    history.emplace(y,p[y]);\n    if(x==y)return x;\n    if(p[x]>p[y])swap(x,y);\n\
    \    p[x]+=p[y];p[y]=x;\n    return x;\n  }\n  void undo(){\n    p[history.top().first]=history.top().second;history.pop();\n\
    \    p[history.top().first]=history.top().second;history.pop();\n  }\n  void snapshot(){while(!history.empty())history.pop();}\n\
    \  void rollback(){\n    while(!history.empty())undo();\n  }\n  vector<vector<int>>groups()const{\n\
    \    const int n=p.size();\n    vector<vector<int>>result(n);\n    for(int i=0;i<n;i++)result[root(i)].push_back(i);\n\
    \    result.erase(remove_if(result.begin(),result.end(),[](const vector<int>&v){return\
    \ v.empty();}),result.end());\n    return result;\n  }\n};\n/**\n * @brief Rollback\
    \ Disjoint Set Union(Union Find)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/rollback_dsu.hpp
  requiredBy: []
  timestamp: '2022-07-01 22:16:58+01:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/persistent_unionfind2.test.cpp
documentation_of: Data_Structure/rollback_dsu.hpp
layout: document
redirect_from:
- /library/Data_Structure/rollback_dsu.hpp
- /library/Data_Structure/rollback_dsu.hpp.html
title: Rollback Disjoint Set Union(Union Find)
---
