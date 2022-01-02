---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_2_A.test.cpp
    title: test/aoj/DSL/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_range_sum1.test.cpp
    title: test/yosupo/point_add_range_sum1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
    links: []
  bundledCode: "#line 1 \"Data_Structure/segtree.hpp\"\n/**\n * @brief Segment Tree(\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728)\n*/\ntemplate<class S,S (*op)(S,S),S (*e)()>\n\
    struct segtree{\n  private:\n  int _n,size,idx=0;\n  vector<S>seq;\n  void update(int\
    \ k){seq[k]=op(seq[2*k],seq[2*k+1]);}\n  public:\n  segtree():segtree(0){};\n\
    \  segtree(int n):segtree(vector<S>(n,e())){}\n  segtree(const vector<S>&v):_n(int(v.size())){\n\
    \    while((1<<idx)<_n)idx++;\n    size=1<<idx;\n    seq=vector<S>(2*size,e());\n\
    \    for(int i=0;i<_n;i++)seq[size+i]=v[i];\n    for(int i=size-1;i>=1;i--)update(i);\n\
    \  }\n  void set(int p,S x){\n    p+=size;\n    seq[p]=x;\n    for(int i=1;i<=idx;i++)update(p>>i);\n\
    \  }\n  S operator[](int p){return seq[p+size];}\n  S query(int l,int r)const{\n\
    \    S sml=e(),smr=e();\n    l+=size,r+=size;\n    while(l<r){\n      if(l&1)sml=op(sml,seq[l++]);\n\
    \      if(r&1)smr=op(seq[--r],smr);\n      l>>=1,r>>=1;\n    }\n    return op(sml,smr);\n\
    \  }\n  S all_query()const{\n    return seq[1];\n  }\n};\n"
  code: "/**\n * @brief Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n*/\ntemplate<class\
    \ S,S (*op)(S,S),S (*e)()>\nstruct segtree{\n  private:\n  int _n,size,idx=0;\n\
    \  vector<S>seq;\n  void update(int k){seq[k]=op(seq[2*k],seq[2*k+1]);}\n  public:\n\
    \  segtree():segtree(0){};\n  segtree(int n):segtree(vector<S>(n,e())){}\n  segtree(const\
    \ vector<S>&v):_n(int(v.size())){\n    while((1<<idx)<_n)idx++;\n    size=1<<idx;\n\
    \    seq=vector<S>(2*size,e());\n    for(int i=0;i<_n;i++)seq[size+i]=v[i];\n\
    \    for(int i=size-1;i>=1;i--)update(i);\n  }\n  void set(int p,S x){\n    p+=size;\n\
    \    seq[p]=x;\n    for(int i=1;i<=idx;i++)update(p>>i);\n  }\n  S operator[](int\
    \ p){return seq[p+size];}\n  S query(int l,int r)const{\n    S sml=e(),smr=e();\n\
    \    l+=size,r+=size;\n    while(l<r){\n      if(l&1)sml=op(sml,seq[l++]);\n \
    \     if(r&1)smr=op(seq[--r],smr);\n      l>>=1,r>>=1;\n    }\n    return op(sml,smr);\n\
    \  }\n  S all_query()const{\n    return seq[1];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/segtree.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:45:08+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL/DSL_2_A.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yosupo/point_add_range_sum1.test.cpp
documentation_of: Data_Structure/segtree.hpp
layout: document
redirect_from:
- /library/Data_Structure/segtree.hpp
- /library/Data_Structure/segtree.hpp.html
title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---