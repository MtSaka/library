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
  bundledCode: "#line 1 \"Data_Structure/lazy-segtree.cpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\ntemplate<class S,S (*op)(S,S),S (*e)(),class F,S (*mapping)(F,S),F\
    \ (*composition)(F,F),F (*id)()>\nstruct lazy_segtree{\n  private:\n  int _n,size,idx=0;\n\
    \  vector<S>seq;\n  vector<F>lazy;\n  void update(int k){seq[k]=op(seq[2*k],seq[2*k+1]);}\n\
    \  void all_apply(int k,F f){\n    seq[k]=mapping(f,seq[k]);\n    if(k<size)lazy[k]=composition(f,lazy[k]);\n\
    \  }\n  void eval(int k){\n    all_apply(2*k,lazy[k]);\n    all_apply(2*k+1,lazy[k]);\n\
    \    lazy[k]=id();\n  }\n  public:\n  lazy_segtree():lazy_segtree(0){}\n  lazy_segtree(int\
    \ n):lazy_segtree(vector<S>(n,e())){}\n  lazy_segtree(const vector<S>&v):_n(int(v.size())){\n\
    \    while(1<<idx<_n)idx++;\n    size=1<<idx;\n    seq=vector<S>(2*size,e());\n\
    \    lazy=vector<F>(2*size,id());\n    for(int i=0;i<_n;i++)seq[size+i]=v[i];\n\
    \    for(int i=size-1;i>=1;i--)update(i);\n  }\n  void set(int p,S x){\n    p+=size;\n\
    \    for(int i=idx;i>=1;i--)eval(p>>i);\n    seq[p]=x;\n    for(int i=1;i<=idx;i++)update(p>>i);\n\
    \  }\n  S operator[](int p){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n\
    \    return seq[p];\n  }\n  S query(int l,int r){\n    if(l==r)return e();\n \
    \   S sml=e(),smr=e();\n    l+=size,r+=size;\n    for(int i=idx;i>=1;i--){\n \
    \     if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n   \
    \ }\n    while(l<r){\n      if(l&1)sml=op(sml,seq[l++]);\n      if(r&1)smr=op(seq[--r],smr);\n\
    \      l>>=1,r>>=1;\n    }\n    return op(sml,smr);\n  }\n  S all_query()const{return\
    \ seq[1];}\n  void apply(int p,F f){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n\
    \    seq[p]=mapping(f,seq[p]);\n    for(int i=1;i<=idx;i++)update(p>>i);\n  }\n\
    \  void apply(int l,int r,F f){\n    if(l==r)return ;\n    l+=size;\n    r+=size;\n\
    \    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval((r-1)>>i);\n\
    \    }\n    int l2=l,r2=r;\n    while(l<r){\n      if(l&1)all_apply(l++,f);\n\
    \      if(r&1)all_apply(--r,f);\n      l>>=1;\n      r>>=1;\n    }\n    l=l2,r=r2;\n\
    \    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n      if(((r>>i)<<i)!=r)update((r-1)>>i);\n\
    \    }\n  }\n};\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\ntemplate<class S,S (*op)(S,S),S\
    \ (*e)(),class F,S (*mapping)(F,S),F (*composition)(F,F),F (*id)()>\nstruct lazy_segtree{\n\
    \  private:\n  int _n,size,idx=0;\n  vector<S>seq;\n  vector<F>lazy;\n  void update(int\
    \ k){seq[k]=op(seq[2*k],seq[2*k+1]);}\n  void all_apply(int k,F f){\n    seq[k]=mapping(f,seq[k]);\n\
    \    if(k<size)lazy[k]=composition(f,lazy[k]);\n  }\n  void eval(int k){\n   \
    \ all_apply(2*k,lazy[k]);\n    all_apply(2*k+1,lazy[k]);\n    lazy[k]=id();\n\
    \  }\n  public:\n  lazy_segtree():lazy_segtree(0){}\n  lazy_segtree(int n):lazy_segtree(vector<S>(n,e())){}\n\
    \  lazy_segtree(const vector<S>&v):_n(int(v.size())){\n    while(1<<idx<_n)idx++;\n\
    \    size=1<<idx;\n    seq=vector<S>(2*size,e());\n    lazy=vector<F>(2*size,id());\n\
    \    for(int i=0;i<_n;i++)seq[size+i]=v[i];\n    for(int i=size-1;i>=1;i--)update(i);\n\
    \  }\n  void set(int p,S x){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n\
    \    seq[p]=x;\n    for(int i=1;i<=idx;i++)update(p>>i);\n  }\n  S operator[](int\
    \ p){\n    p+=size;\n    for(int i=idx;i>=1;i--)eval(p>>i);\n    return seq[p];\n\
    \  }\n  S query(int l,int r){\n    if(l==r)return e();\n    S sml=e(),smr=e();\n\
    \    l+=size,r+=size;\n    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n\
    \      if(((r>>i)<<i)!=r)eval(r>>i);\n    }\n    while(l<r){\n      if(l&1)sml=op(sml,seq[l++]);\n\
    \      if(r&1)smr=op(seq[--r],smr);\n      l>>=1,r>>=1;\n    }\n    return op(sml,smr);\n\
    \  }\n  S all_query()const{return seq[1];}\n  void apply(int p,F f){\n    p+=size;\n\
    \    for(int i=idx;i>=1;i--)eval(p>>i);\n    seq[p]=mapping(f,seq[p]);\n    for(int\
    \ i=1;i<=idx;i++)update(p>>i);\n  }\n  void apply(int l,int r,F f){\n    if(l==r)return\
    \ ;\n    l+=size;\n    r+=size;\n    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n\
    \      if(((r>>i)<<i)!=r)eval((r-1)>>i);\n    }\n    int l2=l,r2=r;\n    while(l<r){\n\
    \      if(l&1)all_apply(l++,f);\n      if(r&1)all_apply(--r,f);\n      l>>=1;\n\
    \      r>>=1;\n    }\n    l=l2,r=r2;\n    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n\
    \      if(((r>>i)<<i)!=r)update((r-1)>>i);\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/lazy-segtree.cpp
  requiredBy: []
  timestamp: '2021-10-18 18:04:46+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/lazy-segtree.cpp
layout: document
redirect_from:
- /library/Data_Structure/lazy-segtree.cpp
- /library/Data_Structure/lazy-segtree.cpp.html
title: Data_Structure/lazy-segtree.cpp
---
