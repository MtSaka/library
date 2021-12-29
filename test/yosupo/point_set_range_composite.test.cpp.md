---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: modint
  - icon: ':question:'
    path: template/template.hpp
    title: "Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 8: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include\"../../template/template.hpp\"\n#include\"../../Data_Structure/segtree.hpp\"\
    \n#include\"../../Math/modint.hpp\"\nusing mint=modint<mod>;\nusing S=pair<mint,mint>;\n\
    S op(S a,S b){return S{a.first*b.first,a.second*b.first+b.second};}\nS e(){return\
    \ S{mint(1),mint(0)};}\nint main(){\n  int n,q;\n  cin>>n>>q;\n  vector<S>a(n);\n\
    \  cin>>a;\n  segtree<S,op,e>s(a);\n  while(q--){\n    int t;\n    cin>>t;\n \
    \   if(t){\n      int l,r,x;\n      cin>>l>>r>>x;\n      auto [n,m]=s.query(l,r);\n\
    \      cout<<n*mint(x)+m<<endl;\n    }\n    else{\n      int p;\n      cin>>p;\n\
    \      mint c,d;\n      cin>>c>>d;\n      s.set(p,S{c,d});\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Data_Structure/segtree.hpp
  - Math/modint.hpp
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 01:45:05+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.test.cpp
- /verify/test/yosupo/point_set_range_composite.test.cpp.html
title: test/yosupo/point_set_range_composite.test.cpp
---
