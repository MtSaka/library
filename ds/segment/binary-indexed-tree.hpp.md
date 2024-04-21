---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Binary Indexed Tree(Fenwick Tree, BIT)
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
  code: "#pragma once\n#include\"../template/template.hpp\"\n#include\"../others/monoid.hpp\"\
    \n\ntemplate<typename M,bool=Monoid::is_monoid<M>::value>\nstruct BinaryIndexedTree{\n\
    \  private:\n  using T=typename M::value_type;\n  int n;\n  vector<T>data;\n \
    \ public:\n  BinaryIndexedTree():BinaryIndexedTree(0){}\n  BinaryIndexedTree(int\
    \ n_){init(n_);}\n  void init(int n_){\n    n=n_;\n    data.assign(n+1,M::id());\n\
    \  }\n  void apply(int k,T x){\n    k++;\n    while(k<=n){\n      data[k]=M::op(data[k],x);\n\
    \      k+=k&-k;\n    }\n  }\n  T prod(int k)const{\n    T res=M::id();\n    while(k){\n\
    \      res=M::op(res,data[k]);\n      k-=k&-k;\n    }\n    return res;\n  }\n\
    \  template<bool dummy=true,typename enable_if<Monoid::has_inv<M>::value&&dummy>::type*\
    \ = nullptr>\n  T prod(int l,int r)const{\n    return M::inv(prod(r),prod(l));\n\
    \  }\n  T operator[](int k)const{return prod(k,k+1);}\n  void set(int k,T x){apply(k,M::inv(x,(*this)[k]));}\n\
    };\ntemplate<typename T>\nstruct BinaryIndexedTree<T,false>:BinaryIndexedTree<Monoid::Sum<T>>{\n\
    \  private:\n  using Base=BinaryIndexedTree<Monoid::Sum<T>>;\n  public:\n  using\
    \ Base::Base;\n  void add(int k,T x){this->apply(k,x);}\n  T sum(int k)const{return\
    \ this->prod(k);}\n  T sum(int l,int r)const{return this->prod(l,r);}\n};\n/**\n\
    \ * @brief Binary Indexed Tree(Fenwick Tree, BIT)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: ds/segment/binary-indexed-tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segment/binary-indexed-tree.hpp
layout: document
redirect_from:
- /library/ds/segment/binary-indexed-tree.hpp
- /library/ds/segment/binary-indexed-tree.hpp.html
title: Binary Indexed Tree(Fenwick Tree, BIT)
---
