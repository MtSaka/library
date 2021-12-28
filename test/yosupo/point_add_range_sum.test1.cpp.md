---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 8: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include\"../../template/template.hpp\"\n#include\"../../Data_Structure/segtree.hpp\"\
    \nlong long op(long long a,long long b){return a+b;}\nlong long e(){return 0;}\n\
    int main(){\n  int n,q;\n  cin>>n>>q;\n  vector<long long>a(n);\n  cin>>a;\n \
    \ segtree<long long,op,e>s(a);\n  while(q--){\n    int t,l,r;\n    cin>>t>>l>>r;\n\
    \    if(t)cout<<s.query(l,r)<<endl;\n    else s.set(l,s[l]+r);\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Data_Structure/segtree.hpp
  isVerificationFile: false
  path: test/yosupo/point_add_range_sum.test1.cpp
  requiredBy: []
  timestamp: '2021-12-28 01:45:05+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yosupo/point_add_range_sum.test1.cpp
layout: document
redirect_from:
- /library/test/yosupo/point_add_range_sum.test1.cpp
- /library/test/yosupo/point_add_range_sum.test1.cpp.html
title: test/yosupo/point_add_range_sum.test1.cpp
---
