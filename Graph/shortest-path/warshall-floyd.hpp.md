---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Warshall Floyd(\u5168\u70B9\u5BFE\u9593\u6700\u77ED\u8DEF)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Graph-template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../../template/template.hpp\"\n#include\"../Graph-template.hpp\"\
    \n\ntemplate<typename T>\nvector<vector<T>>warshall_floyd(const Graph<T>&g){\n\
    \  const int n=g.size();\n  const T MAX=numeric_limits<T>::max()/2;\n  vector<vector<T>>d(n,vector<T>(n,MAX));\n\
    \  for(int i=0;i<n;i++){\n    d[i][i]=0;\n    for(auto &e:g[i])d[i][e]=e.cost;\n\
    \  }\n  for(int k=0;k<n;k++){\n    for(int i=0;i<n;i++){\n      for(int j=0;j<n;j++){\n\
    \        if(d[i][k]!=MAX&&d[k][j]!=MAX){\n          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);\n\
    \        }\n      }\n    }\n  }\n  return d;\n}\n/**\n * @brief Warshall Floyd(\u5168\
    \u70B9\u5BFE\u9593\u6700\u77ED\u8DEF)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Graph/shortest-path/warshall-floyd.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/shortest-path/warshall-floyd.hpp
layout: document
redirect_from:
- /library/Graph/shortest-path/warshall-floyd.hpp
- /library/Graph/shortest-path/warshall-floyd.hpp.html
title: "Warshall Floyd(\u5168\u70B9\u5BFE\u9593\u6700\u77ED\u8DEF)"
---
