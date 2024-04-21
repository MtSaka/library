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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../template/template.hpp\"\n\nstruct RollbackUnionFind{\n\
    \  private:\n  vector<int>p;\n  stack<pair<int,int>>history;\n  public:\n  RollbackUnionFind(int\
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
  path: ds/union-find/rollback-union-find.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/union-find/rollback-union-find.hpp
layout: document
redirect_from:
- /library/ds/union-find/rollback-union-find.hpp
- /library/ds/union-find/rollback-union-find.hpp.html
title: Rollback Disjoint Set Union(Union Find)
---
