---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  requiredBy: []
  timestamp: '2022-01-17 17:09:11+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/staticrmq.test.cpp
documentation_of: Data_Structure/sparse_table.hpp
layout: document
redirect_from:
- /library/Data_Structure/sparse_table.hpp
- /library/Data_Structure/sparse_table.hpp.html
title: Sparse Table
---
