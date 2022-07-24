---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/segtree_monoids.hpp
    title: "Monoids(\u30E2\u30CE\u30A4\u30C9)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_2_A.test.cpp
    title: test/aoj/DSL/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_2_B2.test.cpp
    title: test/aoj/DSL/DSL_2_B2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_2_D.test.cpp
    title: test/aoj/DSL/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_2_E.test.cpp
    title: test/aoj/DSL/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_2_F.test.cpp
    title: test/aoj/DSL/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_2_G.test.cpp
    title: test/aoj/DSL/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_2_H.test.cpp
    title: test/aoj/DSL/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_2_I.test.cpp
    title: test/aoj/DSL/DSL_2_I.test.cpp
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
    _deprecated_at_docs: docs/segtree.md
    document_title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
    links: []
  bundledCode: "#line 2 \"Data_Structure/segtree.hpp\"\ntemplate<class S,S (*op)(S,S),S\
    \ (*e)()>\nstruct segtree{\n  private:\n  int _n,size=1,idx=0;\n  vector<S>seq;\n\
    \  void update(int k){seq[k]=op(seq[k<<1],seq[k<<1^1]);}\n  public:\n  segtree():segtree(0){};\n\
    \  segtree(int n):segtree(vector<S>(n,e())){}\n  segtree(const vector<S>&v):_n(int(v.size())){\n\
    \    while(size<_n)size<<=1,idx++;\n    seq=vector<S>(size<<1,e());\n    for(int\
    \ i=0;i<_n;i++)seq[size+i]=v[i];\n    for(int i=size-1;i>=1;i--)update(i);\n \
    \ }\n  void set(int p,S x){\n    p+=size;\n    seq[p]=x;\n    for(int i=1;i<=idx;i++)update(p>>i);\n\
    \  }\n  S operator[](int p)const{return seq[p+size];}\n  S query(int l,int r)const{\n\
    \    S sml=e(),smr=e();\n    l+=size,r+=size;\n    while(l<r){\n      if(l&1)sml=op(sml,seq[l++]);\n\
    \      if(r&1)smr=op(seq[--r],smr);\n      l>>=1,r>>=1;\n    }\n    return op(sml,smr);\n\
    \  }\n  S all_query()const{return seq[1];}\n  template<typename F>\n  int find_right(int\
    \ l,const F&f)const{\n    if(l==_n)return _n;\n    l+=size;\n    S sum=e();\n\
    \    do{\n      while(!(l&1))l>>=1;\n      if(!f(op(sum,seq[l]))){\n        while(l<size){\n\
    \          l<<=1;\n          if(f(op(sum,seq[l])))sum=op(sum,seq[l++]);\n    \
    \    }\n        return l-size;\n      }\n      sum=op(sum,seq[l++]);\n    }while((l&-l)!=l);\n\
    \    return _n;\n  }\n  template<typename F>\n  int find_left(int r,const F&f)const{\n\
    \    if(!r)return 0;\n    r+=size;\n    S sum=e();\n    do{\n      r--;\n    \
    \  while(r>1&&(r&1))r>>=1;\n      if(!f(op(seq[r],sum))){\n        while(r<size){\n\
    \          (r<<=1)++;\n          if(f(op(seq[r],sum)))sum=op(seq[r--],sum);\n\
    \        }\n        return r+1-size;\n      }\n      sum=op(seq[r],sum);\n   \
    \ }while((r&-r)!=r);\n    return 0;\n  }\n};\n/**\n * @brief Segment Tree(\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728)\n * @docs docs/segtree.md\n*/\n"
  code: "#pragma once\ntemplate<class S,S (*op)(S,S),S (*e)()>\nstruct segtree{\n\
    \  private:\n  int _n,size=1,idx=0;\n  vector<S>seq;\n  void update(int k){seq[k]=op(seq[k<<1],seq[k<<1^1]);}\n\
    \  public:\n  segtree():segtree(0){};\n  segtree(int n):segtree(vector<S>(n,e())){}\n\
    \  segtree(const vector<S>&v):_n(int(v.size())){\n    while(size<_n)size<<=1,idx++;\n\
    \    seq=vector<S>(size<<1,e());\n    for(int i=0;i<_n;i++)seq[size+i]=v[i];\n\
    \    for(int i=size-1;i>=1;i--)update(i);\n  }\n  void set(int p,S x){\n    p+=size;\n\
    \    seq[p]=x;\n    for(int i=1;i<=idx;i++)update(p>>i);\n  }\n  S operator[](int\
    \ p)const{return seq[p+size];}\n  S query(int l,int r)const{\n    S sml=e(),smr=e();\n\
    \    l+=size,r+=size;\n    while(l<r){\n      if(l&1)sml=op(sml,seq[l++]);\n \
    \     if(r&1)smr=op(seq[--r],smr);\n      l>>=1,r>>=1;\n    }\n    return op(sml,smr);\n\
    \  }\n  S all_query()const{return seq[1];}\n  template<typename F>\n  int find_right(int\
    \ l,const F&f)const{\n    if(l==_n)return _n;\n    l+=size;\n    S sum=e();\n\
    \    do{\n      while(!(l&1))l>>=1;\n      if(!f(op(sum,seq[l]))){\n        while(l<size){\n\
    \          l<<=1;\n          if(f(op(sum,seq[l])))sum=op(sum,seq[l++]);\n    \
    \    }\n        return l-size;\n      }\n      sum=op(sum,seq[l++]);\n    }while((l&-l)!=l);\n\
    \    return _n;\n  }\n  template<typename F>\n  int find_left(int r,const F&f)const{\n\
    \    if(!r)return 0;\n    r+=size;\n    S sum=e();\n    do{\n      r--;\n    \
    \  while(r>1&&(r&1))r>>=1;\n      if(!f(op(seq[r],sum))){\n        while(r<size){\n\
    \          (r<<=1)++;\n          if(f(op(seq[r],sum)))sum=op(seq[r--],sum);\n\
    \        }\n        return r+1-size;\n      }\n      sum=op(seq[r],sum);\n   \
    \ }while((r&-r)!=r);\n    return 0;\n  }\n};\n/**\n * @brief Segment Tree(\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728)\n * @docs docs/segtree.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/segtree.hpp
  requiredBy:
  - Data_Structure/segtree_monoids.hpp
  timestamp: '2022-07-03 22:49:08+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL/DSL_2_A.test.cpp
  - test/aoj/DSL/DSL_2_H.test.cpp
  - test/aoj/DSL/DSL_2_D.test.cpp
  - test/aoj/DSL/DSL_2_B2.test.cpp
  - test/aoj/DSL/DSL_2_F.test.cpp
  - test/aoj/DSL/DSL_2_G.test.cpp
  - test/aoj/DSL/DSL_2_I.test.cpp
  - test/aoj/DSL/DSL_2_E.test.cpp
  - test/yosupo/point_add_range_sum1.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
documentation_of: Data_Structure/segtree.hpp
layout: document
redirect_from:
- /library/Data_Structure/segtree.hpp
- /library/Data_Structure/segtree.hpp.html
title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
## 概要
完全二分木の実装です。モノイドについての区間に対する演算が$O(\log N)$で処理できます。
実装では木を1-indexedで表現しています。

## 使い方
* `segtree<S,op,e>seg(N)`:サイズ`N`で初期化する、ここで`S`は型、`op`は二項演算、`e`はモノイドの単位元である。また、opとeはそれぞれ関数である。計算量は$O(N)$  
* `segtree<S,op,e>seg(V)`:配列`V`で初期化する。`S`,`op`,`e`は上と同じく。`N=V.size()`として、計算量は$O(N)$  
* `set(p,x)`:`p`番目の要素を`x`に変更する。この時、0-indexedで表現している。計算量は$O(\log N)$
* `operator[p]`:`p`番目の要素を返す。(0-indexed)計算量は$O(1)$  
* `query(l,r)`:区間$[l,r)$に対しての演算の結果を返す。`l`,`r`は0-indexedで表現している。計算量は$O(\log N)$  
* `all_query()`:全体に対しての演算の結果を返す。計算量は$O(1)$  
* `find_right(l,F)`:区間$[l,x)$に対して$F(x)$が$false$を返す、最小の$x$を返す。存在しないときは$N$を返す。計算量は$O(\log N)$
* `find_left(r,F)`:区間$[x,r)$に対して$F(x)$が$false$を返す、最大の$x$を返す。存在しないときは$-1$を返す。計算量は$O(\log N)$