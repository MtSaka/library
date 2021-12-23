---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/modint.hpp
    title: Math/modint.hpp
  - icon: ':heavy_check_mark:'
    path: Math/ntt.hpp
    title: Math/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\"\
    ../../template/template.hpp\"\n#include\"../../Math/ntt.hpp\"\nint main(){\n \
    \ INT(n,m);\n  vector<modint<mod>>a(n),b(m);\n  scan(a,b);\n  NTT<mod>ntt;\n \
    \ print(ntt.multiply(a,b));\n}"
  dependsOn:
  - template/template.hpp
  - Math/ntt.hpp
  - Math/modint.hpp
  isVerificationFile: true
  path: test/verify/yosupo-convolution-mod.test.cpp
  requiredBy: []
  timestamp: '2021-12-23 11:07:04+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-convolution-mod.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-convolution-mod.test.cpp
- /verify/test/verify/yosupo-convolution-mod.test.cpp.html
title: test/verify/yosupo-convolution-mod.test.cpp
---
