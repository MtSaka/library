---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../template/template.hpp\"\n#include\"../others/monoid.hpp\"\
    \n\ntemplate<typename M>\nstruct SegmentTree{\n  private:\n  using T=typename\
    \ M::value_type;\n  int n,size;\n  vector<T>data;\n  void update(int k){data[k]=M::op(data[k<<1],data[k<<1^1]);}\n\
    \  public:\n  SegmentTree():SegmentTree(0){}\n  SegmentTree(int n,const T&e=M::id()):SegmentTree(vector<T>(n,e)){}\n\
    \  SegmentTree(const vector<T>&v){init(v);}\n  void init(const vector<T>&v){\n\
    \    n=v.size();\n    size=1<<ceil_log2(n);\n    data.assign(size<<1,M::id());\n\
    \    rep(i,n)data[size+i]=v[i];\n    rrep(i,1,size)update(i);\n  }\n  template<class\
    \ Upd>\n  void update(int k,const Upd&upd){\n    k+=size;\n    data[k]=upd(data[k]);\n\
    \    while(k>>=1)update(k);\n  }\n  void set(int k,const T&x){\n    update(k,[&](T)->T\
    \ {return x;});\n  }\n  void apply(int k,const T&x){\n    update(k,[&](T y)->T\
    \ {return M::op(y,x);});\n  }\n  T operator[](int k)const{return data[size+k];}\n\
    \  T prod(int l,int r)const{\n    l+=size,r+=size;\n    T sml=M::id(),smr=M::id();\n\
    \    while(l!=r){\n      if(l&1)sml=M::op(sml,data[l++]);\n      if(r&1)smr=M::op(data[--r],smr);\n\
    \      l>>=1,r>>=1;\n    }\n    return M::op(sml,smr);\n  }\n  T all_prod()const{return\
    \ data[1];}\n  template<class F>\n  int max_right(int l,const F&f)const{\n   \
    \ if(l==n)return n;\n    l+=size;\n    T sum=M::id();\n    do{\n      while((l&1)==0)l>>=1;\n\
    \      if(!f(M::op(sum,data[l]))){\n        while(l<size){\n          l<<=1;\n\
    \          if(f(M::op(sum,data[l])))sum=M::op(sum,data[l++]);\n        }\n   \
    \     return l-size;\n      }\n      sum=M::op(sum,data[l++]);\n    }while((l&-l)!=l);\n\
    \    return n;\n  }\n  template<class F>\n  int min_left(int r,const F&f)const{\n\
    \    if(r==0)return 0;\n    r+=size;\n    T sum=M::id();\n    do{\n      --r;\n\
    \      while((r&1)&&r>1)r>>=1;\n      if(!f(M::op(data[r],sum))){\n        while(r<size){\n\
    \          r=(r<<1)^1;\n          if(f(M::op(data[r],sum)))sum=M::op(data[r--],sum);\n\
    \        }\n        return r+1-size;\n      }\n      sum=M::op(data[r],sum);\n\
    \    }while((r&-r)!=r);\n    return 0;\n  }\n};\ntemplate<typename T,T max_value=infinity<T>::max>\n\
    using RangeMinimumQuery=SegmentTree<Monoid::Min<T,max_value>>;\ntemplate<typename\
    \ T,T min_value=infinity<T>::min>\nusing RangeMaximumQuery=SegmentTree<Monoid::Max<T,min_value>>;\n\
    template<typename T>\nusing RangeSumQuery=SegmentTree<Monoid::Sum<T>>;\n/**\n\
    \ * @brief Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: ds/segment/segment-tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segment/segment-tree.hpp
layout: document
redirect_from:
- /library/ds/segment/segment-tree.hpp
- /library/ds/segment/segment-tree.hpp.html
title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
