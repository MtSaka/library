---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Data_Structure/segtree_monoids.hpp
    title: "Monoids(\u30E2\u30CE\u30A4\u30C9)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL/DSL_2_A.test.cpp
    title: test/aoj/DSL/DSL_2_A.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL/DSL_2_B2.test.cpp
    title: test/aoj/DSL/DSL_2_B2.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL/DSL_2_D.test.cpp
    title: test/aoj/DSL/DSL_2_D.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL/DSL_2_E.test.cpp
    title: test/aoj/DSL/DSL_2_E.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL/DSL_2_F.test.cpp
    title: test/aoj/DSL/DSL_2_F.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL/DSL_2_G.test.cpp
    title: test/aoj/DSL/DSL_2_G.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL/DSL_2_H.test.cpp
    title: test/aoj/DSL/DSL_2_H.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL/DSL_2_I.test.cpp
    title: test/aoj/DSL/DSL_2_I.test.cpp
  - icon: ':x:'
    path: test/yosupo/point_add_range_sum1.test.cpp
    title: test/yosupo/point_add_range_sum1.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Dual Segment Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      )"
    links: []
  bundledCode: "#line 2 \"Data_Structure/dual_segtree.hpp\"\ntemplate<class S,class\
    \ F,S (*mapping)(F,S),F (*composition)(F,F),F (*id)()>\nstruct dual_segtree{\n\
    \  private:\n  int _n,size=1,idx=0;\n  vector<S>seq;\n  vector<F>lazy;\n  void\
    \ all_apply(int k,F f){\n    if(k<size)lazy[k]=composition(f,lazy[k]);\n    else\
    \ if(k<size+_n)seq[k-size]=mapping(f,seq[k-size]);\n  }\n  void eval(int k){\n\
    \    all_apply(k<<1,lazy[k]);\n    all_apply(k<<1^1,lazy[k]);\n    lazy[k]=id();\n\
    \  }\n  public:\n  dual_segtree():dual_segtree(0){}\n  dual_segtree(int n,S e=S()):dual_segtree(vector<S>(n,e)){};\n\
    \  dual_segtree(const vector<S>&v):_n(v.size()){\n    while(size<_n)size<<=1,idx++;\n\
    \    seq=v;lazy=vector<F>(size,id());\n  }\n  void set(int p,S x){\n    p+=size;\n\
    \    for(int i=idx;i>=1;i--)eval(p>>i);\n    seq[p-size]=x;\n  }\n  S operator[](int\
    \ p){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n    return seq[p-size];\n\
    \  }\n  void apply(int p,F f){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n\
    \    seq[p-size]=mapping(f,seq[p-size]);\n  }\n  void apply(int l,int r,F f){\n\
    \    if(l==r)return;\n    l+=size;r+=size;\n    for(int i=idx;i>=1;i--){\n   \
    \   if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n    }\n\
    \    while(l<r){\n      if(l&1)all_apply(l++,f);\n      if(r&1)all_apply(--r,f);\n\
    \      l>>=1,r>>=1;\n    }\n  }\n};\n/**\n *@brief Dual Segment Tree(\u53CC\u5BFE\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n*/\n"
  code: "#pragma once\ntemplate<class S,class F,S (*mapping)(F,S),F (*composition)(F,F),F\
    \ (*id)()>\nstruct dual_segtree{\n  private:\n  int _n,size=1,idx=0;\n  vector<S>seq;\n\
    \  vector<F>lazy;\n  void all_apply(int k,F f){\n    if(k<size)lazy[k]=composition(f,lazy[k]);\n\
    \    else if(k<size+_n)seq[k-size]=mapping(f,seq[k-size]);\n  }\n  void eval(int\
    \ k){\n    all_apply(k<<1,lazy[k]);\n    all_apply(k<<1^1,lazy[k]);\n    lazy[k]=id();\n\
    \  }\n  public:\n  dual_segtree():dual_segtree(0){}\n  dual_segtree(int n,S e=S()):dual_segtree(vector<S>(n,e)){};\n\
    \  dual_segtree(const vector<S>&v):_n(v.size()){\n    while(size<_n)size<<=1,idx++;\n\
    \    seq=v;lazy=vector<F>(size,id());\n  }\n  void set(int p,S x){\n    p+=size;\n\
    \    for(int i=idx;i>=1;i--)eval(p>>i);\n    seq[p-size]=x;\n  }\n  S operator[](int\
    \ p){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n    return seq[p-size];\n\
    \  }\n  void apply(int p,F f){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n\
    \    seq[p-size]=mapping(f,seq[p-size]);\n  }\n  void apply(int l,int r,F f){\n\
    \    if(l==r)return;\n    l+=size;r+=size;\n    for(int i=idx;i>=1;i--){\n   \
    \   if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n    }\n\
    \    while(l<r){\n      if(l&1)all_apply(l++,f);\n      if(r&1)all_apply(--r,f);\n\
    \      l>>=1,r>>=1;\n    }\n  }\n};\n/**\n *@brief Dual Segment Tree(\u53CC\u5BFE\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/dual_segtree.hpp
  requiredBy:
  - Data_Structure/segtree_monoids.hpp
  timestamp: '2022-07-03 22:13:23+01:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL/DSL_2_G.test.cpp
  - test/aoj/DSL/DSL_2_B2.test.cpp
  - test/aoj/DSL/DSL_2_E.test.cpp
  - test/aoj/DSL/DSL_2_A.test.cpp
  - test/aoj/DSL/DSL_2_F.test.cpp
  - test/aoj/DSL/DSL_2_I.test.cpp
  - test/aoj/DSL/DSL_2_H.test.cpp
  - test/aoj/DSL/DSL_2_D.test.cpp
  - test/yosupo/point_add_range_sum1.test.cpp
documentation_of: Data_Structure/dual_segtree.hpp
layout: document
redirect_from:
- /library/Data_Structure/dual_segtree.hpp
- /library/Data_Structure/dual_segtree.hpp.html
title: "Dual Segment Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
