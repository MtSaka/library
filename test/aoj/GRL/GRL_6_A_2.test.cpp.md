---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../graph/flow/ford_fulkerson.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../graph/flow/ford_fulkerson.hpp\"\
    \nint main(){\n  int v,e;\n  cin>>v>>e;\n  FordFulkerson<int>g(v);\n  for(int\
    \ i=0;i<e;i++){\n    int a,b,c;\n    cin>>a>>b>>c;\n    g.add_edge(a,b,c);\n \
    \ }\n  cout<<g.max_flow(0,v-1)<<endl;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/GRL/GRL_6_A_2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_6_A_2.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_6_A_2.test.cpp
- /verify/test/aoj/GRL/GRL_6_A_2.test.cpp.html
title: test/aoj/GRL/GRL_6_A_2.test.cpp
---