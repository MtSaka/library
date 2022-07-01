---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Data_Structure/inversion.hpp
    title: "Inversion Number(\u8EE2\u5012\u6570)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1/ALDS1_5_D.test.cpp
    title: test/aoj/ALDS1/ALDS1_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_2_B.test.cpp
    title: test/aoj/DSL/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_range_sum2.test.cpp
    title: test/yosupo/point_add_range_sum2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Binary Indexed Tree(BIT)
    links: []
  bundledCode: "#line 2 \"Data_Structure/BIT.hpp\"\ntemplate<typename T>\nstruct BIT{\n\
    \  private:\n  int N;\n  vector<T>bit;\n  public:\n  BIT(int n){\n    N=1;\n \
    \   while(N<n)N<<=1;\n    bit=vector<T>(N+1,0);\n  }\n  void add(int i,T x){\n\
    \    i++;\n    while(i<=N){\n      bit[i]+=x;\n      i+=i&-i;    \n    }\n  }\n\
    \  T sum(int i){\n    T ans=0;\n    while(i>0)ans+=bit[i],i-=i&-i;\n    return\
    \ ans;\n  }\n  T query(int l,int r){\n    return sum(r)-sum(l);\n  }\n};\n/**\n\
    \ * @brief Binary Indexed Tree(BIT)\n*/\n"
  code: "#pragma once\ntemplate<typename T>\nstruct BIT{\n  private:\n  int N;\n \
    \ vector<T>bit;\n  public:\n  BIT(int n){\n    N=1;\n    while(N<n)N<<=1;\n  \
    \  bit=vector<T>(N+1,0);\n  }\n  void add(int i,T x){\n    i++;\n    while(i<=N){\n\
    \      bit[i]+=x;\n      i+=i&-i;    \n    }\n  }\n  T sum(int i){\n    T ans=0;\n\
    \    while(i>0)ans+=bit[i],i-=i&-i;\n    return ans;\n  }\n  T query(int l,int\
    \ r){\n    return sum(r)-sum(l);\n  }\n};\n/**\n * @brief Binary Indexed Tree(BIT)\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/BIT.hpp
  requiredBy:
  - Data_Structure/inversion.hpp
  timestamp: '2022-07-01 22:11:02+01:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/static_range_inversions_query.test.cpp
  - test/yosupo/point_add_range_sum2.test.cpp
  - test/aoj/ALDS1/ALDS1_5_D.test.cpp
  - test/aoj/DSL/DSL_2_B.test.cpp
documentation_of: Data_Structure/BIT.hpp
layout: document
redirect_from:
- /library/Data_Structure/BIT.hpp
- /library/Data_Structure/BIT.hpp.html
title: Binary Indexed Tree(BIT)
---
