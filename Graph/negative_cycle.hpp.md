---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL/GRL_1_B.test.cpp
    title: test/aoj/GRL/GRL_1_B.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL/GRL_1_C.test.cpp
    title: test/aoj/GRL/GRL_1_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Negative Cycle Detection(\u8CA0\u9589\u8DEF\u691C\u51FA)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Graph/negative_cycle.hpp: line 4: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Negative Cycle Detection(\u8CA0\u9589\u8DEF\u691C\u51FA)\n\
    */\n#pragma once\n#include\"graph_template.hpp\"\ntemplate<typename T>\nbool negative_cycle(const\
    \ Graph<T>&g){\n  int n=g.size();\n  T MAX=numeric_limits<T>::max()/2;\n  vector<T>d(n,MAX);\n\
    \  for(int i=0;i<n;i++){\n    bool update=false;\n    for(int j=0;j<n;j++){\n\
    \      for(auto &e:g[j])if(d[e]>d[j]+e.cost&&d[j]!=MAX){\n        d[e]=d[j]+e.cost;\n\
    \        update=true;\n        if(i==n-1)return true;\n      }\n    }\n    if(!update)break;\n\
    \  }\n  return false;\n}"
  dependsOn:
  - Graph/graph_template.hpp
  isVerificationFile: false
  path: Graph/negative_cycle.hpp
  requiredBy: []
  timestamp: '2021-12-29 20:16:34+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL/GRL_1_C.test.cpp
  - test/aoj/GRL/GRL_1_B.test.cpp
documentation_of: Graph/negative_cycle.hpp
layout: document
redirect_from:
- /library/Graph/negative_cycle.hpp
- /library/Graph/negative_cycle.hpp.html
title: "Negative Cycle Detection(\u8CA0\u9589\u8DEF\u691C\u51FA)"
---
