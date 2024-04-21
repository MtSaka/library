---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Weighted Disjoint Set Union(\u91CD\u307F\u4ED8\u304DUnion Find)"
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
  code: "#pragma once\n#include\"../template/template.hpp\"\n\ntemplate<typename T>\n\
    struct WeightedUnionFind{\n  vector<int>p;vector<T>diff;\n  WeightedUnionFind(){}\n\
    \  WeightedUnionFind(int n,T s=0):p(n,-1),diff(n,s){}\n  int root(int x){\n  \
    \  if(p[x]<0)return x;\n    int r=root(p[x]);\n    diff[x]+=diff[p[x]];\n    return\
    \ p[x]=r;\n  }\n  T weight(int x){\n    root(x);\n    return diff[x];\n  }\n \
    \ bool same(int x,int y){return root(x)==root(y);}\n  int size(int x){return -p[root(x)];}\n\
    \  bool merge(int x,int y,T w){\n    int xx=x,yy=y;T ww=w;\n    w+=weight(x),w-=weight(y);\n\
    \    x=root(x),y=root(y);\n    if(x==y)return dist(xx,yy)==ww;\n    if(p[x]>p[y])swap(x,y),w=-w;\n\
    \    p[x]+=p[y];\n    p[y]=x;\n    diff[y]=w;\n    return true;\n  }\n  T dist(int\
    \ x,int y){\n    return weight(y)-weight(x);\n  }\n};\n/**\n * @brief Weighted\
    \ Disjoint Set Union(\u91CD\u307F\u4ED8\u304DUnion Find)\n*/ "
  dependsOn: []
  isVerificationFile: false
  path: ds/union-find/weighted-union-find.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/union-find/weighted-union-find.hpp
layout: document
redirect_from:
- /library/ds/union-find/weighted-union-find.hpp
- /library/ds/union-find/weighted-union-find.hpp.html
title: "Weighted Disjoint Set Union(\u91CD\u307F\u4ED8\u304DUnion Find)"
---
