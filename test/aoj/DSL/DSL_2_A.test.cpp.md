---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Data_Structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 8: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../Data_Structure/segtree.hpp\"\
    \nint op(int a,int b){return min(a,b);}\nint e(){return INT_MAX;}\nint main(){\n\
    \  INT(n,q);\n  segtree<int,op,e>s(n);\n  while(q--){\n    INT(t,x,y);\n    if(t==0)s.update(x,y);\n\
    \    else cout<<s.query(x,y+1)<<endl;\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Data_Structure/segtree.hpp
  isVerificationFile: true
  path: test/aoj/DSL/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2021-12-24 00:01:49+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_2_A.test.cpp
- /verify/test/aoj/DSL/DSL_2_A.test.cpp.html
title: test/aoj/DSL/DSL_2_A.test.cpp
---
