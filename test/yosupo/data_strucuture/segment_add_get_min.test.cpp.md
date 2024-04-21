---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    #include\"../../../template/template.hpp\"\n#include\"../../../ds/cht/li-chao-tree.hpp\"\
    \nint main(){\n  INT(n,q);\n  vector<array<ll,4>>A(n);\n  for(auto&[l,r,a,b]:A)cin>>l>>r>>a>>b;\n\
    \  vector<array<ll,5>>B(q);\n  for(auto&[t,l,r,a,b]:B){\n    cin>>t;\n    if(t==0)cin>>l>>r>>a>>b;\n\
    \    else cin>>l;\n  }\n  compressor<ll>press;\n  for(auto&[a,b,c,d,e]:B){\n \
    \   if(a==1)press.push_back(b);\n  }\n  press.build();\n  vector<ll>x(press.size());\n\
    \  rep(i,press.size())x[i]=press[i];\n  LiChaoTree lct(x);\n  for(auto&[a,b,c,d]:A){\n\
    \    lct.add_segment(press.get_index(a),press.get_index(b),c,d);\n  }\n  for(auto&[a,b,c,d,e]:B){\n\
    \    if(a==0)lct.add_segment(press.get_index(b),press.get_index(c),d,e);\n   \
    \ else{\n      ll res=lct.get_min(press.get_index(b));\n      if(res==infinity<ll>::max)print(\"\
    INFINITY\");\n      else print(res);\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/data_strucuture/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/data_strucuture/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_strucuture/segment_add_get_min.test.cpp
- /verify/test/yosupo/data_strucuture/segment_add_get_min.test.cpp.html
title: test/yosupo/data_strucuture/segment_add_get_min.test.cpp
---
