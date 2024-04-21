---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Dual Segment Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      )"
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
    \n\ntemplate<typename A,bool =Monoid::is_semigroup<A>::value>\nstruct DualSegmentTree{\n\
    \  static_assert(Monoid::is_semigroup<typename A::M>::value,\"A::M must be semigroup\"\
    );\n  static_assert(Monoid::is_semigroup<typename A::E>::value,\"A::E must be\
    \ action\");\n  static_assert(Monoid::has_op<A>::value||Monoid::has_mul_op<A>::value,\"\
    A must have op\");\n  private:\n  using M=typename A::M;\n  using E=typename A::E;\n\
    \  using T=typename M::value_type;\n  using U=typename E::value_type;\n  int lg,n,size;\n\
    \  vector<T>data;\n  vector<U>lazy;\n  vector<bool>lazy_flag;\n  template<bool\
    \ dummy=true,typename enable_if<!Monoid::has_mul_op<A>::value&&dummy>::type* =\
    \ nullptr>\n  inline static T Aop(const U&a,const T&b,int){\n    return A::op(a,b);\n\
    \  }\n  template<bool dummy=true,typename enable_if<Monoid::has_mul_op<A>::value&&dummy>::type*\
    \ = nullptr>\n  inline static T Aop(const U&a,const T&b,int sz){\n    return A::mul_op(a,sz,b);\n\
    \  }\n  void all_apply(int k,U x){\n    if(k<size){\n      if(lazy_flag[k])lazy[k]=E::op(lazy[k],x);\n\
    \      else lazy[k]=x,lazy_flag[k]=true;\n    }\n    else if(k<n+size){\n    \
    \  data[k-size]=Aop(x,data[k-size],1);\n    }\n  }\n  void eval(int k){\n    if(lazy_flag[k]){\n\
    \      all_apply(k<<1,lazy[k]);\n      all_apply(k<<1^1,lazy[k]);\n      lazy_flag[k]=false;\n\
    \    }\n  }\n  public:\n  DualSegmentTree():DualSegmentTree(0){}\n  DualSegmentTree(int\
    \ n,const T&e=T{}):DualSegmentTree(vector<T>(n,e)){};\n  DualSegmentTree(const\
    \ vector<T>&v){init(v);}\n  void init(const vector<T>&v){\n    n=v.size();\n \
    \   lg=ceil_log2(n);\n    size=1<<lg;\n    data=v;\n    lazy.resize(size);\n \
    \   lazy_flag.assign(size,false);\n  }\n  T operator[](int k){\n    k+=size;\n\
    \    rrep(i,1,lg+1)eval(k>>i);\n    return data[k-size];\n  }\n  template<typename\
    \ Upd>\n  void update(int k,const Upd&upd){\n    k+=size;\n    rrep(i,1,lg+1)eval(k>>i);\n\
    \    data[k-size]=upd(data[k-size]);\n  }\n  void set(int k,const T&x){\n    update(k,[&](T)->T\
    \ {return x;});\n  }\n  void apply(int k,const U&x){\n    update(k,[&](const T&y)->T\
    \ {return Aop(x,y,1);});\n  }\n  void apply(int l,int r,const U&x){\n    l+=size,r+=size;\n\
    \    rrep(i,1,lg+1){\n      bool f=false;\n      if(((l>>i)<<i)!=l)eval(l>>i),f=true;\n\
    \      if(((r>>i)<<i)!=r)eval((r-1)>>i),f=true;\n      if(!f)break;\n    }\n \
    \   while(l!=r){\n      if(l&1)all_apply(l++,x);\n      if(r&1)all_apply(--r,x);\n\
    \      l>>=1,r>>=1;\n    }\n  }\n};\ntemplate<typename E>\nstruct DualSegmentTree<E,true>:DualSegmentTree<Monoid::AttachMonoid<E>>{\n\
    \  private:\n  using Base=DualSegmentTree<Monoid::AttachMonoid<E>>;\n  public:\n\
    \  using Base::Base;\n};\ntemplate<typename T>using RangeUpdateQuery=DualSegmentTree<Monoid::Assign<T>>;\n\
    template<typename T>using RangeAddQuery=DualSegmentTree<Monoid::Sum<T>>;\ntemplate<typename\
    \ T,T max_value=infinity<T>::max>using RangeChminQuery=DualSegmentTree<Monoid::Min<T,max_value>>;\n\
    template<typename T,T min_value=infinity<T>::min>using RangeChmaxQuery=DualSegmentTree<Monoid::Max<T,min_value>>;\n\
    /**\n *@brief Dual Segment Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    )\n*/"
  dependsOn: []
  isVerificationFile: false
  path: ds/segment/dual-segment-tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segment/dual-segment-tree.hpp
layout: document
redirect_from:
- /library/ds/segment/dual-segment-tree.hpp
- /library/ds/segment/dual-segment-tree.hpp.html
title: "Dual Segment Tree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
