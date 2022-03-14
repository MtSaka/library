---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../geometry/geometry.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../geometry/geometry.hpp\"\
    \nint main(){\n  int n;\n  cin>>n;\n  geometry::polygon pol(n);\n  for(int i=0;i<n;i++)cin>>pol[i];\n\
    \  long double ans=geometry::area(pol);\n  cout<<fixed<<setprecision(1)<<ans<<endl;\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/CGL/CGL_3_A.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL/CGL_3_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL/CGL_3_A.test.cpp
- /verify/test/aoj/CGL/CGL_3_A.test.cpp.html
title: test/aoj/CGL/CGL_3_A.test.cpp
---
