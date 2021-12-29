---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/bellman_ford.hpp
    title: "Bellman-Ford(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF)"
  - icon: ':question:'
    path: Graph/graph_template.hpp
    title: "Graph Template(\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  - icon: ':x:'
    path: Graph/negative_cycle.hpp
    title: "Negative Cycle Detection(\u8CA0\u9589\u8DEF\u691C\u51FA)"
  - icon: ':question:'
    path: template/template.hpp
    title: "Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 8: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../Graph/bellman_ford.hpp\"\
    \n#include\"../../../Graph/negative_cycle.hpp\"\nint main(){\n  int v,e,r;\n \
    \ cin>>v>>e>>r;\n  Graph<long long>g(v);\n  g.read(e,0,true,true);\n  if(negative_cycle(g)){\n\
    \    cout<<\"NEGATIVE CYCLE\"<<endl;\n    return 0;\n  }\n  auto d=bellman_ford(g,r);\n\
    \  for(auto i:d)cout<<(i==numeric_limits<long long>::max()/2?\"INF\":to_string(i))<<endl;\n\
    }"
  dependsOn:
  - template/template.hpp
  - Graph/bellman_ford.hpp
  - Graph/graph_template.hpp
  - Graph/negative_cycle.hpp
  isVerificationFile: true
  path: test/aoj/GRL/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-12-29 18:50:25+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_1_B.test.cpp
- /verify/test/aoj/GRL/GRL_1_B.test.cpp.html
title: test/aoj/GRL/GRL_1_B.test.cpp
---
