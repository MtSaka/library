---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Mod Log(\u96E2\u6563\u5BFE\u6570)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../ds/hash-map.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../../template/template.hpp\"\n#include\"../../ds/hash-map.hpp\"\
    \n\ntemplate<typename T>\nT discrete_logarithm(T x,T y,T m){\n  x%=m,y%=m;\n \
    \ if(y==1||m==1)return 0;\n  if(x==0)return y==0?1:-1;\n  T add=0,g,k=1%m;\n \
    \ while((g=gcd(x,m))>1){\n    if(y==k)return add;\n    if(y%g)return -1;\n   \
    \ y/=g,m/=g,add++;\n    k=(k*(x/g))%m;\n  }\n  T n=sqrt(m)+1;\n  T tmp=mod_pow(x,n,m);\n\
    \  HashMap<T,T>mp;\n  for(T i=0,now=y;i<=n;i++){\n    mp[now]=i;\n    now=(now*x)%m;\n\
    \  }\n  for(T i=1,now=k;i<=n;i++){\n    now=(now*tmp)%m;\n    if(mp.contain(now))return\
    \ n*i-mp[now]+add;\n  }\n  return -1;\n}\n/**\n * @brief Mod Log(\u96E2\u6563\u5BFE\
    \u6570)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/modular/mod-log.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modular/mod-log.hpp
layout: document
redirect_from:
- /library/math/modular/mod-log.hpp
- /library/math/modular/mod-log.hpp.html
title: "Mod Log(\u96E2\u6563\u5BFE\u6570)"
---
