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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data-structure/binay-indexed-tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include\"../../template/template.hpp\"\n#include\"../../data-structure/binay-indexed-tree.hpp\"\
    \n#include\"../../Others/mo.hpp\"\nint main(){\n  int n,q;\n  cin>>n>>q;\n  vector<int>a(n);\n\
    \  cin>>a;\n  Mo mo(n);\n  for(int i=0;i<q;i++){\n    int l,r;cin>>l>>r;\n   \
    \ mo.add(l,r);\n  }\n  vector<int>b{a};\n  sort(b.begin(),b.end());\n  b.erase(unique(b.begin(),b.end()),b.end());\n\
    \  for(auto&i:a)i=lower_bound(b.begin(),b.end(),i)-b.begin();\n  BinaryIndexedTree<int>bit(b.size()+1);\n\
    \  ll inv=0,sum=0;\n  vector<ll>ans(q);\n  auto add_left=[&](int idx){\n    inv+=bit.sum(a[idx]);\n\
    \    bit.add(a[idx],1);\n    sum++;\n  };\n  auto add_right=[&](int idx){\n  \
    \  inv+=sum-bit.sum(a[idx]+1);\n    bit.add(a[idx],1);\n    sum++;\n  };\n  auto\
    \ delete_left=[&](int idx){\n    inv-=bit.sum(a[idx]);\n    bit.add(a[idx],-1);\n\
    \    sum--;\n  };\n  auto delete_right=[&](int idx){\n    inv-=sum-bit.sum(a[idx]+1);\n\
    \    bit.add(a[idx],-1);\n    sum--;\n  };\n  auto rem=[&](int idx){ans[idx]=inv;};\n\
    \  mo.run(add_left,add_right,delete_left,delete_right,rem);\n  for(auto i:ans)print(i);\n\
    }"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_inversions_query.test.cpp
- /verify/test/yosupo/static_range_inversions_query.test.cpp.html
title: test/yosupo/static_range_inversions_query.test.cpp
---
