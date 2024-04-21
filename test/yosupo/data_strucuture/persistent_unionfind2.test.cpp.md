---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    #include\"../../../template/template.hpp\"\n#include\"../../../ds/union-find/rollback-union-find.hpp\"\
    \nint main(){\n  int n,q;cin>>n>>q;\n  vector<vector<array<int,3>>>g(q+1);\n \
    \ vector<vector<array<int,3>>>a(q+1);\n  rep(i,q){\n    int t,k,u,v;cin>>t>>k>>u>>v;\n\
    \    if(t==0)g[k+1].eb(array<int,3>{(int)i+1,u,v});\n    else a[k+1].eb(array<int,3>{(int)i,u,v});\n\
    \  }\n  vector<int>ans(q,-1);\n  RollbackUnionFind dsu(n);\n  REC([&](auto&&f,int\
    \ v)->void{\n    for(auto&b:a[v])ans[b[0]]=dsu.same(b[1],b[2]);\n    for(auto&e:g[v]){\n\
    \      dsu.merge(e[1],e[2]);\n      f(e[0]);\n      dsu.undo();\n    }\n  })(0);\n\
    \  for(auto&i:ans)if(i!=-1)print(i);\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/data_strucuture/persistent_unionfind2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/data_strucuture/persistent_unionfind2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_strucuture/persistent_unionfind2.test.cpp
- /verify/test/yosupo/data_strucuture/persistent_unionfind2.test.cpp.html
title: test/yosupo/data_strucuture/persistent_unionfind2.test.cpp
---
