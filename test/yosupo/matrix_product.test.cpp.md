---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/matrix.hpp
    title: "Matrix(\u884C\u5217)"
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 8: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\"\
    ../../template/template.hpp\"\n#include\"../../Math/matrix.hpp\"\n#include\"../../Math/modint.hpp\"\
    \nint main(){\n  int n,m,k;\n  cin>>n>>m>>k;\n  Matrix<modint<mod>>a(n,m),b(m,k);\n\
    \  for(int i=0;i<n;i++){\n    for(int j=0;j<m;j++){\n      cin>>a[i][j];\n   \
    \ }\n  }\n  for(int i=0;i<m;i++){\n    for(int j=0;j<k;j++){\n      cin>>b[i][j];\n\
    \    }\n  }\n  a*=b;\n  for(int i=0;i<n;i++){\n    cout<<a[i]<<endl;\n  }\n}"
  dependsOn:
  - template/template.hpp
  - Math/matrix.hpp
  - Math/modint.hpp
  isVerificationFile: true
  path: test/yosupo/matrix_product.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 02:04:29+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_product.test.cpp
- /verify/test/yosupo/matrix_product.test.cpp.html
title: test/yosupo/matrix_product.test.cpp
---
