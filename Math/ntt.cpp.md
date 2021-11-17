---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../code/library/Math/modint.cpp:\
    \ line -1: no such header\n"
  code: "#include<bits/stdc++.h>\n#include\"../../code/library/Math/modint.cpp\"\n\
    using namespace std;\ntemplate<long long m>\nstruct NTT{\n  using mint=modint<m>;\n\
    \  mint g=2;\n  int limit=0;\n  vector<mint>root,inv_root;\n  mint primitive_root(long\
    \ long mo){\n    if(mo==167772161)return mint(3);\n    if(mo==469762049)return\
    \ mint(3);\n    if(mo==754974721)return mint(11);\n    if(mo==998244353)return\
    \ mint(3);\n    if(mo==1224736769)return mint(3);\n    return mint(0);\n  }\n\
    \  NTT(){\n    g=primitive_root(m);\n    long long now=m-1;\n    while(!(now&1))now>>=1,limit++;\n\
    \    root.resize(limit+1,1),inv_root.resize(limit+1,1);\n    root[limit]=g.pow(now);\n\
    \    inv_root[limit]/=root[limit];\n    for(int i=limit-1;i>=0;i--){\n      root[i]=root[i+1]*root[i+1];\n\
    \      inv_root[i]=inv_root[i+1]*inv_root[i+1];\n    }\n  }\n  void dft(vector<mint>&a,int\
    \ inv){\n    int sz=a.size();\n    if(sz==1)return;\n    int mask=sz-1;\n    vector<mint>b(sz);\n\
    \    for(int i=sz>>1;i>=1;i>>=1){\n      int e=__builtin_ffsll(sz/i)-1;\n    \
    \  mint w=1,z=(inv==1?root[e]:inv_root[e]);\n      for(int j=0;j<sz;j+=i){\n \
    \       for(int k=0;k<i;k++)b[j+k]=a[((j<<1)&mask)+k]+w*a[(((j<<1)+i)&mask)+k];\n\
    \        w*=z;\n      }\n      swap(a,b);\n    }\n  }\n  vector<mint>multiply(vector<mint>a,vector<mint>b){\n\
    \    int sz=1,mxsiz=a.size()+b.size()-1;\n    while(sz<mxsiz)sz<<=1;\n    a.resize(sz),b.resize(sz);\n\
    \    dft(a,1),dft(b,1);\n    for(int i=0;i<sz;i++)a[i]*=b[i];\n    dft(a,-1);\n\
    \    mint iz=mint(sz).inv();\n    for(int i=0;i<mxsiz;i++)a[i]*=iz;\n    a.resize(mxsiz);\n\
    \    return a;\n  }\n  template<typename T,std::enable_if_t<is_integral<T>::value>*\
    \ = nullptr>\n  vector<T>multiply(const vector<T>&a,const vector<T>&b){\n    using\
    \ mint=modint<m>;\n    vector<mint>a2(a.size()),b2(b.size());\n    for(int i=0;i<a.size();i++)a2[i]=a[i];\n\
    \    for(int i=0;i<b.size();i++)b2[i]=b[i];\n    auto c2=multiply(move(a2),move(b2));\n\
    \    vector<T>c(c2.size());\n    for(int i=0;i<c.size();i++)c[i]=c2[i].x;\n  \
    \  return c;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Math/ntt.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/ntt.cpp
layout: document
redirect_from:
- /library/Math/ntt.cpp
- /library/Math/ntt.cpp.html
title: Math/ntt.cpp
---
