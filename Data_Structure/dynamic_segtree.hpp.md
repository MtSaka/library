---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_range_sum3.test.cpp
    title: test/yosupo/point_add_range_sum3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u6728)"
    links: []
  bundledCode: "#line 2 \"Data_Structure/dynamic_segtree.hpp\"\ntemplate<typename\
    \ S,S (*op)(S,S),S (*e)()>\nstruct dynamic_segtree{\n  public:\n  dynamic_segtree():dynamic_segtree(numeric_limits<long\
    \ long>::max()>>1){}\n  dynamic_segtree(long long n):n(n),root(nullptr){}\n  void\
    \ set(int p,const S&x){inner_set(root,0,n,p,x);}\n  S get(long long p)const{return\
    \ inner_get(root,0,n,p);}\n  S operator[](long long p)const{return inner_get(root,0,n,p);}\n\
    \  S query(long long l,long long r)const{return inner_query(root,0,n,l,r);}\n\
    \  S all_query()const{return root?root->val:e();}\n  void reset(long long l,long\
    \ long r){inner_reset(root,0,n,l,r);}\n  private:\n  struct node;\n  using ptr=unique_ptr<node>;\n\
    \  struct node{\n    S val;\n    ptr l,r;\n    node(const S&val):val(val),l(nullptr),r(nullptr){}\n\
    \  };\n  const long long n;\n  ptr root;\n  void inner_set(ptr&nd,long long l,long\
    \ long r,long long p,const S&x){\n    if(!nd)nd=make_unique<node>(e());\n    if(r-l==1){nd->val=x;return;}\n\
    \    long long m=(l+r)>>1;\n    if(p<m)inner_set(nd->l,l,m,p,x);\n    else inner_set(nd->r,m,r,p,x);\n\
    \    nd->val=op(nd->l?nd->l->val:e(),nd->r?nd->r->val:e());\n  }\n  S inner_get(const\
    \ ptr&nd,long long l,long long r,long long p)const{\n    if(!nd)return e();\n\
    \    if(r-l==1)return nd->val;\n    long long m=(l+r)>>1;\n    if(p<m)return inner_get(nd->l,l,m,p);\n\
    \    return inner_get(nd->r,m,r,p);\n  }\n  S inner_query(const ptr&nd,long long\
    \ nl,long long nr,long long l,long long r)const{\n    if(!nd||nr<=l||r<=nl)return\
    \ e();\n    if(l<=nl&&nr<=r)return nd->val;\n    long long m=(nl+nr)>>1;\n   \
    \ return op(inner_query(nd->l,nl,m,l,r),inner_query(nd->r,m,nr,l,r));\n  }\n \
    \ void inner_reset(ptr&nd,long long nl,long long nr,long long l,long long r){\n\
    \    if(!nd||nr<=l||r<=nl)return;\n    if(l<=nl&&nr<=r){\n      nd.reset();return;\n\
    \    }\n    long long m=(l+r)>>1;\n    inner_reset(nd->l,nl,m,l,r);\n    inner_reset(nd->r,m,nr,l,r);\n\
    \    nd->val=op(nd->l?nd->l->val:e(),nd->r?nd->r->val:e());\n  }\n};\n/**\n *\
    \ @brief Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u6728)\n */\n"
  code: "#pragma once\ntemplate<typename S,S (*op)(S,S),S (*e)()>\nstruct dynamic_segtree{\n\
    \  public:\n  dynamic_segtree():dynamic_segtree(numeric_limits<long long>::max()>>1){}\n\
    \  dynamic_segtree(long long n):n(n),root(nullptr){}\n  void set(int p,const S&x){inner_set(root,0,n,p,x);}\n\
    \  S get(long long p)const{return inner_get(root,0,n,p);}\n  S operator[](long\
    \ long p)const{return inner_get(root,0,n,p);}\n  S query(long long l,long long\
    \ r)const{return inner_query(root,0,n,l,r);}\n  S all_query()const{return root?root->val:e();}\n\
    \  void reset(long long l,long long r){inner_reset(root,0,n,l,r);}\n  private:\n\
    \  struct node;\n  using ptr=unique_ptr<node>;\n  struct node{\n    S val;\n \
    \   ptr l,r;\n    node(const S&val):val(val),l(nullptr),r(nullptr){}\n  };\n \
    \ const long long n;\n  ptr root;\n  void inner_set(ptr&nd,long long l,long long\
    \ r,long long p,const S&x){\n    if(!nd)nd=make_unique<node>(e());\n    if(r-l==1){nd->val=x;return;}\n\
    \    long long m=(l+r)>>1;\n    if(p<m)inner_set(nd->l,l,m,p,x);\n    else inner_set(nd->r,m,r,p,x);\n\
    \    nd->val=op(nd->l?nd->l->val:e(),nd->r?nd->r->val:e());\n  }\n  S inner_get(const\
    \ ptr&nd,long long l,long long r,long long p)const{\n    if(!nd)return e();\n\
    \    if(r-l==1)return nd->val;\n    long long m=(l+r)>>1;\n    if(p<m)return inner_get(nd->l,l,m,p);\n\
    \    return inner_get(nd->r,m,r,p);\n  }\n  S inner_query(const ptr&nd,long long\
    \ nl,long long nr,long long l,long long r)const{\n    if(!nd||nr<=l||r<=nl)return\
    \ e();\n    if(l<=nl&&nr<=r)return nd->val;\n    long long m=(nl+nr)>>1;\n   \
    \ return op(inner_query(nd->l,nl,m,l,r),inner_query(nd->r,m,nr,l,r));\n  }\n \
    \ void inner_reset(ptr&nd,long long nl,long long nr,long long l,long long r){\n\
    \    if(!nd||nr<=l||r<=nl)return;\n    if(l<=nl&&nr<=r){\n      nd.reset();return;\n\
    \    }\n    long long m=(l+r)>>1;\n    inner_reset(nd->l,nl,m,l,r);\n    inner_reset(nd->r,m,nr,l,r);\n\
    \    nd->val=op(nd->l?nd->l->val:e(),nd->r?nd->r->val:e());\n  }\n};\n/**\n *\
    \ @brief Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u6728)\n */"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/dynamic_segtree.hpp
  requiredBy: []
  timestamp: '2022-07-29 00:43:22+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/point_add_range_sum3.test.cpp
documentation_of: Data_Structure/dynamic_segtree.hpp
layout: document
redirect_from:
- /library/Data_Structure/dynamic_segtree.hpp
- /library/Data_Structure/dynamic_segtree.hpp.html
title: "Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u6728)"
---
