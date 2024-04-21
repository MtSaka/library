---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Bit Vector
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../template/template.hpp\"\n\nstruct BitVector{\n\
    \  private:\n  size_t size,block;\n  vector<unsigned int>bit,sum;\n  public:\n\
    \  BitVector(){}\n  BitVector(size_t size):size(size),block((size+31)>>5),bit(block,0u),sum(block,0u){}\n\
    \  void set(int i){bit[i>>5]|=1u<<(i&31);}\n  bool operator[](int i)const{return\
    \ (bit[i>>5]>>(i&31))&1;}\n  void build(){\n    sum[0]=0u;\n    for(size_t i=1;i<block;i++)sum[i]=sum[i-1]+__builtin_popcount(bit[i-1]);\n\
    \  }\n  int rank(int i)const{return sum[i>>5]+__builtin_popcount(bit[i>>5]&((1<<(i&31))-1));}\n\
    \  int rank(bool v,int i)const{return (v?rank(i):i-rank(i));}\n};\n/**\n * @brief\
    \ Bit Vector\n*/"
  dependsOn: []
  isVerificationFile: false
  path: ds/wavelet/bit-vector.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/wavelet/bit-vector.hpp
layout: document
redirect_from:
- /library/ds/wavelet/bit-vector.hpp
- /library/ds/wavelet/bit-vector.hpp.html
title: Bit Vector
---
