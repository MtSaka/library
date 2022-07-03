---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/bit_vector.hpp
    title: Bit Vector
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_kth_smallest.test.cpp
    title: test/yosupo/range_kth_smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Wavelet Matrix
    links: []
  bundledCode: "#line 2 \"Data_Structure/bit_vector.hpp\"\nstruct bit_vector{\n  private:\n\
    \  size_t size,block;\n  vector<unsigned int>bit,sum;\n  public:\n  bit_vector(){}\n\
    \  bit_vector(size_t size):size(size),block((size+31)>>5),bit(block,0u),sum(block,0u){}\n\
    \  void set(int i){bit[i>>5]|=1u<<(i&31);}\n  bool operator[](int i)const{return\
    \ (bit[i>>5]>>(i&31))&1;}\n  void build(){\n    sum[0]=0u;\n    for(size_t i=1;i<block;i++)sum[i]=sum[i-1]+__builtin_popcount(bit[i-1]);\n\
    \  }\n  int rank(int i)const{return sum[i>>5]+__builtin_popcount(bit[i>>5]&((1<<(i&31))-1));}\n\
    \  int rank(bool v,int i)const{return (v?rank(i):i-rank(i));}\n};\n/**\n * @brief\
    \ Bit Vector\n*/\n#line 3 \"Data_Structure/wavelet_matrix.hpp\"\ntemplate<typename\
    \ T,int LOG>\nstruct wavelet_matrix{\n  private:\n  size_t size;\n  bit_vector\
    \ matrix[LOG];\n  int mid[LOG];\n  public:\n  wavelet_matrix(){}\n  wavelet_matrix(vector<T>v):size(v.size()){\n\
    \    vector<T>left(size),right(size);\n    for(int level=LOG-1;level>=0;level--){\n\
    \      matrix[level]=bit_vector(size+1);\n      int l=0,r=0;\n      for(size_t\
    \ i=0;i<size;i++){\n        if((v[i]>>level)&1)right[r++]=v[i],matrix[level].set(i);\n\
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
    \    int cnt=range_freq(l,r,x);\n    return (cnt==r-l?T(-1):kth_largest(l,r,cnt));\n\
    \  }\n};\n\ntemplate<typename T,int LOG>\nstruct compressed_wavelet_matrix{\n\
    \  private:\n  wavelet_matrix<int,LOG>w;\n  vector<T>v;\n  int get(const T&x)const{return\
    \ lower_bound(v.begin(),v.end(),x)-v.begin();}\n  public:\n  compressed_wavelet_matrix(){}\n\
    \  compressed_wavelet_matrix(const vector<T>&x):v(x){\n    sort(v.begin(),v.end());\n\
    \    v.erase(unique(v.begin(),v.end()),v.end());\n    vector<int>t(x.size());\n\
    \    for(int i=0;i<(int)x.size();i++)t[i]=get(x[i]);\n    w=wavelet_matrix<int,LOG>(t);\n\
    \  }\n  T access(int i)const{return v[w.access(i)];}\n  T operator[](int i)const{return\
    \ access(i);}\n  int rank(int r,const T&x)const{\n    auto idx=get(x);\n    if(idx==(int)v.size()||v[idx]!=x)return\
    \ 0;\n    return w.rank(r,idx);\n  }\n  T kth_smallest(int l,int r,int k)const{\n\
    \    return v[w.kth_smallest(l,r,k)];\n  }\n  T kth_largest(int l,int r,int k)const{\n\
    \    return v[w.kth_largest(l,r,k)];\n  }\n  int range_freq(int l,int r,T high)const{\n\
    \    return w.range_freq(l,r,get(high));\n  }\n  int range_freq(int l,int r,T\
    \ low,T high)const{\n    return w.range_freq(l,r,get(low),get(high));\n  }\n \
    \ T prev_val(int l,int r,T high)const{\n    auto ret=w.prev_val(l,r,get(high));\n\
    \    return ret==-1?T(-1):v[ret];\n  }\n  T next_val(int l,int r,T low)const{\n\
    \    auto ret=w.next_val(l,r,get(low));\n    return ret==-1?T(-1):v[ret];\n  }\n\
    };\n/**\n * @brief Wavelet Matrix\n*/\n"
  code: "#pragma once\n#include\"bit_vector.hpp\"\ntemplate<typename T,int LOG>\n\
    struct wavelet_matrix{\n  private:\n  size_t size;\n  bit_vector matrix[LOG];\n\
    \  int mid[LOG];\n  public:\n  wavelet_matrix(){}\n  wavelet_matrix(vector<T>v):size(v.size()){\n\
    \    vector<T>left(size),right(size);\n    for(int level=LOG-1;level>=0;level--){\n\
    \      matrix[level]=bit_vector(size+1);\n      int l=0,r=0;\n      for(size_t\
    \ i=0;i<size;i++){\n        if((v[i]>>level)&1)right[r++]=v[i],matrix[level].set(i);\n\
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
    \    int cnt=range_freq(l,r,x);\n    return (cnt==r-l?T(-1):kth_largest(l,r,cnt));\n\
    \  }\n};\n\ntemplate<typename T,int LOG>\nstruct compressed_wavelet_matrix{\n\
    \  private:\n  wavelet_matrix<int,LOG>w;\n  vector<T>v;\n  int get(const T&x)const{return\
    \ lower_bound(v.begin(),v.end(),x)-v.begin();}\n  public:\n  compressed_wavelet_matrix(){}\n\
    \  compressed_wavelet_matrix(const vector<T>&x):v(x){\n    sort(v.begin(),v.end());\n\
    \    v.erase(unique(v.begin(),v.end()),v.end());\n    vector<int>t(x.size());\n\
    \    for(int i=0;i<(int)x.size();i++)t[i]=get(x[i]);\n    w=wavelet_matrix<int,LOG>(t);\n\
    \  }\n  T access(int i)const{return v[w.access(i)];}\n  T operator[](int i)const{return\
    \ access(i);}\n  int rank(int r,const T&x)const{\n    auto idx=get(x);\n    if(idx==(int)v.size()||v[idx]!=x)return\
    \ 0;\n    return w.rank(r,idx);\n  }\n  T kth_smallest(int l,int r,int k)const{\n\
    \    return v[w.kth_smallest(l,r,k)];\n  }\n  T kth_largest(int l,int r,int k)const{\n\
    \    return v[w.kth_largest(l,r,k)];\n  }\n  int range_freq(int l,int r,T high)const{\n\
    \    return w.range_freq(l,r,get(high));\n  }\n  int range_freq(int l,int r,T\
    \ low,T high)const{\n    return w.range_freq(l,r,get(low),get(high));\n  }\n \
    \ T prev_val(int l,int r,T high)const{\n    auto ret=w.prev_val(l,r,get(high));\n\
    \    return ret==-1?T(-1):v[ret];\n  }\n  T next_val(int l,int r,T low)const{\n\
    \    auto ret=w.next_val(l,r,get(low));\n    return ret==-1?T(-1):v[ret];\n  }\n\
    };\n/**\n * @brief Wavelet Matrix\n*/"
  dependsOn:
  - Data_Structure/bit_vector.hpp
  isVerificationFile: false
  path: Data_Structure/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2022-06-02 17:56:16+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_kth_smallest.test.cpp
documentation_of: Data_Structure/wavelet_matrix.hpp
layout: document
redirect_from:
- /library/Data_Structure/wavelet_matrix.hpp
- /library/Data_Structure/wavelet_matrix.hpp.html
title: Wavelet Matrix
---
