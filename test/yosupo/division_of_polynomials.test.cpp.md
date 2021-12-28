---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/fps.hpp
    title: "Formal Power Series(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: Math/ntt.hpp
    title: "Number Theoretic Transform(\u6570\u8AD6\u5909\u63DB)"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: "Template(\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/division_of_polynomials
    links:
    - https://judge.yosupo.jp/problem/division_of_polynomials
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 8: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/division_of_polynomials\"\
    \n#include\"../../template/template.hpp\"\n#include\"../../Math/fps.hpp\"\nint\
    \ main(){\n  int n,m;\n  cin>>n>>m;\n  vector<modint<mod>>a(n),b(m);\n  cin>>a>>b;\n\
    \  FPS<mod>f(a),g(b);\n  FPS<mod>q=f/g,r=f%g;\n  cout<<q.size()<<\" \"<<r.size()<<endl;\n\
    \  cout<<q.val<<endl;\n  cout<<r.val<<endl;\n}"
  dependsOn:
  - template/template.hpp
  - Math/fps.hpp
  - Math/ntt.hpp
  - Math/modint.hpp
  isVerificationFile: true
  path: test/yosupo/division_of_polynomials.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 02:04:29+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/division_of_polynomials.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/division_of_polynomials.test.cpp
- /verify/test/yosupo/division_of_polynomials.test.cpp.html
title: test/yosupo/division_of_polynomials.test.cpp
---
