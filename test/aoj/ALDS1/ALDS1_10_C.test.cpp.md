---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Dynamic_Programming/longest_common-subsequence.hpp
    title: "Longest Common Subsequence(\u6700\u9577\u5171\u901A\u90E8\u5206\u5217)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 8: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../Dynamic_Programming/longest_common-subsequence.hpp\"\
    \nint main(){\n  int q;\n  cin>>q;\n  while(q--){\n    string s,t;\n    cin>>s>>t;\n\
    \    vector<char>a(s.begin(),s.end()),b(t.begin(),t.end());\n    cout<<lcsl(a,b)<<endl;\n\
    \  }\n}"
  dependsOn:
  - template/template.hpp
  - Dynamic_Programming/longest_common-subsequence.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1/ALDS1_10_C.test.cpp
  requiredBy: []
  timestamp: '2021-12-29 18:50:25+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1/ALDS1_10_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1/ALDS1_10_C.test.cpp
- /verify/test/aoj/ALDS1/ALDS1_10_C.test.cpp.html
title: test/aoj/ALDS1/ALDS1_10_C.test.cpp
---
