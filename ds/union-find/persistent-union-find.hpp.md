---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Persistent Disjoint Set Union(\u6C38\u7D9AUnion-Find)"
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
  code: "#pragma once\n#include\"../template/template.hpp\"\n#include\"persistent-array.hpp\"\
    \n\nstruct PersistentUnionFind{\n  private:\n  using pa=PersistentArray<int,2>;\n\
    \  pa p;\n  public:\n  using node=pa::node;\n  PersistentUnionFind(){}\n  PersistentUnionFind(int\
    \ n){\n    p.build(vector<int>(n,-1));\n  }\n  int root(int x,node*t){\n    if(p.get(x,t)<0)return\
    \ x;\n    return root(p.get(x,t),t);\n  }\n  bool same(int x,int y,node*t){\n\
    \    return root(x,t)==root(y,t);\n  }\n  int size(int x,node*t){\n    return\
    \ -p.get(root(x,t),t);\n  }\n  pair<int,node*>merge(int x,int y,node*t){\n   \
    \ x=root(x,t),y=root(y,t);\n    if(x==y)return {x,t};\n    if(p.get(x,t)>p.get(y,t))swap(x,y);\n\
    \    node*ret=p.set(y,x,p.set(x,p.get(x,t)+p.get(y,t),t));\n    return {x,ret};\n\
    \  }\n  node*get_root(){return p.get_root();}\n};\n/**\n * @brief Persistent Disjoint\
    \ Set Union(\u6C38\u7D9AUnion-Find)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: ds/union-find/persistent-union-find.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/union-find/persistent-union-find.hpp
layout: document
redirect_from:
- /library/ds/union-find/persistent-union-find.hpp
- /library/ds/union-find/persistent-union-find.hpp.html
title: "Persistent Disjoint Set Union(\u6C38\u7D9AUnion-Find)"
---
