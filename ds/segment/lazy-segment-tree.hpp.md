---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Lazy Segment Tree(\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
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
    \n\ntemplate<typename A>\nstruct LazySegmentTree{\n  static_assert(Monoid::is_action<A>::value,\"\
    A must be action\");\n  private:\n  using M=typename A::M;\n  using E=typename\
    \ A::E;\n  using T=typename M::value_type;\n  using U=typename E::value_type;\n\
    \  int lg,n,size;\n  vector<T>data;\n  vector<U>lazy;\n  vector<bool>lazy_flag;\n\
    \  template<bool dummy=true,typename enable_if<!Monoid::has_mul_op<A>::value&&dummy>::type*\
    \ = nullptr>\n  inline static T Aop(const U&a,const T&b,int){\n    return A::op(a,b);\n\
    \  }\n  template<bool dummy=true,typename enable_if<Monoid::has_mul_op<A>::value&&dummy>::type*\
    \ = nullptr>\n  inline static T Aop(const U&a,const T&b,int sz){\n    return A::mul_op(a,sz,b);\n\
    \  }\n  void update(int k){data[k]=M::op(data[k<<1],data[k<<1^1]);}\n  void all_apply(int\
    \ k,const U&x,int sz){\n    data[k]=Aop(x,data[k],sz);\n    if(k<size){\n    \
    \  if(lazy_flag[k])lazy[k]=E::op(lazy[k],x);\n      else lazy[k]=x,lazy_flag[k]=true;\n\
    \    }\n  }\n  void eval(int k,int sz){\n    if(lazy_flag[k]){\n      all_apply(k<<1,lazy[k],sz>>1);\n\
    \      all_apply(k<<1^1,lazy[k],sz>>1);\n      lazy_flag[k]=false;\n    }\n  }\n\
    \  public:\n  LazySegmentTree():LazySegmentTree(0){}\n  LazySegmentTree(int n,const\
    \ T&e=M::id()):LazySegmentTree(vector<T>(n,e)){}\n  LazySegmentTree(const vector<T>&v){init(v);}\n\
    \  void init(const vector<T>&v){\n    n=v.size();\n    lg=ceil_log2(n);\n    size=1<<lg;\n\
    \    data.assign(size<<1,M::id());\n    lazy.resize(size);\n    lazy_flag.assign(size,false);\n\
    \    rep(i,n)data[size+i]=v[i];\n    rrep(i,1,size)update(i);\n  }\n  T prod(int\
    \ l,int r){\n    if(l==r)return M::id();\n    l+=size,r+=size;\n    rrep(i,1,lg+1){\n\
    \      bool f=false;\n      if(((l>>i)<<i)!=l)eval(l>>i,1<<i),f=true;\n      if(((r>>i)<<i)!=r)eval((r-1)>>i,1<<i),f=true;\n\
    \      if(!f)break;\n    }\n    T sml=M::id(),smr=M::id();\n    while(l!=r){\n\
    \      if(l&1)sml=M::op(sml,data[l++]);\n      if(r&1)smr=M::op(data[--r],smr);\n\
    \      l>>=1,r>>=1;\n    }\n    return M::op(sml,smr);\n  }\n  T operator[](int\
    \ k){\n    k+=size;\n    rrep(i,1,lg+1)eval(k>>i,1<<i);\n    return data[k];\n\
    \  }\n  T all_prod()const{return data[1];}\n  template<typename Upd>\n  void update(int\
    \ k,const Upd&upd){\n    k+=size;\n    rrep(i,1,lg+1)eval(k>>i,1<<i);\n    data[k]=upd(data[k]);\n\
    \    rep(i,1,lg+1)update(k>>i);\n  }\n  void set(int k,const T&x){\n    update(k,[&](const\
    \ T&y)->T {return x;});\n  }\n  void apply(int k,const U&x){\n    update(k,[&](const\
    \ T&y)->T {return Aop(x,y,1);});\n  }\n  void apply(int l,int r,const U&x){\n\
    \    if(l==r)return;\n    l+=size,r+=size;\n    int lst=lg+1;\n    rrep(i,1,lg+1){\n\
    \      if(((l>>i)<<i)!=l)eval(l>>i,1<<i),lst=i;\n      if(((r>>i)<<i)!=r)eval((r-1)>>i,1<<i),lst=i;\n\
    \      if(lst!=i)break;\n    }\n    for(int l2=l,r2=r,sz=1;l2!=r2;l2>>=1,r2>>=1,sz<<=1){\n\
    \      if(l2&1)all_apply(l2++,x,sz);\n      if(r2&1)all_apply(--r2,x,sz);\n  \
    \  }\n    rep(i,lst,lg+1){\n      if(((l>>i)<<i)!=l)update(l>>i);\n      if(((r>>i)<<i)!=r)update((r-1)>>i);\n\
    \    }\n  }\n};\ntemplate<typename T,T max_value=infinity<T>::max>\nusing RangeUpdateQueryRangeMinimumQuery=LazySegmentTree<Monoid::AssignMin<T,max_value>>;\n\
    template<typename T,T min_value=infinity<T>::min>\nusing RangeUpdateQueryRangeMaximumQuery=LazySegmentTree<Monoid::AssignMax<T,min_value>>;\n\
    template<typename T>\nusing RangeUpdateQueryRangeSumQuery=LazySegmentTree<Monoid::AssignSum<T>>;\n\
    template<typename T,T max_value=infinity<T>::max>\nusing RangeAddQueryRangeMinimumQuery=LazySegmentTree<Monoid::AddMin<T,max_value>>;\n\
    template<typename T,T min_value=infinity<T>::min>\nusing RangeAddQueryRangeMaximumQuery=LazySegmentTree<Monoid::AddMax<T,min_value>>;\n\
    template<typename T>\nusing RangeAddQueryRangeSumQuery=LazySegmentTree<Monoid::AddSum<T>>;\n\
    template<typename T,T max_value=infinity<T>::max>\nusing RangeChminQueryRangeMinimumQuery=LazySegmentTree<Monoid::ChminMin<T,max_value>>;\n\
    template<typename T,T min_value=infinity<T>::min>\nusing RangeChminQueryRangeMaximumQuery=LazySegmentTree<Monoid::ChminMax<T,min_value>>;\n\
    template<typename T,T max_value=infinity<T>::max>\nusing RangeChmaxQueryRangeMinimumQuery=LazySegmentTree<Monoid::ChmaxMin<T,max_value>>;\n\
    template<typename T,T min_value=infinity<T>::min>\nusing RangeChmaxQueryRangeMaximumQuery=LazySegmentTree<Monoid::ChmaxMax<T,min_value>>;\n\
    /**\n * @brief Lazy Segment Tree(\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    )\n*/"
  dependsOn: []
  isVerificationFile: false
  path: ds/segment/lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segment/lazy-segment-tree.hpp
layout: document
redirect_from:
- /library/ds/segment/lazy-segment-tree.hpp
- /library/ds/segment/lazy-segment-tree.hpp.html
title: "Lazy Segment Tree(\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
