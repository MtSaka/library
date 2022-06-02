---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Data_Structure/wavelet_matrix.hpp
    title: Wavelet Matrix
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Data_Structure/bit_vector.hpp\"\nstruct bit_vector{\n  private:\n\
    \  size_t size,block;\n  vector<unsigned int>bit,sum;\n  public:\n  bit_vector(){}\n\
    \  bit_vector(size_t size):size(size),block((size+31)>>5),bit(block,0u),sum(block,0u){}\n\
    \  void set(int i){bit[i>>5]|=1u<<(i&31);}\n  bool operator[](int i){return bool((bit[i>>5]>>(i&31))&1);}\n\
    \  void build(){\n    sum[0]=0u;\n    for(size_t i=1;i<block;i++)sum[i]=sum[i-1]+__buitin_popcount(bit[i-1]);\n\
    \  }\n  int rank(int i){return sum[i>>5]+__builtin_popcount(bit[i>>5]&((1u<<(i&31))-1));}\n\
    \  int rank(bool v,int i){return (v?rank(i):i-rank(i));}\n};\n"
  code: "#pragma once\nstruct bit_vector{\n  private:\n  size_t size,block;\n  vector<unsigned\
    \ int>bit,sum;\n  public:\n  bit_vector(){}\n  bit_vector(size_t size):size(size),block((size+31)>>5),bit(block,0u),sum(block,0u){}\n\
    \  void set(int i){bit[i>>5]|=1u<<(i&31);}\n  bool operator[](int i){return bool((bit[i>>5]>>(i&31))&1);}\n\
    \  void build(){\n    sum[0]=0u;\n    for(size_t i=1;i<block;i++)sum[i]=sum[i-1]+__buitin_popcount(bit[i-1]);\n\
    \  }\n  int rank(int i){return sum[i>>5]+__builtin_popcount(bit[i>>5]&((1u<<(i&31))-1));}\n\
    \  int rank(bool v,int i){return (v?rank(i):i-rank(i));}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/bit_vector.hpp
  requiredBy:
  - Data_Structure/wavelet_matrix.hpp
  timestamp: '2022-06-02 17:05:14+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/bit_vector.hpp
layout: document
redirect_from:
- /library/Data_Structure/bit_vector.hpp
- /library/Data_Structure/bit_vector.hpp.html
title: Data_Structure/bit_vector.hpp
---
