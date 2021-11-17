---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_Structure/segtree.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\ntemplate<class S,S (*op)(S,S),S (*e)()>\nstruct segtree{\n\
    \  private:\n  int _n,size,idx=0;\n  vector<S>seq;\n  void update(int k){seq[k]=op(seq[2*k],seq[2*k+1]);}\n\
    \  public:\n  segtree():segtree(0){};\n  segtree(int n):segtree(vector<S>(n,e())){}\n\
    \  segtree(const vector<S>&v):_n(int(v.size())){\n    while((1<<idx)<_n)idx++;\n\
    \    size=1<<idx;\n    seq=vector<S>(2*size,e());\n    for(int i=0;i<_n;i++)seq[size+i]=v[i];\n\
    \    for(int i=size-1;i>=1;i--)update(i);\n  }\n  void set(int p,S x){\n    p+=size;\n\
    \    seq[p]=x;\n    for(int i=1;i<=idx;i++)update(p>>i);\n  }\n  S operator[](int\
    \ p){return seq[p+size];}\n  S query(int l,int r)const{\n    S sml=e(),smr=e();\n\
    \    l+=size,r+=size;\n    while(l<r){\n      if(l&1)sml=op(sml,seq[l++]);\n \
    \     if(r&1)smr=op(seq[--r],smr);\n      l>>=1,r>>=1;\n    }\n    return op(sml,smr);\n\
    \  }\n  S all_query()const{\n    return seq[1];\n  }\n};\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\ntemplate<class S,S (*op)(S,S),S\
    \ (*e)()>\nstruct segtree{\n  private:\n  int _n,size,idx=0;\n  vector<S>seq;\n\
    \  void update(int k){seq[k]=op(seq[2*k],seq[2*k+1]);}\n  public:\n  segtree():segtree(0){};\n\
    \  segtree(int n):segtree(vector<S>(n,e())){}\n  segtree(const vector<S>&v):_n(int(v.size())){\n\
    \    while((1<<idx)<_n)idx++;\n    size=1<<idx;\n    seq=vector<S>(2*size,e());\n\
    \    for(int i=0;i<_n;i++)seq[size+i]=v[i];\n    for(int i=size-1;i>=1;i--)update(i);\n\
    \  }\n  void set(int p,S x){\n    p+=size;\n    seq[p]=x;\n    for(int i=1;i<=idx;i++)update(p>>i);\n\
    \  }\n  S operator[](int p){return seq[p+size];}\n  S query(int l,int r)const{\n\
    \    S sml=e(),smr=e();\n    l+=size,r+=size;\n    while(l<r){\n      if(l&1)sml=op(sml,seq[l++]);\n\
    \      if(r&1)smr=op(seq[--r],smr);\n      l>>=1,r>>=1;\n    }\n    return op(sml,smr);\n\
    \  }\n  S all_query()const{\n    return seq[1];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/segtree.cpp
  requiredBy: []
  timestamp: '2021-10-25 15:52:00+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/segtree.cpp
layout: document
redirect_from:
- /library/Data_Structure/segtree.cpp
- /library/Data_Structure/segtree.cpp.html
title: Data_Structure/segtree.cpp
---
