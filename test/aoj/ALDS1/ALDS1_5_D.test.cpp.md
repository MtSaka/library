---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/BIT.hpp
    title: Binary Indexed Tree(BIT)
  - icon: ':heavy_check_mark:'
    path: Data_Structure/inversion.hpp
    title: "Inversion Number(\u8EE2\u5012\u6570)"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 8: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../Data_Structure/inversion.hpp\"\
    \nint main(){\n  int n;\n  cin>>n;\n  vector<int>a(n);\n  cin>>a;\n  cout<<inversion(a)<<endl;\n\
    }"
  dependsOn:
  - template/template.hpp
  - Data_Structure/inversion.hpp
  - Data_Structure/BIT.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1/ALDS1_5_D.test.cpp
  requiredBy: []
  timestamp: '2021-12-24 23:49:56+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1/ALDS1_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1/ALDS1_5_D.test.cpp
- /verify/test/aoj/ALDS1/ALDS1_5_D.test.cpp.html
title: test/aoj/ALDS1/ALDS1_5_D.test.cpp
---
