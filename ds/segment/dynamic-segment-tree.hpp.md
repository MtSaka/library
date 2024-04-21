---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u6728)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../template/template.hpp\"\n\ntemplate<typename S,S\
    \ (*op)(S,S),S (*e)()>\nstruct DynamicSegmentTree{\n  public:\n  DynamicSegmentTree():DynamicSegmentTree(numeric_limits<long\
    \ long>::max()>>1){}\n  DynamicSegmentTree(long long n):n(n),root(nullptr){}\n\
    \  void set(int p,const S&x){inner_set(root,0,n,p,x);}\n  S get(long long p)const{return\
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
    \ @brief Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u6728)\n */"
  dependsOn: []
  isVerificationFile: false
  path: ds/segment/dynamic-segment-tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segment/dynamic-segment-tree.hpp
layout: document
redirect_from:
- /library/ds/segment/dynamic-segment-tree.hpp
- /library/ds/segment/dynamic-segment-tree.hpp.html
title: "Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u6728)"
---
