---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../graph/shortest-path/warshall-floyd.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../graph/shortest-path/warshall-floyd.hpp\"\
    \nint main(){\n  int v,e;\n  cin>>v>>e;\n  Graph<long long>g(v);\n  g.read(e,0,true,true);\n\
    \  auto d=warshall_floyd(g);\n  for(int i=0;i<v;i++){\n    if(d[i][i]<0){\n  \
    \    cout<<\"NEGATIVE CYCLE\"<<endl;\n      return 0;\n    }\n  }\n  for(auto\
    \ k:d)for(int i=0;i<k.size();i++)cout<<(k[i]==numeric_limits<long long>::max()/2?\"\
    INF\":to_string(k[i]))<<(i==k.size()-1?\"\\n\":\" \");\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/GRL/GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_1_C.test.cpp
- /verify/test/aoj/GRL/GRL_1_C.test.cpp.html
title: test/aoj/GRL/GRL_1_C.test.cpp
---
