---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Wavelet Matrix
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
  code: "#pragma once\n#include\"../template/template.hpp\"\n#include\"bit-vector.hpp\"\
    \n\ntemplate<typename T,int LOG>\nstruct WaveletMatrix{\n  private:\n  size_t\
    \ size;\n  BitVector matrix[LOG];\n  int mid[LOG];\n  public:\n  WaveletMatrix(){}\n\
    \  WaveletMatrix(vector<T>v):size(v.size()){\n    vector<T>left(size),right(size);\n\
    \    for(int level=LOG-1;level>=0;level--){\n      matrix[level]=BitVector(size+1);\n\
    \      int l=0,r=0;\n      for(size_t i=0;i<size;i++){\n        if((v[i]>>level)&1)right[r++]=v[i],matrix[level].set(i);\n\
    \        else left[l++]=v[i];\n      }\n      mid[level]=l;\n      matrix[level].build();\n\
    \      swap(v,left);\n      for(int i=0;i<r;i++)v[l+i]=right[i];\n    }\n  }\n\
    \  T access(int i)const{\n    T ret=0;\n    for(int level=LOG-1;level>=0;level--){\n\
    \      bool f=matrix[level][i];\n      if(f)ret|=T(1)<<level;\n      i=mid[level]*f+matrix[level].rank(f,i);\n\
    \    }\n    return ret;\n  }\n  T operator[](int i)const{return access(i);}\n\
    \  pair<int,int>succ(bool f,int l,int r,int level)const{\n    return {matrix[level].rank(f,l)+mid[level]*f,matrix[level].rank(f,r)+mid[level]*f};\n\
    \  }\n  int rank(int r,const T&x)const{\n    int l=0;\n    for(int level=LOG-1;level>=0;level--){\n\
    \      tie(l,r)=succ((x>>level)&1,l,r,level);\n    }\n    return r-l;\n  }\n \
    \ T kth_smallest(int l,int r,int k)const{\n    T ret=0;\n    for(int level=LOG-1;level>=0;level--){\n\
    \      int cnt=matrix[level].rank(false,r)-matrix[level].rank(false,l);\n    \
    \  bool f=(cnt<=k);\n      if(f){\n        ret|=T(1)<<level;\n        k-=cnt;\n\
    \      }\n      tie(l,r)=succ(f,l,r,level);\n    }\n    return ret;\n  }\n  T\
    \ kth_largest(int l,int r,int k)const{return kth_smallest(l,r,r-l-1-k);}\n  int\
    \ range_freq(int l,int r,T high)const{\n    int ret=0;\n    for(int level=LOG-1;level>=0;level--){\n\
    \      bool f=(high>>level)&1;\n      if(f)ret+=matrix[level].rank(false,r)-matrix[level].rank(false,l);\n\
    \      tie(l,r)=succ(f,l,r,level);\n    }\n    return ret;\n  }\n  int range_freq(int\
    \ l,int r,T low,T high)const{return range_freq(l,r,high)-range_freq(l,r,low);}\n\
    \  int prev_val(int l,int r,T x)const{\n    int cnt=range_freq(l,r,x);\n    return\
    \ (cnt==0?T(-1):kth_smallest(l,r,cnt-1));\n  }\n  int next_val(int l,int r,T x)const{\n\
    \    int cnt=range_freq(l,r,x);\n    return (cnt==r-l?T(-1):kth_smallest(l,r,cnt));\n\
    \  }\n};\n\ntemplate<typename T,int LOG>\nstruct CompressedWaveletMatrix{\n  private:\n\
    \  WaveletMatrix<int,LOG>w;\n  vector<T>v;\n  int get(const T&x)const{return lower_bound(v.begin(),v.end(),x)-v.begin();}\n\
    \  public:\n  CompressedWaveletMatrix(){}\n  CompressedWaveletMatrix(const vector<T>&x):v(x){\n\
    \    sort(v.begin(),v.end());\n    v.erase(unique(v.begin(),v.end()),v.end());\n\
    \    vector<int>t(x.size());\n    for(int i=0;i<(int)x.size();i++)t[i]=get(x[i]);\n\
    \    w=WaveletMatrix<int,LOG>(t);\n  }\n  T access(int i)const{return v[w.access(i)];}\n\
    \  T operator[](int i)const{return access(i);}\n  int rank(int r,const T&x)const{\n\
    \    auto idx=get(x);\n    if(idx==(int)v.size()||v[idx]!=x)return 0;\n    return\
    \ w.rank(r,idx);\n  }\n  T kth_smallest(int l,int r,int k)const{\n    return v[w.kth_smallest(l,r,k)];\n\
    \  }\n  T kth_largest(int l,int r,int k)const{\n    return v[w.kth_largest(l,r,k)];\n\
    \  }\n  int range_freq(int l,int r,T high)const{\n    return w.range_freq(l,r,get(high));\n\
    \  }\n  int range_freq(int l,int r,T low,T high)const{\n    return w.range_freq(l,r,get(low),get(high));\n\
    \  }\n  T prev_val(int l,int r,T high)const{\n    auto ret=w.prev_val(l,r,get(high));\n\
    \    return ret==-1?T(-1):v[ret];\n  }\n  T next_val(int l,int r,T low)const{\n\
    \    auto ret=w.next_val(l,r,get(low));\n    return ret==-1?T(-1):v[ret];\n  }\n\
    };\n/**\n * @brief Wavelet Matrix\n*/"
  dependsOn: []
  isVerificationFile: false
  path: ds/wavelet/wavelet-matrix.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/wavelet/wavelet-matrix.hpp
layout: document
redirect_from:
- /library/ds/wavelet/wavelet-matrix.hpp
- /library/ds/wavelet/wavelet-matrix.hpp.html
title: Wavelet Matrix
---
