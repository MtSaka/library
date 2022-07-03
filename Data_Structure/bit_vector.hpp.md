---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Data_Structure/wavelet_matrix.hpp
    title: Wavelet Matrix
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/range_kth_smallest.test.cpp
    title: test/yosupo/range_kth_smallest.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Bit Vector
    links: []
  bundledCode: "#line 2 \"Data_Structure/bit_vector.hpp\"\nstruct bit_vector{\n  private:\n\
    \  size_t size,block;\n  vector<unsigned int>bit,sum;\n  public:\n  bit_vector(){}\n\
    \  bit_vector(size_t size):size(size),block((size+31)>>5),bit(block,0u),sum(block,0u){}\n\
    \  void set(int i){bit[i>>5]|=1u<<(i&31);}\n  bool operator[](int i)const{return\
    \ (bit[i>>5]>>(i&31))&1;}\n  void build(){\n    sum[0]=0u;\n    for(size_t i=1;i<block;i++)sum[i]=sum[i-1]+__builtin_popcount(bit[i-1]);\n\
    \  }\n  int rank(int i)const{return sum[i>>5]+__builtin_popcount(bit[i>>5]&((1<<(i&31))-1));}\n\
    \  int rank(bool v,int i)const{return (v?rank(i):i-rank(i));}\n};\n/**\n * @brief\
    \ Bit Vector\n*/\n"
  code: "#pragma once\nstruct bit_vector{\n  private:\n  size_t size,block;\n  vector<unsigned\
    \ int>bit,sum;\n  public:\n  bit_vector(){}\n  bit_vector(size_t size):size(size),block((size+31)>>5),bit(block,0u),sum(block,0u){}\n\
    \  void set(int i){bit[i>>5]|=1u<<(i&31);}\n  bool operator[](int i)const{return\
    \ (bit[i>>5]>>(i&31))&1;}\n  void build(){\n    sum[0]=0u;\n    for(size_t i=1;i<block;i++)sum[i]=sum[i-1]+__builtin_popcount(bit[i-1]);\n\
    \  }\n  int rank(int i)const{return sum[i>>5]+__builtin_popcount(bit[i>>5]&((1<<(i&31))-1));}\n\
    \  int rank(bool v,int i)const{return (v?rank(i):i-rank(i));}\n};\n/**\n * @brief\
    \ Bit Vector\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/bit_vector.hpp
  requiredBy:
  - Data_Structure/wavelet_matrix.hpp
  timestamp: '2022-06-02 17:56:16+01:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/range_kth_smallest.test.cpp
documentation_of: Data_Structure/bit_vector.hpp
layout: document
redirect_from:
- /library/Data_Structure/bit_vector.hpp
- /library/Data_Structure/bit_vector.hpp.html
title: Bit Vector
---
