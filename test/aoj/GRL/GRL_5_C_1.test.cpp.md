---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../graph/tree/doubling_lowest_common_ancestor.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../graph/tree/doubling_lowest_common_ancestor.hpp\"\
    \nint main(){\n  int n;\n  cin>>n;\n  Doubling_LCA<int>g(n);\n  for(int i=0;i<n;i++){\n\
    \    int k;\n    cin>>k;\n    while(k--){\n      int j;\n      cin>>j;\n     \
    \ g.add_edge(i,j);\n    }\n  }\n  int q;\n  cin>>q;\n  g.build();\n  while(q--){\n\
    \    int a,b;\n    cin>>a>>b;\n    cout<<g.lca(a,b)<<endl;\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/GRL/GRL_5_C_1.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_5_C_1.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_5_C_1.test.cpp
- /verify/test/aoj/GRL/GRL_5_C_1.test.cpp.html
title: test/aoj/GRL/GRL_5_C_1.test.cpp
---
