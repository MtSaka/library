---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Union Find(Disjoint Set Union)
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../template/template.hpp\"\n\nstruct UnionFind{\n\
    \  private:\n  int n;\n  vector<int>p;\n  public:\n  UnionFind():UnionFind(0){}\n\
    \  UnionFind(int n):n(n),p(n,-1){}\n  int root(int x){return p[x]<0?x:p[x]=root(p[x]);}\n\
    \  bool same(int x,int y){return root(x)==root(y);}\n  int size(int x){return\
    \ -p[root(x)];}\n  int merge(int x,int y){\n    x=root(x),y=root(y);\n    if(x==y)return\
    \ x;\n    if(p[x]>p[y])swap(x,y);\n    p[x]+=p[y];p[y]=x;\n    return x;\n  }\n\
    \  vector<vector<int>>groups(){\n    vector<vector<int>>result(n);\n    for(int\
    \ i=0;i<n;i++)result[root(i)].push_back(i);\n    result.erase(remove_if(result.begin(),result.end(),[](const\
    \ vector<int>&v){return v.empty();}),result.end());\n    return result;\n  }\n\
    };\n/**\n * @brief Union Find(Disjoint Set Union)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: ds/union-find/union-find.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/union-find/union-find.hpp
layout: document
redirect_from:
- /library/ds/union-find/union-find.hpp
- /library/ds/union-find/union-find.hpp.html
title: Union Find(Disjoint Set Union)
---
