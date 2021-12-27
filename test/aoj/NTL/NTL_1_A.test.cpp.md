---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/factorize.hpp
    title: "Prime Factorization(\u7D20\u56E0\u6570\u5206\u89E3)"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 8: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../Math/factorize.hpp\"\
    \nint main(){\n  int n;\n  cin>>n;\n  cout<<n<<\":\";\n  for(auto p:factorize(n)){\n\
    \    while(p.second--)cout<<\" \"<<p.first;\n  }\n  cout<<endl;\n}"
  dependsOn:
  - template/template.hpp
  - Math/factorize.hpp
  isVerificationFile: true
  path: test/aoj/NTL/NTL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-12-27 00:11:57+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL/NTL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL/NTL_1_A.test.cpp
- /verify/test/aoj/NTL/NTL_1_A.test.cpp.html
title: test/aoj/NTL/NTL_1_A.test.cpp
---
