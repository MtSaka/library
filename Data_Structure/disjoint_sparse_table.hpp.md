---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Disjoint Sparse Table
    links: []
  bundledCode: "#line 2 \"Data_Structure/disjoint_sparse_table.hpp\"\ntemplate<class\
    \ S,S (*op)(S,S),S (*e)()>\nstruct disjoint_sparse_table{\n  private:\n  vector<vector<S>>table;\n\
    \  vector<int>log_table;\n  public:\n  disjoint_sparse_table(const vector<S>&v){\n\
    \    int bit=0,sz=1;\n    while(sz<=(int)v.size())sz<<=1,bit++;\n    table.resize(bit,vector<S>(v.size(),e()));\n\
    \    for(size_t i=0;i<v.size();i++)table[0][i]=v[i];\n    int shift=1;\n    for(int\
    \ i=1;i<bit;i++){\n      shift<<=1;\n      for(int j=0;j<(int)v.size();j+=shift<<1){\n\
    \        int l=min<int>(j+shift,v.size());\n        table[i][l-1]=v[l-1];\n  \
    \      for(int k=l-2;l>=j;l--)table[i][k]=op(v[k],table[i][k+1]);\n        if((int)v.size()==l)break;\n\
    \        table[i][l]=v[l];\n        int r=min<int>(l+shift,v.size());\n      \
    \  for(int k=l+1;k<r;k++)table[i][k]=op(table[i][k-1],v[k]);\n      }\n    }\n\
    \    log_table.resize(sz);\n    for(int i=2;i<sz;i++)log_table[i]=1+log_table[i>>1];\n\
    \  }\n  S query(int l,int r){\n    if(l>=--r)return table[0][l];\n    int pos=log_table[l^r];\n\
    \    return op(table[pos][l],table[pos][r]);\n  }\n};\n/**\n * @brief Disjoint\
    \ Sparse Table\n */\n"
  code: "#pragma once\ntemplate<class S,S (*op)(S,S),S (*e)()>\nstruct disjoint_sparse_table{\n\
    \  private:\n  vector<vector<S>>table;\n  vector<int>log_table;\n  public:\n \
    \ disjoint_sparse_table(const vector<S>&v){\n    int bit=0,sz=1;\n    while(sz<=(int)v.size())sz<<=1,bit++;\n\
    \    table.resize(bit,vector<S>(v.size(),e()));\n    for(size_t i=0;i<v.size();i++)table[0][i]=v[i];\n\
    \    int shift=1;\n    for(int i=1;i<bit;i++){\n      shift<<=1;\n      for(int\
    \ j=0;j<(int)v.size();j+=shift<<1){\n        int l=min<int>(j+shift,v.size());\n\
    \        table[i][l-1]=v[l-1];\n        for(int k=l-2;l>=j;l--)table[i][k]=op(v[k],table[i][k+1]);\n\
    \        if((int)v.size()==l)break;\n        table[i][l]=v[l];\n        int r=min<int>(l+shift,v.size());\n\
    \        for(int k=l+1;k<r;k++)table[i][k]=op(table[i][k-1],v[k]);\n      }\n\
    \    }\n    log_table.resize(sz);\n    for(int i=2;i<sz;i++)log_table[i]=1+log_table[i>>1];\n\
    \  }\n  S query(int l,int r){\n    if(l>=--r)return table[0][l];\n    int pos=log_table[l^r];\n\
    \    return op(table[pos][l],table[pos][r]);\n  }\n};\n/**\n * @brief Disjoint\
    \ Sparse Table\n */"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2022-06-02 20:39:24+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/Data_Structure/disjoint_sparse_table.hpp
- /library/Data_Structure/disjoint_sparse_table.hpp.html
title: Disjoint Sparse Table
---
