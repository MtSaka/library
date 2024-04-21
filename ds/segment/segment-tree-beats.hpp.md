---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Segment Tree Beats!(Rnage Chmin Chmax Add Update Range Sum Min
      Max)
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
  code: "#pragma once\n#include\"../template/template.hpp\"\n\ntemplate<class T>\n\
    struct SegmentTreeBeats{\n  private:\n  static constexpr T INF=numeric_limits<T>::max();\n\
    \  struct S{\n    T sum=0,b1=0,s1=0,b2=-INF,s2=INF,b_cnt=1,s_cnt=1,add=0;\n  \
    \  S(){}\n    S(const T&a):sum(a),b1(a),s1(a){}\n  };\n  vector<S>seq;\n  int\
    \ size=1,idx=0;\n  void update(int k){\n    S&s=seq[k];\n    S&l=seq[2*k];\n \
    \   S&r=seq[2*k+1];\n    s.sum=l.sum+r.sum;\n    if(l.b1==r.b1){\n      s.b1=l.b1;\n\
    \      s.b2=max(l.b2,r.b2);\n      s.b_cnt=l.b_cnt+r.b_cnt;\n    }\n    else{\n\
    \      s.b1=max(l.b1,r.b1);\n      s.b2=max(l.b1>r.b1?l.b2:l.b1,l.b1>r.b1?r.b1:r.b2);\n\
    \      s.b_cnt=l.b1>r.b1?l.b_cnt:r.b_cnt;\n    }\n    if(l.s1==r.s1){\n      s.s1=l.s1;\n\
    \      s.s2=min(l.s2,r.s2);\n      s.s_cnt=l.s_cnt+r.s_cnt;\n    }\n    else{\n\
    \      s.s1=min(l.s1,r.s1);\n      s.s2=min(l.s1>r.s1?l.s1:l.s2,l.s1>r.s1?r.s2:r.s1);\n\
    \      s.s_cnt=l.s1>r.s1?r.s_cnt:l.s_cnt;\n    }\n  }\n  void eval_add(int k,T\
    \ x){\n    S&s=seq[k];\n    s.sum+=x<<(idx+__builtin_clz(k)-31);\n    s.b1+=x,s.s1+=x;\n\
    \    if(s.b2!=-INF)s.b2+=x;\n    if(s.s2!=INF)s.s2+=x;\n    s.add+=x;\n  }\n \
    \ void eval_min(int k,T x){\n    S&s=seq[k];\n    s.sum+=(x-s.b1)*s.b_cnt;\n \
    \   if(s.s1==s.b1)s.s1=x;\n    if(s.s2==s.b1)s.s2=x;\n    s.b1=x;\n  }\n  void\
    \ eval_max(int k,T x){\n    S&s=seq[k];\n    s.sum+=(x-s.s1)*s.s_cnt;\n    if(s.b1==s.s1)s.b1=x;\n\
    \    if(s.b2==s.s1)s.b2=x;\n    s.s1=x;\n  }\n  void eval(int k){\n    S&s=seq[k];\n\
    \    if(s.add!=0){\n      eval_add(k*2,s.add);\n      eval_add(k*2+1,s.add);\n\
    \      s.add=0;\n    }\n    if(s.b1<seq[2*k].b1)eval_min(2*k,s.b1);\n    if(s.s1>seq[2*k].s1)eval_max(2*k,s.s1);\n\
    \    if(s.b1<seq[2*k+1].b1)eval_min(2*k+1,s.b1);\n    if(s.s1>seq[2*k+1].s1)eval_max(2*k+1,s.s1);\n\
    \  }\n  void apply_min(int k,T x){\n    if(seq[k].b1<=x)return;\n    if(seq[k].b2<x){\n\
    \      eval_min(k,x);\n      return;\n    }\n    eval(k);\n    apply_min(2*k,x);\n\
    \    apply_min(2*k+1,x);\n    update(k);\n  }\n  void apply_max(int k,T x){\n\
    \    if(seq[k].s1>=x)return;\n    if(seq[k].s2>x){\n      eval_max(k,x);\n   \
    \   return;\n    }\n    eval(k);\n    apply_max(2*k,x);\n    apply_max(2*k+1,x);\n\
    \    update(k);\n  }\n  void inner_chmin(int l,int r,T x){\n    if(l==r)return;\n\
    \    l+=size,r+=size;\n    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n\
    \      if(((r>>i)<<i)!=r)eval(r>>i);\n    }\n    int l2=l,r2=r;\n    while(l<r){\n\
    \      if(l&1)apply_min(l++,x);\n      if(r&1)apply_min(--r,x);\n      l>>=1;\n\
    \      r>>=1;\n    }\n    l=l2,r=r2;\n    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n\
    \      if(((r>>i)<<i)!=r)update(r>>i);\n    }\n  }\n  void inner_chmax(int l,int\
    \ r,T x){\n    if(l==r)return;\n    l+=size,r+=size;\n    for(int i=idx;i>=1;i--){\n\
    \      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n  \
    \  }\n    int l2=l,r2=r;\n    while(l<r){\n      if(l&1)apply_max(l++,x);\n  \
    \    if(r&1)apply_max(--r,x);\n      l>>=1;\n      r>>=1;\n    }\n    l=l2,r=r2;\n\
    \    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n      if(((r>>i)<<i)!=r)update(r>>i);\n\
    \    }\n  }\n  void inner_add(int l,int r,T x){\n    if(l==r)return;\n    l+=size,r+=size;\n\
    \    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    int l2=l,r2=r;\n    while(l<r){\n      if(l&1)eval_add(l++,x);\n \
    \     if(r&1)eval_add(--r,x);\n      l>>=1;\n      r>>=1;\n    }\n    l=l2,r=r2;\n\
    \    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n      if(((r>>i)<<i)!=r)update(r>>i);\n\
    \    }\n  }\n  void inner_update(int l,int r,T x){\n    if(l==r)return;\n    l+=size,r+=size;\n\
    \    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    int l2=l,r2=r;\n    while(l<r){\n      if(l&1)apply_min(l++,x),apply_max(l,x);\n\
    \      if(r&1)apply_min(--r,x),apply_max(r,x);\n      l>>=1;\n      r>>=1;\n \
    \   }\n    l=l2,r=r2;\n    for(int i=1;i<=idx;i++){\n      if(((l>>i)<<i)!=l)update(l>>i);\n\
    \      if(((r>>i)<<i)!=r)update(r>>i);\n    }\n  }\n  T inner_min(int l,int r){\n\
    \    if(l==r)return INF;\n    T sml=INF,smr=INF;\n    l+=size,r+=size;\n    for(int\
    \ i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    while(l<r){\n      if(l&1)sml=min(sml,seq[l++].s1);\n      if(r&1)smr=min(seq[--r].s1,smr);\n\
    \      l>>=1,r>>=1;\n    }\n    return min(sml,smr);\n  }\n  T inner_max(int l,int\
    \ r){\n    if(l==r)return -INF;\n    T sml=-INF,smr=-INF;\n    l+=size,r+=size;\n\
    \    for(int i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    while(l<r){\n      if(l&1)sml=max(sml,seq[l++].b1);\n      if(r&1)smr=max(seq[--r].b1,smr);\n\
    \      l>>=1,r>>=1;\n    }\n    return max(sml,smr);\n  }\n  T inner_sum(int l,int\
    \ r){\n    if(l==r)return 0;\n    T sml=0,smr=0;\n    l+=size,r+=size;\n    for(int\
    \ i=idx;i>=1;i--){\n      if(((l>>i)<<i)!=l)eval(l>>i);\n      if(((r>>i)<<i)!=r)eval(r>>i);\n\
    \    }\n    while(l<r){\n      if(l&1)sml+=seq[l++].sum;\n      if(r&1)smr+=seq[--r].sum;\n\
    \      l>>=1,r>>=1;\n    }\n    return sml+smr;\n  }\n  public:\n  SegmentTreeBeats(){}\n\
    \  SegmentTreeBeats(int n):SegmentTreeBeats(vector<T>(n)){}\n  SegmentTreeBeats(const\
    \ vector<T>&v){\n    const int n=v.size();\n    while(size<n)size<<=1,idx++;\n\
    \    seq.resize(2*size);\n    for(int i=0;i<n;i++)seq[i+size]=v[i];\n    for(int\
    \ i=size-1;i;i--)update(i);\n  }\n  void range_chmin(int l,int r,T x){inner_chmin(l,r,x);}\n\
    \  void range_chmax(int l,int r,T x){inner_chmax(l,r,x);}\n  void range_add(int\
    \ l,int r,T x){inner_add(l,r,x);}\n  void range_update(int l,int r,T x){inner_update(l,r,x);}\n\
    \  T range_min(int l,int r){return inner_min(l,r);}\n  T range_max(int l,int r){return\
    \ inner_max(l,r);}\n  T range_sum(int l,int r){return inner_sum(l,r);}\n};\n/**\n\
    \ * @brief Segment Tree Beats!(Rnage Chmin Chmax Add Update Range Sum Min Max)\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: ds/segment/segment-tree-beats.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segment/segment-tree-beats.hpp
layout: document
redirect_from:
- /library/ds/segment/segment-tree-beats.hpp
- /library/ds/segment/segment-tree-beats.hpp.html
title: Segment Tree Beats!(Rnage Chmin Chmax Add Update Range Sum Min Max)
---
