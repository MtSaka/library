---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Graph/tree/RMQ_lowest_common_ancestor.hpp
    title: "RMQ Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL/GRL_5_C_2.test.cpp
    title: test/aoj/GRL/GRL_5_C_2.test.cpp
  - icon: ':x:'
    path: test/yosupo/lca2.test.cpp
    title: test/yosupo/lca2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Sparse Table
    links: []
  bundledCode: "#line 1 \"Data_Structure/sparse_table.hpp\"\ntemplate<class S,S (*op)(S,S)>\n\
    struct sparse_table{\n  private:\n  vector<vector<S>>table;\n  vector<int>log_table;\n\
    \  public:\n  sparse_table()=default;\n  sparse_table(const vector<S>&v){\n  \
    \  const int n=(int)v.size();\n    const int lg=32-__builtin_clz(n);\n    table.assign(lg,vector<S>(n));\n\
    \    for(int i=0;i<n;i++)table[0][i]=v[i];\n    for(int i=1;i<lg;i++)for(int j=0;j+(1<<i)<=n;j++)table[i][j]=op(table[i-1][j],table[i-1][j+(1<<(i-1))]);\n\
    \    log_table.resize(n+1);\n    for(int i=2;i<=n;i++)log_table[i]=1+log_table[i>>1];\n\
    \  }\n  S query(int l,int r){\n    int a=log_table[r-l];\n    return op(table[a][l],table[a][r-(1<<a)]);\n\
    \  }\n};\n/**\n * @brief Sparse Table\n*/\n"
  code: "template<class S,S (*op)(S,S)>\nstruct sparse_table{\n  private:\n  vector<vector<S>>table;\n\
    \  vector<int>log_table;\n  public:\n  sparse_table()=default;\n  sparse_table(const\
    \ vector<S>&v){\n    const int n=(int)v.size();\n    const int lg=32-__builtin_clz(n);\n\
    \    table.assign(lg,vector<S>(n));\n    for(int i=0;i<n;i++)table[0][i]=v[i];\n\
    \    for(int i=1;i<lg;i++)for(int j=0;j+(1<<i)<=n;j++)table[i][j]=op(table[i-1][j],table[i-1][j+(1<<(i-1))]);\n\
    \    log_table.resize(n+1);\n    for(int i=2;i<=n;i++)log_table[i]=1+log_table[i>>1];\n\
    \  }\n  S query(int l,int r){\n    int a=log_table[r-l];\n    return op(table[a][l],table[a][r-(1<<a)]);\n\
    \  }\n};\n/**\n * @brief Sparse Table\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/sparse_table.hpp
  requiredBy:
  - Graph/tree/RMQ_lowest_common_ancestor.hpp
  timestamp: '2022-06-02 20:39:24+01:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/GRL/GRL_5_C_2.test.cpp
  - test/yosupo/lca2.test.cpp
  - test/yosupo/staticrmq.test.cpp
documentation_of: Data_Structure/sparse_table.hpp
layout: document
redirect_from:
- /library/Data_Structure/sparse_table.hpp
- /library/Data_Structure/sparse_table.hpp.html
title: Sparse Table
---
