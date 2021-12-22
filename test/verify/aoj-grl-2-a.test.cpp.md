---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/dsu.cpp
    title: Data_Structure/dsu.cpp
  - icon: ':heavy_check_mark:'
    path: Graph/kruskal.cpp
    title: Graph/kruskal.cpp
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.cpp: line 5: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n#include \"../../template/template.cpp\"\n#include \"../../Graph/kruskal.cpp\"\
    \nint main(){\n  INT(v,e);\n  vector<tuple<int,int,int>>edges;\n  for(int i =\
    \ 0; i < e; i++){\n    INT(a,b,c);\n    edges.emplace_back(a,b,c);\n  }\n  mst<int>ans\
    \ = kruskal(edges,v);\n  cout<<ans.cost<<endl;\n}"
  dependsOn:
  - template/template.cpp
  - Graph/kruskal.cpp
  - Data_Structure/dsu.cpp
  isVerificationFile: true
  path: test/verify/aoj-grl-2-a.test.cpp
  requiredBy: []
  timestamp: '2021-12-06 20:10:12+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/aoj-grl-2-a.test.cpp
layout: document
redirect_from:
- /verify/test/verify/aoj-grl-2-a.test.cpp
- /verify/test/verify/aoj-grl-2-a.test.cpp.html
title: test/verify/aoj-grl-2-a.test.cpp
---
