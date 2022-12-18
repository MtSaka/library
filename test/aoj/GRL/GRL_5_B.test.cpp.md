---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../graph/tree/rerooting.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../graph/tree/rerooting.hpp\"\
    \nlong long f(long long a,long long b){\n  return max(a,b);\n}\nlong long g(long\
    \ long a,ReRooting<long long>::Edge b){\n  return a+b.cost;\n}\nint main(){\n\
    \  int n;\n  cin>>n;\n  ReRooting<long long>r(n,f,g);\n  for(int i=0;i<n-1;i++){\n\
    \    int s,t;\n    long long w;\n    cin>>s>>t>>w;\n    r.add_edge(s,t,w);\n \
    \ }\n  auto ans=r.solve();\n  for(auto i:ans)cout<<i<<endl;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/GRL/GRL_5_B.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_5_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_5_B.test.cpp
- /verify/test/aoj/GRL/GRL_5_B.test.cpp.html
title: test/aoj/GRL/GRL_5_B.test.cpp
---
