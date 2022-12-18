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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../geometry/geometry.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C\"\
    \n#include\"../../../template/template.hpp\"\n#include\"../../../geometry/geometry.hpp\"\
    \nint main(){\n  geometry::point p1,p2;\n  cin>>p1>>p2;\n  int q;\n  cin>>q;\n\
    \  while(q--){\n    geometry::point p;cin>>p;\n    int dir=geometry::ccw(p,p1,p2);\n\
    \    if(dir==1)cout<<\"COUNTER_CLOCKWISE\"<<endl;\n    else if(dir==-1)cout<<\"\
    CLOCKWISE\"<<endl;\n    else if(p==p1||p==p2||dir==2)cout<<\"ON_SEGMENT\"<<endl;\n\
    \    else if(dir==-2)cout<<\"ONLINE_BACK\"<<endl;\n    else cout<<\"ONLINE_FRONT\"\
    <<endl;\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/CGL/CGL_1_C.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL/CGL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL/CGL_1_C.test.cpp
- /verify/test/aoj/CGL/CGL_1_C.test.cpp.html
title: test/aoj/CGL/CGL_1_C.test.cpp
---
