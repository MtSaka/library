---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Combinatorics(\u7D44\u307F\u5408\u308F\u305B)"
    links: []
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../modular/ModInt.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../../template/template.hpp\"\n#include\"../modular/ModInt.hpp\"\
    \n\ntemplate<int m>\nstruct Combinatorics{\n  using mint=ModInt<m>;\n  private:\n\
    \  static vector<mint>dat,idat;\n  inline static void extend(int sz){\n    if((int)dat.size()<sz+1){\n\
    \      int pre_sz=max<int>(1,dat.size());\n      dat.resize(sz+1,1);\n      idat.resize(sz+1,1);\n\
    \      for(int i=pre_sz;i<=sz;i++)dat[i]=dat[i-1]*i;\n      idat[sz]=1/dat[sz];\n\
    \      for(int i=sz-1;i>=pre_sz;i--)idat[i]=idat[i+1]*(i+1);\n    }\n  }\n  public:\n\
    \  Combinatorics(int sz=0){extend(sz);}\n  template<typename T>\n  static inline\
    \ mint fac(T n){\n    if(n<0)return mint();\n    extend(n);\n    return dat[n];\n\
    \  }\n  template<typename T>\n  static inline mint finv(T n){\n    if(n<0)return\
    \ mint();\n    extend(n);\n    return idat[n];\n  }\n  template<typename T,typename\
    \ U>\n  static mint com(T n,U k){\n    if(k<0||n<k)return mint();\n    return\
    \ fac(n)*finv(k)*finv(n-k);\n  }\n  template<typename T,typename U>\n  static\
    \ mint hom(T n,U k){\n    if(n<0||k<0)return mint();\n    return k==0?1:com(n+k-1,k);\n\
    \  }\n  template<typename T,typename U>\n  static mint per(T n,U k){\n    if(k<0||n<k)return\
    \ mint();\n    return fac(n)*finv(n-k);\n  }\n};\ntemplate<int m>\nvector<ModInt<m>>Combinatorics<m>::dat=vector<ModInt<m>>();\n\
    template<int m>\nvector<ModInt<m>>Combinatorics<m>::idat=vector<ModInt<m>>();\n\
    template<long long p>\nstruct COMB{\n  private:\n  static vector<vector<ModInt<p>>>comb;\n\
    \  static void init(){\n    if(!comb.empty())return;\n    comb.assign(p,vector<ModInt<p>>(p));\n\
    \    comb[0][0]=1;\n    for(int i=1;i<p;i++){\n      comb[i][0]=1;\n      for(int\
    \ j=i;j>0;j--)comb[i][j]=comb[i-1][j-1]+comb[i-1][j];\n    }\n  }\n  public:\n\
    \  COMB(){\n    init();\n  }\n  ModInt<p>com(int n,int k){\n    init();\n    ModInt<p>ret=1;\n\
    \    while(n>0||k>0){\n      int ni=n%p,ki=k%p;\n      ret*=comb[ni][ki];\n  \
    \    n/=p;k/=p;\n    }\n    return ret;\n  }\n};\ntemplate<long long p>\nvector<vector<ModInt<p>>>COMB<p>::comb=vector<vector<ModInt<p>>>();\n\
    /**\n * @brief Combinatorics(\u7D44\u307F\u5408\u308F\u305B)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: math/others/combinatorics.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/others/combinatorics.hpp
layout: document
redirect_from:
- /library/math/others/combinatorics.hpp
- /library/math/others/combinatorics.hpp.html
title: "Combinatorics(\u7D44\u307F\u5408\u308F\u305B)"
---
