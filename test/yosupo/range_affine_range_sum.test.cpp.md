---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Data_Structure/lazy_segtree.hpp
    title: "Lazy Segment Tree(\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':question:'
    path: Math/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 8: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include\"../../template/template.hpp\"\n#include\"../../Math/modint.hpp\"\n\
    #include\"../../Data_Structure/lazy_segtree.hpp\"\nusing mint=modint<mod>;\nusing\
    \ pi = pair< mint, int >;\nusing qi = pair< mint, mint >;\npi op(pi a,pi b){return\
    \ {a.first+b.first,a.second+b.second};}\npi mapping(qi a,pi b){return {a.first*b.first+a.second*mint(b.second),b.second};}\n\
    qi composition(qi b,qi a){return {a.first*b.first,a.second*b.first+b.second};}\n\
    pi e(){return pi(0,0);}\nqi id(){return qi(1,0);}\nint main(){\n  INT(n,q);\n\
    \  lazy_segtree<pi,op,e,qi,mapping,composition,id>s(n);\n  rep(i,n){\n    mint\
    \ a;\n    scan(a);\n    s.set(i,pi(a,1));\n  }\n  while(q--){\n    LL(t);\n  \
    \  if(t){\n      INT(l,r);\n      print(s.query(l,r).first);\n    }\n    else{\n\
    \      INT(l,r);\n      mint b,c;\n      scan(b,c);\n      s.apply(l,r,qi(b,c));\n\
    \    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Math/modint.hpp
  - Data_Structure/lazy_segtree.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-12-23 23:52:29+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.test.cpp
- /verify/test/yosupo/range_affine_range_sum.test.cpp.html
title: test/yosupo/range_affine_range_sum.test.cpp
---
