---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/dijkstra.cpp
    title: Graph/dijkstra.cpp
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.cpp: line 5: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#include\"../../template/template.cpp\"\n#include\"../../Graph/dijkstra.cpp\"\
    \nint main(){\n  INT(v,e,r);\n  Graph g(v);\n  for(int i=0;i<e;i++){\n    INT(a,b,c);\n\
    \    Edge d;\n    d.to=b;\n    d.cost=c;\n    g[a].push_back(d);\n  }\n  vector<long\
    \ long>dists=dijkstra(g,r);\n  for(long long dist:dists){\n    if(dist==inf)print(\"\
    INF\");\n    else print(dist);\n  }\n}"
  dependsOn:
  - template/template.cpp
  - Graph/dijkstra.cpp
  isVerificationFile: true
  path: test/verify/aoj-grl-1-a.test.cpp
  requiredBy: []
  timestamp: '2021-12-06 20:10:12+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/aoj-grl-1-a.test.cpp
layout: document
redirect_from:
- /verify/test/verify/aoj-grl-1-a.test.cpp
- /verify/test/verify/aoj-grl-1-a.test.cpp.html
title: test/verify/aoj-grl-1-a.test.cpp
---
