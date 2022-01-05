---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/inversion.hpp
    title: "Inversion Number(\u8EE2\u5012\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1/ALDS1_5_D.test.cpp
    title: test/aoj/ALDS1/ALDS1_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_2_B.test.cpp
    title: test/aoj/DSL/DSL_2_B.test.cpp
  - icon: ':x:'
    path: test/yosupo/point_add_range_sum2.test.cpp
    title: test/yosupo/point_add_range_sum2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Binary Indexed Tree(BIT)
    links: []
  bundledCode: "#line 1 \"Data_Structure/BIT.hpp\"\n/**\n * @brief Binary Indexed\
    \ Tree(BIT)\n*/\ntemplate<typename T>\nstruct BIT{\n  long long N;\n  vector<T>bit;\n\
    \  BIT(long long n){\n    N=1;\n    while(N<n){\n      N*=2;\n    }\n    bit=vector<T>(N+1,0);\n\
    \  }\n  void add(int i,T x){\n    i++;\n    while(i<=N){\n      bit[i]+=x;\n \
    \     i+=i&-i;    \n    }\n  }\n  T sum(int i){\n    T ans=0;\n    while(i>0)ans+=bit[i],i-=i&-i;\n\
    \    return ans;\n  }\n  T query(int l,int r){\n    return sum(r)-sum(l);\n  }\n\
    };\n"
  code: "/**\n * @brief Binary Indexed Tree(BIT)\n*/\ntemplate<typename T>\nstruct\
    \ BIT{\n  long long N;\n  vector<T>bit;\n  BIT(long long n){\n    N=1;\n    while(N<n){\n\
    \      N*=2;\n    }\n    bit=vector<T>(N+1,0);\n  }\n  void add(int i,T x){\n\
    \    i++;\n    while(i<=N){\n      bit[i]+=x;\n      i+=i&-i;    \n    }\n  }\n\
    \  T sum(int i){\n    T ans=0;\n    while(i>0)ans+=bit[i],i-=i&-i;\n    return\
    \ ans;\n  }\n  T query(int l,int r){\n    return sum(r)-sum(l);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/BIT.hpp
  requiredBy:
  - Data_Structure/inversion.hpp
  timestamp: '2021-12-23 11:45:08+00:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DSL/DSL_2_B.test.cpp
  - test/aoj/ALDS1/ALDS1_5_D.test.cpp
  - test/yosupo/point_add_range_sum2.test.cpp
documentation_of: Data_Structure/BIT.hpp
layout: document
redirect_from:
- /library/Data_Structure/BIT.hpp
- /library/Data_Structure/BIT.hpp.html
title: Binary Indexed Tree(BIT)
---
