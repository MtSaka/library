---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/tree/RMQ_lowest_common_ancestor.hpp
    title: "RMQ Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_5_C_2.test.cpp
    title: test/aoj/GRL/GRL_5_C_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca2.test.cpp
    title: test/yosupo/lca2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Sparse Table
    links: []
  bundledCode: "#line 1 \"Data_Structure/sparse_table.hpp\"\ntemplate<typename T,typename\
    \ F>\nstruct sparse_table{\n  F f;\n  vector<vector<T>>table;\n  vector<int>log_table;\n\
    \  sparse_table()=default;\n  sparse_table(const vector<T>&v,const F&f):f(f){\n\
    \    const int n=(int)v.size();\n    const int lg=32-__builtin_clz(n);\n    table.assign(lg,vector<T>(n));\n\
    \    for(int i=0;i<n;i++)table[0][i]=v[i];\n    for(int i=1;i<lg;i++)for(int j=0;j+(1<<i)<=n;j++)table[i][j]=f(table[i-1][j],table[i-1][j+(1<<(i-1))]);\n\
    \    log_table.resize(n+1);\n    for(int i=2;i<=n;i++)log_table[i]=1+log_table[i>>1];\n\
    \  }\n  T query(int l,int r){\n    int a=log_table[r-l];\n    return f(table[a][l],table[a][r-(1<<a)]);\n\
    \  }\n};\ntemplate<typename T,typename F>\nsparse_table<T,F>make_sparse_table(const\
    \ vector<T>&v,const F&f){\n  return sparse_table<T,F>(v,f);\n} \n/**\n * @brief\
    \ Sparse Table\n*/\n"
  code: "template<typename T,typename F>\nstruct sparse_table{\n  F f;\n  vector<vector<T>>table;\n\
    \  vector<int>log_table;\n  sparse_table()=default;\n  sparse_table(const vector<T>&v,const\
    \ F&f):f(f){\n    const int n=(int)v.size();\n    const int lg=32-__builtin_clz(n);\n\
    \    table.assign(lg,vector<T>(n));\n    for(int i=0;i<n;i++)table[0][i]=v[i];\n\
    \    for(int i=1;i<lg;i++)for(int j=0;j+(1<<i)<=n;j++)table[i][j]=f(table[i-1][j],table[i-1][j+(1<<(i-1))]);\n\
    \    log_table.resize(n+1);\n    for(int i=2;i<=n;i++)log_table[i]=1+log_table[i>>1];\n\
    \  }\n  T query(int l,int r){\n    int a=log_table[r-l];\n    return f(table[a][l],table[a][r-(1<<a)]);\n\
    \  }\n};\ntemplate<typename T,typename F>\nsparse_table<T,F>make_sparse_table(const\
    \ vector<T>&v,const F&f){\n  return sparse_table<T,F>(v,f);\n} \n/**\n * @brief\
    \ Sparse Table\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/sparse_table.hpp
  requiredBy:
  - Graph/tree/RMQ_lowest_common_ancestor.hpp
  timestamp: '2022-06-02 20:57:01+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lca2.test.cpp
  - test/yosupo/staticrmq.test.cpp
  - test/aoj/GRL/GRL_5_C_2.test.cpp
documentation_of: Data_Structure/sparse_table.hpp
layout: document
redirect_from:
- /library/Data_Structure/sparse_table.hpp
- /library/Data_Structure/sparse_table.hpp.html
title: Sparse Table
---
