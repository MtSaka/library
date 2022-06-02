---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Data_Structure/presistent_array.hpp
    title: Data_Structure/presistent_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Presistent Disjoint Set Union(\u6C38\u7D9AUnion-Find)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Data_Structure/presistent_dsu.hpp: line 2: #pragma once found in a non-first\
    \ line\n"
  code: "\n#pragma once\n#include\"presistent_array.hpp\"\nstruct presistent_dsu{\n\
    \  private:\n  using pa=persistent_array<int>;\n  pa p;\n  public:\n  using node=pa::node;\n\
    \  presistent_dsu(){}\n  presistent_dsu(int n){\n    p.build(vector<int>(n,-1));\n\
    \  }\n  int root(int x,node*t){\n    if(p.get(x,t)<0)return x;\n    return root(p.get(x,t),t);\n\
    \  }\n  bool same(int x,int y,node*t){\n    return root(x,t)==root(y,t);\n  }\n\
    \  int size(int x,node*t){\n    return -p.get(root(x,t),t);\n  }\n  pair<int,node*>merge(int\
    \ x,int y,node*t){\n    x=root(x,t),y=root(y,t);\n    if(x==y)return {x,t};\n\
    \    if(p.get(x,t)>p.get(y,t))swap(x,y);\n    node*ret=p.set(y,x,p.set(x,p.get(x,t)+p.get(y,t),t));\n\
    \    return {x,ret};\n  }\n};\n/**\n * @brief Presistent Disjoint Set Union(\u6C38\
    \u7D9AUnion-Find)\n*/"
  dependsOn:
  - Data_Structure/presistent_array.hpp
  isVerificationFile: false
  path: Data_Structure/presistent_dsu.hpp
  requiredBy: []
  timestamp: '2022-06-02 12:05:46+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/presistent_dsu.hpp
layout: document
redirect_from:
- /library/Data_Structure/presistent_dsu.hpp
- /library/Data_Structure/presistent_dsu.hpp.html
title: "Presistent Disjoint Set Union(\u6C38\u7D9AUnion-Find)"
---
